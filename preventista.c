#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//lista de productos
char *TiposProductos[]= {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas", "Alfajores"};
//estructura para los datos de los productos
struct {
    int ProductoID; //Numerado en ciclo iterativo
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
    int Cantidad; // entre 1 y 10   
    
}typedef producto;
//estructura para los datos de los cliente
struct CLIENTE{
    int ClienteID; // Numerado en el ciclo iterativo
    char NombreCliente[20]; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir"
}typedef cliente;
//carga de clientes y productos
void cargaClientes(cliente *listaClientes, int nClient);
producto cargaProductos(producto *listaProductos, int nProductos);
float costoTotalProducto(producto *xProducto);
void mostrarProductoDunCliente(cliente *listaClientes);
void mostrarProductoDClientes(cliente *listaClientes, int nClient);

int main(){
    int nClientes;
    cliente *listaClientes;
    char nom[20];
    printf("\nIngrese su nombre: ");
    gets(nom);
    printf("\nIngrese la cantidad de clientes que visitara: ");
    scanf("%d", &nClientes);
    listaClientes=(cliente *)malloc(nClientes*sizeof(cliente));
    cargaClientes(listaClientes, nClientes);
    mostrarProductoDClientes(listaClientes, nClientes);
    free(listaClientes);
    return 0;
}

void cargaClientes(cliente *listaClientes, int nClient)
{
    producto *listaProductos;
    int i;
    srand(time(NULL));
    printf("\nIngrese los datos de los clientes"); 
    for (i = 0; i < nClient; i++)
    {
        printf("\n*************************************");
        printf("\nCliente %d", i+1);
        listaClientes[i].ClienteID=i+1;
        printf("\nIngrese el nombre:.............. ");
        fflush(stdin);
        gets(listaClientes[i].NombreCliente);
        listaClientes[i].CantidadProductosAPedir=rand()%5+1;
        printf("\nCantidad de productos a pedir:.. %d", listaClientes[i].CantidadProductosAPedir);
        listaProductos=(producto *)malloc(listaClientes[i].CantidadProductosAPedir*sizeof(producto));
        listaClientes[i].Productos=listaProductos;
        cargaProductos(listaClientes[i].Productos, listaClientes[i].CantidadProductosAPedir);
    }
    //free(listaProductos);
}
producto cargaProductos(producto *listaProductos, int nProductos)
{
    srand(time(NULL));
    printf("\nIngrese datos de los productos pedidos: ");
    for (int i = 0; i < nProductos; i++)
    {
        printf("\n________________________________________");
        printf("\nProductoID............... %d", i+1);
        listaProductos[i].ProductoID=i+1;
        listaProductos[i].TipoProducto=TiposProductos[i];
        printf("\nNombre:.................. %s", listaProductos[i].TipoProducto);
        listaProductos[i].PrecioUnitario=rand()%91+10;
        printf("\nPrecio por unidad:....... %.2f pesos", listaProductos[i].PrecioUnitario);
        listaProductos[i].Cantidad=rand()%10+1;
        printf("\nCantidad:................ %d", listaProductos[i].Cantidad);
    }
}
float costoTotalProducto(producto *xProducto)
{
    return xProducto->Cantidad*xProducto->PrecioUnitario;
}

void mostrarProductoDunCliente(cliente *listaClientes)
{
    float costoFinal=0;
    
    printf("\n************Cliente %d************", listaClientes->ClienteID);
    printf("\nNombre:........................... ");
    puts(listaClientes->NombreCliente);
    printf("\nCantidad de productos pedidos:.... %d", listaClientes->CantidadProductosAPedir);
    for (size_t i = 0; i < listaClientes->CantidadProductosAPedir; i++)
    {
        printf("\n___________________________________________");
        fflush(stdout);
        printf("\nProductoID.................. %d", listaClientes->Productos[i].ProductoID);
        printf("\nNombre:..................... %s", listaClientes->Productos->TipoProducto);
        //puts(listaClientes->Productos->TipoProducto);
        printf("\nPrecio por unidad:.......... %.2f pesos", listaClientes->Productos[i].PrecioUnitario);
        printf("\nCantidad:................... %d", listaClientes->Productos[i].Cantidad);
        costoFinal=costoFinal+costoTotalProducto(&listaClientes->Productos[i]);
        printf("\nTotal del producto:......... %.2f pesos", costoTotalProducto(&listaClientes->Productos[i]));
    }
    printf("\n=================================================");
    printf("\nTotal final:........................ %.2f pesos\n", costoFinal);   
}
void mostrarProductoDClientes(cliente *listaClientes, int nClient)
{
    printf("\n\n_________DATOS DEL PEDIDO DEL CLIENTE__________\n");
    for (int i = 0; i < nClient; i++)
    {
        mostrarProductoDunCliente(listaClientes);
        listaClientes++;
    }
    //free(listaClientes->Productos); 
}