#ifndef _FExploracion_
#define _FExploracion_

#include <iostream>

template <class Clave>
class FExploracionBase{
  private:

  public:

    FExploracionBase<Clave>()
    {
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

    FExploracionLineal<Clave>()
    {
      std::cout << "Soy lineal" << std::endl;
    }

    virtual int operator() (const Clave&, int i) override
    {
      return 0;
    }
};

template <class Clave>
class FExploracionCuadratica: public FExploracionBase<Clave>{
  private:

  public:

    FExploracionCuadratica<Clave>()
    {
      std::cout << "Soy cuadrático" << std::endl;
    }

    virtual int operator() (const Clave&, int i) override
    {
      return 0;
    }
};

template <class Clave>
class FExploracionDispersion_doble: public FExploracionBase<Clave>{
  private:

  public:

    FExploracionDispersion_doble<Clave>()
    {
      std::cout << "Soy Dispersion_doble" << std::endl;
    }

    virtual int operator() (const Clave&, int i) override
    {
      return 0;
    }
};

template <class Clave>
class FExploracionRedispersion: public FExploracionBase<Clave>{
  private:

  public:

    FExploracionRedispersion<Clave>()
    {
      std::cout << "Soy Redispersion" << std::endl;
    }
    virtual int operator() (const Clave&, int i) override
    {
      return 0;
    }
};
#endif
