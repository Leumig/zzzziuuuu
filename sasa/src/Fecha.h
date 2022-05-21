/*
 * Fecha.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

#endif // FECHA_H_INCLUDED

/// @brief Valido que una fecha sea posible. No toma en cuenta los años bisiestos.
///
/// @param unaFecha recibo la ddm de la fecha que quiero validar
/// @return devuelvo 1 cuando finalice la función y 0 si le llegó algún dato inválido
int validarFecha(eFecha* unaFecha);

/// @brief Compara dos fechas, más precisamente si la primer fecha es más actual que la segunda.
///
/// @param fecha1 recibe la ddm de la estructura eFecha, con el valor de la primer fecha
/// @param fecha2 recibe la ddm de la estructura eFecha, con el valor de la segunda fecha
/// @return devuelve 1 si la primer fecha es mayor/actual, al contrario devuelve -1, y si son iguales, 0
int compararFechas(eFecha* fecha1, eFecha* fecha2);
