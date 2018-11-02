/**
* @file/ main.c  "./music"
* @brief/ Este programa es un sistema de almacenamiento y control de archivos de
* musica para el sistema de renta de musica "BEAT-ON", en este, quien controle el
* programa puede pedirle a un administrador del sistema que se le haga una cuenta
* de usuario que le de accseso a el sistema de musica "BEAT-ON" que le permitira
* escuchar las canciones almacenadas en la biblioteca del administrador.
* El administrador tiene la facultad de poder dar de alta y baja, tanto usuarios
* como albumes, asi como la edicion individual de los albumes, en cada seccion 
* correspondiente al administrador o usuario, existe un manual de instrucciones 
* que dice como se manupula la seccion correspondiente.
* Por ultimo tenemos al "Brain Master" una funcion a la cual se obtiene accseso 
* colocando "USUAIO : brainmtr" y "CONTRASEÑA : beaton" en la seccion "ACCSEDE 
* COMO BRAIN MASTER", cuya unica funcion es eliminar los datos del administrador
* y suplantarlas por las de uno nuevo.
* @author/ Luis Vizcaino, David Parra, Daniela Raquejo.
* @date/ Finish: 07/12/14
*/
#include "bibliotecas.h"

extern void limpia(void);
extern int menu_brain(void);
extern void logo_beaton(void);
extern void op_invalida(void);
extern void manual_usuario(void);
extern void regresa(void);
extern void presentacion(void);

extern void inicio_admin(void);
extern void inicio_usuario(void);
extern void brain_master(void);

void main(void){
  int opcion;
  presentacion();
  while(opcion != 5){
    opcion = menu_brain();
    switch(opcion){
    case 1:
      limpia();
      inicio_admin();
      break;
    case 2:
      limpia();
      inicio_usuario();
      break;
    case 3:
      limpia();
      manual_usuario();
      break;
    case 4:
      limpia();
      brain_master();
      break;
    case 5:
      limpia();
      printf("\t====================================\n");
      printf("\t---HASTA LUEGO---\n");
      break;
    default:
      op_invalida();
      break;
    }
  }
}
