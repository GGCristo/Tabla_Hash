#ifndef _Tabla_
#define _Tabla_

#include <iostream>
#include <string>
#include "Celda.hpp"
#include "FDispersion.hpp"
#include "FExploracion.hpp"
#include <typeinfo>
#include <string>

template <class Clave>
class Tabla{
  private:
    Celda<Clave>* vCelda;
    int nCeldas_;
    std::string fExploracion_s_;

    FDispersionBase<Clave>* fDispersion;
    FExploracionBase<Clave>* fExploracion;

  public:

    Tabla(const std::string& fDispersion_s, const std::string& fExploracion_s, const int& nCeldas = 5, const int nClaves = 5)
    {
      nCeldas_ = nCeldas;
      vCelda   = new  Celda<Clave>  [nCeldas];
      if (fDispersion_s == "módulo")    fDispersion = new FDispersionModulo<Clave>(nCeldas_);
      else if (fDispersion_s == "suma") fDispersion = new FDispersionSuma<Clave>(nCeldas_);
      else                              fDispersion = new FDispersionPseudoaleatorio<Clave>(nCeldas_);

      if (fExploracion_s == "lineal")                fExploracion = new FExploracionLineal<Clave>(nCeldas_);
      else if (fExploracion_s == "cuadrática")       fExploracion = new FExploracionCuadratica<Clave>(nCeldas_);
      else if (fExploracion_s == "dispersión_doble") fExploracion = new FExploracionDispersion_doble<Clave>(nCeldas_);
      else                                           fExploracion = new FExploracionRedispersion<Clave>(nCeldas_);

      for (int i = 0; i < nCeldas_; i++)
      {
        vCelda[i].resize (nClaves);
      }
      fExploracion_s_ = fExploracion_s;
    }

    ~Tabla()
    {
      delete [] vCelda;
      delete fDispersion;
      delete fExploracion;
    }

    bool Buscar(Clave X)
    {
      int d = 0;
      int c = (*fDispersion)(X);
      for (int i = c; d < nCeldas_ + 1; i = (c + (*fExploracion)(X, i)) % nCeldas_)
      {
        if (vCelda[i].Buscar(X)) return true;
        else if (!vCelda[i].estaLlena()) return false;

        // Esta es la parte negativa de la función cuadrática
        else if (fExploracion_s_ == "cuadrática" && d!=0 && d + 2 < nCeldas_) // Me aseguro de que no es la primera iteracción pues esa esta destina a la función dispersión
        {                                                                     // Así mismo aumento el iterador porque considero que la parte negativa tambien cuenta como un intento más
          i = d - (*fExploracion)(X,i);

          if (i < 0)
            i = (i * (-1)) % nCeldas_;
          else
            i %= nCeldas_;

          if (vCelda[i].Buscar(X)) return true;
          else if (!vCelda[i].estaLlena()) return false;
          d++;
        }
        d++;
      }
      return false;
    }

    bool Insertar(Clave X)
    {
      int d = 0;
      int c = (*fDispersion)(X);
      for (int i = c; d < nCeldas_ + 1; i = (c + (*fExploracion)(X, i)) % nCeldas_)
      {
        if (vCelda[i].Insertar(X)) return true;
        else if (fExploracion_s_ == "cuadrática" && d!=0 && d + 2 < nCeldas_)
        {
          i = d - (*fExploracion)(X,i);

          if (i < 0)
            i = (i * (-1)) % nCeldas_;
          else
            i %= nCeldas_;

          if (vCelda[i].Buscar(X)) return true;
        }
        d++;
      }
      return false;
    }

    void clear ()
    {
      for (int i = 0; i < nCeldas_; i++)
      {
        vCelda[i].clear();
      }
    }
};
#endif
