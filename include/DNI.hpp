#ifndef _DNI_
#define _DNI_

class DNI{
  private:
    unsigned long Valor_;
  public:
    static unsigned acumulado;
    DNI();
    bool operator == (const DNI&);
    operator unsigned long ()  {return Valor_;}
    operator unsigned long () const  {return Valor_;}
};
#endif
