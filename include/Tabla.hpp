#ifndef _Tabla_
#define _Tabla_

#include <iostream>
#include <string>
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

    Tabla(const std::string& fDispersion_s, const std::string& fExploracion_s, const int& nCeldas = 5, const int nClaves = 5)
    {
      if (fDispersion_s == "módulo") fDispersion = new FDispersionModulo<Clave>;
      else if (fDispersion_s == "suma") fDispersion = new FDispersionSuma<Clave>;
      else fDispersion = new FDispersionPseudoaleatorio<Clave>;

      if (fExploracion_s == "lineal") fExploracion = new FExploracionLineal<Clave>;
      else if (fExploracion_s == "cuadrática") fExploracion = new FExploracionCuadratica<Clave>;
      else if (fExploracion_s == "dispersión_doble") fExploracion = new FExploracionDispersion_doble<Clave>;
      else fExploracion = new FExploracionRedispersion<Clave>;

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
      delete fDispersion;
      delete fExploracion;
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
