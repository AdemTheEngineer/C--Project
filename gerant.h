#pragma once
#include "utilisateur.h"
#include "fournisseur.h"
#include "list"
#include <iostream>
using namespace std;

class gerant: public utilisateur
{
private:
	list<fournisseur> Fournisseur;
public:
	gerant(int id=0,string nom="",string email="",string pwd="",string role="");
	gerant(const gerant&);
	~gerant(void);
	void saisir();
	void afficher();
	void ajouterFournisseur(fournisseur);
	void supprimerFournisseur(int);
	int rechercherFournisseur(int);
	friend ostream& operator<<(ostream&, gerant&);
	friend istream& operator>>(istream&, gerant&);
};
