/*
  Universidad del Valle de Guatemala
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
   for(int n = 1; n <= 70; n++){ //permite al robot girar a la derecha y avanzar evitando que los sensores lo hagan girar nuevamente a la derecha instantaneamente y asi seguir avanzando por el pasillo           
    drive_rampStep(20,20);                   
    pause(10);                               
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
    for(int n = 1; n <= 100; n++){  //permite al robot girar a la derecha y avanzar evitando que los sensores lo hagan girar nuevamente a la derecha instantaneamente y asi seguir avanzando por el pasillo
    drive_rampStep(20,20);                   
    pause(10);                               
  } 
    // avanza hasta que se encuentra denuevo con una pared a la derecha
    return;
  }      
}



void girar180(){//giro doble a la derecha para salir de caminos cerrarrados
    drive_speed(0,0);
    pause(500);
    drive_goto(24,-24); //giro a la derecha
    pause(500);
    drive_goto(24,-24); //giro a la derecha
    pause(500);                               
    // avanza hasta que se encuentra denuevo con una pared a la derecha
    return;
       
}




int v_adelante(){//sensor que lee la distancia frontal a la que el robot se encuentra de la pared
  return ping_cm(8);
}

//Función que verifica el estado del la derecha
//Retorna 1 cuandosi no hay pared
//Retorna 0 cuando cuando hay pared
int consultarDerecha(){
  freqout(1,1,28000);
  return (input(2));
  }

//Función que verifica el estado del ir izquierda
//Retorna 1 cuandosi no hay pared
//Retorna 0 cuando cuando hay pared
int consultarIzquierda(){
  freqout(11,1,28000);
  return (input(10));
  }