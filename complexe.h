#ifndef COMPLEXE_H
#define COMPLEXE_H
#include <iostream>


class complexe
{
public:
    complexe(double,double);
    complexe();
    void setRe(double);
    void setIm(double);
    double getRe();
    double getIm();
    complexe operator+(const complexe);
    complexe& operator+=(const complexe);
    complexe operator*(const complexe);
    complexe& operator*=(const complexe);

private :
    double Re, Im;

};
std::ostream&operator<<(std::ostream & ,complexe &);

#endif // COMPLEXE_H
