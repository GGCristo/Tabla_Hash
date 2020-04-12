#ifndef _Tabla_
#define _Tabla_

#include <iostream>
#include "Celda.hpp"
#include "FDispersion.hpp"
#include "FExploracion.hpp"

template <class Clave>
class Tabla{
  private:
    Celda<Clave>* vCelda;
    int nCeldas_;

    FDispersionBase<Clave>* fDispersion;
    FExploracionBase<Clave>* fExploracion;

  public:

    Tabla(const int& nCeldas = 5, const int nClaves = 5)
    {
      nCeldas_ = nCeldas;
      vCelda = new  Celda<Clave>  [nCeldas];
      for (int i = 0; i < nCeldas_; i++)
      {
        vCelda[i].resize (nClaves);
      }
    }

    ~Tabla()
    {
      delete [] vCelda;
    }

    bool Buscar(Clave X)
    {
      for (int i = 0; i < nCeldas_; i++)
      {
        if (vCelda[i].Buscar(X))
          return true;
      }
      return false;
    }

    bool Insertar(Clave X)
    {
      return true;
    }
};



#endif
