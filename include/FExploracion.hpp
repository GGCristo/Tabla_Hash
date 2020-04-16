#ifndef _FExploracion_
#define _FExploracion_

#include <iostream>
#include "FDispersion.hpp"

template <class Clave>
class FExploracionBase{
  protected:
    int nCeldas_;

  public:

    FExploracionBase<Clave>(const int& nCeldas = 5)
    {
      nCeldas_ = nCeldas;
    }

    virtual ~FExploracionBase<Clave>()
    {
    }

    virtual int operator() (const Clave&, int i) = 0;
};

template <class Clave>
class FExploracionLineal: public FExploracionBase<Clave>{
  private:

  public:

    using FExploracionBase<Clave>::FExploracionBase;
    virtual int operator() (const Clave&, int i) override
    {
      return i;
    }
};

template <class Clave>
class FExploracionCuadratica: public FExploracionBase<Clave>{
  private:

  public:

    using FExploracionBase<Clave>::FExploracionBase;
    virtual int operator() (const Clave& X, int i) override
    {
      if (i == 0 || i == 1)
        return i;
      return (i*i);
    }
};

template <class Clave>
class FExploracionDispersion_doble: public FExploracionBase<Clave>{
  private:

   FDispersionBase<Clave>* fDispersion;
   int nCeldas_;
  public:

    FExploracionDispersion_doble<Clave>(const int& nCeldas)
    {
      fDispersion = new FDispersionSuma<Clave>(nCeldas);
      this -> nCeldas_ = nCeldas;
    }

    ~FExploracionDispersion_doble<Clave>()
    {
      delete fDispersion;
    }

    virtual int operator() (const Clave& X, int i) override
    {
      return i * (1 + (*fDispersion)(X));
    }
};

template <class Clave>
class FExploracionRedispersion: public FExploracionBase<Clave>{
  private:
  public:

    using FExploracionBase<Clave>::FExploracionBase;
    virtual int operator() (const Clave& X, int i) override
    {
      srand(X + i);
      return i + rand();
    }
};
#endif
