#include <stdio.h>
#include <stdlib.h>
#include "FILAS.h"
#include <time.h>
#include <string.h>
#include <windows.h>

int main()
{
    Nodo *top;
    Nodo *top2;
    Nodo *top3;
    Nodo *top4;
    top=NULL;
    top2=NULL;
    top3=NULL;
    top4=NULL;
    int al;

    for(int i=0; i<15; i++)
    {
        Sleep(1000);
        top=Push(top,"A",i+1);
        top2=Push(top2,"B",i+1);
        top3=Push(top3,"C",i+1);
        printf("\nIMPRESIONES PENDIENTES\n");
        verCola(top);
        verCola(top2);
        verCola(top3);
    }

    srand(time(NULL));

    while(top!=NULL||top2!=NULL||top3!=NULL)
    {
        Sleep(250);
        al=rand()%3;

        if(al==0&&top!=NULL)
        {
            top4=Push(top4,top->dato,top->edicion);
            top=Pop(top);
            printf("\nIMPRESIONES PENDIENTES\n");
            verCola(top);
            verCola(top2);
            verCola(top3);
        }
        if(al==1&&top2!=NULL)
        {
            top4=Push(top4,top2->dato,top2->edicion);
            top2=Pop(top2);
            printf("\nIMPRESIONES PENDIENTES\n");
            verCola(top);
            verCola(top2);
            verCola(top3);
        }
        if(al==2&&top3!=NULL)
        {
            top4=Push(top4,top3->dato,top3->edicion);
            top3=Pop(top3);
            printf("\nIMPRESIONES PENDIENTES\n");
            verCola(top);
            verCola(top2);
            verCola(top3);
        }
    }



    printf("\nIMPRESIONES REALIZADAS\n");
        verCola(top4);

    printf("\nIMPRESIONES PENDIENTES\n");
        verCola(top);
        verCola(top2);
        verCola(top3);

    return 0;
}
