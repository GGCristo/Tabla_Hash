#include <iostream>
#include <string>
#include <vector>

#include "../include/Tabla.hpp"
#include "../include/DNI.hpp"

unsigned DNI::acumulado = 0;

int main ()
{
  srand(time(NULL));
  std::cout << "¿Cuantas celdas?" << "\n";
  unsigned int nCeldas;
  std::cin >> nCeldas;

  std::cout << "¿Con que tamaño?" << "\n";
  unsigned int nClaves;
  std::cin >> nClaves;


  std::string fDispersion;
  do
  {
    std::cout << "¿Función de dispersión? (módulo, suma y pseudoaleatoria)" << "\n";
    std::cin >> fDispersion;
  } while (fDispersion != "módulo" && fDispersion != "suma" && fDispersion != "pseudoaleatoria");

  std::string fExploracion;
  do
  {
    std::cout << "¿Función de Exploración? (lineal, cuadrática , dispersión_doble y re-dispersión)" << "\n";
    std::cin >> fExploracion;
  } while (fExploracion != "lineal" && fExploracion != "cuadrática" &&
           fExploracion != "dispersión_doble" && fExploracion != "re-dispersión" );

  Tabla<DNI> Tablota(fDispersion, fExploracion, nCeldas, nClaves);

  float factor;
  do
  {
    std::cout << "¿Factor de carga?" << "\n";
    std::cin >> factor;
  } while (factor < 0 || factor > 1);

  std::cout << "¿Número de pruebas?" << "\n";
  unsigned int nPruebas;
  std::cin >> nPruebas;

  // Banco de pruebas //
  std::vector<DNI> Banco;

  for (int i = 0; i < 2*(factor*nCeldas*nClaves); i++)
  {
    Banco.push_back(DNI());
  }

  for (int i = 0; i/(nCeldas*nClaves) < factor; i++)
  {
    Tablota.Insertar(Banco[i]);
  }
  unsigned int maximo = 0, minimo = 99999999;
  for (int i = 0; i/(nCeldas*nClaves) < factor; i++)
  {
    Tablota.Buscar(Banco[i]);
    if (DNI::acumulado > maximo) maximo = DNI::acumulado;
    if (DNI::acumulado < minimo) minimo = DNI::acumulado;
  }
  std::cout << maximo << std::endl;
  std::cout << minimo << std::endl;
return 0;
}
