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
    	printf("Fecha inválida. Recuerde que debe separar día, mes y año (máx 2032) usando / / / \n");
		printf("Reingrese fecha dd/mm/aaaa: ");
		fflush(stdin);
		scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
	}

	switch(unaFecha->mes)
	{
	case 2:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 28))
		{
			printf("Día inválido. Febrero tiene 28 días \n");
			printf("Reingrese día: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 4:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Día inválido. Abril tiene 30 días \n");
			printf("Reingrese día: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 6:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Día inválido. Junio tiene 30 días \n");
			printf("Reingrese día: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 9:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Día inválido. Septiembre tiene 30 días \n");
			printf("Reingrese día: ");
			fflush(stdin);
			scanf("%d", &unaFecha->dia);
		}

	break;

	case 11:
		while(!(unaFecha->dia > 0 && unaFecha->dia <= 30))
		{
			printf("Día inválido. Noviembre tiene 30 días \n");
			printf("Reingrese día: ");
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

int compararFechas(eFecha* fecha1, eFecha* fecha2) //Se leería fecha1 > fecha2.  Devuelve 1 si es verdad -1 si no lo es.
{												   //Si ambas fechas son exactamente iguales, devuelvo 0.
	int todoOk = -1;

	if(fecha1 != NULL && fecha2 != NULL)
	{
		//Primero analizamos AÑO
		if(fecha1->anio > fecha2->anio)  //Si fecha1 es más grande
		{
			todoOk = 1;	  //Devuelvo 1
			return todoOk;
		}else  //Si fecha1 no es más grande...
		{
			if(fecha1->anio < fecha2->anio)  //Y fecha2 si lo es...
			{
				return todoOk;  //Devuelvo -1
			}else

			//Si eso no pasó, ahora analizamos MES
			{
				if(fecha1->mes > fecha2->mes)  //Si fecha1 es más grande...
				{
					todoOk = 1;  //Devuelvo 1
					return todoOk;
				}else  //Si fecha1 no es más grande...
				{
					if(fecha1->mes < fecha2->mes)  //Y fecha2 si lo es...
					{
						return todoOk;  //Devuelvo -1
					}else

					//Si eso no pasó, analizamos DÍA
					{
						if(fecha1->dia > fecha2->dia)  //Si fecha1 es más grande...
						{
							todoOk = 1;  //Devuelvo 1
							return todoOk;
						}else  //Si fecha1 no es más grande...
						{
							if(fecha1->dia < fecha2->dia)  //Y fecha2 si lo es...
							{
								return todoOk;  //Devuelvo -1
							}else

							//Si eso tampoco pasó, significa que fecha1 == fecha2
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













