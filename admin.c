#include "bibliotecas.h"
typedef struct ADMIN{
  char nombre[40];
  char contrasenia[40];
}ADMIN;
typedef struct USUARIO{
  char nickname[40];
  char contrasenia[40];
  char nombre[40];
  char correo[40];
}USUARIO;
typedef struct ALBUMES{
  int catalogo;
  char artista[40];
  char album[40];
  int anio;
  char genero[40];
  char cancion1[40];
  char cancion2[40];
  char cancion3[40];
  char cancion4[40];
  char cancion5[40];
}ALBUMES;
typedef struct ALV{
  int catalogo;
  char artista[40];
  char album[40];
  int anio;
  char genero[40];
  char cancion1[40];
  char cancion2[40];
  char cancion3[40];
  char cancion4[40];
  char cancion5[40];
}ALV;

extern void limpia(void);
extern int menu_admin(void);
extern int menu_op_usuario(void);
extern int menu_op_album(void);
extern void logo_beaton(void);
extern void op_invalida(void);
extern void manual_administrador(void);
extern int menu_op_actualiza(void);
extern void regresa (void);
extern int catalogo(void);

extern void inicio_admin(void);
void secion_admin(void);

void usuario(void);
void nuevo_usuario(void);
void ver_usuarios(void);
void eliminar_usuario(void);

