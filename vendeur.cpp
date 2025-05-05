#include <iostream>
#include "vendeur.h"
using namespace std;

vendeur::vendeur(int id,string nom,string email,string pwd,string role,double salaire):
utilisateur(id,nom,email,pwd,role)
{
	this->salaire=salaire;
}

vendeur::~vendeur(void){
}

void vendeur::saisir(){
	utilisateur::saisir();
	cout<<"saisir le salaire de vendeur :";
	cin>>salaire;
}

void vendeur::afficher(){
	utilisateur::afficher();
	cout<<"le salaire de vendeur :"<<salaire<<endl;
}

double vendeur::getSalaire(){
	return this->salaire;
}

void vendeur::setSalaire(double salaire){
	this->salaire=salaire;
}

ostream& operator<<(ostream& out,vendeur &v){
	out<<"id de vendeur : "<<v.id<<endl<<"nom de vendeur : "<<v.nom<<endl<<"email de vendeur : "<<v.email<<endl<<"salaire de vendeur : "<<v.salaire;
	return out;
}

istream& operator>>(istream& in, vendeur &v){
	cout<<"saisir l'id de vendeur : ";
	in>>v.id;
	cout<<"saisir le nom de vendeur : ";
	in>>v.nom;
	cout<<"saisir l'email de vendeur : ";
	in>>v.email;
	cout<<"saisir le salaire de vendeur : ";
	in>>v.salaire;
	return in;
}
