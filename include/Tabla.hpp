#ifndef _Tabla_
#define _Tabla_

#include <iostream>
#include "Celda.hpp"

template <class Clave>
class Tabla{
  private:
    Celda<Clave>* vCelda;
    int a;
    //int fDispersion();
    //int fExploracion();

  public:

    Tabla(const int& nCeldas = 5, const int nClaves = 5)
    {
      vCelda = new  Celda<Clave>  [nCeldas];
      for (int i = 0; i < nCeldas; i++)
      {
        vCelda[i].resize (nClaves);
      }
    }

    ~Tabla()
    {
      delete [] vCelda;
    }

    bool Buscar(Clave)
    {
      return true;
    }

    bool Insertar(Clave)
    {
      return true;
    }
};



#endif
