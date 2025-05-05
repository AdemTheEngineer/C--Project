#pragma once
#include <iostream>
#include <string>
using namespace std;

class utilisateur
{
protected:
	int id;
	string nom;
	string email;
	string pwd;
	string role;
public:
	utilisateur(int id=0 ,string nom="",string email="",string pwd="",string role="");
	virtual ~utilisateur(void);
	virtual void saisir();
	virtual void afficher();
	virtual void seConnecter();	
	int getId();
	void setId(int id);
	string getNom();
	void setNom(string nom);
	string getEmail();
	void setEmail(string email);
	string getRole();
	void setRole(string role);
	string getPwd();
	void setPwd(string pwd);
	friend ostream& operator<<(ostream&, utilisateur&);
	friend istream& operator>>(istream&, utilisateur&);
};
