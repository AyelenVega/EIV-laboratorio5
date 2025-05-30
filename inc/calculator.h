/*********************************************************************************************************************
Copyright (c) 2025, María Ayelén Vega Caro <ayelenvegacaro@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/** @file calculator.h
 ** @brief Declaraciones del modulo calculadora
 **/

/* === Headers files inclusions ==================================================================================== */
#include <stdbool.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */
//! Estructura que representa una calculadora
typedef struct calculator_s * calculator_t;

//! Puntero a funcion que define una operación entre dos enteros
typedef int (*operation_func_t)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */
/**
 * @brief Crea la calculadora
 *
 * @return calculator_t Referencia a la calculadora creada
 */
calculator_t CalculatorCreate(void);

/**
 * @brief Agrega una nueva operación a la calculadora
 *
 * @param calculator Referencia a la calculadora
 * @param function Función que implementa la operación a agregar
 * @param operator Simbolo que representa el operador matemático
 * @return true Si se pudo agregar la operación
 * @return false Si no se pudo agregar la operación
 */
bool CalculatorAddOperation(calculator_t calculator, char operator, operation_func_t function);

/**
 * @brief Resuleve la operación matematica que se pasa como cadena y devuelve el resultado
 *
 * @param calculator Referencia a la calculadora
 * @param expression Cadena de caracteres que representa la operación matemática
 * @return int Valor calculado
 */
int CalculatorCalculate(calculator_t calculator, const char expression[]);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULATOR_H_ */
