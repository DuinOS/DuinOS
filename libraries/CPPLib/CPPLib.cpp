/*
  CPPLib.cpp - add the new() and delete() operators, (with very common and well known iplementations) and the function that allows to have virtual pure destructors.
  
  Copyright (c) 2009-2010  Multiplo (http://multiplo.org)
  
  NOTE: We strongly believe in peace, so we would not like to see our work in any non-civil or military project. 
  But, due to the FreeRTOS's modified GPL license which we do have to maintain, this is only a recommendation and an expression of our wishes.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/


extern "C"
{
	//#include "avr/io.h"
	#include <avr/interrupt.h>
	#include "stdlib.h"
}

#include "CPPLib.h"

void __cxa_pure_virtual()
{
    //abort();

    //See http://www.arduino.cc/playground/Code/Eclipse
    cli();
    for (;;) ;
}


void operator delete (void *ptr) throw ()
{
    //I know: The "if" is not necessary, according to the standard.
    //But it's just one more line of code, and I sleep better with it:
    if (ptr)
        free (ptr);
}


void operator delete[] (void *ptr) throw ()
{
    ::operator delete (ptr);
}


void *operator new (size_t size) throw()
{
    return malloc(size);
}


void *operator new[] (size_t size) throw()
{
    return ::operator new(size);
}

/*
void * operator new[](size_t size)
{
    return malloc(size);
}

void operator delete[](void * ptr)
{
    free(ptr);
}
*/
