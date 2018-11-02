#include "bibliotecas.h"

typedef struct USUARIO{
  char nombre[40];
  char contrasenia[40];
}USUARIO;

extern void limpia(void);
extern void logo_beaton(void);
extern void op_invalida(void);
extern void regresa(void);

extern void brain_master(void);
void nuevo_admin(void);
/**
* Esta funcion evalua dos datos ingresados por el que controle el programa
* (usuario y contraseña) y los evalua con dos cadenas predeterminadas con
* el usuario y contraseña estipulados del sistema creador de adiminstradores
* dichos valores son "USUARIO : brainmtr" y "CONTRASEÑA : beaton", si los
* valores ingresados son identicos, se da accseso a la creacion de un nuevo
* adiminstrador unico para el programa.
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
extern void brain_master(void){
  char usuario[8], contrasenia[5], c_brain[7]="beaton",u_brain[10]="brainmtr";
  int user, pass, limit=8;
  printf("\t====================================\n");
  printf("\tINGRESE LOS DATOS DE \"BRAIN MASTER\"\n");
  printf("\tUSUARIO : ");
  gets(usuario);  //OBTIENE UN VALOR DE USUARIO
  printf("\tCONTRASEÑA : ");
  gets(contrasenia);  //OBRIENE UN VALOR DE CONTRASEÑA
  printf("\t====================================\n");
  user = strcmp(u_brain,usuario);  //EVALUA EL VALOR INGRESADO CON EL PREESTABLECIDO PARA EL USUARIO
  pass = strcmp(contrasenia,c_brain);  //EVALUA EL VALOR INGRESADO CON EL PREESTABLECIDO PARA LA CONTRASEÑA
  if(user != 0){  //SI EL VALOR INGRESADO DE USUARIO NO ES CORRECTO REGRESA
    printf("\tUSUARIO INCORRECTO\n");
    if(pass != 0){ //SI EL VALOR INGRESADO DE CONTRASEÑA NO ES CORRECTO REGRESA
      printf("\tCONTRASEÑA INCORRECTA\n");
      return;
    }
    return;
  }
  else{
    if(user == 0){  //SI EL VALOR DE USUARIO ES CORRECTO...
      if(pass == 0){  //Y LA CONTRASEÑA ES CORRECTA...
	nuevo_admin();  //SE CREA UN NUEVO ADMINISTRADOR
      }
    }
  }
  return;  //REGRESA AL MENU PRINCIPAL
}
/**
* Esta funcion asinga los valores de usuario y contraseña de aministrador
* nuevos dados por el controlador del porgrama en un archivo binario, tambien,
* revisa dicho archivo generado para comprobar los datos ingresados y asi poder
* usuarlos en el inicio de secion de administrador
* @author/ Luis Vizcaino.
* @param chrData/ NOTHING
* @return/ NOTHING
*/
void nuevo_admin(void){
  FILE *f1;
  USUARIO datos;
  USUARIO *ptr;
  long int registros=0;
  int i=0;
  if((f1=fopen("ADMINISTRADORES", "w+b"))==NULL){  //CREA O SOBRESCRIBE EL ARHIVO BINARIO PARA EL ADMINISTRADOR, TAMBIEN, VERIFICA SU EXISTENCIA.
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA.
  }
  system("clear");
  logo_beaton();  //SECCION PARA LA COLOCACION DE DATOS PARA EL ADMINISTRADOR
  printf("\tBIENVENIDO BRAIN MASTER.\n\tINGRESE LOS DATOS DEL NUEVO ADMINISTRADOR\n");
  printf("\t====================================\n");
  printf("\tNOMBRE : ");
  gets(datos.nombre);  //OBTIENE EL NUEVO NOMBRE DE ADMINISTRADOR
  printf("\tCONTRASEÑA : ");
  gets(datos.contrasenia);  //OBTIENE LA NUEVA CONTRASEÑA DE ADMINISTRADOR
  printf("\t====================================\n");
  fwrite(&datos,sizeof(USUARIO),1,f1);  //ESCRIBE ESTOS VALORES EN EL ARCHIVO
  fclose(f1);  //CIERRA EL ARCHIVO
  if((f1=fopen("ADMINISTRADORES", "r+b"))==NULL){  //ABRE EL ARCHIVO RECIEN CREADO PARA VERFICAR LOS DATOS COLOCADOS
    printf("\tFALLA DE ARCHIVO, ARCHIVO NO EXISTE\n");
    exit(1);  //SI EL ARCHIVO NO EXISTE, SALE DEL PROGRAMA
  }
  printf("\tVERIFICACION DE LOS TERMINOS INGRESADOS\n");
  fseek(f1,0,SEEK_END);  //DETERMINA EL INICIO DE BUSQUEDA 
  registros = ftell(f1)/sizeof(struct USUARIO);  //DETERMINA EL NUMERO DE REGISTROS
  ptr = (struct USUARIO*)malloc(sizeof(struct USUARIO)*registros);  //DETERMINA EL TAMAÑO PARA LA ESTRUCTURA DINAMICA DONDE SE REVISARAN LOS DATOS
  rewind(f1);
  fread(ptr,sizeof(struct USUARIO),registros,f1);  //LEE EL ARCHIVO
  fclose(f1); //CIERRA EL ARCHIVO
  for(i=0;i<registros;i++){  //IMPRIME LOS DATOS DEL ARCHIVO DE ADMINISTRADORES
    printf("\tNOMBRE : ");
    printf("%s\n",ptr[i].nombre);
    printf("\tCONTRASEÑA : ");
    printf("%s\n",ptr[i].contrasenia);
  }
  printf("\t====================================\n");
  regresa();
  return;  //REGRESA AL MENU PRINCIPAL
}
