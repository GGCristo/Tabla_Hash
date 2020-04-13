#ifndef _FDispersion_
#define _FDispersion_
#include <iostream>

template <class Clave>
class FDispersionBase{
  protected:
    int nCeldas_;

  public:

    FDispersionBase<Clave>(const int& nCeldas)
    {
      nCeldas_ = nCeldas;
    }

    ~FDispersionBase<Clave>()
    {
    }

    virtual int operator() (const Clave& X) = 0;
};

template <class Clave>
class FDispersionModulo: public FDispersionBase<Clave> {
  private:

  public:
    using FDispersionBase<Clave>::FDispersionBase;
   // FDispersionModulo<Clave>()
   // {
   // }

    int operator() (const Clave& X) override
    {
      return X % this -> nCeldas_; //two-phase name lookup
    }
};

template <class Clave>
class FDispersionSuma: public FDispersionBase<Clave> {
  private:
  public:

    using FDispersionBase<Clave>::FDispersionBase;
   // FDispersionSuma<Clave>()
   // {
   // }

    int operator() (const Clave& X) override
    {
      unsigned int d = 0;
      Clave x = X;
      int y = 0;
      while (x > 0)
      {
        y = x % 10;
        d = d + y;
        x = x/10;
      }
      return (d % this -> nCeldas_);
    }
};

template <class Clave>
class FDispersionPseudoaleatorio: public FDispersionBase<Clave> {
  private:

  public:

   using FDispersionBase<Clave>::FDispersionBase;
   // FDispersionPseudoaleatorio<Clave>()
   // {
   // }

    int operator() (const Clave& X) override
    {
      std::srand(X);
      return rand() % this -> nCeldas_;
    }
};
#endif
