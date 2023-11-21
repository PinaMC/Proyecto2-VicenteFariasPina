#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

//struct Ciudades (City,ConnectedCity)
struct CIUDADES{

    string nombre;
    vector <string> CiudadesConectadas;
       
};
//struct guardianes (Name,PowerLevel,Master,City)
struct GUARDIANES{
    
    string nombre;
    int poder;
    string maestro;
    string ciudad;
    vector <string>aprendices;

};



int main(){

    /*leer archivo contiene los datos de las capitales ( saco nombre de las capitales y caminos )
    leer archivo saco {vertice} y saco el punto "A(V1,V2)"
    El formato de lectura es de: string, string, int, string = nombre guardian, origen, "poder 1-99", "maestro";
        //como leer archivos -> https://parzibyte.me/blog/2020/09/11/leer-archivo-texto-cpp/
    En caso de usar matriz uso  
    1- [V, indice]-> N°Vertices
    2- los vertcies para la matriz quedan asi
    Vertice-> indice, A->0, B->1, C->2
    hacer un grafo para la forma del mapa
    Un guardian puede ser aprendiz y maestro a la vez
    Al vencer un a un maestro es de 5 pts y con un aprendiz 3
    CIUDADES:
    -Las ciudades se deben leer antes que los guardianes
    GUARDIANES:
    -Solo un guardian puede tener 100 puntos
    -Solo 3 guardianes entre 90 y 99 puntos
    -Deben vivir en una ciudad que exista
    */

   cout << "Proyecto 1 de Vicente Farias Pina" << endl;
   cout << "Este programa tratara de unos guardianes y maestros " << endl;
   cout << "" << endl;
   //Lectura Ciudades
   cout << "Lectura del archivo ciudades" << endl;
   int contadorLine = 0;
   string nameFile = "pruebatxt.txt";
   ifstream file(nameFile.c_str());
   string lineaCiudad;
   
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(file, lineaCiudad)) {
        // Imprimir el contenido
        cout << "Linea numero " << contadorLine << ": ";
        cout << lineaCiudad << endl;
        contadorLine++;
    }
    int sizeLine =  lineaCiudad.size();
    cout <<sizeLine << endl;


    //Lectura Guardianes
    cout << "Lectura del archivo guardianes" << endl;
    contadorLine = 0;
    string guardianFile = "guardians.txt";
    ifstream guardian(guardianFile.c_str());
    string lineaGuardian;

    while (getline(guardian, lineaGuardian))
    {
        cout << "Linea numero " << contadorLine << ": ";
        cout << lineaGuardian << endl;
        contadorLine++;
    }
    sizeLine = lineaGuardian.size();
    cout << sizeLine << endl;
    
    

   
   cout <<"                    ***FIN DEL PROGRAMA***" << endl;

    return 0;
}
