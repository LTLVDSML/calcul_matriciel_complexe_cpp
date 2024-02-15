#ifndef MATRICE_H
#define MATRICE_H
#include "complexe.h"
#include <iostream>
#include<vector>


class matrice
{
public:
    matrice();
    matrice(int,int);
    void setdata(int,int,complexe);
    complexe getdata(int,int);
    void setrow(int);
    double getrow();
    void setcolumn(int);
    double getcolumn();
    matrice operator + (matrice);
    matrice operator * (matrice);

private:
    std::vector<std::vector<complexe>>Data;
};
std::ostream &operator<<(std::ostream &,matrice&);
#endif // MATRICE_H

