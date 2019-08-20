#include <iostream>
#include <bits/stdc++.h>
#include "DataTypes.h"
#include "includes/TerminalUtilities.h"

//Punto 1 hecho por Marcos Torres
void registerNewPokemons(std::vector<PokemonType> & pokemonVector)
{
    std::cout << "Ingresa Todos los Pokemons que quieras.\n\tIngresa: TIPO, NIVEL, NOMBRE.\n\tIngresa TIPO Q para terminar la lista de Pokemons y volver al menu..." << std::endl;
    int inputIndex = pokemonVector.size();
    PokemonType newPokemon;

    do{

        //solicita valor char por terminal, la expresion sera evaluada por regular expresion para coincidir con: T, F, A, E, Q(termina el ingreso)
        TerminalUtilities::getValidValue<char>(newPokemon.Type, "Ingresa TIPO (T para Tierra, F para Fuego, A para Agua, E para Electrico, Q para terminar el ingreso):>", "^(T|F|A|E|Q)$",  "\tERROR! (ingresa un tipo valido: T,F,A,E)");

        if(newPokemon.Type != 'Q')
        {
            //solicita valor int por terminal, la expresion sera evaluada por regular expression para coincidir con un numero entre 1 y 1000.
            TerminalUtilities::getValidValue<int>(newPokemon.Level, "Ingresa NIVEL (valor entero entre 1 y 1000):>", "^([1-9][0-9]{0,2}$|^1000)$", "\tERROR! (ingresa un valor entero entre 1 y 1000)");

            //solicita valor char[10] por terminal, la expresion sera evaluada por regular expression para coincidir con una combinacion de letras mayusculas y minusculas entre a y z sin considerar caracteres especiales (longitud entre 1 y 10)
            TerminalUtilities::getValidValue<std::string>(newPokemon.Name, "Ingresa NOMBRE (cadena de letras, 10 max):>", "^[a-zA-Z]{1,10}$", "\tERROR! (ingresa una cadena de letras, 10 longitud max)");

            pokemonVector.push_back(newPokemon);

            inputIndex++;

            std::cout << "----------------------[ #" << inputIndex << " Pokemon registrado ]--------------------------------" << std::endl;
        }

    }while(newPokemon.Type != 'Q');

    if(pokemonVector.size() > 0)
    {
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "Pokemons ingresados:" << std::endl;
        for(auto it = pokemonVector.begin(); it != pokemonVector.end() ; ++it)
        {
            std::cout << "\t - TIPO: " << (*it).Type << " , NIVEL: " << (*it).Level << " , NOMBRE: " << (*it).Name << std::endl;
        }
    }
}

//Punto 2 hecho por Marcos Torres
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


//Punto 3 hecho por Pedro Lopez Slevin
// Creo variables contadores; tl es el sumador de niveles y t el de elementos
void showPromedioByType(std::vector<PokemonType> & pokemonVector)
{
    std::cout << "Promedio de nivel de Pokemons por cada tipo:" << std::endl;
        int t = 0;
        int tl = 0;
        int a = 0;
        int al = 0;
        int f = 0;
        int fl = 0;
        int e = 0;
        int el = 0;
//recorro el vector para darle valor al sumador y contador
    for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
    {
        if((*it).Type == 'T')
        {
            tl = tl + (*it).Level;
            t++;
        }
        if((*it).Type == 'A'){
            al = al + (*it).Level;
            a++;
        }
        if((*it).Type == 'F'){
            fl = fl + (*it).Level;
            f++;
        }
        if((*it).Type == 'E'){
            el = el + (*it).Level;
            e++;
        }
    }

    //el if es para que no haya indeterminaciones del tipo 0/0
    // en el caso de ser 0, se notifica al usuario que no posee pokemones de ese tipo.
    if(t > 0)
    {
        std::cout << "Para tierra el promedio es: " << (float)tl/(float)t << std::endl;
    }
    else
    {
        std::cout << "No posees pokemons de tierra para realizar un promedio, lo siento." << std::endl;
    }

    if(a > 0)
    {
        std::cout << "Para agua el promedio es: " << (float)al/(float)a << std::endl;
    }
    else
    {
        std::cout << "No posees pokemons de agua para realizar un promedio, lo siento." << std::endl;
    }

    if(f > 0)
    {
        std::cout << "Para fuego el promedio es: " << (float)fl/(float)f << std::endl;
    }
    else
    {
        std::cout << "No posees pokemons de fuego para realizar un promedio, lo siento." << std::endl;
    }

    if(e > 0)
    {
        std::cout << "Para electricos el promedio es: " << (float)el/(float)e << std::endl;
    }
    else
    {
        std::cout << "No posees pokemons electricos para realizar un promedio, lo siento." << std::endl;
    }
}

