#include "../include/DNI.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
DNI::DNI ()
{
  Valor_ = rand() % 99999999;
  std::cout << "Se crea el valor: " << Valor_ << std::endl;
}
bool DNI::operator == (const DNI& dni)
{
  acumulado++;
  return Valor_ == dni.Valor_;
}
