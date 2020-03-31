#include <iostream>
#include <string>

int main ()
{
  std::cout << "¿Cuantas celdas?" << "\n";
  unsigned int nCeldas;
  std::cin >> nCeldas;

  std::cout << "¿Con que tamaño?" << "\n";
  unsigned int nClaves;
  std::cin >> nClaves;

  std::string fDispersion = " ";
  while (fDispersion != "módulo" && fDispersion != "suma" && fDispersion != "pseudoaleatoria")
  {
    std::cout << "¿Función de dispersión? (módulo, suma y pseudoaleatoria)" << "\n";
    std::cin >> fDispersion;
  }

  std::string fExploracion;
  while (fExploracion != "lineal" && fExploracion != "cuadrática" && fExploracion != "dispersión" && fExploracion != "re-dispersión" )
  {
    std::cout << "¿Función de Exploración? (lineal, cuadrática , dispersión doble y re-dispersión)" << "\n";
    std::cin >> fExploracion;
  }

  float factor = 5;
  while (factor < 0 || factor > 1)
  {
    std::cout << "¿Factor de carga?" << "\n";
    std::cin >> factor;
  }

  std::cout << "¿Número de pruebas?" << "\n";
  unsigned int nPruebas;
  std::cin >> nPruebas;


return 0;
}

