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

};


#endif
