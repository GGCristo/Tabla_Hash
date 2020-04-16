#include "../include/DNI.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
DNI::DNI ()
{
  Valor_ = rand() % 9999;
  char A = 65 + rand() % (90 - 65 + 1);
  char B = 65 + rand() % (90 - 65 + 1);
  char C = 65 + rand() % (90 - 65 + 1);
  Valor_ = Valor_ * 100 + A;
  Valor_ = Valor_ * 100 + B;
  Valor_ = Valor_ * 100 + C;
}
bool DNI::operator == (const DNI& dni)
{
  acumulado++;
  return Valor_ == dni.Valor_;
}
