#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 122
#include <locale.h>

int ConfiguraIdioma(){
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();

	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";
		
}
int BorraPantalla(){
	system("cls");
 }

 int Centrar(char *cadena){
	int i;
	int longitud = strlen(cadena);
	int inicio = 40 - (longitud / 2);

	for(i=0;i<inicio; i++)
	{
		printf("%c",' ');
	}
	printf("%s",cadena);

 }

 int Alineado(char *cadena, int cantidad, int conRetorno){
	int i;

	for(i=1;i<=cantidad;i++)
	{
		printf("\t");
	}

	printf("%s",cadena);

	if(conRetorno)
	{
		printf("\n");
	}
 }

 int Titulo(char *cadena){
	printf("\n");
	Centrar("----------------------------------------");
	printf("\n");
	Centrar(cadena);
	printf("\n");
	Centrar("----------------------------------------");
	printf("\n");
 }

 int pausa(){
	Centrar("\n\t\tOprima una tecla para continuar...");
	fflush(stdin);
	getch();
 }
void descifrado(char cadena[X],int n){
    int i=0,aux=0;
    while(cadena[i]!='\0'){
      aux=cadena[i];
     	if(aux+n>122){
         	aux=((aux+n)-122)+96;          
      	}else{
          aux=aux+n;
      } 
      if(cadena[i]!=' ')//espacios
	  {
         cadena[i]=aux;             
      }        
        i++;
    }
    printf("\nMensaje descifrado: \n%s\n",cadena);
}
void cifrado(char cadena[X],int n){
    int i=0, aux=0;
    
    while(cadena[i]!='\0'){
    	aux=cadena[i];
    
      	if(aux-n<97) {
        aux=122-(96-(aux-n));          
      }
      else{
         	aux=aux-n;
      } 
      if(cadena[i]!=' '){
         cadena[i]=aux;             
      } 
        
        i++;
    }
    printf("\nLa frase encriptado es:\n%s\n",cadena);
}

int main(){
	ConfiguraIdioma();
    int x=3,opcion=0,s=0;
    char cadena[X];

    Titulo("Seguridad Informática");
    Titulo("Cifrado Cesar");

    printf("\n");
    	Titulo("Menú ");
		Alineado("Ingresa un 1 para  cifrar un mensaje",3,1);
		Alineado("Ingresa un 2 para  descifrar el mensaje",3,1);
		Alineado("Ingresa un 0 para  salir",3,1);
		scanf("%d",&opcion);
		while(getchar()!='\n');
		printf("\n");
		if(opcion==1){
			printf("Ingresa el mensaje:  ");
		    scanf("%128[^\n]", cadena);
		    while(getchar()!='\n');
		    cifrado(cadena, x);
		    getchar();
		    pausa();
		    Alineado("\nMensaje cifrado",3,1);
		    Alineado("Para descifrar este mensaje oprime 3 , para salir oprime 0",3,1);
		    scanf("%d",&s);
		    
		    if(s==3){
		    	while(getchar()!='\n');
		    	descifrado(cadena, x);
	    		getchar();
	    		pausa();
			}else{
				BorraPantalla();
				pausa();
			}
	  }else if(opcion==2){
	  		while(getchar()!='\n');
	  		printf("Ingresa el mensaje:  ");
	  		scanf("%128[^\n]", cadena);
		    while(getchar()!='\n');
		    descifrado(cadena, x);
	    	getchar();
	  }
    return 0;
}
