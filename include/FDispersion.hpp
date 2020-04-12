#ifndef _FDispersion_
#define _FDispersion_
#include <iostream>
template <class Clave>
class FDispersionBase{
  private:

  public:

    FDispersionBase<Clave>()
    {
      std::cout << "Soy un desgraciado" << std::endl;
    }

    ~FDispersionBase<Clave>()
    {
      std::cout << "Me estan borrando" << std::endl;
    }

    virtual int operator() (const Clave&) = 0;
};

template <class Clave>
class FDispersionModulo: public FDispersionBase<Clave> {
  private:

  public:

    FDispersionModulo<Clave>()
    {
      std::cout << "Soy el modulo" << std::endl;
    }

    int operator() (const Clave&)
    {
    }
};

template <class Clave>
class FDispersionSuma: public FDispersionBase<Clave> {
  private:

  public:

    FDispersionSuma<Clave>()
    {
      std::cout << "Soy la suma" << std::endl;
    }

    int operator() (const Clave&)
    {
    }
};

template <class Clave>
class FDispersionPseudoaleatorio: public FDispersionBase<Clave> {
  private:

  public:

    FDispersionPseudoaleatorio<Clave>()
    {
      std::cout << "Soy Pseudoaletorio" << std::endl;
    }

    int operator() (const Clave&)
    {
    }
};
#endif
