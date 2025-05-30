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

/** @file main.c
 ** @brief
 **/

/* === Headers files inclusions ==================================================================================== */
#include "calculator.h"
#include <stdio.h>

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function implementation ============================================================================== */

int OperationAdd(int a, int b) {
    return a + b;
}
int OperationSubstract(int a, int b) {
    return a - b;
}
int OperationMultiply(int a, int b) {
    return a * b;
}

int OperationDivide(int a, int b) {
    return a / b;
}

int main(void) {
    static char addition[] = "20+35";
    static char subtraction[] = "2-8";
    static char multiplication[] = "14*333";
    static char division[] = "6/3";
    bool success;
    int result;

    calculator_t calculator = CalculatorCreate();

    success = CalculatorAddOperation(calculator, '+', OperationAdd);
    if (success) {
        printf("\nSe agrego la operacion SUMA");
    } else {
        printf("\nNo se pudo agregar la operacion SUMA");
    }
    success = CalculatorAddOperation(calculator, '-', OperationSubstract);
    if (success) {
        printf("\nSe agrego la operacion RESTA");
    } else {
        printf("\nNo se pudo agregar la operacion RESTA");
    }
    success = CalculatorAddOperation(calculator, '*', OperationMultiply);
    if (success) {
        printf("\nSe agrego la operacion MULTIPLICACION");
    } else {
        printf("\nNo se pudo agregar la operacion MULTIPLICACION");
    }
    success = CalculatorAddOperation(calculator, '/', OperationDivide);
    if (success) {
        printf("\nSe agrego la operacion DIVISION");
    } else {
        printf("\nNo se pudo agregar la operacion DIVISION");
    }

    result = CalculatorCalculate(calculator, addition);
    printf("\nEl resultado de la suma \"%s\" es %i\n", addition, result);
    result = CalculatorCalculate(calculator, subtraction);
    printf("El resultado de la resta \"%s\" es %i\n", subtraction, result);
    result = CalculatorCalculate(calculator, multiplication);
    printf("El resultado de la multiplicacion \"%s\" es %i\n", multiplication, result);
    result = CalculatorCalculate(calculator, division);
    printf("El resultado de la division \"%s\" es %i\n", division, result);

    return 0;
}

/* === End of documentation ======================================================================================== */
