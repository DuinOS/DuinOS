
#include <LiquidCrystal2.h>



LiquidCrystal2 lcd(10,11,2,3,4,5);
//LiquidCrystal2 lcd(10,11,22,24,26,28);

void setup(){
    lcd.begin(16,2);
    
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);

    analogWrite(8,200); // contraste
    analogWrite(9,128); // brilho de fundo
    lcd.write("1234567890123456");
}

volatile int x = 40;
void loop(){
    //lcd.write("1234567890123456");
    //lcd.write("1234567890123456");
    
    
delay(3);
    lcd.setCursor(0,1);
delay(3);

//taskENTER_CRITICAL();
lcd.print(x++);
//taskEXIT_CRITICAL();     

lcd.print("teste ");

    for(int i=100;i<=200;i++) {
        analogWrite(8,i);
        delay(15);
    }
    for(int i=200;i>=100;i--) {
        analogWrite(8,i);
        delay(15);
    }
    
    
     
}



