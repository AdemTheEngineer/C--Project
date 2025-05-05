#include <iostream>
#include "produit.h"
using namespace std;

produit::produit(int idPrd,string nomPrd,string description,double prix,int qteStock){
	this->idPrd=idPrd;
	this->nomPrd=nomPrd;
	this->description=description;
	this->prix=prix;
	this->qteStock=qteStock;
}

produit::~produit(void){
}

void produit::saisirPrd(){
	cout<<"entrer l'id de produit :";
	cin>>idPrd;
	cout<<"entrer le nom de produit :";
	cin>>nomPrd;
	cout<<"entrer la description de produit :";
	cin>>description;
	cout<<"entrer le prix de produit :";
	cin>>prix;
	cout<<"entrer la quantite de stock de produit :";
	cin>>qteStock;
}

void produit::afficherPrd(){
	cout<<"........affichage de produit........"<<endl;
	cout<<"nom de produit :"<<nomPrd<<endl;
	cout<<"id de produit :"<<idPrd<<endl;
	cout<<"description de produit :"<<description<<endl;
	cout<<"prix de produit :"<<prix<<endl;
	cout<<"quantite disponible de produit :"<<qteStock<<endl;
}

void produit::modifierPrd(string description,double prix,int qteStock){
	this->description=description;
	this->prix=prix;
	this->qteStock=qteStock;
}

int produit::getIdP(){
	return this->idPrd;
}

void produit::setIdP(int idPrd){
	this->idPrd=idPrd;
}

string produit::getNomP(){
	return this->nomPrd;
}

void produit::setNomP(string nomPrd){
	this->nomPrd=nomPrd;
}

string produit::getDescription(){
	return this->description;
}

void produit::setDescription(string description){
	this->description=description;
}

double produit::getPrix(){
	return this->prix;
}

void produit::setPrix(double prix){
	this->prix=prix;
}

int produit::getQte(){
	return this->qteStock;
}

void produit::setQte(int qteStock){
	this->qteStock=qteStock;
}

ostream& operator<<(ostream& out,produit &p ){
	out<<"l'id de produit : "<<p.idPrd<<endl<<"le nom de produit : "<<p.nomPrd<<endl<<"le description de produit : "<<p.description<<endl<<"le prix de produit : "<<p.prix<<endl<<"quantite de produit : "<<p.qteStock<<endl;
	return out;
}

istream& operator>>(istream& in, produit &p){
	cout<<"saisir l'id de produit : ";
	in>>p.idPrd;
	cout<<"saisir le nom de produit : ";
	in>>p.nomPrd;
	cout<<"saisir la description de produit : ";
	in>>p.description;
	cout<<"saisir le prix de produit : ";
	in>>p.prix;
	cout<<"saisir la quantite de produit : ";
	in>>p.qteStock;
	return in;
}

produit produit::operator+(produit &p){
	produit d;
	d.idPrd=this->idPrd+p.idPrd;
	d.nomPrd=this->nomPrd+" & "+p.nomPrd;
	d.description=this->description+" + "+p.description;
	d.prix=this->prix+p.prix;
	if (p.qteStock > this->qteStock){
		d.qteStock=this->qteStock;
	} else{
		d.qteStock=p.qteStock;
	}
	return d;
}
