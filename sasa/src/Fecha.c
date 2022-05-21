/*
 * Fecha.c
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Notebook.h"
#include "Fecha.h"


int validarFecha(eFecha* unaFecha)
{
	int todoOk = 0;

	while(!(unaFecha != NULL && (unaFecha->anio >= 1992 && unaFecha->anio <= 2052) &&
	  (unaFecha->mes > 0 && unaFecha->mes <= 12) && (unaFecha->dia > 0 && unaFecha->dia <= 31)))
	{
    	printf("Fecha inv�lida. Recuerde que debe separar d�a, mes y a�o (m�x 2032) usando / / / \n");
		printf("Reingrese fecha dd/mm/aaaa: ");
		fflush(stdin);
		scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
	}

	switch(unaFecha->mes)
	{
	case 2:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 28))
		{
			printf("D�a inv�lido. Febrero tiene 28 d�as \n");
			printf("Reingrese d�a: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 4:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("D�a inv�lido. Abril tiene 30 d�as \n");
			printf("Reingrese d�a: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 6:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("D�a inv�lido. Junio tiene 30 d�as \n");
			printf("Reingrese d�a: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 9:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("D�a inv�lido. Septiembre tiene 30 d�as \n");
			printf("Reingrese d�a: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 11:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("D�a inv�lido. Noviembre tiene 30 d�as \n");
			printf("Reingrese d�a: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	default:
		todoOk = 1;
	}

	todoOk = 1;


	return todoOk;
}

int compararFechas(eFecha* fecha1, eFecha* fecha2) //Se leer�a fecha1 > fecha2.  Devuelve 1 si es verdad -1 si no lo es.
{												   //Si ambas fechas son exactamente iguales, devuelvo 0.
	int todoOk = -1;

	if(fecha1 != NULL && fecha2 != NULL)
	{
		//Primero analizamos A�O
		if(fecha1->anio > fecha2->anio)  //Si fecha1 es m�s grande
		{
			todoOk = 1;	  //Devuelvo 1
			return todoOk;
		}else  //Si fecha1 no es m�s grande...
		{
			if(fecha1->anio < fecha2->anio)  //Y fecha2 si lo es...
			{
				return todoOk;  //Devuelvo -1
			}else

			//Si eso no pas�, ahora analizamos MES
			{
				if(fecha1->mes > fecha2->mes)  //Si fecha1 es m�s grande...
				{
					todoOk = 1;  //Devuelvo 1
					return todoOk;
				}else  //Si fecha1 no es m�s grande...
				{
					if(fecha1->mes < fecha2->mes)  //Y fecha2 si lo es...
					{
						return todoOk;  //Devuelvo -1
					}else

					//Si eso no pas�, analizamos D�A
					{
						if(fecha1->dia > fecha2->dia)  //Si fecha1 es m�s grande...
						{
							todoOk = 1;  //Devuelvo 1
							return todoOk;
						}else  //Si fecha1 no es m�s grande...
						{
							if(fecha1->dia < fecha2->dia)  //Y fecha2 si lo es...
							{
								return todoOk;  //Devuelvo -1
							}else

							//Si eso tampoco pas�, significa que fecha1 == fecha2
							{
								todoOk = 0;
								return todoOk;
							}
						}
					}
				}
			}
		}
	}

	return todoOk;
}













