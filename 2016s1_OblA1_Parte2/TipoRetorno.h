#ifndef TIPO_RETORNO_H
#define TIPO_RETORNO_H

enum _retorno
{
	OK, ERROR, NO_IMPLEMENTADA
};
typedef enum _retorno TipoRetorno;


enum _errorRepetido {
	E_NOMBRE, E_NUMERO, E_ESTADO, BIEN
};
typedef enum _errorRepetido ErrorRepetido;


#endif