#pragma once
#include <iostream>
#include <string>
using namespace std;

class fournisseur
{	
public:
	int idFourn;
	string nomFourn;
	string contact;
	fournisseur(int idFourn=0,string nomFourn="",string contact="");
	~fournisseur(void);
	void saisirFournisseur();
	void afficherFournisseur();
	void fournirProduit();
	void envoyerFacture();
	int getIdF();
	void setIdF(int idFourn);
	string getNomF();
	void setNomF(string nomFourn);
	string getContact();
	void setContact(string c);
	friend ostream& operator<<(ostream&, fournisseur&);
};

