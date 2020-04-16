#ifndef _Celda_
#define _Celda_

#include <iostream>

template <class Clave>
class Celda{
  private:

    Clave* Registros_;
    unsigned int nClaves_;
    int ultimo; // Posición del ultimo elemento insertado [-1 - nClaves_ - 1]
  public:

    Celda()
    {
      Registros_ = new Clave[1];
      nClaves_ = 0;
      ultimo = -1;
    }

    void resize (const int& nClaves)
    {
      nClaves_ = nClaves;
      clear();
    }

    void clear ()
    {
      delete [] Registros_;
      Registros_ = new Clave[nClaves_];
      ultimo = -1;
    }

    ~Celda ()
    {
      delete [] Registros_;
      nClaves_ = 0;
    }

    bool Buscar (Clave X)
    {
      for (int i = 0; i < ultimo + 1; i++)
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
        Registros_[++ultimo] = X;
        return true;
      }
      return false;
    }

    bool estaLlena ()
    {
      if (ultimo + 1 == (int)(nClaves_))
      {
        return true;
      }
      return false;
    }
};


#endif
