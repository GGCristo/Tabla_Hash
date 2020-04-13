#include "../include/DNI.hpp"
#include <cstdlib>
#include <ctime>
DNI::DNI ()
{
  srand(time(NULL));
  Valor_ = rand() % 99999999;
}
