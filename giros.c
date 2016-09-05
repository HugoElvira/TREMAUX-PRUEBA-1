/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                    // Include simple tools

int main()                                    // Main function
{
  // Add startup code here.
  girarDerecha();

  while(1)
  
  {
    // Add main loop code here.
    
    //girarDerecha();
     //gira a la izquierda
    //pause(3000);
    //girarIzquierda();
     
    
  }  
}
void girarDerecha(){
  drive_goto(15,15); 
  drive_speed(0,0);
  pause(3000);
  drive_goto(26,-25); //giro a la derecha
  pause(3000);

  drive_goto(10,10);//avanza una pequeña distancia para evitar que detecte de nuevo un vacio en la derecha
  return;  
}
void girarIzquierda(){
  drive_speed(0,0);
  pause(500);
  drive_goto(-26,25); //gira a la izquierda 
  pause(500);
  drive_goto(5,5);
  return;
}