#include <iostream>
#include <bits/stdc++.h>
#include "DataTypes.h"

int main() {

    PokemonType myPokemon;
    myPokemon.Level = 1;
    myPokemon.Type = 'F';

    // like if you were assigning myPokemon.Name = "Juancho" because you can't assign string values directly to char array. You will have to copy them.
    strcpy(myPokemon.Name, "Juancho");

    int number1 = 3;
    int number2 = 4;
    int number4 = 5;
    int result = number1 + number2 + number4;
    std::cout << "Hello, World! - result:" << result << std::endl;
    std::cout << "pokemon.Level:" << myPokemon.Level << std::endl;
    std::cout << "pokemon.Type:" << myPokemon.Type << std::endl;
    std::cout << "pokemon.Name:" << myPokemon.Name << std::endl;
    return 0;
}