#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char *Buff; //variable auxiliar para nombre a ingresar
char **Nombre; //vector de nombres
int cantNom=0, j;
printf("Indique la cantidad de nombres de personas que va a ingresar: ");
scanf("%d", &cantNom);
Nombre=(char **)malloc(cantNom*sizeof(char *));
Buff= (char *) malloc(50*sizeof(char));//reserva para nombre de x caracteres
printf("Ingrese los nombres de las personas:\n");
for (int i = 0; i < cantNom; i++)
{
    printf("Persona %d: ", i+1);
    fflush(stdin);
    gets(Buff);
    Nombre[i]=(char *)malloc((strlen(Buff)+1)*sizeof(char));//reserva para nombre de n longitud
    strcpy(Nombre[i], Buff);
}
free(Buff);    
printf("\nLos %d nombres ingresados son:\n", cantNom);
for (int i = 0; i < cantNom; i++)
{    
    printf("\nPersona %d: ", i+1);
    puts(Nombre[i]);
    free(Nombre[i]);
}
free(Nombre);
return 0;
}