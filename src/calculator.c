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

/** @file calculator.c
 ** @brief Codigo fuente que implementa el modulo calculadora
 **/

/* === Headers files inclusions ==================================================================================== */

#include "calculator.h"
#include <stdlib.h>
#include <string.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */
//! Estructura que representa la operación
typedef struct operation_s * operation_t;

struct operation_s {
    char operator;
    operation_func_t function;
    operation_t next;
};

struct calculator_s {
    operation_t operations;
};

/* === Private function declarations =============================================================================== */
/**
 * @brief Busca una operación que se haya agregado a la calculadora
 *
 * @param calculator Referencia a la calculadora
 * @param operator Símbolo que representa al operador matemático
 * @return operation_t Referencia a la operación que se buscaba
 */
operation_t findOperation(calculator_t calculator, char operator);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */
operation_t findOperation(calculator_t calculator, char operator) {
    operation_t current = calculator->operations;
    while (current != NULL) {
        if (current->operator == operator) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/* === Public function implementation ============================================================================== */
calculator_t CalculatorCreate(void) {
    calculator_t calculator = malloc(sizeof(struct calculator_s));
    if (calculator) {
        calculator->operations = NULL;
    }
    return calculator;
}
bool CalculatorAddOperation(calculator_t calculator, char operator, operation_func_t function) {
    if (!calculator || !function || findOperation(calculator, operator)) {
        return false;
    }
    operation_t operation = malloc(sizeof(struct operation_s));
    if (operation) {
        operation->operator = operator;
        operation->function = function;
        operation->next = calculator->operations;
        calculator->operations = operation;
        return true;
    }
    return false;
}
int CalculatorCalculate(calculator_t calculator, const char expression[]) {
    int a = 0;
    int b = 0;
    char operator = 0;
    int result = 0;
    if (!calculator || !expression) {
        return 0;
    }
    for (size_t i = 0; i < strlen(expression); i++) {
        if ((expression[i] < '0') || (expression[i] > '9')) {
            operator = expression[i];
            a = atoi(expression);
            b = atoi(expression + i + 1);
            break;
        }
    }
    operation_t operation = findOperation(calculator, operator);
    if (operation) {
        result = operation->function(a, b);
    }
    return result;
}

/* === End of documentation ======================================================================================== */
