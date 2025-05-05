#pragma once
#include "produit.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class commande
{
private:
	int idCmd;
	string statut;
	double total;
	vector<produit*>tab;
public:
	commande(int idCmd=0,string statut="",double total=0.0);
	commande(const commande&);
	~commande(void);
	void saisirCmd();
	void afficherCmd();
	void ajouter(produit);
	void supprimer(int);
	int getIdC();
	void setIdC(int idCmd);
	string getStatut();
	void setStatut(string statut);
	double getTotal();
	void setTotal(double total);
	commande & operator= (const commande&);
	friend ostream& operator<<(ostream& ,commande&);
	void creerFichier(fstream&);
	void lectureFichier(fstream&);
};
