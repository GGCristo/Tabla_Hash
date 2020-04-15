#include "../include/DNI.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
DNI::DNI ()
{
  Valor_ = rand() % 99999999;
}
bool DNI::operator == (const DNI& dni)
{
  acumulado++;
  return Valor_ == dni.Valor_;
}
