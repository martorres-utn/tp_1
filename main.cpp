#include <iostream>
#include <bits/stdc++.h>
#include "DataTypes.h"

template<class T>
void getValueFromTerminal(T &target, std::string inputMessage, std::string errorMessage)
{
    std::cout << inputMessage;
    while(!(std::cin >> target)){
        std::cout << errorMessage << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << inputMessage;
    }
}

template<class T>
void getValidValueFromTerminal(T &target, std::string inputMessage, bool (*validation)(T & argument), std::string errorMessage)
{
    std::cout << inputMessage;
    while(!(std::cin >> target) || !validation(target)){
        std::cout << errorMessage << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << inputMessage;
    }
}

int main() {
    //main menu options
    std::map<int, std::string> mapOptions = {
            {1, "Ingresar Pokemons"},
            {2, "Consultar Cantidad de Pokemons de cada tipo"},
            {3, "Salir del la Pokedex"}
    };

    std::vector<PokemonType> pokemonVector;

    std::cout << "Bienvenido a la Pokedex!" << std::endl;

    //selectedOption: will contain user's selected option, this variable will be assigned from the console input.
    int selectedOption = 0;

    while(selectedOption != 3)
    {
        std::cout << "Selecciona una opcion." << std::endl;

        //print available options using mapOptions
        for(auto it = mapOptions.begin(); it != mapOptions.end(); ++it)
        {
            std::cout << (*it).second << "[" << (*it).first << "]" << std::endl;
        }

        //read console option
        auto optionValidation = [](int &value){
            return (value >= 1 && value <= 3);
        };
        getValidValueFromTerminal<int>(selectedOption, "Ingresa tu opcion:", optionValidation ,  "ERROR! (ingresa un numero entero entre 1 y 3)");

        switch(selectedOption)
        {
            case 1:
            {
                std::cout << "Ingresa Todos los Pokemons que quieras. Ingresa: TIPO, NIVEL, NOMBRE. Ingresa TIPO Q para terminar la lista de Pokemons y volver al menu..." << std::endl;
                int inputIndex = 0;
                PokemonType newPokemon;

                do
                {
                    auto typeValidation = [](char &value){
                        //could be replaced for regex match?
                        return (value == 'T' || value == 'F' || value == 'A' || value == 'E' || value == 'Q');
                    };
                    getValidValueFromTerminal<char>(newPokemon.Type, "Ingresa TIPO (T para tierra, F para fuego, A para agua, E para electrico):", typeValidation , "ERROR! (ingresa un tipo valido: T,F,A,E)");

                    if(newPokemon.Type != 'Q')
                    {
                        auto levelValidation = [](int &value)
                        {
                            return (value >= 1 && value <=100);
                        };
                        getValidValueFromTerminal<int>(newPokemon.Level, "Ingresa NIVEL (valor entero entre 1 y 100):", levelValidation, "ERROR! (ingresa un valor entero entre 1 y 100)");

                        auto nameValidation = []( char (&value)[10])
                        {
                            //check using regex?
                            return true;
                        };
                        getValidValueFromTerminal<char[10]>(newPokemon.Name, "ingresa NOMBRE (valor alfanumerico , 10 max):", nameValidation, "ERROR! (ingresa un valor alfanumerico , 10 longitud max)");

                        pokemonVector.push_back(newPokemon);

                        inputIndex++;
                    }

                }while(newPokemon.Type != 'Q' && inputIndex < 100);

                //printing just for debug
                std::cout << "Pokemons ingresados:" << std::endl;
                for(auto it = pokemonVector.begin(); it != pokemonVector.end() ; ++it)
                {
                    std::cout << (*it).Type << "-" << (*it).Level << "-" << (*it).Name << std::endl;
                }

                break;
            }

            case 2:
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
