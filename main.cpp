#include <iostream>
#include <bits/stdc++.h>
#include "DataTypes.h"
#include "includes/TerminalUtilities.h"

void registerNewPokemons(std::vector<PokemonType> & pokemonVector)
{
    std::cout << "Ingresa Todos los Pokemons que quieras.\n\tIngresa: TIPO, NIVEL, NOMBRE.\n\tIngresa TIPO Q para terminar la lista de Pokemons y volver al menu..." << std::endl;
    int inputIndex = pokemonVector.size();
    PokemonType newPokemon;

    do
    {

        //solicita valor char por terminal, la expresion sera evaluada por regular expresion para coincidir con: T, F, A, E, Q(termina el ingreso)
        TerminalUtilities::getValidValue<char>(newPokemon.Type, "Ingresa TIPO (T para Tierra, F para Fuego, A para Agua, E para Electrico, Q para terminar el ingreso):>", "^(T|F|A|E|Q)$",  "\tERROR! (ingresa un tipo valido: T,F,A,E)");

        if(newPokemon.Type != 'Q')
        {
            //solicita valor int por terminal, la expresion sera evaluada por regular expression para coincidir con un numero entre 1 y 1000.
            TerminalUtilities::getValidValue<int>(newPokemon.Level, "Ingresa NIVEL (valor entero entre 1 y 1000):>", "^([1-9][0-9]{0,2}$|^1000)$", "\tERROR! (ingresa un valor entero entre 1 y 1000)");

            //solicita valor char[10] por terminal, la expresion sera evaluada por regular expression para coincidir con una combinacion de letras mayusculas y minusculas entre a y z sin considerar caracteres especiales (longitud entre 1 y 10)
            TerminalUtilities::getValidValue<char[10]>(newPokemon.Name, "Ingresa NOMBRE (cadena de letras, 10 max):>", "^[a-zA-Z]{1,10}$", "\tERROR! (ingresa una cadena de letras, 10 longitud max)");

            pokemonVector.push_back(newPokemon);

            inputIndex++;

            std::cout << "----------------------[ #" << inputIndex << " Pokemon registrado ]--------------------------------" << std::endl;
        }

    }while(newPokemon.Type != 'Q');

    std::cout << "------------------------------------------------------" << std::endl;

    //printing just for debug
    std::cout << "Pokemons ingresados:" << std::endl;
    for(auto it = pokemonVector.begin(); it != pokemonVector.end() ; ++it)
    {
        std::cout << "\t - TIPO: " << (*it).Type << " , NIVEL: " << (*it).Level << " , NOMBRE: " << (*it).Name << std::endl;
    }
}

void showAmountOfPokemonsByType(std::vector<PokemonType> & pokemonVector)
{
    std::map<char, int> typeAmount = {
        {'T', 0},
        {'F', 0},
        {'A', 0},
        {'E', 0}
    };

    for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
    {
        PokemonType pokemon = (*it);
        typeAmount[pokemon.Type]++;
    }

    std::cout << "Cantidad de Pokemons por tipo" << std::endl;
    for(auto it = typeAmount.begin(); it != typeAmount.end(); ++it)
    {
        char type = (*it).first;
        int amount = (*it).second;
        std::cout << "\tTipo: " << type << " - Cantidad: " << amount << std::endl;

    }
}


//Es el punto 3 en proceso
/*
void ShowPromedioByType(std::vector<Pokemontype> & pokemonVector)
{
    std::cout << "Promedio de nivel de Pokemons por cada tipo:" << std::endl;
    for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
    {
        int t=0;
        int tl=0;
        int a=0;
        int al=0;
        int f=0;
        int fl=0;
        int e=0;
        int el=0;
        if(pokemonVector.Type=T){tl=tl+pokemonVector.Level;
            t++;}
        if(pokemonVector.Type=A){al=al+pokemonVector.Level;
            a++;}
        if(pokemonVector.type=F){fl=fl+pokemonVector.Level;
            f++;}
        if(pokemonVector.type=E){el=el+pokemonVector.Level;
            e++;}
        std::cout << "Para tierra el promedio es: " tl/t << std::endl;
        std::cout << "Para agua el promedio es: " al/a << std::endl;
        std::cout << "Para fuego el promedio es: " fl/f << std::endl;
        std::cout << "Para electricos el promedio es: " el/e << std::endl;

    }
}
*/




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
            std::cout << "\t[" << (*it).first << "] - " << (*it).second << std::endl;
        }

        //solicita valor entero por terminal, la expresion sera evaluada por la regular expression del 3er parametro.
        TerminalUtilities::getValidValue<int>(selectedOption, "Ingresa tu opcion:>", "^\\d{1}$", "\tERROR! (ingresa un numero entero entre 1 y 9)");

        switch(selectedOption)
        {
            case 1: //REGISTRAR POKEMONS
            {
                registerNewPokemons(pokemonVector);
                break;
            }

            case 2: //CANTIDAD DE POKEMONS POR TIPO
            {
                showAmountOfPokemonsByType(pokemonVector);
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
