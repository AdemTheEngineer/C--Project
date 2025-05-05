#include<iostream>
#include"commercial.h"
using namespace std;

commercial::commercial(int id,string nom,string email,string pwd,string role,double salaire,string contact):
vendeur(id,nom,email,pwd,role,salaire),
fournisseur(id,nom,contact){
	
}

void commercial::saisir(){
	vendeur::saisir();
	cout<<"entrer le contact de commercial : ";
	cin>>contact;
}

void commercial::afficher(){
	vendeur::afficher();
	cout<<"entrer le contact de commercial : "<<contact<<endl;
}

commercial::~commercial(void){
}

