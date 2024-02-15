#include <iostream>
#include <vector>
#include <complexe.h>
#include <matrix.h>
using namespace std ;



int main ( )
{     //on s'intéresse aux opérations sur deux matrices
    void initialiser(matrice &Matrice) ;
    matrice matrice1, matrice2;
    char choix , choix2 ;                               //on définit les differents menus du programme
    do{
    cout<<"Operations aux choix\n" ;                    //menu d'operations 1
    cout<<"1 : Initialiser la matrice 1\n" ;
    cout<<"2 : Initialiser la matrice 2\n" ;
    cout<<"3 : Afficher la matrice 1\n" ;
    cout<<"4 : Afficher la matrice 2\n" ;
    cout<<"5 : Additionner les matrices\n" ;
    cout<<"6 : Multiplier les matrices\n" ;
    cout<<"q : Quitter\n" ;
    cout<<"Votre choix : " ;
    cin>>choix ;
    switch (choix) {                                              //effets des choix du menu 1
    case '1' :initialiser(matrice1);cout<<matrice1;break;
    case '2' :initialiser(matrice2);cout<<matrice2;break;
    case '3' : cout<<matrice1 ; break ;                     //affichage matrices
    case '4' : cout<<matrice2 ; break ;
    case '5' : do{
    cout<<"Operations aux choix\n" ;
    cout<<"1 : Sauvegarder le resultat dans la matrice 1\n" ;
    cout<<"2 : Sauvegarder le resultat dans la matrice 2\n" ;
    cout<<"3 : Ne pas Sauvegarder le resultat\n" ;
    cout<<"q : Quitter\n" ;
    cout<<"Votre choix : " ;

    cin>>choix2 ;                                                   //menu d'operations 2
    switch (choix2) {
    case '1' : matrice1=matrice1 + matrice2 ; cout<<matrice1 ;        //on choisit dans quel matrice on stocke le resultat ou si on ne le stocke pas
    break ;
    case '2' : matrice2=matrice1 + matrice2 ; cout<<matrice2 ;
    break ;
    case '3' : {
        matrice m;
        m = matrice1 + matrice2;
        cout<<m;
        break ;
    }
    default : cout<<"Vous avez commis une erreur de saisie, veuillez recommencer"<<endl ;
    }
        }while(choix2!='q') ;
    break ;
    case '6' : do{
    cout<<"Operations aux choix\n" ;
    cout<<"1 : Sauvegarder le resultat dans la matrice 1\n" ;
    cout<<"2 : Sauvegarder le resultat dans la matrice 2\n" ;
    cout<<"3 : Ne pas Sauvegarder le resultat\n" ;
    cout<<"q : Quitter\n" ;
    cout<<"Votre choix : " ;
    cin>>choix2 ;
    switch (choix2) {                                                         //on reste sur le menu 2 pour faire des operations jusqu'a entrer q pour
    case '1' : matrice1=matrice1 * matrice2 ; cout<<matrice1 ;                  //repasser au menu 1
    break ;
    case '2' : matrice2=matrice1 * matrice2 ; cout<<matrice2 ;
    break ;
    case '3': {
    matrice m;
    m = matrice1 * matrice2;
    cout<<m;
    break ;
    }
    default : cout<<"Vous avez commis une erreur de saisie, veuillez recommencer"<<endl ;
    }
        }while(choix2!='q') ; break ;
    case 'q' : ; break ;
    default : cout<<"Vous avez commis une erreur de saisie, veuillez recommencer"<<endl ;
    }
    }while(choix !='q') ;
}

void initialiser(matrice &Matrice)       //fonction permettant de créer les matrices etudiees
{
    double ligne1;
    cout<<"indiquez le nombre de lignes"<<endl;
    cin>> ligne1;                             //on initialise la matrice 1
    Matrice.setrow(ligne1);                 //nbre de lignes colonnes
    double colonne1;
    cout<<"indiquez le nombre de colonnes"<<endl;
    cin>> colonne1;
    Matrice.setcolumn(colonne1);
    for(int i = 0 ; i < ligne1 ; ++i)
    {
        for (int j = 0 ; j < colonne1 ; ++j)
        {
            complexe complexe;                      //puis les termes de la matrice
            double r, im;
            cout<<"partie reelle en("<<i<<j<<")";
            cin>>r;
            complexe.setRe(r);
            cout<<"partie imaginaire en("<<i<<j<<")";
            cin>>im;
            complexe.setIm(im);
            Matrice.setdata(i,j,complexe);
        }
    }
}

