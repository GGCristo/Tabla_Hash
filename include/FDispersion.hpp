#ifndef _FDispersion_
#define _FDispersion_

template <class Clave>
class FDispersionBase{
  private:

  public:
    virtual int operator() (const Clave&) = 0;
};

template <class Clave>
class FDispersionModulo{
  private:

  public:
    int operator() (const Clave&)
    {
    }
};

template <class Clave>
class FDispersionSuma {
  private:

  public:
    int operator() (const Clave&)
    {
    }
};

template <class Clave>
class FDispersionPseudoaleatorio {
  private:

  public:
    int operator() (const Clave&)
    {
    }
};
#endif
