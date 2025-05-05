#include<iostream>
#include"fournisseur.h"
using namespace std;

fournisseur::fournisseur(int idFourn,string nomFourn,string contact){
	this->idFourn=idFourn;
	this->nomFourn=nomFourn;
	this->contact=contact;
}

fournisseur::~fournisseur(void){
}

void fournisseur::saisirFournisseur(){
	cout<<"entrer l'id de fournisseur : ";
	cin>>idFourn;
	cout<<"entrer le nom de fournisseur : ";
	cin>>nomFourn;
	cout<<"entrer le contact de fournisseur : ";
	cin>>contact;
}

void fournisseur::afficherFournisseur(){
	cout<<"affichage de fournisseur :"<<endl;
	cout<<"nom de fournisseur :"<<nomFourn<<endl;
	cout<<"id de fournisseur :"<<idFourn<<endl;
	cout<<"contact de fournisseur :"<<contact<<endl;
}

void fournisseur::fournirProduit(){
	cout<<nomFourn<<" fournit un produit."<<endl;
}

void fournisseur::envoyerFacture(){
	cout<<"facture envoyer par "<<nomFourn<<endl;
}

int fournisseur::getIdF(){
	return this->idFourn;
}

void fournisseur::setIdF(int idFourn){
	this->idFourn=idFourn;
}

string fournisseur::getNomF(){
	return this->nomFourn;
}

void fournisseur::setNomF(string nomFourn){
	this->nomFourn=nomFourn;
}

string fournisseur::getContact(){
	return this->contact;
}

ostream& operator<<(ostream& out, fournisseur& f) {
    out << "ID Fournisseur: " << f.idFourn << endl;
    out << "Nom Fournisseur: " << f.nomFourn << endl;
    out << "Contact: " << f.contact << endl;
    return out;
}
