#include <iostream>
#include <stdexcept>
#include "gerant.h"
using namespace std;

gerant::gerant(int id,string nom,string email,string pwd,string role):
utilisateur(id,nom,email,pwd,role){
}

gerant::gerant(const gerant &g){
	for (list<fournisseur>::const_iterator it = g.Fournisseur.begin(); it != g.Fournisseur.end(); ++it) {
    fournisseur* rep = new fournisseur(*it);
    Fournisseur.push_back(*rep);
}
}

gerant::~gerant(void){
}

void gerant::saisir(){
	utilisateur::saisir();
}

void gerant::afficher(){
	utilisateur::afficher();
}

void gerant::ajouterFournisseur(fournisseur Fournisseur){
	fournisseur* f=new fournisseur(Fournisseur);
	this->Fournisseur.push_back(*f); 
}

int gerant::rechercherFournisseur(int idf){
	int i=0;
    list<fournisseur>::iterator it;
    for(it=Fournisseur.begin();it!=Fournisseur.end();it++){
        if(it->getIdF()==idf){
            return i;
        }
        i++;
    }
    throw logic_error("Aucun fournisseur trouver avec ce id ");
}

void gerant::supprimerFournisseur(int idf){
	try {
        int i = rechercherFournisseur(idf);
        list<fournisseur>::iterator it = Fournisseur.begin();
        advance(it, i);
        Fournisseur.erase(it);
    } catch ( logic_error& e) {
        cout << "Erreur lors de la suppression: " << e.what() << endl;
    }
}

ostream& operator<<(ostream& out,gerant &g){
	out<<"id de gerant : "<<g.id<<endl<<"nom de gerant : "<<g.nom<<endl<<"email de gerant : "<<g.email<<endl;
	out<<"\n********affichage de liste de fournisseur********"<<endl;
	list<fournisseur>::iterator it;
    for(it=g.Fournisseur.begin();it!=g.Fournisseur.end();it++){
        out<<*it;
        out << "------------------------" << endl;
    }
	return out;
}

istream& operator>>(istream& in, gerant &g){
	cout<<"saisir l'id de gerant : ";
	in>>g.id;
	cout<<"saisir le nom de gerant : ";
	in>>g.nom;
	cout<<"saisir l'email de gerant : ";
	in>>g.email;
	return in;
}
