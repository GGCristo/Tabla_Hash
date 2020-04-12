#ifndef _Celda_
#define _Celda_

#include <iostream>

template <class Clave>
class Celda{
  private:

    Clave* Registros_;
    Clave nClaves_;
  public:

    Celda()
    {
      Registros_ = nullptr;
      nClaves_ = 0;
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
      for (int i = 0; i < nClaves_; i++)
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
      std::cout << "Incompleto" << std::endl;
      return false;
    }

    bool estaLlena ()
    {
      for (int i = 0; i < nClaves_; i++)
      {
        return false;
      }
      return true;
    }
};


#endif
