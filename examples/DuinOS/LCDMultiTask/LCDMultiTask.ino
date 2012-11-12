/**
 * Exemplo de Uso de LCD com DuinOS
 * O exemplo demonstra as melhores práticas para uso do LCD.
 * Este exemplo está sendo construindo e no momento seu código foi ajustado para
 * LCD de 16x2 e 20x4
 * O Exemplo também demonstra o uso de Mutex para evitar concorrencia no posicionamento 
 * do cursor, o que pode causar impressões misturadas, em locais errados.
 *
 * Autor: Carlos Delfino
 * E-mail Autor: consultoria@carlosdelfino.eti.br
 */
#define configUSE_MUTEX 1;

#include <LiquidCrystal.h>

#define LCD_C16_R2 1
#define LCD_C20_R4 2
#define LCD_TYPE  LCD_C20_R4

#if (LCD_TYPE == LCD_C16_R2)
#define COL 16
#define ROW 2
#define LCD_BACKGROUND_LIMIT_MAX 180
#define LCD_BACKGROUND_LIMIT_MIN 50
#elif (LCD_TYPE == LCD_C20_R4)
#define COL 20
#define ROW 4
#define LCD_BACKGROUND_LIMIT_MAX 180
#define LCD_BACKGROUND_LIMIT_MIN 50
#else
#define COL 16
#define ROW 2
#define LCD_BACKGROUND_LIMIT_MAX 180
#define LCD_BACKGROUND_LIMIT_MIN 50
#endif



#define constrast_pin 6
#define background_pin 9

#define sensor1_pin A0
#define sensor2_pin A1

#define sensor1_col 10
#define sensor2_col 10
#define sensor1_row 2
#define sensor2_row 3

LiquidCrystal lcd(7,8,2,3,4,5);
//LiquidCrystal2 lcd(10,11,22,24,26,28);


#include <DuinOS/semphr.h>
xSemaphoreHandle xMutexLCD = NULL;

declareTaskLoop(changeLCD);
declareTaskLoop(readSensor1);
declareTaskLoop(readSensor2);
declareTaskLoop(changeLCDSensor1);
declareTaskLoop(changeLCDSensor2);

int sensor1;
int sensor2;

void setup(){

  initMainLoopStackSize(configMINIMAL_STACK_SIZE*3);

  pinMode(constrast_pin,OUTPUT);
  pinMode(background_pin,OUTPUT);

  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);

  analogWrite(constrast_pin, 50); // contraste
  analogWrite(background_pin, LCD_BACKGROUND_LIMIT_MAX); // brilho de fundo

  vSemaphoreCreateBinary(xMutexLCD);

  lcd.begin(COL,ROW);

  digitalWrite(13,LOW);

  lcd.home();
  for(char i = 0; i< COL;i++) lcd.write("*");
  lcd.setCursor(0,1);

  int fator = (COL - 15)/2;
  for(char i = 0; i<fator;i++) lcd.write("*");
  lcd.print(" LCD MultiTask ");
  for(char i = 0; i< fator;i++) lcd.write("*");

  digitalWrite(13,HIGH);

  delay(2000);

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Tempo");
  lcd.setCursor(8,0);
  lcd.print(":");

  lcd.setCursor(0,sensor1_row);
  lcd.print("Sensor 1:");

  lcd.setCursor(0,sensor2_row);
  lcd.print("Sensor 2:");

  createTaskLoop(changeLCD,LOW_PRIORITY);
  //createTaskLoop(readSensor1,LOW_PRIORITY);
  //createTaskLoop(readSensor2,LOW_PRIORITY);
  createTaskLoop(changeLCDSensor1,LOW_PRIORITY);
  createTaskLoop(changeLCDSensor2,LOW_PRIORITY);

}

volatile int x = 40;
void loop(){ 
  digitalWrite(13,!digitalRead(13));
  delay(800);

  unsigned char i;
  for(i=LCD_BACKGROUND_LIMIT_MAX;i>=LCD_BACKGROUND_LIMIT_MIN;i--) {
    analogWrite(background_pin,i);
    delay(15);
  }
  for(i=LCD_BACKGROUND_LIMIT_MIN;i<=LCD_BACKGROUND_LIMIT_MAX;i++) {
    analogWrite(background_pin,i);
    delay(15);
  }

}

taskLoop(changeLCD){
  //taskENTER_CRITICAL();


  char x=0;
  for(char i=40;i<128;i++){
    if(xSemaphoreTake(xMutexLCD, ( portTickType ) 10 ) == pdTRUE){
      lcd.setCursor(x++,1);
      lcd.write(i);
      xSemaphoreGive(xMutexLCD);
    }
    if(x>=COL)x=0;
    delay(30);
  }  
  //taskEXIT_CRITICAL();
}

taskLoop(readSensor1){
  sensor1 = analogRead(sensor1_pin);
  resumeTask(changeLCDSensor1);
}
taskLoop(readSensor2){
  sensor2 = analogRead(sensor1_pin);
  resumeTask(changeLCDSensor2);
}

taskLoop(changeLCDSensor1){
  if(xSemaphoreTake(xMutexLCD, ( portTickType ) 10 ) == pdTRUE){
    lcd.setCursor(sensor1_col,sensor1_row);
    lcd.print("Sen1"); // aqui deve ser espaço em branco, para limpar valores maiores do que o que será exibido.
    lcd.print(sensor1);
    xSemaphoreGive(xMutexLCD);
  }
  suspend();
}

taskLoop(changeLCDSensor2){

  if(xSemaphoreTake(xMutexLCD, ( portTickType ) 10 ) == pdTRUE){
    lcd.setCursor(sensor2_col,sensor2_row);
    lcd.print("Sen2"); // aqui deve ser espaço em branco, para limpar valores maiores do que o que será exibido.
    //lcd.print(sensor2);
    xSemaphoreGive(xMutexLCD);
  }

  suspend();
}



