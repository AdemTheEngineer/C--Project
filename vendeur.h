#pragma once
#include "utilisateur.h"
#include <iostream>
using namespace std;

class vendeur: public utilisateur
{
private:
	double salaire;
public:
	vendeur(int id=0,string nom ="",string email="",string pwd="",string role="",double salaire=0.0);
	~vendeur(void);
	void saisir();
	void afficher();
	double getSalaire();
	void setSalaire(double salaire);
	friend ostream& operator<<(ostream&, vendeur&);
	friend istream& operator>>(istream&, vendeur&);
};