//punto 4 hecho por Pedro Lopez Slevin
//recorro el vector comparando el level contra el valor fijo 500, si es mayor imprimo el nombre y el type
void showBiggerThan (std::vector<PokemonType> & pokemonVector)
{
    int contador = 0;
    bool prim = true;


        for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
        {
            if((*it).Level > 500)
            {
                contador++;

                if(prim)
                {
                    std::cout << "Nombres de Pokemons con nivel superior a 500" << std::endl;
                    std::cout << "Nombre"  << " - " << " Tipo " << " - " << " Nivel " << std::endl;
                    prim=false;
                }
                std::cout << (*it).Name  << " " << (*it).Type << " " << (*it).Level << std::endl;
            }
        }
    if(contador == 0)
    {
        std::cout << "No posees pokemons con nivel superior a 500, lo siento." << std::endl;
    }
    else
    {
        std::cout << "Posees " << contador << " Pokemons con nivel superior a 500. Bien hecho!"<< std::endl;
    }
}


//punto 5 hecho por Florencia Leggio.
void showSmallerThan (std::vector<PokemonType> & pokemonVector)
{
    int contador = 0;
    bool prim = true;

    for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
    {
        if((*it).Level < 500)
        {
            contador++;

            if(prim)
            {
                std::cout << "Nombres de Pokemons con nivel inferior a 500" << std::endl;
                std::cout << "Nombre"  << " - " << " Tipo " << " - " << " Nivel " << std::endl;
                prim=false;
            }

            std::cout << (*it).Name  << " " << (*it).Type << " " << (*it).Level << std::endl;
        }
    }

    if(contador == 0)
    {
        std::cout << "No posees pokemons con nivel inferior a 500, lo siento." << std::endl;
    }
    else
    {
        std::cout << "Posees " << contador << " Pokemons con nivel inferior a 500. " << std::endl;
    }


}

// punto 6 hecho por Florencia Leggio.
void showEqualTo (std::vector<PokemonType> & pokemonVector)
{
    int contador = 0;
    bool prim = true;

    for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
    {
        if((*it).Level == 500)
        {
            contador++;

            if(prim)
            {
                std::cout << "Nombres de Pokemons con nivel igual a 500" << std::endl;
                std::cout << "Nombre"  << " - " << " Tipo " <<  std::endl;
                prim=false;
            }

            std::cout << (*it).Name  << " " << (*it).Type << std::endl;

        }
    }

    if(contador == 0)
    {
        std::cout << "No posees pokemons con nivel igual a 500, lo siento." << std::endl;
    }
    else
    {
        std::cout << "Cantidad de Pokemons con nivel igual a 500: " << contador << std::endl;
    }

}

//punto 7 hecho por Pedro Lopez Slevin
void showStrongestPokemon(std::vector<PokemonType> & pokemonVector){

    //variables de cual es mayor
    PokemonType tt; //= {'T', 0, ""};
    PokemonType at; //= {'A', 0, ""};
    PokemonType ft; //= {'F', 0, ""};
    PokemonType et; //= {'E', 0, ""};

    //bools de primera vez
    bool tierra = true;
    bool agua = true;
    bool fuego = true;
    bool elec = true;

    //recorro el vector comparando para ver cual es el mayor Level entre cada Type
    for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
    {
        //+ performance cambiando ifs por switchs para que el programa no haga comparaciones innecesarias :D
        switch((*it).Type)
        {
            case 'T':
            {
                //primera vez
                if (tierra)
                {
                    tt.Name = (*it).Name;
                    tt.Level = (*it).Level;
                    tt.Type = (*it).Type;

                    tierra = false;
                }

                //ahora si pregunto si es mayor que el primero que se ingreso
                if (tt.Level < (*it).Level)
                {
                    tt.Name = (*it).Name;
                    tt.Level = (*it).Level;
                    tt.Type = (*it).Type;
                }
                break;
            }

            case 'A':
            {
                //primera vez
                if (agua)
                {
                    at.Name = (*it).Name;
                    at.Level = (*it).Level;
                    at.Type = (*it).Type;

                    agua = false;
                }

                //ahora si pregunto si es mayor que el primero que se ingreso
                if (at.Level < (*it).Level)
                {
                    at.Name = (*it).Name;
                    at.Level = (*it).Level;
                    at.Type = (*it).Type;
                }
                break;
            }

            case 'F':
            {
                //primera vez
                if (fuego)
                {
                    ft.Name = (*it).Name;
                    ft.Level = (*it).Level;
                    ft.Type = (*it).Type;
                    fuego = false;
                }

                //ahora si pregunto si es mayor que el primero que se ingreso
                if (ft.Level < (*it).Level)
                {
                    ft.Name = (*it).Name;
                    ft.Level = (*it).Level;
                    ft.Type = (*it).Type;
                }
                break;
            }

            case 'E':
            {
                //primera vez
                if (elec)
                {
                    et.Name = (*it).Name;
                    et.Level = (*it).Level;
                    et.Type = (*it).Type;

                    elec = false;
                }

                //ahora si pregunto si es mayor que el primero que se ingreso
                if (et.Level < (*it).Level)
                {
                    et.Name = (*it).Name;
                    et.Level = (*it).Level;
                    et.Type = (*it).Type;
                }
                break;
            }
        }
    }

    //Imprimo los de mayor nivel segun su Type.
    //Tambien valido si realmente hay registrados de ese tipo preguntando por el bool de cada type
    std::cout << "Nombre" << " " << "Tipo" << " " << "Nivel" << std::endl;
    if(elec)
        {
            std::cout << "No posee Pokemones Electricos." << std::endl;
        }
    else
        {
            std::cout << et.Name << " - " << et.Type << " - " << et.Level << std::endl;
        }

    if(fuego)
    {
        std::cout << "No posee Pokemones de Fuego." << std::endl;
    }
    else
    {
        std::cout << ft.Name << " - " << ft.Type << " - " << ft.Level << std::endl;;
    }

    if(tierra)
    {
        std::cout << "No posee Pokemones de Tierra." << std::endl;
    }
    else
    {
        std::cout << tt.Name << " - " << tt.Type << " - " << tt.Level << std::endl;
    }

    if(agua)
    {
        std::cout << "No posee Pokemones de Agua." << std::endl;
    }
    else
    {
        std::cout << at.Name << " - " << at.Type << " - " << at.Level << std::endl;
    }

}


