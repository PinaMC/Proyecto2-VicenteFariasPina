#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <sstream>
#include <limits>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

//formato del struct Ciudades (City,ConnectedCity)
struct CIUDADES{

    string nombre;
    vector <string> ciudadesConectadas;
       
};
//struct guardianes (Name,PowerLevel,Master,City)
struct GUARDIANES{
    
    string nombre;
    int poder;
    string maestro;
    string ciudad;
    vector <string>aprendices;

};

// Función para leer ciudades desde un archivo
vector<CIUDADES> leerCiudades(const string &ciudadesArchivo)
{
    ifstream ciudadesFile(ciudadesArchivo);

    if (!ciudadesFile.is_open())
    {
        cerr << "***ERROR EN EL ARCHIVO DE CIUDADES***" << endl;
        exit(1);
    }

    string lineaCiudad;
    vector<CIUDADES> ciudades;

    while (getline(ciudadesFile, lineaCiudad))
    {
        stringstream ss(lineaCiudad);
        string ciudad, conectada;

        getline(ss, ciudad, ',');
        CIUDADES nuevaCiudad;
        nuevaCiudad.nombre = ciudad;

        while (getline(ss, conectada, ','))
        {
            nuevaCiudad.ciudadesConectadas.push_back(conectada);
        }

        ciudades.push_back(nuevaCiudad);
    }

    ciudadesFile.close();
    cout << "Lectura de ciudades hecha" << endl;
    return ciudades;
}
// Función para construir un grafo no dirigido a partir de la información de ciudades
unordered_map<string, vector<string>> construirGrafo(const vector<CIUDADES> &ciudades)
{
    unordered_map<string, vector<string>> grafo;

    for (const auto &ciudad : ciudades)
    {
        // Añadir la ciudad al grafo si no está presente
        if (grafo.find(ciudad.nombre) == grafo.end())
        {
            grafo[ciudad.nombre] = vector<string>();
        }

        // Añadir las ciudades conectadas
        for (const auto &conectada : ciudad.ciudadesConectadas)
        {
            grafo[ciudad.nombre].push_back(conectada);

            // Asegurarse de que la ciudad conectada también tenga una entrada en el grafo
            if (grafo.find(conectada) == grafo.end())
            {
                grafo[conectada] = vector<string>();
            }

            // Agregar la ciudad actual a las ciudades conectadas (grafo no dirigido)
            grafo[conectada].push_back(ciudad.nombre);
        }
    }

    return grafo;
}


// Función para leer guardianes desde el archivo txt
vector<GUARDIANES> leerGuardianes(const string& guardianFile) {
    ifstream guardian(guardianFile);

    if (!guardian.is_open()) {
        cerr << "***ERROR EN EL ARCHIVO DE GUARDIANES***" << endl;
        exit(1);
    }

    string lineaGuardian;
    vector<GUARDIANES> guardianes;

    //contador de la validacion
    int contGuardianes100 = 0;  // Contador de guardianes con poder 100
    int contGuardianesReino = 0; // Contador de guardianes con poder entre 90 y 99
    //Text Formato de ejemplo [ City,ConnectedCity ]
    while (getline(guardian, lineaGuardian)) {
        stringstream ss(lineaGuardian);
        string nombre, maestro, ciudad, poderStr;

        getline(ss, nombre, ',');
        getline(ss, poderStr, ',');
        getline(ss, maestro, ',');
        getline(ss, ciudad, ',');

        GUARDIANES nuevoGuardian;
        nuevoGuardian.nombre = nombre;
        nuevoGuardian.poder = stoi(poderStr);
        nuevoGuardian.maestro = maestro;
        nuevoGuardian.ciudad = ciudad;

        guardianes.push_back(nuevoGuardian);
        //validar que solo haya un guardian con 100 y maximo 3 de entre 90 y 99
        if (nuevoGuardian.poder == 100) {
            contGuardianes100++;
        } else if (nuevoGuardian.poder >= 90 && nuevoGuardian.poder <= 99) {
            contGuardianesReino++;
        }
    }

    guardian.close();

    if (contGuardianes100 != 1 || (contGuardianesReino < 1 || contGuardianesReino > 3)) {
        cout << "***ERROR*** En guardianes existe un error con el poder de los guardianes" << endl;
        cerr << "Intenta revisar las reglas para el texto de guardianes" <<endl;
        exit(1);// Terminar el programa con código de error
    }
    cout << "Lectura de guardianes hecha" << endl;
    return guardianes;
}
// Función para mostrar todos los guardianes
void mostrarGuardianes(const vector<GUARDIANES>& guardianes) {
    cout << "Lista de todos los guardianes:" << endl;
    for (const auto& guardian : guardianes) {
        cout << "Nombre: " << guardian.nombre << ", Poder: " << guardian.poder << ", Maestro: " << guardian.maestro << ", Ciudad: " << guardian.ciudad << endl;
    }
}

void reglas(){
    cout << "***REGLAS**" << endl;
    cout << "1- Solo puedes crear caminos al inicio del programa" << endl;
    cout << "2- El programa solo funcionara si haces la correcta carga de archivos de texto" << endl;
    cout << "3- Puedes elegir un guardian para jugar" << endl;
    cout << "4- Si tienes mas puntos que el guardian al que enfrentas ganaras puntos y el rival perdera puntos" << endl;
    cout << "5-" << endl;
    cout << "6- " << endl;
    cout << "7- " << endl;
}


int main(){

   cout << "Proyecto 1 de Vicente Farias Pina" << endl;
   cout << "Este programa tratara de los guardianes de un reino donde lucharan entre varias ciudades para determinar " << endl;
   cout << "quien es el nuevo guardian del reino, para esto tendras que elegir un candidato que te permita pelear con otros guardianes recorriendo ciudades" << endl;
   cout << "y obteniendo puntos" << endl;

   //Lectura Ciudades
   //formato [city, connectedCity]
    cout << "Lectura del archivo ciudades" << endl;
    vector<CIUDADES> ciudades = leerCiudades("ciudadestxt.txt");
   
   //Text formato de ejemplo  nombre,poder,maestro,ciudad       Freya,100,None,Tesla Capital
   // Lectura Guardianes
    ifstream guardianFile("guardians.txt");
    vector<GUARDIANES> guardianes = leerGuardianes("guardians.txt");

    int opMenu = 0;
    do
    {
        //menu
        cout << "\n\n******MENU*******"<< endl;
        cout << "       Opcion1: Ver la carga del texto de guardianes (sus datos), ver el texto ciudades y sus conexiones "<< endl;
        cout << "       Opcion2: Ver las reglas nuevamente \n       Opcion3: Ver la lista de candidatos. \n      Opcion4: Ver al guardian. \n      Opcion5: Conocer el reino." << endl;
        cout << "      Opcion6: Presenciar una Batalla. \n      Opcion0: Salir del programa" << endl;
        cin >> opMenu;
        switch (opMenu)
        {
        case 1: //carga de informacion y muestra de los guardianes
            cout << "Elegiste ver los guardianes cargados" << endl;
            mostrarGuardianes(guardianes);
        
            break;
        
        case 2: reglas();
            break;
        
        case 3: cout << "Elegiste ver la lista de candidatos" << endl;
            break;
        
        case 4: cout <<"Ver al guardian" <<endl;
            break;
        case 5: cout << "Conocer el reino" << endl;
            break;

        case 6: cout << "Presenciar una Batalla" << endl;
            break;
        default:
            break;
        }
    } while (opMenu != 0);
    

    cout <<"                    ***FIN DEL PROGRAMA***" << endl;

    return 0;
}