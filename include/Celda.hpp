#ifndef _Celda_
#define _Celda_

#include <iostream>

template <class Clave>
class Celda{
  private:

    Clave* Registros_;
    Clave nClaves_;
    int ultimo; // Posición del ultimo elemento insertado [-1 - nClaves_ - 1]
  public:

    Celda()
    {
      Registros_ = nullptr;
      nClaves_ = 0;
      ultimo = -1;
    }

    void resize (const int& nClaves)
    {
      Registros_ = new Clave[nClaves];
      nClaves_ = nClaves;
    }

    ~Celda ()
    {
      delete [] Registros_;
      nClaves_ = 0;
    }

    bool Buscar (Clave X)
    {
      for (int i = 0; i < ultimo; i++)
      {
        if (Registros_[i] == X)
        {
          return true;
        }
      }
      return false;
    }

    bool Insertar (Clave X)
    {
      if (!estaLlena())
      {
        Registros_[++ultimo];
      }
      return false;
    }

    bool estaLlena ()
    {
      if (ultimo + 1 == nClaves_)
        return true;
      return false;
    }
};


#endif
