/*
 ============================================================================
 Name        : 1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Menu.h"
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"

#define ASC 1
#define DESC 0

#define TAM 10
#define TAMM 4
#define TAMT 4
#define TAMS 4
#define TAMTR 5

int informarNotebooksMarca(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);
int informarNotebooksTipo(eNotebook vec[], int tam, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar);

int ordenarTrabajosPorFecha(eTrabajo vec[], int tam, int criterio);



int main() {
	setbuf(stdout, NULL);

	char salir = 'n';
	int proximaId = 10000;
	int idTrabajo = 7000;

	eNotebook lista[TAM];
	eTrabajo listaT[TAMTR];
	eMarca marcas[TAMM] ={
		{1000, "Compaq"},
		{1001, "Asus"},
		{1002, "Acer"},
		{1003, "HP"}
	};
	eTipo tipos[TAMT] ={
		{5000, "Gamer"},
		{5001, "Disenio"},
		{5002, "Ultrabook"},
		{5003, "Normalita"}
	};
	eServicio servicios[TAMS] ={
		{20000, "Bateria", 2250},
		{20001, "Display", 10300},
		{20002, "Mantenimiento", 4400},
		{20003, "Fuente", 5600}
	};

	inicializarNotebooks(lista, TAM);
	inicializarTrabajos(listaT, TAMTR);

	hardcodearNotebooks(lista, TAM, 5, &proximaId);

	/////////////////////////
	//eFecha fechas[TAMTR];
	/////////////////////////

	do
	{
		switch(menu())
		{

		case 1:
			altaNotebook(lista, TAM, &proximaId, marcas, TAMM, tipos, TAMT);
			break;

		case 2:
			modificarNotebook(lista, TAM, marcas, TAMM, tipos, TAMT);
			break;

		case 3:
			bajaNotebook(lista, TAM, marcas, TAMM, tipos, TAMT);
			break;

		case 4:
			listarNotebooks(lista, TAM, marcas, TAMM, tipos, TAMT);
			break;

		case 5:
			listarMarcas(marcas, TAMM);
			break;

		case 6:
			listarTipos(tipos, TAMT);
			break;

		 case 7:
			listarServicios(servicios, TAMS);
			break;

		 case 8:
			altaTrabajo(listaT, TAMTR, &idTrabajo, lista, TAM, marcas, TAMM, tipos, TAMT, servicios, TAMS);
			break;

		 case 9:
			listarTrabajos(listaT, TAMTR, lista, TAM, servicios, TAMS);
			break;

		 case 10:
			//Informe
			informarNotebooksMarca(lista, TAM, marcas, TAMM, tipos, TAMT);
			break;

		 case 11:
			//Informe
			informarNotebooksTipo(lista, TAM, tipos, TAMT, marcas, TAMM);

			break;

		 case 12:
			//Informe
			ordenarTrabajosPorFecha(listaT, TAMTR, ASC);
			listarTrabajos(listaT, TAMTR, lista, TAM, servicios, TAMS);
			break;

		 case 13:
			//Informe

			break;

		 case 14:
			//Informe

			break;

		 case 15:
			//Informe

			break;

	     case 16:
	        confirmarSalidaMenu(&salir);
	        break;

		default:
			printf("Opción inválida. Debe ingresar una opción del 1 al 10\n");
			break;
		}
		system("pause");

	}
	while(salir != 's');

	printf("Fin del programa");


	return 0;
}


int informarNotebooksMarca(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip)
{
	int todoOk = 0;
	int idMarca;
	int flag = 0;
	char descripcion[20];

	if(vec != NULL && tam > 0 && marcas != NULL && tamMar > 0 && tipos != NULL && tamTip > 0)
	{
		listarMarcas(marcas, tamMar);
		printf("Ingrese el ID de la marca que quiere ver su lista de Notebooks: ");
		scanf("%d", &idMarca);
		while(!validarMarca(marcas, tamMar, idMarca))
		{
			printf("Error, esa ID no corresponde a ninguna marca. Reingrese ID: ");
			fflush(stdin);
			scanf("%d", &idMarca);
		}

        printf("\n           ***   Lista de Notebooks de una marca   ***\n");
        printf("-------------------------------------------------------------------\n");
        printf("   ID             Modelo       Marca          Tipo        Precio\n");
        printf("-------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
        	if(!vec[i].isEmpty && vec[i].idMarca == idMarca)
        	{
                mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip);
                flag = 1;
        	}
        }

        if(flag == 0)
        {
        	cargarDescripcionMarca(marcas, tamMar, idMarca, descripcion);
        	printf("No hay Notebooks de esta marca\n");
        }

        todoOk = 1;
	}

	return todoOk;
}

int informarNotebooksTipo(eNotebook vec[], int tam, eTipo tipos[], int tamTip, eMarca marcas[], int tamMar)
{
	int todoOk = 0;
	int idTipo;
	int flag = 0;
	char descripcion[20];

	if(vec != NULL && tam > 0 && tipos != NULL && tamTip > 0 && marcas != NULL && tamMar > 0)
	{
		listarTipos(tipos, tamTip);
		printf("Ingrese el ID del tipo que quiere ver su lista de Notebooks: ");
		scanf("%d", &idTipo);
		while(!validarTipo(tipos, tamTip, idTipo))
		{
			printf("Error, esa ID no corresponde a ningún tipo. Reingrese ID: ");
			fflush(stdin);
			scanf("%d", &idTipo);
		}

        printf("\n           ***   Lista de Notebooks de un tipo   ***\n");
        printf("-------------------------------------------------------------------\n");
        printf("   ID             Modelo       Marca          Tipo        Precio\n");
        printf("-------------------------------------------------------------------\n");

        for(int i = 0; i < tam; i++)
        {
        	if(!vec[i].isEmpty && vec[i].idTipo == idTipo)
        	{
                mostrarNotebook(vec[i], marcas, tamMar, tipos, tamTip);
                flag = 1;
        	}
        }

        if(flag == 0)
        {
        	cargarDescripcionTipo(tipos, tamTip, idTipo, descripcion);
        	printf("No hay Notebooks de este tipo\n");
        }

        todoOk = 1;
	}

	return todoOk;
}


int ordenarTrabajosPorFecha(eTrabajo vec[], int tam, int criterio)
{
    int todoOk = 0;

    eTrabajo auxTrabajo;
    eFecha fecha1;
    eFecha fecha2;

    //Verificación de si llega o no la fecha correcta
    /*for(int i=0; i < tam -1; i++)
	{
		for(int j= i + 1; j < tam; j++)
		{
			fecha1 = vec[i].fPactada;
		    fecha2 = vec[j].fPactada;
			printf("%d%d%d\n", fecha1.anio, fecha1.mes, fecha1.dia);
			printf("%d%d%d", fecha2.anio, fecha2.mes, fecha2.dia);
		}
	}
    */

    if(vec != NULL && tam > 0 && criterio >= 0 && criterio <= 1)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
            	fecha1 = vec[i].fPactada;
            	fecha2 = vec[j].fPactada;
                if(((compararFechas(&fecha1, &fecha2) > 0) && criterio)
                || ((compararFechas(&fecha1, &fecha2) < 0) && !criterio))
                {
                	auxTrabajo = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxTrabajo;
                }

            }
        }
        todoOk = 1;
    }

    return todoOk;
}