void albumes(void);
void nuevo_album(void);
void ver_albumes(void);
void eliminar_albumes(void);
void actualizar_albumes(void);
/**
* Esta funcion abre el archivo generado para los datos del administrador y 
* adquiere dos datos (usuario y contraseña) de quien use el programa y los
* evalua con los del archivo, si son iguales, se da entrada al menu de
* opciones para el administrador. Si no son iguales, se regresa al menu 
* principal.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void inicio_admin(void){
  FILE *f1;
  struct ADMIN datos;
  ADMIN *ptr;
  char usuario[40], contrasenia[40];
  int registros, i, user, pass;
  printf("\t====================================\n");
  printf("\tINGRESE LOS DATOS DE \"ADMINISTRADOR\"\n");
  printf("\tUSUARIO : ");
  gets(usuario);  //OBTIENE VALOR DE USUARIO DE QUIEN USE EL PROGRAMA
  printf("\tCONTRASEÑA : ");
  gets(contrasenia);  //OBTIENE VALOR DE CONTRASEÑA DE QUIEN USE EL PROGRAMA
  printf("\t====================================\n");
  if((f1=fopen("ADMINISTRADORES", "r"))==NULL){  //ABRE EL ARCHIVO DE ADMINISTRADORES Y VERIFICA SU EXISTENCIA
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO ESISTE, SALE DEL PROGRAMA
  }
  fseek(f1,0,SEEK_END);  //DETERMINA EL INICIO DE BUSQUEDA
  registros = ftell(f1)/sizeof(struct ADMIN);  //DETERMINA EL NUMERO DE REGISTROS
  ptr = (struct ADMIN*)malloc(sizeof(struct ADMIN)*registros);  //DETERMINA EL TAMAÑO PARA LA ESTRUCTURA DINAMICA DONDE SE REVISARAN LOS DATOS
  rewind(f1);
  fread(ptr,sizeof(struct ADMIN),registros,f1);  //LEE EL ARCHIVO
  fclose(f1);  //CIERRA EL ARCHIVO
  for (i=0;i<registros;i++){
    user = strcmp(ptr[i].nombre,usuario); //EVALUA EL VALOR INGRESADO CON EL DEL ARCHIVO PARA EL USUARIO
    pass = strcmp(ptr[i].contrasenia,contrasenia);  //EVALUA EL VALOR INGRESADO CON EL DEL ARCHIVO PARA LA CONTRASEÑA
  }
  if(user != 0){  //SI EL VALOR INGRESADO DE USUARIO NO ES CORRECTO, REGRESA
    printf("\tUSUARIO INCORRECTO\n");
    if(pass != 0){ //SI EL VALOR INGRESADO DE CONTRASEÑA NO ES CORRECTO, REGRESA
      printf("\tCONTRASEÑA INCORRECTA\n");
      return;
    }
    return;
  }
  else{
    if(user == 0){  //SI EL VALOR DE USUARIO ES CORRECTO...
      if(pass == 0){  //Y LA CONTRASEÑA ES CORRECTA...
	secion_admin();  //ENTRA AL MENU DE ADMINISTRADOR
      }
    }
  }
  return;  //REGRESA AL MENU PRINCIPAL
}
/**
* Esta funcion toma el valor dado por el menu del adiministrador y conduce a 
* quien use el programa a los submenus correspondientes o a las funciones
* correspondientes.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void secion_admin(void){
  int opcion;
  while(opcion != 4){
    opcion = menu_admin();  //OBTIENE VALOR DE SELECCION DE MENU
    switch(opcion){  //SEGUN EL VALOR DE SELECCION SE EJECUTA EN EL PROGRAMA...
    case 1:  //MENU DE OPCIONES DE USUARIO
      limpia();
      usuario();
      break;  //REGRESA AL MENU DE ADMINISTRADOR
    case 2:  //MENU DE OPCIONES DE ALBUMES
      limpia();
      albumes();
      break;  //REGRESA AL MENU DE ADMINISTRADOR
    case 3:  //MANUAL DEL ADMINISTRADOR
      limpia();
      manual_administrador();
      break;  //REGRESA AL MENU DE ADIMINISTRADOR
    case 4:  //SALE DEL MENU DE ADMINISTRADOR
      limpia();
      break;  //REGRESA AL MENU PRINCIPAL
    default:  //OPCION DE MENU INVALIDA
      op_invalida(); 
      break;  //REGRESA AL MENU DE ADMINISTRADOR
    }
  }
}
/**
* Esta funcion toma el valor dado por el menu de administrador y conduce
* a quien use el programa a los submenus correspondientes o a las funciones
* correspondientes.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void usuario(void){
  int opcion;
  while(opcion != 4){
    opcion = menu_op_usuario();  //OBTIENE EL VALOR DE SELECCION DEL PROGRAMA
    switch(opcion){  //SEGUN EL VALOR DE SELECCION SE EJECUTA EN EL PROGRAMA...
    case 1:  //ALTA DE NUEVO USUARIO
      limpia();
      nuevo_usuario();
      break;  //REGRESA A OPCIONES DE USUARIO
    case 2:  //REVISA LA LISTA DE USUARIOS
      limpia();
      ver_usuarios();
      break;  //REGRESA A OPCIONES DE USUARIO
    case 3:  //DA DE BAJA UN USUARIO
      limpia();
      eliminar_usuario();
      break;  //REGRESA A OPCIONES DE USUARIO
    case 4:  //REGRESA AL MENU DE ADMINISTRADOR
      limpia();
      break;
    default:  //OPCION DE MENU INVALIDA
      op_invalida();
      break;  //REGRESA A OPCIONES DE USUARIO
    }
  }
}
/**
* Esta funcion toma los datos ingresados por el que controle el programa y los
* almacena en una estructura que despues es almacenada en un archivo binario.
* Despues, abre el mismo archivo donde se alamacenaron los datos y verifica que
* los datos ingresados existan
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void nuevo_usuario(void){
  FILE *f1;
  USUARIO valor;
  struct USUARIO datos;
  USUARIO *ptr;
  int i;
  long int registros;
  system("clear");
  logo_beaton();
  if((f1=fopen("USUARIOS", "a+b"))==NULL){  //SE ABRE EL ARCHIVO DE USUARIOS
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXITE, SALE DEL PROGRAMA
  }
  printf("\t---CREACION DE NUEVO USUARIO--\n");
  printf("\t\tINGRESE LOS DATOS DEL NUEVO USUARIO\n");
  printf("\t====================================\n");
  printf("\tNICKNAME : ");
  gets(valor.nickname);  //SE OBTIENE EL VALOR DEL APODO
  printf("\tCONTRASEÑA : ");
  gets(valor.contrasenia); //SE OBTINE EL VALOR DE LA CONTRASEÑA
  printf("\tNOMBRE COMPLETO : ");
  gets(valor.nombre);  //SE OBTIENE EL VALOR DEL NOMBRE DEL USUARIO
  printf("\tCORREO : ");
  gets(valor.correo);  //SE OBTIENE EL VALOR DEL CORREO
  fwrite(&valor,sizeof(USUARIO),1,f1);  //SE ALMACENAN LOS DATOS EN EL ARCHIVO
  fclose(f1);  //SE CIERRA EL ARCHIVO
  if((f1=fopen("USUARIOS", "r+b"))==NULL){ //SE ABRE EL ARCHIVO DE LOS USUARIOS
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  printf("\t====================================\n");
  printf("\tVERIFICACION DE LOS DATOS INGRESADOS\n");
  fseek(f1,0,SEEK_END);  //DETERMINA EL INICIO DE LA BUSQUEDA
  registros = ftell(f1)/sizeof(struct USUARIO);  //DETERMINA EL NUMERO DE REGISTROS
  ptr = (struct USUARIO*)malloc(sizeof(struct USUARIO)*registros);  //DETERMINA EL TAMAÑO DE LA ESTRUCTURA DINAMICA DONDE SE REVISARAN LOS DATOS
  rewind(f1);
  fread(ptr,sizeof(struct USUARIO),registros,f1);  //LEE EL ARCHIVO
  fclose(f1);  //CIERRA EL ARCHIVO
  for(i=registros-1;i<registros;i++){  //IMPRIME EL ULTIMO DATO DEL ARCHIVO
    printf("\t NICKNAME : ");
    printf("%s\n",ptr[i].nickname);
    printf("\t CONTRASEÑA : ");
    printf("%s\n",ptr[i].contrasenia);
    printf("\t NOMBRE : ");
    printf("%s\n",ptr[i].nombre);
    printf("\t CORREO : ");
     printf("%s\n",ptr[i].correo);
    printf("\t====================================\n");
  }
  regresa();  //REGRESA A OPCIONES DE USUARIO
}
/**
* Esta funcion abre el archivo donde se almacenan los datos de los usuarios y
* muestra su contenido en pantalla. Clasificandolos en cuantos usuarios hay. 
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void ver_usuarios(void){
  FILE *f1;
  struct USUARIO datos;
  USUARIO *ptr;
  long int registros;
  int i;
  system("clear");
  logo_beaton();
  if((f1=fopen("USUARIOS", "r+b"))==NULL){  //ABRE EL ARCHIVO DE USUARIO
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  printf("\n\t---LISTA DE TODOS LOS USUARIOS---\n");
  printf("\t====================================\n");
  fseek(f1,0,SEEK_END);  //DETERMINA EL INICIO DE LA BUSQUEDA
  registros = ftell(f1)/sizeof(struct USUARIO);  //DETERMINA EL NUMERO DE REGISTROS
  ptr = (struct USUARIO*)malloc(sizeof(struct USUARIO)*registros); //DETERMINA EL TAMAÑO DE LA ESTRUCTURA DINAMICA DONDE SE REVISARAN LOS DATOS
  rewind(f1);
  fread(ptr,sizeof(struct USUARIO),registros,f1);  //LEE EL ARCHIVO
  fclose(f1);  //CIERRA EL ARCHIVO
  for(i=0;i<registros;i++){  //IMPRIME EN PANTALLA LOS USUARIOS
    printf("\t NICKNAME : ");
    printf("%s\n",ptr[i].nickname);
    printf("\t CONTRASEÑA : ");
    printf("%s\n",ptr[i].contrasenia);
    printf("\t NOMBRE : ");
    printf("%s\n",ptr[i].nombre);
    printf("\t CORREO : ");
    printf("%s\n",ptr[i].correo);
    printf("\n");
  }
  printf("\t====================================\n");
  regresa();  //REGRESA A OPCIONES DE USUARIO
}
/**
* Esta funcion abre el archivo donde se almacenan los datos de los usuarios y
* busca en este el apodo de un usuario a eliminar, este valor buscado es 
* analizado en el archivo de usuarios y si hay coincidencia, se copian todos
* los registros de usuario en un archivo temporal menos el buscado.
* Depues, se copian los datos del archivo temporal en el archivo de usuarios
* sobreescribiendo el archivo de usuarios original y eliminando el usuario.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void eliminar_usuario(void){
  FILE *f1, *f2;
  struct USUARIO datos;
  USUARIO *ptr;
  long int registros;
  int i, val;
  char nombre[20];
  system("clear");
  logo_beaton();
  if((f1=fopen("USUARIOS", "r+b"))==NULL){  //ABRE EL ARCHIVO CON LA INFORMACION DE LOS USUARIOS
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  printf("\n\t---ELIMINACION DE USUARIOS---\n");
  printf("\t====================================\n");
  printf("\tINGRESE EL APODO DEL USUARIO A ELIMINAR : ");
  gets(nombre);  //OBTIENE EL APODO A BUSCAR
  fseek(f1,0,SEEK_END);  //DETERMINA EL INICIO DE LA BUSQUEDA
  registros = ftell(f1)/sizeof(struct USUARIO);  //DETERMINA EL NUMERO DE REGISTROS
  ptr = (struct USUARIO*)malloc(sizeof(struct USUARIO)*registros);  //DETERMINA EL TAMAÑO DE LA ESTRUCTURA DINAMICA DONDE SE REVISARAN LOS DATOS
  rewind(f1);
  fread(ptr,sizeof(struct USUARIO),registros,f1);  //LEER EL ARCHIVO
  fclose(f1);  //CIERRA EL ARCHIVO
  if((f2=fopen("TEMPORAL", "w+b"))==NULL){  //CREA UN ARCHIVO TEMPORAL
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  for(i=0;i<registros;i++){  //COMPARA LOS DATOS DEL ARCHIVO
    val = strcmp(ptr[i].nickname,nombre);  //DETERMINA SI HAY COINCIDENCIA
    if(val == 0){  //SI HAY COINCIDENCIA...
      printf("\n\tUSUARIO ENCONTRADO\n");
      printf("\t\tUSUARIO : %s\n",ptr[i].nombre);  //SE MUESTRA EN PANTALLA EL APODO DEL USUARIO CON COINCIDENCIA
      printf("\t\t\tUSUARIO ELIMINADO\n");
    }
    else{  //SI NO HAY COINCIDENCIA...
      fwrite(&ptr[i],sizeof(USUARIO),1,f2); //SE COPIAN LOS DATOS AL ARCHIVO TEMPORAL
    }
  }
  fclose(f2);  //CIERRA EL ARCHIVO TEMPORAL
  if((f1=fopen("USUARIOS", "w+b"))==NULL){  //ABRE EL ARCHIVO DE USUARIOS
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  if((f2=fopen("TEMPORAL", "r+b"))==NULL){  //ABRE EL ARCHIVO TEMPORAL
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  fseek(f2,0,SEEK_END);  //DETERMINA EL INICIO DE LA BUSQUEDA
  ptr = (struct USUARIO*)malloc(sizeof(struct USUARIO));  //DETERMINA EL TAMAÑO DE LA ESTRUCTURA DINAMICA DONDE SE REVISARAN LOS DATOS
  rewind(f2);
  while ((fread(ptr,sizeof(struct USUARIO),1,f2)) != 0){  //MIENTRAS EL ARCHIVO TENGA ALGO QUE LEER...
    fwrite(ptr,sizeof(struct USUARIO),1,f1);  //ESCRIBE LOS DATOS DEL ARCHIVO TEMPORAL EN EL ARCHIVO DE LOS USUARIOS
  }
  fclose(f1);  //CIERRA EL ARCHIVO DE USUAIROS
  fclose(f2);  //CIERRA EL ARCHIVO TEMPORAL
  if(remove("TEMPORAL")==0);
  printf("\t====================================\n");
  regresa();  //REGRESA A OPCIONES DE USUARIOS
}
/**
* Esta funcion toma el valor dado por el menu de administrador y conduce
* a quien use el programa a los submenus correspondientes o a las funciones
* correspondientes.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void albumes(void){
  int opcion;
  while(opcion != 5){  
    opcion = menu_op_album();  //OBTIENE EL VALOR DE SELECCION DEL PROGRAMA
    switch(opcion){  //SEGUN EL VALOR DE SELECCION SE EJECUTA EN EL PROGRAMA...
    case 1:  //ALTA DE NUEVO ALBUM
      limpia();
      nuevo_album();
      break;  //REGRESA A OPCIOES DE ALBUMES
    case 2:  //REVISA LA LISTA DE ALBUMES
      limpia();
      ver_albumes();
      break;  //REGRESA A OPCIONES DE ALBUMES
    case 3:  //DA DE BAJA UN ALBUM
      limpia();
      eliminar_albumes();
      break;  //REGRESA A OPCIONES DE ALBUMES
    case 4:
      limpia();
      actualizar_albumes();
      break;
    case 5:
      limpia();
      break;  //REGRESA AL MENU DE ADMINISTRADOR
    default:  //OPCION DE MENU INVALIDA
      op_invalida();
      break;  //REGRESA A OPCIONES DE ALBUMES
    }
  }
}
/**
* Esta funcion toma los datos ingresados por el que controle el programa y los
* almacena dentro de un archivo de texto para bajo el nombre de su numero de
* catalogo, asi como tambien almacena el numero y el nombre en un archivo
* para la administracion general de los albumes.
* @author/ David Parra.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void nuevo_album(void){
  FILE *f1,*f2;
  ALBUMES datos;
  ALV val;
  int num;
  char nombre[20], nom[20], tipo[20]="Alta: ";
  char *timestamp = (char *)malloc(sizeof(char) * 16);
  time_t ltime;
  ltime=time(NULL);
  struct tm *tm;
  system("clear");
  logo_beaton();
  if((f1=fopen("ALBUMES", "a"))==NULL){  //ABRE EL ARCHIVO DE CONSULTA GENERAL
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  if((f2=fopen("BITACORA","a"))==NULL){  //ABRE EL ARCHIVO DE BITACORA
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(2);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  printf("\t---CREACION DE NUEVO ALBUM--\n");
  printf("\t\tINGRESE LOS DATOS DEL NUEVO ALBUM (USE \'_\' COMO ESPACIO)\n");
  printf("\t====================================\n");
  printf("\tTITULO DEL ALBUM : ");  //OBTIENE TITULO DEL ALBUM
  gets(datos.album);
  fprintf(f1,"%s\n",datos.album);  //SE CREA NUMERO DE CATALOGO
  datos.catalogo = catalogo();
  fprintf(f1,"%d\n",datos.catalogo);
  fclose(f1);  //SE ALMACENA LA INFORMACION DENTRO DEL ARCHIVO GENERAL
  sprintf(nombre,"%d",datos.catalogo);
  if((f1=fopen(nombre, "a"))==NULL){  //ABRE EL ARCHIVO INDIVIDUAL CON LA INFORMACION DE SU REGISTRO
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE SALE DEL PROGRAMA
  }
  printf("\tARTISTA : ");  //OBTIENE LOS DATOS INDIVIDUALES DEL ALBUM
  gets(datos.artista);
  printf("\tAÑO : ");
  scanf("%d",&datos.anio);
  limpia(); 
  printf("\tGENERO: ");
  gets(datos.genero);
  printf("\t====================================\n");
  printf("\tINGRESE LAS CANCIONES DEL ALBUM\n");
  printf("\t====================================\n");
  printf("\tCANCION 1 : ");
  gets(datos.cancion1);
  printf("\tCANCION 2 : ");
  gets(datos.cancion2);
  printf("\tCANCION 3 : ");
  gets(datos.cancion3);
  printf("\tCANCION 4 : ");
  gets(datos.cancion4);
  printf("\tCANCION 5 : ");
  gets(datos.cancion5);
  printf("\t====================================\n");  //COLOCA LOS DATOS DEL ALBUM DENTRO DE SU ARCHIVO INDIVIDUAL
  fprintf(f1,"%d\n",datos.catalogo);
  fprintf(f1,"%s\n",datos.artista);
  fprintf(f1,"%s\n",datos.album);
  fprintf(f1,"%d\n",datos.anio);
  fprintf(f1,"%s\n",datos.genero);
  fprintf(f1,"%s\n",datos.cancion1);
  fprintf(f1,"%s\n",datos.cancion2);
  fprintf(f1,"%s\n",datos.cancion3);
  fprintf(f1,"%s\n",datos.cancion4);
  fprintf(f1,"%s\n",datos.cancion5);
  fclose(f1);  //CIERRA EL ARCHIVO
  if((f1=fopen(nombre, "r"))==NULL){  //ABRE EL ARCHIVO INDIVIDUAL PARA VERIFICAR LOS DATOS INGRESADOS
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PORGRAMA
  }
  printf("\tVERIFICACION DE LOS DATOS INGRESADOS\n");  //IMPRIME LOS DATOS QUE ESTAN DENTRO DEL ARCHIVO DEL ALBUM INDIVIDUAL
  fscanf(f1,"%d\n",&val.catalogo);
  fscanf(f1,"%s\n",val.artista);
  fscanf(f1,"%s\n",val.album);
  fscanf(f1,"%d\n",&val.anio);
  fscanf(f1,"%s\n",val.genero);
  fscanf(f1,"%s\n",val.cancion1);
  fscanf(f1,"%s\n",val.cancion2);
  fscanf(f1,"%s\n",val.cancion3);
  fscanf(f1,"%s\n",val.cancion4);
  fscanf(f1,"%s\n",val.cancion5);
  printf("\tCATALOGO : %d\n",val.catalogo);
  printf("\tARTISTA : %s\n",val.artista);
  printf("\tALBUM : %s\n",val.album);
  printf("\tAÑO : %d\n",val.anio);
  printf("\tGENERO : %s\n",val.genero);
  printf("\tCANCIONES DEL ALBUM\n");
  printf("\t\tCANCION 1 : %s\n",val.cancion1);
  printf("\t\tCANCION 2 : %s\n",val.cancion2);
  printf("\t\tCANCION 3 : %s\n",val.cancion3);
  printf("\t\tCANCION 4 : %s\n",val.cancion4);
  printf("\t\tCANCION 5 : %s\n",val.cancion5);
  printf("\t====================================\n");
  fclose(f1);  //CIERRA EL ARCHIVO
   sprintf(nom,"%d",val.catalogo);
  tm=localtime(&ltime);
  sprintf(timestamp,"%04d\\%02d\\%02d\\%02d\\%02d\\%02d", tm->tm_year+1900, tm->tm_mon, 
	  tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);  //ACTUALIZACION DE LA BITACORA
  fprintf(f2,"%s\n",tipo);
  fprintf(f2,"%s\n",timestamp);
  fprintf(f2,"%s\n",nom);
  fclose(f2);  //CIERRA LA BITACORA
  regresa();  //REGRESA A OPCIONES DE ALBUMES
}

/**
* Esta funcion abre el archivo donde se almacenan los datos de los albumes y
* muestra su contenido en pantalla. Clasificandolos en cuantos albumes hay y
* que numero de catalogo tienen, si el que maneje el porgrama lo desea, puede
* ver el contenido individual del archivo de cada album colocando su numero
* de registro. 
* @author/ David Parra, Luis Vizcaíno.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void ver_albumes(void){
  FILE *f1;
  ALV val;
  char dato[40], album[40],nombre[20];
  int i=0, opcion,num,catalogo;
  system("clear");
  logo_beaton();
  printf("\t---LISTA DE LOS ABUMES EXISTENTES---\n");
  printf("\t====================================\n");
  if((f1=fopen("ALBUMES", "r+"))==NULL){  //ABRE EL ARCHIVO GENERAL DE ALBUMES
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  while(fgets(dato,40,f1)!=NULL){  //IMPRIME LA INFORMACION DE LOS ALBUMES
    fscanf(f1,"%d\n",&num);
    printf("\tNUMERO DE CATALOGO: %d\n",num);
    printf("\t\tALBUM [%d]: %s\n\n",i+1,dato);
    i++;
  }
  fclose(f1);  //CIERRA EL ARCHIVO
  printf("\t====================================\n");
  printf("\t¿DESEAS CONSULTAR UN ALBUM?(SI\'1\'/NO\'0\')\n");
  printf("\tSELECCION : ");
  scanf("%d",&opcion);  //PREGUNTA SI EL CONTROLADOR DEL PROGRAMA DESEA REVISAR UN ARCHIVO INDIVIDUAL
  limpia();
  if(opcion == 0){  //SI NO DESEA CONSULTAR UN ARCHIVO INDIVIDUAL...
    printf("\t====================================\n");
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
  }
  if(opcion == 1){  //SI DESEA CONSULTAR UN ARCHIVO INDIVIDUAL...
    printf("\t====================================\n");
    printf("\tINGRESA EL NUMERO DE CATALOGO COMO SE VE EN LA LISTA\n");
    printf("\tNUMERO CATALOGO : ");
    scanf("%d",&catalogo);  //SE PREGUNTA POR NUMERO DE CATALOGO
    getchar();
    sprintf(nombre,"%d",catalogo);
    if((f1=fopen(nombre, "r+"))==NULL){  //SE ABRRE EL ARCHIVO INDIVUDUAL DEL ALBUM A BUSCAR
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
    }
    system("clear");
    logo_beaton();
    printf("\t---CONTENIDO DEL ALBUM---\n");
    printf("\t====================================\n");  //LEE E IMPRIME EL CONTENIDO DEL ARCHIVO DEL ALBUM INDIVIDUAL.
    fscanf(f1,"%d\n",&val.catalogo);
    fscanf(f1,"%s\n",val.artista);
    fscanf(f1,"%s\n",val.album);
    fscanf(f1,"%d\n",&val.anio);
    fscanf(f1,"%s\n",val.genero);
    fscanf(f1,"%s\n",val.cancion1);
    fscanf(f1,"%s\n",val.cancion2);
    fscanf(f1,"%s\n",val.cancion3);
    fscanf(f1,"%s\n",val.cancion4);
    fscanf(f1,"%s\n",val.cancion5);
    printf("\tCATALOGO : %d\n",val.catalogo);
    printf("\tARTISTA : %s\n",val.artista);
    printf("\tALBUM : %s\n",val.album);
    printf("\tAÑO : %d\n",val.anio);
    printf("\tGENERO : %s\n",val.genero);
    printf("\tCANCIONES DEL ALBUM\n");
    printf("\t\tCANCION 1 : %s\n",val.cancion1);
    printf("\t\tCANCION 2 : %s\n",val.cancion2);
    printf("\t\tCANCION 3 : %s\n",val.cancion3);
    printf("\t\tCANCION 4 : %s\n",val.cancion4);
    printf("\t\tCANCION 5 : %s\n",val.cancion5);
    printf("\t====================================\n");
    fclose(f1);
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
  }
}
/**
* Esta funcion pide a quien maneje el programa el numero de catalogo de un
* album que exista, revisa el archivo general donde se almacena la informacion
* basica de los albumes quitando el registro y eliminando el album con su
* contenido, esto lo hace copiando los datos del los demas registros en un
* archivo temporal y luego suplantandolos en el archivo original.
* @author/ David Parra.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void eliminar_albumes(void){
  char nombre[24],dato[40],album[40],nom[20],tipo[20]="Baja: ";
  FILE *f1,*f2,*f3,*f4;
  char *timestamp = (char *)malloc(sizeof(char) * 16);
  time_t ltime;
  ltime=time(NULL);
  struct tm *tm;
  int num,catalogo;
  if((f4=fopen("BITACORA","a"))==NULL){  //ABRE EL ARCHIVO DE LA BITACORA
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  system("clear");
  logo_beaton();
  printf("\t---ELIMINACION DE ALBUMES---\n");
  printf("\t====================================\n");
    printf("\tESCRIBRE EL NUMERO DE CATOLOGO QUE QUIERAS BORRAR.\n");
    printf("\tNUMERO DE CATALOGO: ");  //PREGUNTA POR EL CATALOGO DEL ALBUM A ELIMINAR
    scanf("%d",&catalogo);
    getchar();
    sprintf(nom,"%d",catalogo);
    if((f1=fopen("ALBUMES","r"))==NULL){  //BUSCA EN EL ARCHIVO GENERAL DE ALBUMES POR SU NUMERO DE CATALOGO
      printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
      exit(1);  //SI EL ARCHIVO NO EXITE, SALE DEL PROGRAMA
    }
    if((f2=fopen("EXTERNO","a"))==NULL){  //ABRE UN ARCHIVO TEMPORAL
      printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
      exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
    }
    while(fgets(dato,40,f1)!=NULL){  //BUSCA UNA CONCIDENCIA CON EL VALOR BUSCADO
      fscanf(f1,"%d\n",&num);
      if(num!=catalogo){  //SI NO HAY CONINCIDENCIA, SE IMPRIME LA INFORMACION GENERAL DEL ALBUM EN EL TEMPORAL
	fprintf(f2,"%s",dato);
	fprintf(f2,"%d\n",num);
      }
      else{  //SI HAY CONINCIDENCA, SE LE SEÑALA AL QUE CONTROLA AL PROGRAMA
	printf("\n\tALBUM ENCONTRADO\n");
	printf("\t\tALBUM : %s",dato);
	printf("\t\t\tALBUM ELIMINADO\n");
      }
    }
    fclose(f1);  //CIERRA ARCHIVO GENERAL
    fclose(f2);  //CIERRA ARCHIVO GENERAL
    if(remove("ALBUMES")==0);  //ELIMINA EL ARCHIVO GENERAL
    if(rename("EXTERNO","ALBUMES")==0);  //CAMBIA EL NOMBRE DEL ARCHIVO TEMPORAL A "ALBUMES" PARA INFORMACION GENERAL
    if((f3=fopen(nom,"a"))==NULL){  //ABRE EL ARCHIVO INDIVIDUAL DEL VALOR BUSCADO
      printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
      exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
    }
    if( f3 != NULL ){  //SI EL ARCHIVO EXISTE...
	fclose(f3);
        if( remove(nom)== 0 );  //ELIMINA EL ARCHIVO INDIVIDUAL
        else   printf( "\n\tNO SE PUDO BORRAR ALBUM\n" );
      }
    else   printf( "\n\tNO SE PUDO ENCONTRAR ALBUM\n" );
    printf("\t====================================\n");
    
    tm=localtime(&ltime);  
    sprintf(timestamp,"%04d\\%02d\\%02d\\%02d\\%02d\\%02d", tm->tm_year+1900, tm->tm_mon, 
	    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);  //ACTUALIZA LA BITACORA
    fprintf(f4,"%s\n",tipo);
    fprintf(f4,"%s\n",timestamp);
    fprintf(f4,"%s\n",nom);
    fclose(f4);  //CIERRA LA BITACORA
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
}
/**
* Esta funcion pide a quien maneje el programa el numero de catalogo de un
* album que exista, revisa el archivo indivudual de ese numero de catalogo
* y suplanta una cancion dentro de ese archivo con una dada por quien controle
* el programa.
* @author/ David Parra.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void actualizar_albumes(void){
  char nombre[24],dato[40],album[40],nom[20],tipo[20]="Actualizar: ";
  FILE *f1,*f2,*f3,*f4;
  ALV val;
  ALBUMES datos;
  char *timestamp = (char *)malloc(sizeof(char) * 16);
  time_t ltime;
  ltime=time(NULL);
  struct tm *tm;
  int num,catalogo,opcion;
  system("clear");
  logo_beaton();
  printf("\t---ACTUALIZACION DE ALBUMES---\n");
  printf("\t====================================\n");
  printf("\tESCRIBRE EL NUMERO DE CATOLOGO QUE QUIERAS ACTUALIZAR.\n");
  printf("\tNUMERO DE CATALOGO: ");  //PREGUNTA POR EL CATALOGO DEL ALBUM A ACTUALIZAR
  scanf("%d",&catalogo);
  getchar();
  sprintf(nom,"%d",catalogo);
  if((f1=fopen(nom,"r"))==NULL){  //ABRE EL ARCHIVO DEL ALBUM INDIVIDUAL
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  if((f2=fopen("EXTERNO","a"))==NULL){  //ABRE UN ARCHIVO TEMPORAL
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  if((f4=fopen("BITACORA","a"))==NULL){  //ABRE EL ARCHIVO DE LA BITACORA
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }   //LE EL ARCHIVO DEL ALBUM INDIVIDUAL
  fscanf(f1,"%d\n",&val.catalogo);
  fscanf(f1,"%s\n",val.artista);
  fscanf(f1,"%s\n",val.album);
  fscanf(f1,"%d\n",&val.anio);
  fscanf(f1,"%s\n",val.genero);
  fscanf(f1,"%s\n",val.cancion1);
  fscanf(f1,"%s\n",val.cancion2);
  fscanf(f1,"%s\n",val.cancion3);
  fscanf(f1,"%s\n",val.cancion4);
  fscanf(f1,"%s\n",val.cancion5);
  opcion = menu_op_actualiza();  //SELECCION DE CANCION A ACTUALIZAR
  switch(opcion){
  case 1:  //ACTUALIZA CANCION 1
    limpia();
    printf("\tDAME LA NUEVA CANCION: ");
    gets(datos.cancion1);  //OBTIENE LOS DATOS DE LA NUEVA CANCION
    fprintf(f2,"%d\n",val.catalogo);
    fprintf(f2,"%s\n",val.artista);
    fprintf(f2,"%s\n",val.album);
    fprintf(f2,"%d\n",val.anio);
    fprintf(f2,"%s\n",val.genero);
    fprintf(f2,"%s\n",datos.cancion1);
    fprintf(f2,"%s\n",val.cancion2);
    fprintf(f2,"%s\n",val.cancion3);
    fprintf(f2,"%s\n",val.cancion4);
    fprintf(f2,"%s\n",val.cancion5);
    fclose(f2);  //CIERRA EL ARCHIVO TEMPORAL 
    remove(nom); //ELIMINA EL ORIGINAL
    rename("EXTERNO",nom);  //SUPLANTA EL ORIGINAL CON EL TEMPORAL
    tm=localtime(&ltime);  
    sprintf(timestamp,"%04d\\%02d\\%02d\\%02d\\%02d\\%02d", tm->tm_year+1900, tm->tm_mon, 
	    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);  //ACTUALIZA BITACORA
    fprintf(f4,"%s\n",tipo);
    fprintf(f4,"%s\n",timestamp);
    fprintf(f4,"%s\n",nom);
    fclose(f4);  //CIERRA BITACORA
    printf("\t====================================\n");
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
    break;
  case 2:   //ACTUALIZA CANCION 2
    limpia();
    printf("\tDAME LA NUEVA CANCION: ");
    gets(datos.cancion2);  //OBTIENE LOS DATOS DE LA NUEVA CANCION
    fprintf(f2,"%d\n",val.catalogo);
    fprintf(f2,"%s\n",val.artista);
    fprintf(f2,"%s\n",val.album);
    fprintf(f2,"%d\n",val.anio);
    fprintf(f2,"%s\n",val.genero);
    fprintf(f2,"%s\n",val.cancion1);
    fprintf(f2,"%s\n",datos.cancion2);
    fprintf(f2,"%s\n",val.cancion3);
    fprintf(f2,"%s\n",val.cancion4);
    fprintf(f2,"%s\n",val.cancion5);
    fclose(f2);  //CIERRA EL ARCHIVO TEMPORAL 
    remove(nom); //ELIMINA EL ORIGINAL
    rename("EXTERNO",nom);  //SUPLANTA EL ORIGINAL CON EL TEMPORAL
    tm=localtime(&ltime);  
    sprintf(timestamp,"%04d\\%02d\\%02d\\%02d\\%02d\\%02d", tm->tm_year+1900, tm->tm_mon, 
	    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);  //ACTUALIZA BITACORA
    fprintf(f4,"%s\n",tipo);
    fprintf(f4,"%s\n",timestamp);
    fprintf(f4,"%s\n",nom);
    fclose(f4);  //CIERRA BITACORA
    printf("\t====================================\n");
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
    break;
  case 3:   //ACTUALIZA CANCION 3
    limpia();
    printf("\tDAME LA NUEVA CANCION: ");
    gets(datos.cancion3);  //OBTIENE LOS DATOS DE LA NUEVA CANCION
    fprintf(f2,"%d\n",val.catalogo);
    fprintf(f2,"%s\n",val.artista);
    fprintf(f2,"%s\n",val.album);
    fprintf(f2,"%d\n",val.anio);
    fprintf(f2,"%s\n",val.genero);
    fprintf(f2,"%s\n",val.cancion1);
    fprintf(f2,"%s\n",val.cancion2);
    fprintf(f2,"%s\n",datos.cancion3);
    fprintf(f2,"%s\n",val.cancion4);
    fprintf(f2,"%s\n",val.cancion5);
    fclose(f2);  //CIERRA EL ARCHIVO TEMPORAL 
    remove(nom); //ELIMINA EL ORIGINAL
    rename("EXTERNO",nom);  //SUPLANTA EL ORIGINAL CON EL TEMPORAL
    tm=localtime(&ltime);  
    sprintf(timestamp,"%04d\\%02d\\%02d\\%02d\\%02d\\%02d", tm->tm_year+1900, tm->tm_mon, 
	    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec); //ACTUALIZA BITACORA
    fprintf(f4,"%s\n",tipo);
    fprintf(f4,"%s\n",timestamp);
    fprintf(f4,"%s\n",nom);
    fclose(f4);  //CIERRA BITACORA
    printf("\t====================================\n");
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
    break;
  case 4:   //ACTUALIZA CANCION 4
    limpia();
    printf("\tDAME LA NUEVA CANCION: ");
    gets(datos.cancion4);
    fprintf(f2,"%d\n",val.catalogo);
    fprintf(f2,"%s\n",val.artista);
    fprintf(f2,"%s\n",val.album);
    fprintf(f2,"%d\n",val.anio);
    fprintf(f2,"%s\n",val.genero);
    fprintf(f2,"%s\n",val.cancion1);
    fprintf(f2,"%s\n",val.cancion2);
    fprintf(f2,"%s\n",val.cancion3);
    fprintf(f2,"%s\n",datos.cancion4);
    fprintf(f2,"%s\n",val.cancion5);
    fclose(f2);  //CIERRA EL ARCHIVO TEMPORAL 
    remove(nom); //ELIMINA EL ORIGINAL
    rename("EXTERNO",nom);  //SUPLANTA EL ORIGINAL CON EL TEMPORAL
    tm=localtime(&ltime);  
    sprintf(timestamp,"%04d\\%02d\\%02d\\%02d\\%02d\\%02d", tm->tm_year+1900, tm->tm_mon, 
	    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec); //ACTUALIZA BITACORA
    fprintf(f4,"%s\n",tipo);
    fprintf(f4,"%s\n",timestamp);
    fprintf(f4,"%s\n",nom);
    fclose(f4);  //CIERRA BITACORA
    printf("\t====================================\n");
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
    break;
  case 5:   //ACTUALIZA CANCION 5
    limpia();
    printf("\tDAME LA NUEVA CANCION: ");
    gets(datos.cancion5);  //OBTIENE LOS DATOS DE LA NUEVA CANCION
    fprintf(f2,"%d\n",val.catalogo);
    fprintf(f2,"%s\n",val.artista);
    fprintf(f2,"%s\n",val.album);
    fprintf(f2,"%d\n",val.anio);
    fprintf(f2,"%s\n",val.genero);
    fprintf(f2,"%s\n",val.cancion1);
    fprintf(f2,"%s\n",val.cancion2);
    fprintf(f2,"%s\n",val.cancion3);
    fprintf(f2,"%s\n",val.cancion4);
    fprintf(f2,"%s\n",datos.cancion5);
    fclose(f2);  //CIERRA EL ARCHIVO TEMPORAL 
    remove(nom); //ELIMINA EL ORIGINAL
    rename("EXTERNO",nom);  //SUPLANTA EL ORIGINAL CON EL TEMPORAL
    tm=localtime(&ltime);  
    sprintf(timestamp,"%04d\\%02d\\%02d\\%02d\\%02d\\%02d", tm->tm_year+1900, tm->tm_mon, 
	    tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);  //ACTUALIZA BITACORA
    fprintf(f4,"%s\n",tipo);
    fprintf(f4,"%s\n",timestamp);
    fprintf(f4,"%s\n",nom);
    fclose(f4);  //CIERRA BITACORA
    printf("\t====================================\n");
    regresa();  //REGRESA A OPCIONES DE ALBUMES
    return;
    break;
  }
  return;
}  
