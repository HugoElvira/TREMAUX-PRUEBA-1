/*
  Projecto1.c
  Autores: Pablo Ortiz, Hugo Elvira, Edgar Ramirez, Pedro Garcia
  
*/
#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"
int main()                                    // Main function
{
  // Add startup code here.
   //Pueros A0 y A1 en LOW
  low(26);
  low(27);

 
  while(1)
  {
    // Add main loop code here.
    while(v_adelante()>5&&consultarDerecha()==0){//pared a la derecha
      drive_rampStep(50,50);
    }
    if(consultarDerecha()==1){//libre a la derecha
      girarDerecha();  
    }
    if(consultarDerecha()==0&&consultarIzquierda()==1){//LIBRE A LA IZQUIERDA
      girarIzquierda();
    }
    if(consultarDerecha()==0&&consultarIzquierda()==0){//camino cerrado
      girar180();
    }
    
    
  }  
  
}

void girarIzquierda(){
  if(v_adelante()>5&&consultarDerecha()==0){
      return;
  }
  else{
    drive_speed(0,0);
    pause(500);
    drive_goto(-24,24); //gira a la izquierda 
    pause(500);
    return;
  }  
}
void girarDerecha(){
   for(int n = 1; n <= 100; n++){                // Count to hundred
    drive_rampStep(20,20);                   // move not too fast
    pause(10);                               // 50 ms between reps
  } 
  if(v_adelante()>5&&consultarDerecha()==0){//pared a la derechaS
      return;
  }
  else{
    if(v_adelante()<15){
      drive_rampStep(50,50);
    } 
    drive_speed(0,0);
    pause(500);
    drive_goto(24,-24); //giro a la derecha
    pause(500);
    for(int n = 1; n <= 100; n++){                // Count to hundred
    drive_rampStep(20,20);                   // move not too fast
    pause(10);                               // 50 ms between reps
  } 
    // avanza hasta que se encuentra denuevo con una pared a la derecha
    return;
  }      
}



void girar180(){
    drive_speed(0,0);
    pause(500);
    drive_goto(24,-24); //giro a la derecha
    pause(500);
    drive_goto(24,-24); //giro a la derecha
    pause(500);                               // 50 ms between reps
    // avanza hasta que se encuentra denuevo con una pared a la derecha
    return;
       
}




int v_adelante(){
  return ping_cm(8);
}

//Función que verifica el estado del ir derecho
//Retorna 1 cuando no hay objeto
//Retorna 0 cuando hay objeto
int consultarDerecha(){
  freqout(1,1,27000);
  return (input(2));
  }

//Función que verifica el estado del ir izquierda
//Retorna 1 cuando no hay objeto
//Retorna 0 cuando hay objeto
int consultarIzquierda(){
  freqout(11,1,27000);
  return (input(10));
  }