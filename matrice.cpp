#include "matrice.h"
#include "complex.h"
using namespace std ;

matrice::matrice()     //matrice nulle par defaut
{
setrow(0);
setcolumn(0);
}

matrice::matrice(int Ligne , int Colonne)         //on definit l objet matrice
{
setrow(Ligne);                               //definition dimensions
setcolumn(Colonne);
}

void matrice::setdata(int Ligne , int Colonne, complexe nbrecomplexe)// fonction permettant de definir un terme de matrice
{                                                                    //avec une classe complexe
    Data[Ligne][Colonne] = nbrecomplexe;
}

complexe matrice::getdata(int Ligne , int Colonne)//fonction permettant de récupérer la valeur avec une classe complexe
{
    complexe nbrecomplexe;
    nbrecomplexe=Data[Ligne][Colonne];
    return nbrecomplexe;
}

void matrice::setrow(int Ligne)              //définit le nombre de lignes
{
    Data.resize(Ligne);
}

void matrice::setcolumn(int Colonne)             //définit le nombre de colonnes
{
    for ( unsigned int i = 0; i < Data.size(); ++i)
    {
      Data[i].resize(Colonne);
    }
}

double matrice::getrow()              //récupère le nombre de lignes
{
    return (Data.size());
}

double matrice::getcolumn()            //récupère le nombre de colonnes
{
    return (Data[1].size());
}

matrice matrice::operator + (matrice mat) // operateur +
{
    int Ligne=Data.size();
    if(Ligne>0)
    {
        int Colonne=Data[0].size();


    if((Ligne==mat.getrow()) && (Colonne==mat.getcolumn())) //si les deux matrices sont de memes dimensions
    {
        matrice M(Ligne,Colonne);
    for(int i=0;i<Ligne;i++)
        {
            for(int j=0;j<Colonne;j++)
            {
                M.setdata(i,j,Data[i][j]+mat.getdata(i,j));
            }
        }
    return M;
    }
    }
    else
    {
        std::cout<<"dimensions non valides";    //impossiblite de calculer
    }

}



matrice matrice::operator * (matrice mat)//operateur *
{
    int Ligne=Data.size();
    if(Ligne>0)
    {
        int Colonne=Data[0].size();
        matrice M(Ligne,Colonne);

    if(Colonne==mat.getrow())
    {
        for(int i=0;i<Ligne;i++)
        {
            for(int j=0;j<mat.getcolumn();j++)
            {
                for(int k=0;k<mat.getrow();k++)
                M.setdata(i,j,Data[i][k]*mat.getdata(k,j));
            }
        }
    }
    return M;
    }
    else
        std::cout<<"Dimensions non valides";
}


ostream &operator<<( ostream &flux , matrice &matrice )     //on definit l'affichage d'une matrice
{
int Ligne=matrice.getrow() ;
if (Ligne!=0)
{
int Colonne=matrice.getcolumn() ;
for (int i=0;i<Ligne ; i++)
{
for (int j=0;j<Colonne ; j++)
{
flux<<matrice.getdata(i,j).getRe()<<"+ ix"<<matrice.getdata(i,j).getIm()<<"\t" ;  //on affiche le nombre complexe associe a la structure de chaque coefficient de
}                                                                   //la matrice
flux<<endl ;
}
}
else
flux<<"La matrice est vide"<<endl ;
flux<<endl ;
return flux ;                              //on affiche ladite matrice
}