//punto 8 hecho por Lucas Fernandez Vincent.
void showWeakestPokemon(std::vector<PokemonType> & pokemonVector){

    //variables de cual es menor
    PokemonType tt; //= {'T', 0, ""};
    PokemonType at; //= {'A', 0, ""};
    PokemonType ft; //= {'F', 0, ""};
    PokemonType et; //= {'E', 0, ""};

    //bools de primera vez
    bool tierra = true;
    bool agua = true;
    bool fuego = true;
    bool elec = true;

    //recorro el vector comparando para ver cual es el menor Level entre cada Type
    for(auto it = pokemonVector.begin(); it != pokemonVector.end(); ++it)
    {
        switch((*it).Type)
        {
            case 'T':
            {
                //primera vez
                if (tierra) {
                    tt.Name = (*it).Name;
                    tt.Level = (*it).Level;
                    tt.Type = (*it).Type;

                    tierra = false;
                }
                //1 pregunto si es menor que el primero que se ingreso
                if (tt.Level > (*it).Level) {
                    tt.Name = (*it).Name;
                    tt.Level = (*it).Level;
                    tt.Type = (*it).Type;
                }
                break;
            }

            case 'A':
            {
                //primera vez
                if(agua)
                {
                    at.Name = (*it).Name;
                    at.Level = (*it).Level;
                    at.Type = (*it).Type;

                    agua = false;
                }
                //pregunto si es menor que el primero que se ingreso
                if(at.Level > (*it).Level)
                {
                    at.Name = (*it).Name;
                    at.Level = (*it).Level;
                    at.Type = (*it).Type;
                }
                break;
            }

            case 'F':
            {
                //primera vez
                if(fuego)
                {
                    ft.Name = (*it).Name;
                    ft.Level = (*it).Level ;
                    ft.Type = (*it).Type ;
                    fuego = false;
                }

                //pregunto si es menor que el primero que se ingreso
                if(ft.Level > (*it).Level)
                {
                    ft.Name = (*it).Name;
                    ft.Level = (*it).Level ;
                    ft.Type = (*it).Type ;
                }
                break;
            }

            case 'E':
            {
                //primera vez
                if(elec)
                {
                    et.Name = (*it).Name;
                    et.Level = (*it).Level ;
                    et.Type = (*it).Type;

                    elec = false;
                }

                //pregunto si es menor que el primero que se ingreso
                if(et.Level > (*it).Level)
                {
                    et.Name = (*it).Name;
                    et.Level = (*it).Level ;
                    et.Type = (*it).Type;
                }
                break;
            }
        }
    }

   /*
    * Si no hay ninguno de tal tipo arroja un template vacio Lucas
    * //Imprimo los de menor nivel segun su Type.
    std::cout << "Nombre" << " " << "Tipo" << " " << "Nivel" << std::endl;
    std::cout << et.Name << " - " << et.Type << " - " << et.Level << std::endl;
    std::cout << ft.Name << " - " << ft.Type << " - " << ft.Level << std::endl;
    std::cout << tt.Name << " - " << tt.Type << " - " << tt.Level << std::endl;
    std::cout << at.Name << " - " << at.Type << " - " << at.Level << std::endl;
*/
    //Imprimo los de menor nivel segun su Type.
    //Tambien valido si realmente hay registrados de ese tipo preguntando por el bool de cada type
    std::cout << "Nombre" << " " << "Tipo" << " " << "Nivel" << std::endl;
    if(elec)
    {
        std::cout << "No posee Pokemones Electricos." << std::endl;
    }
    else
    {
        std::cout << et.Name << " - " << et.Type << " - " << et.Level << std::endl;
    }

    if(fuego)
    {
        std::cout << "No posee Pokemones de Fuego." << std::endl;
    }
    else
    {
        std::cout << ft.Name << " - " << ft.Type << " - " << ft.Level << std::endl;;
    }

    if(tierra)
    {
        std::cout << "No posee Pokemones de Tierra." << std::endl;
    }
    else
    {
        std::cout << tt.Name << " - " << tt.Type << " - " << tt.Level << std::endl;
    }

    if(agua)
    {
        std::cout << "No posee Pokemones de Agua." << std::endl;
    }
    else
    {
        std::cout << at.Name << " - " << at.Type << " - " << at.Level << std::endl;
    }

}


