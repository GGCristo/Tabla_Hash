#include <iostream>
#include <string>
#include "../include/Tabla.hpp"
#include "../include/Celda.hpp"

int main ()
{

  std::cout << "¿Cuantas celdas?" << "\n";
  unsigned int nCeldas;
  std::cin >> nCeldas;

  std::cout << "¿Con que tamaño?" << "\n";
  unsigned int nClaves;
  std::cin >> nClaves;

  Tabla<int> Tablota(nCeldas, nClaves);

 // std::string fDispersion;
 // do
 // {
 //   std::cout << "¿Función de dispersión? (módulo, suma y pseudoaleatoria)" << "\n";
 //   std::cin >> fDispersion;
 // } while (fDispersion != "módulo" && fDispersion != "suma" && fDispersion != "pseudoaleatoria");

 // std::string fExploracion;
 // do
 // {
 //   std::cout << "¿Función de Exploración? (lineal, cuadrática , dispersión doble y re-dispersión)" << "\n";
 //   std::cin >> fExploracion;
 // } while (fExploracion != "lineal" && fExploracion != "cuadrática" && fExploracion != "dispersión" && fExploracion != "re-dispersión" );

 // float factor = 5;
 // do
 // {
 //   std::cout << "¿Factor de carga?" << "\n";
 //   std::cin >> factor;
 // } while (factor < 0 || factor > 1);

 // std::cout << "¿Número de pruebas?" << "\n";
 // unsigned int nPruebas;
 // std::cin >> nPruebas;


return 0;
}
