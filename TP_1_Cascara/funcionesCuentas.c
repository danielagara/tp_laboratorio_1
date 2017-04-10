#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief FUNCION SUMAR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int sumar(int num1, int num2)
{
    int resultado;
    resultado=num1 + num2;
    return resultado;
}

/** \brief FUNCION RESTAR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int restar(int num1, int num2)
{
    int resultado;
    resultado=num1 - num2;
    return resultado;
}

/** \brief FUNCION DIVIDIR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int dividir(int num1, int num2)
{
    int resultado;
	char error;

	while(num2!=0)
	{
		resultado=num1 / num2;
		return resultado;
		break;
	}
	if(num2==0)
	{
		error=1;
		return error;
	}
}

/** \brief FUNCION MULTIPLICAR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int multiplicar(int num1, int num2)
{
    int resultado;
    resultado=num1 * num2;
    return resultado;
}

/** \brief FUNCION FACTORIALES
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int factoriales(int num1, int num2)
{
    int resultado, factorial=1, antecedentes;
    resultado=num1 * num2;
	for(antecedentes=1;antecedentes<=resultado;antecedentes++)
    {
        factorial=factorial*antecedentes;
    }
    return factorial;
}