int main() {
    //main menu options
    std::map<int, std::string> mapOptions = {
            {1, "Registrar Pokemones"},
            {2, "Consultar cantidad de Pokemones por TIPO"},
            {3, "Consultar promedio de NIVEL de Pokemons por cada TIPO"},
            {4, "Consultar cantidad de Pokemons con NIVEL mayor a 500"},
            {5, "Consultar cantidad de Pokemons con NIVEL menor a 500"},
            {6, "Consultar cantidad de Pokemons con NIVEL igual a 500"},
            {7, "Mostrar Pokemon mas poderoso por TIPO"},
            {8, "Mostrar el Pokemon más debil por TIPO"},
            {9, "Salir de la Pokedex"}
    };

    //en este vector se guardaran los pokemones en memoria con una estructura del tipo PokemonType, detallada en Datatypes.h
    std::vector<PokemonType> pokemonVector;

    std::cout << "Bienvenido a la Pokedex!" << std::endl;

    //selectedOption: will contain user's selected option, this variable will be assigned from the console input.
    int selectedOption = 0;

    while(selectedOption != 9)
    {
        std::cout << "[Menu principal] - seleccione una opcion." << std::endl;

        //print available options using mapOptions
        for(auto it = mapOptions.begin(); it != mapOptions.end(); ++it)
        {
            std::cout << "\t[" << (*it).first << "] - " << (*it).second << std::endl;
        }

        //solicita valor entero por terminal, la expresion sera evaluada por la regular expression del 3er parametro.
        TerminalUtilities::getValidValue<int>(selectedOption, "Ingresa tu opcion:>", "^[1-9]$", "\tERROR! (ingresa un numero entero entre 1 y 9)");

        //imprimo en pantalla la opción seleccionada por el usuario en caso de que sea valida

        bool isValidOption = mapOptions.find(selectedOption) != mapOptions.end();
        if(isValidOption)
            std::cout << "[" << selectedOption << " - " << mapOptions[selectedOption].c_str() << "]" << std::endl;

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

            case 3: //MOSTRAR PROMEDIO POR TIPO
            {
                showPromedioByType(pokemonVector);
                break;
            }

            case 4: //MOSTRAR CANTIDAD DE POKEMONS CON NIVEL MAYOR A 500
            {
                showBiggerThan(pokemonVector);
                break;
            }

            case 5: //MOSTRAR CANTIDAD DE POKEMONS CON NIVEL MENOR A 500
            {
                showSmallerThan(pokemonVector);
                break;
            }

            case 6: //MOSTRAR CANTIDAD DE POKEMONS CON NIVEL IGUAL A 500
            {
                showEqualTo(pokemonVector);
                break;
            }

            case 7: //MOSTRAR EL POKEMON MAS PODEROSO SEGUN NIVEL FILTRADO POR TIPO
            {
                showStrongestPokemon(pokemonVector);
                break;
            }

            case 8: //MOSTRAR EL POKEMON MAS DEBIL SEGUN EL NIVEL FILTRADO POR TIPO
            {
                showWeakestPokemon(pokemonVector);
                break;
            }

            case 9: //SALIR DEL POKEDEX
            {
                std::cout << "Hasta luego!" << std::endl;
                break;
            }
        }

        if(isValidOption)
        {
            //muestra mensaje para cualquier opcion que no sea la salida
            if(selectedOption != 9)
                std::cout << "Presione cualquier tecla para continuar..." << std::endl;
            std::cin.ignore();
        }

    }

    return 0;
}
