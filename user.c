#include "bibliotecas.h"
typedef struct USUARIO{
  char nickname[40];
  char contrasenia[40];
  char nombre[40];
  char correo[40];
}USUARIO;
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
extern void logo_beaton(void);
extern void op_invalida(void);
extern void regresa(void);
extern void disco(void);

extern void inicio_usuario(void);
void reproductor(void);
void escuchar(void);
/**
* Esta funcion abre el archivo generado para los datos de los usuarios y 
* adquiere dos datos (apodo y contraseña) de quien use el programa y los
* evalua con los del archivo, si son iguales, se da entrada al reproductor
* de musica.
* Si no son iguales, se regresa al menu principal.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void inicio_usuario(void){
  FILE *f1;
  struct USUARIO datos;
  USUARIO *ptr;
  char nick[40], contrasenia[40];
  int registros, i, user, pass;
  printf("\t====================================\n");
  printf("\tINGRESE LOS DATOS DE \"USUARIO\"\n");
  printf("\tNICKNAME : ");
  gets(nick);  //OBTIENE VALOR DE APODO DE QUIEN USE EL PROGRAMA
  printf("\tCONTRASEÑA : ");
  gets(contrasenia);  //OBTIENE VALOR DE CONTRASEÑA DE QUIEN USE EL PROGRAMA
  printf("\t====================================\n");
  if((f1=fopen("USUARIOS", "r"))==NULL){  //ABRE EL ARCHIVO DE USUARIOS Y VERIFICA SU EXISTENCIA
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  fseek(f1,0,SEEK_END);  //DETERMINA INICIO DE BUSQUEDA
  registros = ftell(f1)/sizeof(struct USUARIO);  //DETERMINA EL NUMERO DE REGISTROS 
  ptr = (struct USUARIO*)malloc(sizeof(struct USUARIO)*registros);  //DETERMINA EL TAMAÑO PARA LA ESTRUCTURA DINAMICA DONDE SE REVISARAN LOS DATOS
  rewind(f1);
  fread(ptr,sizeof(struct USUARIO),registros,f1);  //LEE EL ARCHIVO
  fclose(f1);  //CIERRA EL ARCHIVO
  for (i=0;i<registros;i++){  
    user = strcmp(ptr[i].nickname,nick);  //EVALUA EL VALOR INGRESADO CON EL DEL ARCHIVO PARA LA EL USUARIO 
    pass = strcmp(ptr[i].contrasenia,contrasenia);  //EVALUA EL VALOR INGRESADO CON EL DEL ARCHIVO PARA LA CONTRASEÑA
    if(user == 0){  //SI EL VALOR DE USUARIO ES CORRECTO...
      if(pass == 0){  //Y LA CONTRASEÑA ES CORRECTA...
        reproductor();  //ENTRA AL REPRODUCTOR DE MUSICA
      }
    }
  }
  return;  //REGRESA AL MENU PRINCIPAL
}
/**
* Esta funcion abre el archivo general de los abumes y despliega un menu
* para que quien maneje el programa, seleccione uno y lo mueva al
* reproductor de musica.
* @author/ Daniela Raquejo.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void reproductor(void){
  FILE *f1;
  ALV val;
  char dato[40], album[40],nombre[20];
  int i=0, opcion,num,catalogo;
  int numero=1,opc;
  char cancion[6][40];
  
  system("clear");
  logo_beaton();
  printf("\t██████¡¡BEAT-ON MUSIC PLAYER!!██████\n");
  printf("\t====================================\n");
  if((f1=fopen("ALBUMES", "r+"))==NULL){  //ABRE EL ARCHIVO GENERAL DE ALBUMES  
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA                     
  }
  while(fgets(dato,40,f1)!=NULL){  //IMPRIME LA INFORMACION DE LOS ALBUMES    
    fscanf(f1,"%d\n",&num);
    printf("\tNUMERO DE CATALOGO: %d\n",num);
    printf("\t\tALBUM [%d]: %s\n",i+1,dato);
    i++;
  }
  fclose(f1);  //CIERRA EL ARCHIVO                                            
  printf("\t====================================\n");
  printf("\tESCUCHAR UN ALBUM  \'1\' || REGRESAR AL MENU \'0\' \n");
  printf("\tSELECCION : ");
  scanf("%d",&opcion);  //PREGUNTA SI EL CONTROLADOR DEL PROGRAMA DESEA REVISAR UN ARCHIVO INDIVIDUAL                                                         
  limpia();
  if(opcion >1){
    printf("\t====================================\n");
    printf("\tOPCION INVALIDA, PRESIONE \'ENTER\' PARA REGRESAR AL MENU PRINCIPAL\n");
    limpia();
  }
  if(opcion == 0){  //SI NO DESEA CONSULTAR UN ARCHIVO INDIVIDUAL...          
    printf("\t====================================\n");
    regresa();  //REGRESA A OPCIONES DE ALBUMES                               
    return;
  }
  if(opcion == 1){  //SI DESEA CONSULTAR UN ARCHIVO INDIVIDUAL...
    escuchar();
  }
}
/**
* Esta funcion abre el archivo individual deseado en el menu previo, y muestra 
* el reproductor musical con sus funciones, permitiendole a quien manjeje el
* programa la interactividad con el archivo.
* @author/ Daniela Raquejo.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void escuchar(void){
  FILE *f1;
  ALV val;
  char dato[40], album[40],nombre[20];
  int i=0, opcion,num,catalogo;
  int numero=1,opc;
  char cancion[7][40];
  int seleccion;
  system("clear");
  logo_beaton();
  printf("\t██████¡¡BEAT-ON MUSIC PLAYER!!██████\n");
  printf("\t====================================\n");
  if((f1=fopen("ALBUMES", "r+"))==NULL){  //ABRE EL ARCHIVO GENERAL DE ALBUMES
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA                     
  }
  while(fgets(dato,40,f1)!=NULL){  //IMPRIME LA INFORMACION DE LOS ALBUMES    
    fscanf(f1,"%d\n",&num);
    printf("\tNUMERO DE CATALOGO: %d\n",num);
    printf("\t\tALBUM [%d]: %s\n",i+1,dato);
    i++;
  }
  fclose(f1);
  printf("\t====================================\n");
  printf("\tINGRESA EL NUMERO DE CATALOGO DEL ALBUM QUE QUIERES ESCUCHAR\n");
  printf("\tNUMERO DE CATALOGO : ");
  scanf("%d",&catalogo);  //SE PREGUNTA POR NUMERO DE CATALOGO              
  getchar();
  sprintf(nombre,"%d",catalogo);
  if((f1=fopen(nombre, "r+"))==NULL){  //SE ABRRE EL ARCHIVO INDIVUDUAL DEL ALBUM A BUSCAR        
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE.\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA                  
  }
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
  strcpy(cancion[1],val.cancion1);
  strcpy(cancion[2],val.cancion2);
  strcpy(cancion[3],val.cancion3);
  strcpy(cancion[4],val.cancion4);
  strcpy(cancion[5],val.cancion5);
  opc=0;
  system("clear");  //INICIA EL REPRODUCTOR
  disco();
  printf("\tARTISTA : %s\n",val.artista);
  printf("\tALBUM   : %s\n",val.album);
  printf("\n");
  printf("\t\tCANCION 1 : %s\n",val.cancion1);
  printf("\t\tCANCION 2 : %s\n",val.cancion2);
  printf("\t\tCANCION 3 : %s\n",val.cancion3);
  printf("\t\tCANCION 4 : %s\n",val.cancion4);
  printf("\t\tCANCION 5 : %s\n",val.cancion5);
  printf("\n");
  printf("\t\tESTAS ESCUCHANDO : %s \n",cancion[numero]);
  while(opc !=5 ){
    printf("\t\t====================================\n");
    printf("\t\tSELECCION : ");
    scanf("%d",&opc);
    switch(opc){
    case 1:
      if(numero==1){  //REGRESA CANCION
	limpia();
	system("clear");
	disco();
	printf("\tARTISTA : %s\n",val.artista);
	printf("\tALBUM   : %s\n",val.album);
	printf("\n");
	printf("\t\tCANCION 1 : %s\n",val.cancion1);
        printf("\t\tCANCION 2 : %s\n",val.cancion2);
        printf("\t\tCANCION 3 : %s\n",val.cancion3);
        printf("\t\tCANCION 4 : %s\n",val.cancion4);
	printf("\t\tCANCION 5 : %s\n",val.cancion5);
	printf("\n");
	printf("\t\t====================================\n");
	printf("\t\tUPSS!! YA NO HAY CANCIONES EN ESTE ALBUM\n");
	printf("\t\t---PRECIONA \'ENTER\' PARA SELECCIONAR OTRO ALBUM---\n");
	limpia();
	escuchar();  //SI NO HAY CACIONES REGRESA A LA SELECCION
      }
      else{  
	system("clear");
        disco();
        printf("\tARTISTA : %s\n",val.artista);
        printf("\tALBUM   : %s\n",val.album);
        printf("\n");
        printf("\t\tCANCION 1 : %s\n",val.cancion1);
        printf("\t\tCANCION 2 : %s\n",val.cancion2);
        printf("\t\tCANCION 3 : %s\n",val.cancion3);
        printf("\t\tCANCION 4 : %s\n",val.cancion4);
        printf("\t\tCANCION 5 : %s\n",val.cancion5);
        printf("\n");
        numero--;
        printf("\t\tESTAS ESCUCHANDO : %s \n",cancion[numero]);
	limpia();
      }
      break;
    case 2:  //HACE "PLAY" A CANCION
      system("clear");
      disco();
      printf("\tARTISTA : %s\n",val.artista);
      printf("\tALBUM   : %s\n",val.album);
      printf("\n");
      printf("\t\tCANCION 1 : %s\n",val.cancion1);
      printf("\t\tCANCION 2 : %s\n",val.cancion2);
      printf("\t\tCANCION 3 : %s\n",val.cancion3);
      printf("\t\tCANCION 4 : %s\n",val.cancion4);
      printf("\t\tCANCION 5 : %s\n",val.cancion5);
      printf("\n");
      printf("\t\tESTAS ESCUCHANDO : %s \n",cancion[numero]);
      limpia();
      break;
    case 3:  //HACE PAUSA A CANCION
      system("clear");
      disco();
      printf("\tARTISTA : %s\n",val.artista);
      printf("\tALBUM   : %s\n",val.album);
      printf("\n");
      printf("\t\tCANCION 1 : %s\n",val.cancion1);
      printf("\t\tCANCION 2 : %s\n",val.cancion2);
      printf("\t\tCANCION 3 : %s\n",val.cancion3);
      printf("\t\tCANCION 4 : %s\n",val.cancion4);
      printf("\t\tCANCION 5 : %s\n",val.cancion5);
      printf("\n");
      printf("\t\tCANCION PAUSADA \n");
      limpia();
      break;
    case 4:  //VA A LA CANCION SIGUIENTE
	system("clear");
	disco();
	printf("\tARTISTA : %s\n",val.artista);
	printf("\tALBUM   : %s\n",val.album);
	printf("\n");
	printf("\t\tCANCION 1 : %s\n",val.cancion1);
	printf("\t\tCANCION 2 : %s\n",val.cancion2);
	printf("\t\tCANCION 3 : %s\n",val.cancion3);
	printf("\t\tCANCION 4 : %s\n",val.cancion4);
	printf("\t\tCANCION 5 : %s\n",val.cancion5);
	printf("\n");
	numero++;
	printf("\t\tESTAS ESCUCHANDO : %s \n",cancion[numero]);
	if(numero==6){
	  limpia();
	  system("clear");
	  disco();
	  printf("\tARTISTA : %s\n",val.artista);
	  printf("\tALBUM   : %s\n",val.album);
	  printf("\n");
	  printf("\t\tCANCION 1 : %s\n",val.cancion1);
	  printf("\t\tCANCION 2 : %s\n",val.cancion2);
	  printf("\t\tCANCION 3 : %s\n",val.cancion3);
	  printf("\t\tCANCION 4 : %s\n",val.cancion4);
	  printf("\t\tCANCION 5 : %s\n",val.cancion5);
	  printf("\n");
	  printf("\t\t====================================\n");
	  printf("\t\tUPSS!! YA NO HAY CANCIONES EN ESTE ALBUM\n");
	  printf("\t\t---PRECIONA \'ENTER\' PARA SELECCIONAR OTRO ALBUM---\n");
	  limpia();  //SI NO HAY CANCIONES, REGRESA A SELECCION
	  escuchar();
	}
	break;              
    case 5: //REGRESA A SELECCION
	limpia();
	escuchar();
	break;
    case 6:  //REGRESA A MENU PRINCIPAL
      limpia();
      return;
	break;
      default:
	op_invalida();
	system("clear");  //INICIA EL REPRODUCTOR
	disco();
	printf("\tARTISTA : %s\n",val.artista);
	printf("\tALBUM   : %s\n",val.album);
	printf("\n");
        printf("\t\tCANCION 1 : %s\n",val.cancion1);
	printf("\t\tCANCION 2 : %s\n",val.cancion2);
	printf("\t\tCANCION 3 : %s\n",val.cancion3);
	printf("\t\tCANCION 4 : %s\n",val.cancion4);
	printf("\t\tCANCION 5 : %s\n",val.cancion5);
	printf("\n");
      }
    }   
  fclose(f1);  //CIERRA ARCHIVO
}
