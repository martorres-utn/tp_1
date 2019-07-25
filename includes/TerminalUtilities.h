//
// Created by Marcos on 7/24/2019.
//
#include <iostream>
#include <limits>
#include <iomanip>

#ifndef TP_1_TERMINALUTILITIES_H
#define TP_1_TERMINALUTILITIES_H

namespace TerminalUtilities
{
    /*
     * getValue: obtiene un valor de la consola y lo deposita en target siempre que sea posible. Si ocurre algun error vuelve a solicitar el ingreso.
     * - target: variable donde se quiere depositar el valor que se quiere leer de la consola.
     * - inputMessage: descripcion del valor que se solicita al usuario.
     * - errorMessage: mensaje de error que se quiere mostrar al usuario en caso de falla.
     * */
    template<class T>
    void getValue(T &target, std::string inputMessage, std::string errorMessage)
    {
        std::cout << inputMessage;
        while(!(std::cin >> target)){
            std::cout << errorMessage << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << inputMessage;
        }
        //borra el resto de la cadena en caso de que se haya excedido durante el ingreso, previene que la siguiente sentencia std::cin lea del excedente.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /*
     * getValidValue: obtiene un valor de la consola y lo deposita en target siempre que sea posible. Además ejecuta una función de validación adicional (validate) enviada como parámetro. Si ocurre algun error vuelve a solicitar el ingreso.
     * - target: variable donde se quiere depositar el valor que se quiere leer de la consola.
     * - inputMessage: descripcion del valor que se solicita al usuario.
     * - validation: puntero a función bool que recibe como parámetro el tipo T de target.
     * - errorMessage: mensaje de error que se quiere mostrar al usuario en caso de falla.
     * */
    template<class T>
    void getValidValue(T &target, std::string inputMessage, bool (*validation)(T & argument), std::string errorMessage)
    {
        std::cout << inputMessage;
        while(!(std::cin >> target) || !validation(target)){
            std::cout << errorMessage << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << inputMessage;
        }
        //borra el resto de la cadena en caso de que se haya excedido durante el ingreso, previene que la siguiente sentencia std::cin lea del excedente.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /*
     * getTrimmedValue: obtiene un valor de la consola especificando una longitud máxima del string que lo representa, si se excede la longitud la lectura recorta la cadena y la deposita en target siempre que sea posible. Si ocurre algun error vuelve a solicitar el ingreso.
     * - target: variable donde se quiere depositar el valor que se quiere leer de la consola.
     * - inputMessage: descripcion del valor que se solicita al usuario.
     * - maxSize: longitud máxima de la cadena que se espera.
     * - errorMessage: mensaje de error que se quiere mostrar al usuario en caso de falla.
     * */
    template<class T>
    void getTrimmedValue(T &target, std::string inputMessage, int maxSize, bool (*validation)(T & argument), std::string errorMessage)
    {
        std::cout << inputMessage;
        while(!(std::cin >> std::setw(maxSize) >> target) || !validation(target)){
            std::cout << errorMessage << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << inputMessage;
        }
        //borra el resto de la cadena en caso de que se haya excedido durante el ingreso, previene que la siguiente sentencia std::cin lea del excedente.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

#endif //TP_1_TERMINALUTILITIES_H
