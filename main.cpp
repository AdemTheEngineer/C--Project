#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.h"
#include "vendeur.h"
#include "gerant.h"
#include "fournisseur.h"
#include "commercial.h"
#include "produit.h"
#include "commande.h"

using namespace std;

int main() 
{
	
	cout<<"\n-----------------saisir d'utilisateur-----------------"<<endl;
	utilisateur U1;
	cin>>U1;
	cout<<"\n-----------------affichage d'utilisateur-----------------"<<endl;
	cout<<U1;
	
	cout<<"\n-----------------saisir de vendeur-----------------"<<endl;
	vendeur V1;
	cin>>V1;
	cout<<"\n-----------------affichage de vendeur-----------------"<<endl;
	cout<<V1<<endl;
	
	cout<<"\n-----------------saisir de produit 1-----------------"<<endl;
	produit P1;
	P1.saisirPrd();
	cout<<"\n-----------------saisir de produit 2-----------------"<<endl;
	produit P2;
	P2.saisirPrd();
	
	produit P3=P1+P2;
	cout<<"\n-----------------affichage de produit total -----------------"<<endl;
	P3.afficherPrd();
	
	cout<<"\n-----------------saisir de commande-----------------"<<endl;
	commande C1;
	C1.saisirCmd();
	C1.ajouter(P1);
	C1.ajouter(P2);
	commande C2=C1;
	C2.ajouter(P3);
	cout<<"\n-----------------affichage de commande 1-----------------"<<endl;
	cout<<C1;
	cout<<"\n-----------------affichage de fichier	-----------------"<<endl;
	fstream f;
	C1.creerFichier(f);
	C1.lectureFichier(f);
	cout<<"\n-----------------affichage de commande 2-----------------"<<endl;
	cout<<C2;
	
	cout<<"\n-----------------saisir de gerant-----------------"<<endl;
	gerant G1;
	cin>>G1;
	cout<<"\n-----------------saisir de fournisseur 1-----------------"<<endl;
	fournisseur F1;
	fournisseur F2;
	F1.saisirFournisseur();
	cout<<"\n-----------------saisir de fournisseur 2-----------------"<<endl;
	F2.saisirFournisseur();
	G1.ajouterFournisseur(F1);
	G1.ajouterFournisseur(F2);
	cout<<"\n-----------------affichage de gerant-----------------"<<endl;
	cout<<G1<<endl; 
	
	return 0;
}
