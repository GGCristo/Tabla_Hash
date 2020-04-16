#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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


  float factor;
  do
  {
    std::cout << "¿Factor de carga?" << "\n";
    std::cin >> factor;
  } while (factor < 0 || factor > 1);

  std::cout << "¿Número de pruebas?" << "\n";
  unsigned int nPruebas;
  std::cin >> nPruebas;

  //nCeldas = 1000;
  //nClaves = 2;
  //fDispersion = "suma";
  //fExploracion = "cuadrática";
  //factor = 0.4;
  //nPruebas = 5;

  Tabla<DNI> Tablota(fDispersion, fExploracion, nCeldas, nClaves);

  // Banco de pruebas //
  int N = factor*nCeldas*nClaves;
  std::vector<DNI> Banco(N*2);


  for (int i = 0; i < N; i++)
  {
    Tablota.Insertar(Banco[i]);
  }

  unsigned int B_maximo = 0, acumulado_B = 0, B_minimo = 99999999;
  unsigned int I_maximo = 0, acumulado_I = 0, I_minimo = 99999999;

  for (unsigned int i = 0; i < nPruebas; i++)
  {
    Tablota.Buscar(Banco[rand() % N]);
    if (DNI::acumulado > B_maximo) B_maximo = DNI::acumulado;
    if (DNI::acumulado < B_minimo) B_minimo = DNI::acumulado;
    acumulado_B += DNI::acumulado;
    DNI::acumulado = 0;
  }
  for (unsigned int i = 0; i < nPruebas; i++)
  {
    Tablota.Buscar(Banco[N + (rand() % N)]);
    if (DNI::acumulado > I_maximo) I_maximo = DNI::acumulado;
    if (DNI::acumulado < I_minimo) I_minimo = DNI::acumulado;
    acumulado_I += DNI::acumulado;
    DNI::acumulado = 0;
  }

  std::cout << "Celdas  nClave  Dispersión       Exploracion       Carga  Pruebas" << std::endl;
  std::cout << std::left     << std::setw(8)  << nCeldas;
  std::cout << std::setw(8)  << nClaves;
  std::cout << std::setw(17) << fDispersion;
  std::cout << std::setw(18) << fExploracion;
  std::cout << std::setw(7)  << (factor*100)   << "\%";
  std::cout << std::setw(9)  << nPruebas;
  std::cout << "\n\n           Mínimo  Medio  Máximo" << std::endl;
  std::cout << "Búsquedas: ";
  std::cout << std::setw(8) << B_minimo;
  std::cout << std::setw(7) << (acumulado_B)/nPruebas;
  std::cout << B_maximo << std::endl;
  std::cout << "Inserción: ";
  std::cout << std::setw(8) << I_minimo;
  std::cout << std::setw(7) << (acumulado_I)/nPruebas;
  std::cout << I_maximo << std::endl;
  return 0;
}
