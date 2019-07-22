#include <iostream>
#include <bits/stdc++.h>
#include "DataTypes.h"

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
        std::cout << "tu opcion:";
        std::cin >> selectedOption;

        switch(selectedOption)
        {
            case 1:
            {
                std::cout << "Ingresa Todos los Pokemons que quieras. Ingresa: TIPO, NIVEL, NOMBRE. Ingresa TIPO Q para terminar la lista de Pokemons y volver al menu..." << std::endl;
                int inputIndex = 0;
                PokemonType newPokemon;

                do
                {
                    std::cout << "ingresa TIPO (T para tierra, F para fuego, A para agua, E para electrico):" << std::endl;
                    std::cin >> newPokemon.Type;

                    if(newPokemon.Type != 'Q')
                    {
                        std::cout << "ingresa NIVEL (valor numerico):" << std::endl;
                        std::cin >> newPokemon.Level;

                        std::cout << "ingresa NOMBRE (valor alfanumerico , 10 max):" << std::endl;
                        std::cin >> newPokemon.Name;

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
