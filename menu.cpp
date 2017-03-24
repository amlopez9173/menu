#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct Nodo{
    int num;
    Nodo *Siguiente;
};

void init_pila();
void vacia_pila_bool(Nodo *&, int);
void ins_pila(Nodo *&, int);
void retirar_pila(Nodo *&, int &);

Nodo *pila;

int main()
{
    int n,opc,menu=1;

    do{
        printf("MENU\n");

        printf("1. Inicializar Pila\n");
        printf("2. Verificar estado de Pila\n");
        printf("3. Insertar elementos de Pila\n");
        printf("4. Retirar elementos de Pila\n");
        printf("0. Salir\n");
        printf("Opcion: ");scanf("%d",&opc);


        switch(opc)
        {
            case 0:
                menu=0;
                break;
            case 1:
                init_pila();
                break;
            case 2:
                vacia_pila_bool(pila,n);
                break;
            case 3:
                printf("Presiones (0) cuando termine el ingreso de numeros");
                do{
                    printf("\nIngrese un numero: ");
                    scanf("%d",&n);
                    ins_pila(pila, n);
                }while(n!=0);
                break;

            case 4:
                while(pila!=NULL)
                    {
                        retirar_pila(pila,n);
                        if(pila!=NULL)
                        {
                            printf("%d -> ",n);
                        }else
                        {
                            printf("%d -> FIN",n);
                        }
                    }
                break;
        }
        getch();
    }while(menu !=0);

return 0;
}

void init_pila()
{
    Nodo *pila =NULL;
    printf("Inicializacion realizada correctamente\n");
}

void vacia_pila_bool(Nodo *&pila, int n)
{
    bool validador;

    if(pila==NULL)
        {
            validador=true;
        }else
        {
            validador=false;
        }

    if(validador==true)
        {
            printf("\nLa Pila esta Vacia.\n");
        }else
        {
            printf("\nLa Pila no esta Vacia.\n");
        }
}

void ins_pila(Nodo *&pila, int n)
{

    Nodo *nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->num=n;
    nuevo_nodo->Siguiente=pila;
    pila= nuevo_nodo;
}

void retirar_pila(Nodo *&pila, int &n)
{
    Nodo *aux=pila;
    n=aux->num;
    pila=aux->Siguiente;
    free(aux);
}


