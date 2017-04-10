#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
	int num1, num2, resultado, factorial;
	int resultadoSumar, resultadoRestar, resultadoDividir, resultadoMultiplicar, resultadoFactorial;
	char bandera1='n', bandera2='n';

    while(seguir=='s')
    {
        printf("INGRESE UNA OPCION PARA COMENZAR\n");
        printf("1- Ingresar 1er operando (A=x)\n"); //H
        printf("2- Ingresar 2do operando (B=y)\n"); //H
        printf("3- Calcular la suma (A+B)\n"); //H FUNCION
        printf("4- Calcular la resta (A-B)\n"); //H FUNCION
        printf("5- Calcular la division (A/B)\n");//H FUNCION
        printf("6- Calcular la multiplicacion (A*B)\n"); //H FUNCION
        printf("7- Calcular el factorial (A!)\n");//H FUNCION
        printf("8- Calcular todas las operacione\n");//H
        printf("9- Salir\n"); //H

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
			printf("Ingrese el primer numero ");
			scanf("%d", &num1);
			bandera1='s';
			break;

            case 2:
			printf("Ingrese el segundo numero ");
			scanf("%d", &num2);
			bandera2='s';
            break;

            case 3:
			if(bandera1=='s' && bandera2=='s')
			{
				resultado=sumar(num1, num2);
				printf("El resultado de la suma es:%d", resultado);
			}
            break;

            case 4:
			if(bandera1=='s' && bandera2=='s')
			{
				resultado=restar(num1, num2);
				printf("El resultado de la resta es:%d", resultado);
			}
            break;

            case 5:
			if(bandera1=='s' && bandera2=='s')
			{
				resultado=dividir(num1, num2);
				printf("El resultado de la division es:%d", resultado);
				if(resultado==0)
                {
                    printf("El segundo numero no puede ser 0");
                }
			}

            break;

            case 6:
			if(bandera1=='s' && bandera2=='s')
			{
				resultado=multiplicar(num1, num2);
				printf("El resultado de la multiplicacion es:%d", resultado);
			}
            break;

            case 7:
			if(bandera1=='s' && bandera2=='s')
			{
				factorial=factoriales(num1, num2);
				printf("El factorial del resultado es:%d", factorial);
			}
            break;

            case 8:
			if(bandera1=='s' && bandera2=='s')
			{
				resultadoSumar=sumar(num1, num2);
				printf("El resultado de la suma es:%d", resultadoSumar);

				resultadoRestar=restar(num1, num2);
				printf("\nEl resultado de la resta es:%d", resultadoRestar);

				resultadoDividir=dividir(num1, num2);
				printf("\nEl resultado de la division es:%d", resultadoDividir);

				resultadoMultiplicar=multiplicar(num1, num2);
				printf("\nEl resultado de la multiplicacion es:%d", resultadoMultiplicar);

				resultadoFactorial=factoriales(num1, num2);
				printf("\nEl factorial del resultado es:%d", resultadoFactorial);
			}
            break;

            case 9:
            seguir = 'n';
            break;
        }

	}
    return 0;
}
