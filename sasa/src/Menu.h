/*
 * Menu.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef MENU_H_
#define MENU_H_

/// @brief Muestra un men� de opciones de modificaci�n y le pide al usuario
/// que ingrese una opci�n.
///
/// @return devuelve el valor de la opcion ingresada
int menu();


/// @brief Le pregunta al usuario si confiram la salida del men�, ingresando
/// 's' o 'n'.
///
/// @param p recibe la ddm de una variable a la cual se le va a cargar el valor 's' o 'n'
void confirmarSalidaMenu(char* p);

#endif /* MENU_H_ */
