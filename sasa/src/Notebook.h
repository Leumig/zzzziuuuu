/*
 * Notebook.h
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

#include "Marca.h"
#include "Tipo.h"

typedef struct{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;
} eNotebook;

#endif /* NOTEBOOK_H_ */

/// @brief Muestra los datos de una Notebook en fila (ID, marca, tipo, y precio).
///
/// @param lista recibe el array de la estructura eNotebook
/// @param marcas recibe el array de la estructura eMarca
/// @param tamMar recibe el tama�o del array de la estructura eMarca
/// @param tipos recibe el array de la estructura eTipo
/// @param tamTip recibe el tama�o del array de la estructura eTipo
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int mostrarNotebook(eNotebook lista, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


/// @brief Muestra el listado de todas las Notebooks con isEmpty = 0 del sistema,
/// cada una con su campo.
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tamNot recibe el tama�o del array de la estructura eNotebook
/// @param marcas recibe el array de la estructura eMarca
/// @param tamMar recibe el tama�o del array de la estructura eMarca
/// @param tipos recibe el array de la estructura eTipo
/// @param tamTip recibe el tama�o del array de la estructura eTipo
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int listarNotebooks(eNotebook vec[], int tamNot, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


/// @brief Inicializa el array de Notebooks, colocando a todos
/// los 'isEmpty' en '1'.
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int inicializarNotebooks(eNotebook vec[], int tam);


/// @brief Va a buscar un lugar libre (isEmpty = 1) en el sistema, y al encontrarlo,
/// devuelve el �ndice correspondiente.
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param pIndex recibe la ddm de una variable en la cual va a ser cargado el indice correspondiente (o -1)
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int buscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);


/// @brief Primero va a buscar si hay un lugar disponible en el sistema,
/// y si hay, va a pedirle al usuario que ingrese cada dato de una nueva
/// Notebook para agregarla al listado.
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param pId recibe la ddm de una variable la cual va a tener el valor del id que viene del main
/// @param marcas recibe el array de la estructura eMarca
/// @param tamMar recibe el tama�o del array de la estructura eMarca
/// @param tipos recibe el array de la estructura eTipo
/// @param tamTip recibe el tama�o del array de la estructura eTipo
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int altaNotebook(eNotebook vec[], int tam, int* pId, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


/// @brief Busca por ID la marca que se solicite, y le da valor al �ndice correspondiente (o -1).
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param id recibe el id de la Notebook que debe buscar
/// @param pIndice recibe la ddm de una variable en la cual va a ser cargado el indice correspondiente (o -1)
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int buscarNotebook(eNotebook vec[], int tam, int id, int* pIndice);


/// @brief Le pide al usuario que elija por ID a la Notebook que quiere dar de baja,
/// si se encuentra esa Notebook y lo confirma, su isEmpty pasa a ser 1.
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param marcas recibe el array de la estructura eMarca
/// @param tamMar recibe el tama�o del array de la estructura eMarca
/// @param tipos recibe el array de la estructura eTipo
/// @param tamTip recibe el tama�o del array de la estructura eTipo
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int bajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


/// @brief Hago que el usuario seleccione por ID qu� Notebook de la lista quiere modificar,
/// y le muestro un men� en el cual debe seleccionar qu� campo de la Notebook quiere modificar.
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param marcas recibe el array de la estructura eMarca
/// @param tamMar recibe el tama�o del array de la estructura eMarca
/// @param tipos recibe el array de la estructura eTipo
/// @param tamTip recibe el tama�o del array de la estructura eTipo
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int modificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMar, eTipo tipos[], int tamTip);


/// @brief Muestra un men� de opciones de modificaci�n y le pide al usuario
/// que ingrese una opci�n.
///
/// @return devuelve el valor de la opcion ingresada
int menuModificarNotebook();


/// @brief Le cargo datos v�lidos de distintas Notebooks para ya tener
/// un par en el sistema y no tener que hacer un Alta.
///
/// @param vec recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param cant recibe un entero de la cantidad de hardcodeos que se har� (m�x 5)
/// @param pId recibe la ddm de una variable la cual va a tener el valor del id que viene del main
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int hardcodearNotebooks(eNotebook vec[], int tam, int cant, int* pId);


/// @brief Le pasa el valor de descripci�n de la estructura eNotebook a un array tambi�n
/// llamado descripci�n, para poder mostrarlo usando otra funci�n.
///
/// @param notebooks recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param id recibe la id para pasarsela a la funcion buscarNotebook
/// @param descripcion recibe un array en el cual va a ser cargada la descripci�n correspondiente
/// @return devuelve 1 si funciono correctamente, y sino devuelve 0
int cargarDescripcionNotebook(eNotebook notebooks[], int tam, int id, char descripcion[]);


/// @brief Valida si el ID de la Notebook ingresada existe o no en el sistema.
///
/// @param notebooks recibe el array de la estructura eNotebook
/// @param tam recibe el tama�o del array de la estructura eNotebook
/// @param id recibe la id para buscarla y verificar si existe o no
/// @return devuelve 1 si es valido, y sino devuelve 0
int validarNotebook(eNotebook notebooks[], int tam, int id);
