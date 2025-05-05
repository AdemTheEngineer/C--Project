#include<iostream>
#include"utilisateur.h"
using namespace std;

utilisateur::utilisateur(int id,string nom,string email,string pwd,string role){
	this->id=id;
	this->nom=nom;
	this->email=email;
	this->pwd=pwd;
	this->role=role;
}

utilisateur::~utilisateur(void){
}

void utilisateur::saisir(){
	cout<<"saisir le nom :";
	cin>>nom;
	cout<<"saisir l'id :";
	cin>>id;
	cout<<"saisir l'email :";
	cin>>email;
	cout<<"saisir le role ";
	cin>>role;
}

void utilisateur::afficher(){
	cout<<"nom :"<<nom<<endl;
	cout<<"id :"<<id<<endl;
	cout<<"email :"<<email<<endl;
	cout<<"role :"<<role<<endl;
}

void utilisateur::seConnecter(){
	cout<<"Entrer votre email :"<<endl;
	cin>>email;
	cout<<"Entrer votre mot de passe :"<<endl;
	cin>>pwd;
}

int utilisateur::getId(){
	return this->id;
}

void utilisateur::setId(int id){
	this->id=id;
}

string utilisateur::getNom(){
	return this->nom;
}

void utilisateur::setNom(string nom){
	this->nom=nom;
}

string utilisateur::getEmail(){
	return this->email;
}

void utilisateur::setEmail(string email){
	this->email=email;
}

string utilisateur::getRole(){
	return this->role;
}

void utilisateur::setRole(string role){
	this->role=role;
}

string utilisateur::getPwd(){
	return this->pwd;
}

void utilisateur::setPwd(string pwd){
	this->pwd=pwd;
}

ostream& operator<<(ostream& out,utilisateur &u){
	out<<"id d'utilisateur : "<<u.id<<endl<<"nom d'utilisateur : "<<u.nom<<endl<<"email d'utilisateur : "<<u.email<<endl<<"role d'utilisateur : "<<u.role<<endl;
	return out;
}

istream& operator>>(istream& in, utilisateur &u){
	cout<<"saisir l'id d'utilisateur : ";
	in>>u.id;
	cout<<"saisir le nom d'utilisateur : ";
	in>>u.nom;
	cout<<"saisir l'email d'utilisateur : ";
	in>>u.email;
	cout<<"saisir le role d'utilisateur : ";
	in>>u.role;
	return in;
}
