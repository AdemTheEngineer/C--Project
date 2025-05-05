#pragma once
#include <iostream>
#include <string>
using namespace std;

class produit
{
private:
	int idPrd;
	string nomPrd;
	string description;
	double prix;
	int qteStock;
public:
	produit(int idPrd=0,string nomPrd="",string description="",double prix=0.0,int qteStock=0);
	virtual ~produit(void);
	virtual void saisirPrd();
	virtual void afficherPrd();
	void modifierPrd(string description,double prix,int qteStock);
	int getIdP();
	void setIdP(int ipPrd);
	string getNomP();
	void setNomP(string nomPrd);
	string getDescription();
	void setDescription(string description);
	double getPrix();
	void setPrix(double prix);
	int getQte();
	void setQte(int qteStock);
	friend ostream& operator<<(ostream&, produit&);
	friend istream& operator>>(istream&, produit&);
	produit operator+(produit& );
};

