#ifndef _FExploracion_
#define _FExploracion_

template <class Clave>
class FExploracionBase{
  private:

  public:
    virtual int operator() (const Clave&) = 0;
};

template <class Clave>
class FExploracionLineal{
  private:

  public:
    virtual int operator() (const Clave&) = 0;
};

template <class Clave>
class FExploracionCuadratica{
  private:

  public:
    virtual int operator() (const Clave&) = 0;
};

template <class Clave>
class FExploracionDispersion_doble{
  private:

  public:
    virtual int operator() (const Clave&) = 0;
};

template <class Clave>
class FExploracionRedispersion{
  private:

  public:
    virtual int operator() (const Clave&) = 0;
};
#endif
