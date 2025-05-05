#include<iostream>
#include"commande.h"
#include <typeinfo>
#include <stdexcept>
using namespace std;

commande::commande(int idCmd,string statut,double total){
	this->idCmd=idCmd;
	this->statut=statut;
	this->total=total;
}

commande::commande(const commande &c){
	idCmd=c.idCmd;
	statut=c.statut;
	total=c.total;
	produit *d;
	for (unsigned int i = 0; i < c.tab.size(); i++)
	{
		if (typeid(*c.tab[i])==typeid(produit)){
			d= new produit(static_cast<const produit&>(*c.tab[i]));
		}
		tab.push_back(d);
	}
}

void commande::saisirCmd(){
	cout<<"id commande : ";
	cin>>idCmd;
	cout<<"statut commande : ";
	cin>>statut;
}

void commande::afficherCmd(){
	cout<<"affichage de commande :"<<endl;
	cout<<"id de commande :"<<idCmd<<endl;
	cout<<"statut de commande :"<<statut<<endl;
	cout<<"prix total de commande :"<<total<<endl;
	cout<<"affichage des produits :"<<endl;
	for(unsigned int i=0; i< tab.size(); i++ ){
		tab[i]->afficherPrd();
	}
}

commande::~commande(void){
	for(unsigned int i=0;i<tab.size();i++)
		delete tab[i];
	tab.clear();	
}

int commande::getIdC(){
	return this->idCmd;
}

void commande::setIdC(int idCmd){
	this->idCmd=idCmd;
}

string commande::getStatut(){
	return this->statut;
}

void commande::setStatut(string statut){
	this->statut=statut;
}

double commande::getTotal(){
	return this->total;
}

void commande::setTotal(double total){
	this->total=total;
}

commande& commande::operator= (const commande&c)
{
	produit *p;
	if (this != &c)
	{
		for (unsigned int i = 0; i < tab.size(); i++)
		{
			delete tab[i];
		}
		tab.clear();

		idCmd=c.idCmd;
		statut=c.statut;
		total=c.total;

		for (unsigned int i = 0; i < c.tab.size(); i++)
		{
			p= new produit(static_cast<const produit&>(*c.tab[i]));
			tab.push_back(p);
		}
	}
	return *this;
}

void commande::ajouter(produit c){
	produit *p=new produit(c);
	tab.push_back(p);
	this->total+=c.getPrix();
}

ostream& operator<<(ostream& out ,commande &c){
	out<<"l'id de commande : "<<c.idCmd<<endl<<"le statut de commande : "<<c.statut<<endl<<"le prix total de commande : "<<c.total<<endl;
	out<<"\n********affichage des produits de la commande********"<<endl;
	for (unsigned int i = 0; i < c.tab.size(); i++)
		c.tab[i]->afficherPrd();
		out<<" "<<endl;
	return out;
}

void commande::creerFichier(fstream &file_f){
	try
	{
		file_f.open("commande.txt",ios::in|ios::out|ios::trunc);
		if(file_f.is_open()){
			for(unsigned int i=0 ; i<tab.size() ; i++)
				if(typeid(*tab[i])==typeid(produit))
					file_f<<*tab[i]<<endl;
				file_f.close();
				cout<<"fichier commande creer avec success"<<endl;
		} else {
			throw runtime_error("erreur du creation de fichier");
		}
	}
	catch(exception& e)
	{
		cout<< e.what() <<endl;
	}
}

void commande::lectureFichier(fstream &f){
	try
	{
		fstream f_lecture("commande.txt",ios::in);
		if(f_lecture.is_open()){
			string str;
			while(getline(f_lecture,str)){
				cout<<str<<endl;
			}
			cout<<"fin de lecture des produits"<<endl;
			f_lecture.close();
		} else{
			throw runtime_error("erreur d'ouverture");
		}
	}
	catch(exception& e)
	{
		cout<< e.what() <<endl;
	}
	
	
}
