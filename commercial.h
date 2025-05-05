#pragma once
#include "vendeur.h"
#include "fournisseur.h"
#include<iostream>

class commercial:public vendeur , public fournisseur{
private:
public:
	commercial(int id=0,string nom ="",string email="",string pwd="",string role="",double salaire=0.0,string contact="");
	~commercial(void);
	void saisir();
	void afficher();
};

