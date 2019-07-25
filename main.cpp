#include <iostream>
#include <bits/stdc++.h>
#include "DataTypes.h"
#include "includes/TerminalUtilities.h"

int main() {
    //main menu options
    std::map<int, std::string> mapOptions = {
            {1, "Registrar Pokemons"},
            {2, "Consultar cantidad de Pokemons por TIPO"},
            {3, "Consultar promedio de NIVEL de Pokemons por cada TIPO"},
            {4, "Consultar cantidad de Pokemons con NIVEL mayor a 500"},
            {5, "Consultar cantidad de Pokemons con NIVEL menor a 500"},
            {6, "Consultar cantidad de Pokemons con NIVEL igual a 500"},
            {7, "Mostrar Pokemon mas poderoso por TIPO"},
            {8, "Mostrar el Pokemon más debil por TIPO"},
            {9, "Salir de la Pokedex"}
    };

    std::vector<PokemonType> pokemonVector;

    std::cout << "Bienvenido a la Pokedex!" << std::endl;

    //selectedOption: will contain user's selected option, this variable will be assigned from the console input.
    int selectedOption = 0;

    while(selectedOption != 9)
    {
        std::cout << "Selecciona una opcion." << std::endl;

        //print available options using mapOptions
        for(auto it = mapOptions.begin(); it != mapOptions.end(); ++it)
        {
            std::cout << "[" << (*it).first << "] - " << (*it).second << std::endl;
        }

        //solicita valor entero por terminal, la expresion sera evaluada por la regular expression del 3er parametro.
        TerminalUtilities::getValidValue<int>(selectedOption, "Ingresa tu opcion:>", "^\\d{1}$", "ERROR! (ingresa un numero entero entre 1 y 9)");

        switch(selectedOption)
        {
            case 1: //REGISTRAR POKEMONS
            {
                std::cout << "Ingresa Todos los Pokemons que quieras. Ingresa: TIPO, NIVEL, NOMBRE. Ingresa TIPO Q para terminar la lista de Pokemons y volver al menu..." << std::endl;
                int inputIndex = 0;
                PokemonType newPokemon;

                do
                {
                    //solicita valor char por terminal, la expresion sera evaluada por regular expresion para coincidir con: T, F, A, E, Q(termina el ingreso)
                    TerminalUtilities::getValidValue<char>(newPokemon.Type, "Ingresa TIPO (T para Tierra, F para Fuego, A para Agua, E para Electrico):>", "^(T|F|A|E|Q)$",  "ERROR! (ingresa un tipo valido: T,F,A,E)");

                    if(newPokemon.Type != 'Q')
                    {
                        //solicita valor int por terminal, la expresion sera evaluada por regular expression para coincidir con un numero entre 1 y 100.
                        TerminalUtilities::getValidValue<int>(newPokemon.Level, "Ingresa NIVEL (valor entero entre 1 y 100):>", "^[1-9][0-9]{1,2}$|^1000$", "ERROR! (ingresa un valor entero entre 1 y 1000)");

                        //solicita valor char[10] por terminal, la expresion sera evaluada por regular expression para coincidir con una combinacion de letras mayusculas y minusculas entre a y z sin considerar caracteres especiales (longitud entre 1 y 10)
                        TerminalUtilities::getValidValue<char[10]>(newPokemon.Name, "Ingresa NOMBRE (cadena de letras, 10 max):>", "^[a-zA-Z]{1,10}$", "ERROR! (ingresa una cadena de letras, 10 longitud max)");

                        pokemonVector.push_back(newPokemon);

                        inputIndex++;
                    }

                }while(newPokemon.Type != 'Q' && inputIndex < 100);

                //printing just for debug
                std::cout << "Pokemons ingresados:" << std::endl;
                for(auto it = pokemonVector.begin(); it != pokemonVector.end() ; ++it)
                {
                    std::cout << "> TIPO: " << (*it).Type << " , NIVEL: " << (*it).Level << " , NOMBRE: " << (*it).Name << std::endl;
                }

                break;
            }

            case 2: //CANTIDAD DE POKEMONS POR TIPO
            {
                break;
            }

            case 3:
            {
                break;
            }

            default:
            {
                break;
            }
        }
    }

    return 0;
}
