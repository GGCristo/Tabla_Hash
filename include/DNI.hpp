#ifndef _DNI_
#define _DNI_

class DNI{
  private:
    unsigned long Valor_;
  public:
    DNI();
    operator unsigned long ()  {return Valor_;}
    operator unsigned long () const  {return Valor_;}
};
#endif
