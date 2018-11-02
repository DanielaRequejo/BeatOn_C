#include "bibliotecas.h"

extern void limpia(void);
extern int menu_brain(void);
extern int menu_admin(void);
extern int menu_op_usuario(void);
extern int menu_op_album(void);
extern int menu_op_actualiza(void);
extern void logo_beaton(void);
extern void op_invalida(void);
extern void manual_usuario(void);
extern void manual_administrador(void);
extern void regresa(void);
extern int catalogo(void);
extern void presentacion(void);
/**
* Esta funcion limpia el Buffer.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void limpia(void){
  char c;
  while((c=getchar())!='\n');  //LIMPIA EL BUFFER
  return;
}
/**
* Esta funcion despliega el menu principal que conduce a las secciones de
* usuario, administrador, brain master y el manual de usuario, asi como la 
* unica salida del programa.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ int(opcion);
*/
extern int menu_brain(void){
  int opcion;
  system("clear");
  logo_beaton();  //LOGOTIPO DEL PROYECTO
  printf("\t---MENU PRINCIPAL---\n");
  printf("\t====================================\n");
  printf("\t1)INGRESA COMO \"ADMINISTRADOR\"\n");
  printf("\t2)INGRESA COMO \"USUARIO\"\n");
  printf("\t3)MANUAL DE INSTRUCCIONES DE USUARIO\n");
  printf("\t4)INGRESAR COMO \"BRAIN MASTER\"\n");
  printf("\t5)SALIR DE \"BEAT ON\"\n");
  printf("\t====================================\n");
  printf("\t(COLOQUE EL NUMERO Y LUEGO ENTER)\n");
  printf("\tSELECCION : ");
  scanf("%d",&opcion);  //SELECCION DE OPCION PARA EL MENU
  return(opcion);
}
/**
* Esta funcion despliega el menu del usuario administrador para llevarlo a sus
* funciones correspondientes, comprende al "control de usuarios", "control de
* albumes", "manual de usuario adiminstrador" y el regreso al menu principal.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ int(opcion)
*/
extern int menu_admin(void){
  int opcion;
  system("clear");
  logo_beaton();  //LOGOTIPO DEL PROYECTO
  printf("\tBIENVENIDO ADMINISTRADOR. \n");
  printf("\t\t---BEAT ON, SESION DE ADMINISTRADOR---\n\n");
  printf("\t---MENU DE ADMINISTRADOR---\n");
  printf("\t====================================\n");
  printf("\t1)CONTROL DE USUARIOS\n");
  printf("\t2)CONTROL DE ALBUMES\n");
  printf("\t3)MANUAL DE USUARIO ADMINISTRADOR\n");
  printf("\t4)SALIR DE \"SESION ADMINISTRADOR\"\n");
  printf("\t====================================\n");
  printf("\t(COLOQUE EL NUMERO Y LUEGO ENTER)\n");
  printf("\tSELECCION : ");
  scanf("%d",&opcion);
  return(opcion); //SELECCION DE OPCION PARA EL MENU
}
/**
* Esta funcion despliega un menu para el control de usuarios de la seccion del
* adiminstrador, esta seccion comprende la alta, baja y revisicion de los 
* usuarios del programa almacenados en los archivos.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern int menu_op_usuario(void){
  int opcion;
  system("clear");
  logo_beaton();  //LOGOTIPO DEL PROYECTO
  printf("\t---MENU DE CONTROL DE USUARIOS---\n");
  printf("\t====================================\n");
  printf("\t1)INGRESAR NUEVO USUARIO\n");
  printf("\t2)REVISAR LISTA DE USUARIOS\n");
  printf("\t3)ELIMINAR USUARIO\n");
  printf("\t4)REGRESAR A \"MENU ADMINISTRADOR\"\n");
  printf("\t====================================\n");
  printf("\t(COLOQUE EL NUMERO Y LUEGO ENTER)\n");
  printf("\tSELECCION : ");
  scanf("%d",&opcion);  //SELECCION DE OPCION PARA EL MENU
  return(opcion);
}
/**
* Esta funcion despliega un menu para el control de albumes de la seccion del
* adiminstrador, esta seccion comprende la alta, baja y revisicion de los 
* albumes del programa almacenados en los archivos.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ int(opcion)
*/
extern int menu_op_album(void){
  int opcion;
  system("clear");
  logo_beaton();  //LOGOTIPO DEL PROYECTO
  printf("\t---MENU DE CONTROL DE ALBUMES---\n");
  printf("\t====================================\n");
  printf("\t1)INGRESAR NUEVO ALBUM\n");
  printf("\t2)REVISAR LISTA DE ALBUMES\n");
  printf("\t3)ELIMINAR ALBUM\n");
  printf("\t4)ACTUALIZAR ALBUM\n");
  printf("\t5)REGRESAR A \"MENU ADMINISTRADOR\"\n");
  printf("\t====================================\n");
  printf("\t(COLOQUE EL NUMERO Y LUEGO ENTER)\n");
  printf("\tSELECCION : ");
  scanf("%d",&opcion);  //SELECCION DE OPCION PARA EL MENU
  return(opcion);
}
/**
* Esta funcion despliega un menu para la actualizacion de albumes de la seccion
* del administrador, esta seccion compredende la actualizacion de las canciones
* de los albumes en un archivo individual de album.
* @author/ David Parra.
* @param chrData/ NOTHING
* @return/ int(opcion)
*/
extern int menu_op_actualiza(void){
  int opcion;
  system("clear");
  logo_beaton();  //LOGOTIPO DEL PROYECTO                                                                                        
  printf("\t---MENU DE ACTUALIZACION DE ALBUMES---\n");
  printf("\t====================================\n");
  printf("\t1)CAMBIAR CANCION UNO\n");
  printf("\t2)CAMBIAR CANCION DOS\n");
  printf("\t3)CAMBIAR CANCION TRES\n");
  printf("\t4)CAMBIAR CANCION CUATRO\n");
  printf("\t5)CAMBIAR CANCION CINCO\n");
  printf("\t====================================\n");
  printf("\t(COLOQUE EL NUMERO Y LUEGO ENTER)\n");
  printf("\tSELECCION : ");
  scanf("%d",&opcion);  //SELECCION DE OPCION PARA EL MENU                                                                       
  return(opcion);
}
/**
* Esta funcion despliega un logotipo que forma una imagen mediante caracteres
* que toma parte de la presentacion del programa.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void logo_beaton(void){
  printf("\n");
  printf("\t╔=======================╗ ♫      ♫ \n");
  printf("\t║╔=====╗╔┌─────┐╗╔=====╗║╗  ♪  ♫   \n");
  printf("\t║║░╔=╗░║▼|◘◘◘◘◘|▼║░╔=╗░║║╚========╗\n");
  printf("\t║║░╚=╝░║▲|◘◘◘◘◘|▲║░╚=╝░║║█BEAT-ON█║\n");
  printf("\t║╚=====╝╚└─────┘╝╚=====╝║╔========╝\n");
  printf("\t╚=======================╝╝  ♫   ♪  \n");
  printf("\n");   //LOGOTIPO DEL PROYECTO
  return;
}
/**
* Esta funcion despliega un disco que forma una imagen mediante caracteres
* que toma parte de la presentacion del programa.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void disco(void){
  printf("\n");
  printf("\t╔=============================╗\n");
  printf("\t║▓▓▓|░░░░░░░░░BEAT-ON░░░░░░░░░║\n");
  printf("\t║▓▓▓|░╔=====================╗░║\t1)╓ « ╖ REWIND\n");
  printf("\t║▓▓▓|░║█████████████████████║░║\t2)╓ ► ╖ PLAY\n");
  printf("\t║▓▓▓|░║█████           █████║░║\t3)╓ ‼ ╖ PAUSA\n");
  printf("\t║▓▓▓|░║████   ███████   ████║░║\t4)╓ » ╖  FORWARD\n");
  printf("\t║▓▓▓|░║████  █████████  ████║░║\t5)╓ ♫ ╖ ESCUCHAR OTRO ALBUM\n");
  printf("\t║▓▓▓|░║█     █████████     █║░║\t6)╓ ◘ ╖ SALIR DEL REPRODUCTOR\n");
  printf("\t║▓▓▓|░║█     █████████     █║░║\n");
  printf("\t║▓▓▓|░║█     █████████     █║░║\n");
  printf("\t║▓▓▓|░║█     █████████     █║░║\n");
  printf("\t║▓▓▓|░║█████████████████████║░║\n");
  printf("\t║▓▓▓|░╚=====================╝░║\n");
  printf("\t╚=============================╝\n");
  printf("\n");  //IMAGEN DE DISCO PARA REPRODUCTOR
  return;
}
/**
* Esta funcion que se usa en los menus, despliega un mensaje para cuando el 
* usuario del programa o el administrador coloque un valor incorrecto dentro
* de un menu, y este tambien lo regresa al menu correspondiente.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void op_invalida(void){
  limpia();
  printf("\t====================================\n");
  printf("\t---OPCION INVALIDA---\n");
  printf("\t---PRECIONE \"ENTER\" PARA REGRESAR---\n");
  limpia();
  system("clear");
  return;
}
/**
* Esta funcion despliega un mensaje para regresar al menu correspondiente ya
* terminadas las operaciones de una funcion.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void regresa(void){ 
  printf("\t---PRECIONA \"ENTER\" PARA REGRESAR AL MENU---\n");
  limpia();
  system("clear");
}
/**
* Esta funcion genera un numero aleatorio entre 1 y 1000 para la clasificacion
* de los albumes ingresados mediante catalogo. Dandoles un valor numerico de
* referencia.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ int (random number)
*/
int catalogo(void){
  static int valor =1;
  if(valor){
    srand ((unsigned int) time (NULL));
    valor = 1;
  }
  return (rand ()%1000);  //GENERACION DEL NUMERO ALEATORIO PARA EL CATALOGO DEL ALBUM
}
/**
* Esta funcion despliega un mensaje antes de iniciar el primer menu del sistema
* que contiene el nombre y la clave de todos los colaboradores del proyecto.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void presentacion(void){
  system("clear");
  printf("\n\n");
  printf("\t---PROYECTO FINAL DE PROGRAMACION, PRIMER SEMESTRE---\n");
  printf("\t\t\t♪♪♪//\"BEAT-ON MUSIC\"\\\\♪♪♪\n");
  printf("\t====================================\n");
  printf("\tCREADO POR:\n");
  printf("\t\tLuis Armando Vizcaíno Magdaleno\n\t\t\t\t\t------192537-6\n");
  printf("\t\tDavid Parra Mercado\n\t\t\t\t\t------192098-8\n");
  printf("\t\tDaniela Raquejo Fernandez\n\t\t\t\t\t------190765-9\n");
  printf("\t====================================\n");
  printf("\t---PRESIONA \"ENTER\" PARA ENTRAR AL PROGRAMA---\n");
  limpia();  //PRESENTACION INICIAL
  return;
}

extern void manual_usuario(void){
  system("clear");
  logo_beaton();
  printf("\t---MANUAL DE USUARIO---\n");
  printf("\t====================================\n");
  printf("\n");
  printf("\tSiendo el usuario tiene los privilegios de acceder al reproductor\n");
  printf("\tde musica de \"BEATON\", aqui podra seleccionar el album que usted\n");
  printf("\tquiera escuchar y dentro de este podra moverse entre las canciones\n");  
  printf("\n\tDentro del menu se tiene 2 opciones:\n");
  printf("\n\t - La primera opcion sera para entrar al reproductor de musica,");
  printf("\n\t   dentro de este podra visualizar la lista de albumes que tiene");
  printf("\n\t   para escuchar. Para escuchar un album, solo digite el numero");
  printf("\n\t   de catalogo del album. Esto lo movera al reproductor.");
  printf("\n\t   Dento del reproductor usted tendra 6 opciones: \n");
  printf("\n\t   1. Boton REWIND ╓ « ╖");
  printf("\n\t\tUsando este boton podra moverse para atras entre canciones.");
  printf("\n\n\t   2. Boton PLAY ╓ ► ╖");
  printf("\n\t\tUsando este boton podra reproducir las canciones.");
  printf("\n\n\t   3. Boton PAUSE ╓ ‼ ╖ ");
  printf("\n\t\tUsando este boton podra pausar la cancion.");
  printf("\n\n\t   4. Boton FORWARD ╓ » ╖ ");
  printf("\n\t\tUsando este boton podra moverse para delante entre canciones.");
  printf("\n\n\t   5. Boton CAMBIAR DE ALBUM ╓ ♫ ╖ ");
  printf("\n\t\tUsando este boton podra regresar a seleccionar otro album");
  printf("\n\n\t   6. Boton SALIR ╓ ◘ ╖");
  printf("\n\t\tUsando este boton podra regeresar al menu del usuario.\n");
  printf("\n\t---PRESIONA \"ENTER\" PARA CONTINUAR CON EL MANUAL---");
  limpia();
  system("clear");
  logo_beaton();
  printf("\t---MANUAL DE USUARIO---\n");
  printf("\t====================================\n");
  printf("\n\t - La segunda opcion es salirse de su cuenta de usuario y");
  printf("\n\t   regresar al menu principal, para hacer esto, solo basta");
  printf("\n\t   con colocar \'0\' en la pantalla para seleccionar un album");
  printf("\n\t   o colocar \'6\' en el reproductor\n\n");
  regresa();    //MANUAL DE USUARIO
  return;
}
/**
* Esta funcion despliega el manual que corresponde al uso de las funciones
* de la seccion administrativa del programa, dando una breve explicacion de
* como funciona.
* @author/ David Parra.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void manual_administrador(void){
  system("clear");
  logo_beaton();
  printf("\n\t---MANUAL DE ADMINISTRADOR---\n");
  printf("\t====================================\n");
  printf("\n");
  printf("\tSiendo administrador tiene los privilegios de administrar los\n");
  printf("\tusuarios existentes, asi como los albumes que aparecen dentro\n");
  printf("\tdel reproductor dentro de la aplicacion para el usuario..\n");
  printf("\n\tDentro del menu se tienen 2 opciones: \n");
  printf("\n\t - La primera opcion sera para administrar a los usuarios,");
  printf("\n\t   ingrese a esta opcion digite 1 y presione enter.");
  printf("\n\t   Haciendo esto podra ver otro menu, donde tendra 4 opciones");
  printf("\n\t   mas, las cuales son:\n");
  printf("\n\t   1. Alta de usuarios..");
  printf("\n\t\tDentro de esta seccion, solo tendra que llenar los datos que");
  printf("\n\t\tcorresponden al nuevo usuario.\n");
  printf("\n\t   2. Lista de usuarios..");
  printf("\n\t\tDentro de esta seccion, podra uster revisar la lista general");
  printf("\n\t\tde todos los usuarios ingresados.\n");
  printf("\n\t   3. Baja de usuarios..");
  printf("\n\t\tDentro de esta seccion, usted podra eliminar un usuario que");
  printf("\n\t\teste registrado, colocando el apodo del usuario.\n");
  printf("\n\t   4. Regresar al menu anterior..");
  printf("\n\t\tAl seleccionar este usted regresara al menu del administrador.\n");
  printf("\n\t---PRESIONA \"ENTER\" PARA CONTINUAR CON EL MANUAL---\n");
  limpia();
  system("clear");
  logo_beaton();
  printf("\n\t---MANUAL DE ADMINISTRADOR---\n");
  printf("\t====================================\n");
  printf("\n\t - La segunda opcion es para administrar los albumes dentro de");
  printf("\n\t   su aplicacion para sus usuarios, para ingresar a esta opcion");
  printf("\n\t   digite 2 y presione enter.\n");
  printf("\n\t   Haciendo esto podra observar otro menu, dentro del cual");
  printf("\n\t   de este tendra 4 opciones, las cuales son:\n");
  printf("\n\t   1. Alta de albumes con todo y canciones..");
  printf("\n\t\tDentro de esta seccion, solo tendra que llenar los datos que");
  printf("\n\t\tcorresponden al nuevo album.\n");
  printf("\n\t   2. Lista de albumes con detalle de cada uno de ellos..");
  printf("\n\t\tDentro de esta seccion, podra uster revisar la lista general");
  printf("\n\t\tde todos los albumes y si usted lo desea, puede revisar de");
  printf("\n\t\tforma individual el contenido de estos.\n");
  printf("\n\t   3. Baja de albumes.. ");
  printf("\n\t\tDentro de esta seccion, usted podra eliminar un album que");
  printf("\n\t\teste registrado, colocaldo el numero de catalogo de este.\n");
  printf("\n\t   4. Actualizacion de albumes... ");
  printf("\n\t\tDentro de esta seccion, usted puede modificar los datos que se");
  printf("\n\t\tencuentran en un album individual.\n");
  printf("\n\t   5. Regresar al menu anterior..");
  printf("\n\t\tAl seleccionar este usted regresara al menu del administrador.\n\n");
  regresa();  //MANUAL DE USUARIO ADMINISTRADOR
}

