#include <iostream>
#include <vector>
#include "complexe.h"

complexe::complexe(double Reel, double Imag)
{
    setRe(Reel);
    setIm(Imag);
}
complexe::complexe()
{
    setRe(0);                     //valeurs par défaut si non spécifié
    setIm(0);
}

void complexe::setRe(double Reel)
{
    Re=Reel;
}
void complexe::setIm(double Imag)
{
    Im=Imag;
}

double complexe::getRe( )
{
    return Re;
}
double complexe::getIm()
{
    return Im;
}

complexe complexe::operator + (const complexe Z1)
{
    complexe Z(0,0);
    Z.setRe(this->Re+Z1.Re);
    Z.setIm(this->Im+Z1.Im);
    return(Z);
}

complexe complexe::operator * (const complexe Z1)
{
    complexe Z(0,0);
    Z.setRe(this->Re*Z1.Re-this->Im*Z1.Im);
    Z.setIm(this->Im*Z1.Re+this->Re*Z1.Im);
    return(Z);
}

complexe& complexe::operator += (const complexe Z)
{
    Re+=Z.Re;
    Im+=Z.Im;
    return *this;
}

complexe& complexe::operator *= (const complexe Z)
{
    double Reel=this->Re;
    double Imag=this->Im;
    Re=Reel*Z.Re-Imag*Z.Im;
    Im=Imag*Z.Re+Reel*Z.Im;
    return *this;
}

std::ostream &operator<<(std::ostream & flux, complexe &Z)
{
    double Re=Z.getRe();
    double Im=Z.getIm();
    if(Re!=0)
        flux<<Re;
    if(Im!=0)
    {
        if((Im>0)&&(Re!=0))
            flux<<"+";
            flux<<Im<<"i";
    }
    if((Im==0)&&(Re==0))
        flux<<"0";
        return flux;
}
