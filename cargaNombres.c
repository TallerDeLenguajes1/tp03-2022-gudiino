#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char *Buff; //variable auxiliar para nombre a ingresar
char *Nombre[5]; //vector de nombres
printf("Ingrese el nombre de 5 personas:\n");
for (int i = 0; i < 5; i++)
{
    
    Buff= (char *) malloc(50*sizeof(char));//reserva para nombre de x caracteres
    printf("Persona %d: ", i+1);
    gets(Buff);
    Nombre[i]=(char *)malloc((strlen(Buff)+1)*sizeof(char));//reserva para nombre de n longitud
    strcpy(Nombre[i],Buff);
    free(Buff);    
}
printf("\nLos 5 nombres ingresados son:\n");

for (int i = 0; i < 5; i++)
{    
    printf("\nPersona %d: ", i+1);
    puts(Nombre[i]);
}
return 0;
}