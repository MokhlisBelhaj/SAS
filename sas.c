#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int choix=0,nombreProduits=0,nombreProduitsAchetee=0;
struct produit{
	char code [20] ;
	char nom [20] ;
	float prixHT;
	int qte;
	float prixTTC;
	char date[11];
};
struct produit produits[1000];
struct produit produitsAchetee[1000];
// CALCULER DE PRIX TTC
float calculerPrixTTC(float prixHT){
	
	float prixTTC;
	
	prixTTC= prixHT * 1.15;
	
	return prixTTC;
}
//FONCTION AJOUTER DE produit
void ajouterProduit(int taille){
	int i;
	char x[20];
    int b=0;
	int nbPA=nombreProduits;
	nombreProduits=nombreProduits+taille;
	for(i=nbPA;i<nombreProduits;i++){
		printf("code produit ");
		scanf("%s",produits[i].code);		
		printf("nom produit ");
		scanf("%s",&produits[i].nom);
		printf("prix HT produit ");
		scanf("%f",&produits[i].prixHT);
		printf("quantite du produit ");
		scanf("%d",&produits[i].qte);
		produits[i].prixTTC = calculerPrixTTC(produits[i].prixHT);
		}}
//affichage
void afficherProduits(){
	int i;
	for(i=0;i<nombreProduits;i++){
		printf("produit %d est : Code : %s , Nom : %s , PrixHT : %f , Quantite : %d , PrixTTC : %f \n",i+1,produits[i].code,produits[i].nom,produits[i].prixHT,produits[i].qte,produits[i].prixTTC);
	}}
//recherche par code
void recherchecode(char code[20]){
	int i;
	int valide=0;
	for(i=0;i<nombreProduits;i++){
		if(strcmp(produits[i].code,code)==0){
				printf("produit %d est : Code : %s , Nom : %s , PrixHT : %f , Quantite : %d , PrixTTC : %f \n",i+1,produits[i].code,produits[i].nom,produits[i].prixHT,produits[i].qte,produits[i].prixTTC);
			valide=1;
		}
	}
	if(valide==0){
		printf("le produit recherche n'existe pas \n");
	}
}
//Acheter produit
void acheterProduit(char code[20],int qte, char date[20]){
	int i,j;
	int ref;
	int valide=0;
	int x=0;
	for(i=0;i<nombreProduits;i++){
		ref=strcmp(produits[i].code,code);
		if(ref==0 && produits[i].qte>=qte){
	       for(j=0;j<nombreProduitsAchetee;j++){
	     	if(strcmp(produitsAchetee[j].code,code)==0){
	     		produitsAchetee[j].qte=produitsAchetee[j].qte+qte;
	     		produits[i].qte=produits[i].qte-qte;
	     		x=1;
	     		valide=1;
		}
	}
	if(x==0){
		
			strcpy(produitsAchetee[nombreProduitsAchetee].code,produits[i].code);
			strcpy(produitsAchetee[nombreProduitsAchetee].date,date);
			strcpy(produitsAchetee[nombreProduitsAchetee].nom,produits[i].nom);
			produitsAchetee[nombreProduitsAchetee].prixHT=produits[i].prixHT;
			produitsAchetee[nombreProduitsAchetee].prixTTC=produits[i].prixTTC;
			produitsAchetee[nombreProduitsAchetee].qte=qte;	
			produits[i].qte=produits[i].qte-qte;
			nombreProduitsAchetee++;
			valide=1;
			
		
		}
	}
	
}
	int k;
	
	if(valide==1){
		for(k=0;k<nombreProduitsAchetee;k++){
			printf("produit %d est : Code : %s , Nom : %s , PrixHT : %f , Quantite : %d , PrixTTC : %f , Date : %s \n",k+1,produitsAchetee[k].code,produitsAchetee[k].nom,produitsAchetee[k].prixHT,produitsAchetee[k].qte,produitsAchetee[k].prixTTC,produitsAchetee[k].date);
		}
	}else{
		printf("produit non trouve ou la quantite insuffisant\n");
	}
	
}
//recherche par quantite
void rechercheQuantite(int quantite){
	int i;
	int valide=0;
	for(i=0;i<nombreProduits;i++){
		if(produits[i].qte==quantite){
				printf("produit %d est : Code : %s , Nom : %s , PrixHT : %f , Quantite : %d , PrixTTC : %f \n",i+1,produits[i].code,produits[i].nom,produits[i].prixHT,produits[i].qte,produits[i].prixTTC);
				valide=1;
		}
	}
	if(valide==0){
		printf("le Quantite de  produit  n'existe pas \n");
	}
}
//etat de stock
void etatstock(){
	int i;
	int valide=0;
	for(i=0;i<nombreProduits;i++){
		if(produits[i].qte<=3){
				printf("produit %d est : Code : %s , Nom : %s , PrixHT : %f , Quantite : %d , PrixTTC : %f \n",i+1,produits[i].code,produits[i].nom,produits[i].prixHT,produits[i].qte,produits[i].prixTTC);
				valide=1;
		}
	}
	if(valide==0){
		printf("les Quantites des  produits est superieur de 3 \n");
	}
}
 //Alimenter stock
void alimenterStock(char code[20],int qte){
	int i;
	int valide=0;
	for(i=0;i<nombreProduits;i++){
		if(strcmp(produits[i].code,code)==0){
			produits[i].qte=produits[i].qte+qte;
			valide=1;
		}
	}
	if(valide==0){
		printf("le produit recherche n'existe pas dans le tableau \n");
	}
}
//Supprimer les produits par code
void Supprimer(char code[20]){
	int i;
	for(i=0;i<nombreProduits;i++){
		if(strcmp(produits[i].code,code)==0){
			
				produits[i]=produits[nombreProduits-1];
				nombreProduits--;	}
		 
		}
}

void statistique(char date[20]){
	int i,j=0;
	float totalPrix=0;
	float moyennePrix;
	for(i=0;i<nombreProduitsAchetee;i++){
		if(strcmp(produitsAchetee[i].date,date)==0){
			totalPrix +=(produitsAchetee[i].prixTTC*produitsAchetee[i].qte);
			j++;
		}
	}
	moyennePrix=totalPrix/j;
		
	printf("total est %f moyenne est %f\n",totalPrix,moyennePrix);
		for(i=0;i<nombreProduitsAchetee;i++){
		if(strcmp(produitsAchetee[i].date,date)==0){
			int j,ind;
			struct produit v;
	   for(i=0;i<nombreProduitsAchetee-1;i++){
     	for(j=i+1;j<nombreProduitsAchetee;j++){
     		if(produitsAchetee[i].prixTTC>produitsAchetee[j].prixTTC){
     			v=produitsAchetee[i];
     			produitsAchetee[i]=produitsAchetee[j];
     			produitsAchetee[j]=v;
			}
     		
	 }
           }
		   	printf("min est %f max est %f\n",produitsAchetee[0].prixTTC,produitsAchetee[nombreProduitsAchetee-1].prixTTC);
		}
		}
}

int main() {
	
	int test=0;
	int n;
	char codeR [20];
	char dateN [20];
	int qteN;
	char date[20];
	
	do{
		system("cls");
		printf("*******************MENU*******************\n");
		printf("1- Ajouter un produit \n");
		printf("2- Ajouter plusieurs produits \n");
		printf("3- Afficher tous les produits \n");
		printf("4- Acheter produit \n");
		printf("5- Rechercher produit \n");
		printf("6- Etat de stock \n");
		printf("7- Alimenter stock \n");
		printf("8- Supprimer produit \n");
		printf("9- Statistique \n");
		printf("10- Exit \n\n\n");
		printf("Saisir votre choix : ");
		scanf("%d",&choix);
		
		switch(choix){
			case 1:
				system("cls");
				ajouterProduit(1);
				break;
			case 2:
				system("cls");
				printf("donner le nombre des produits : ");
				scanf("%d",&n);
				ajouterProduit(n);
				break;
			case 3:
				system("cls");
				choix=0;
				int sousTest=0;
				do{
					printf("1- Affichage Normal \n");
					printf("2- Affichage selon l'ordre alphabetique \n");
					printf("3- Affichage selon l'ordre desc du prix \n");
					printf("4- Menu principale \n");
					printf("Saisir votre choix : ");
					scanf("%d",&choix);
								 int i,j,ind;
								  struct produit v;
					switch(choix){
						case 1:
							afficherProduits();
							break;
						case 2:
						    //tri par selectiom alphab       
	                         for(i=0;i<nombreProduits-1;i++){
	                         	ind =i;
     	                     for(j=i+1;j<nombreProduits;j++){
     	                     if(strcmp(produits[j].nom,produits[ind].nom)==-1){
     	                     	ind=j;
                                 	   }
										}
								if(i!=ind){
									v= produits[i];
									 produits[i]=produits[ind];
     			                  	 produits[ind]=v;
			                          }
								}
								afficherProduits();
                                     
                    
							break;
						    case 3:
						    //tri par selectiom prix
				
                            
	                         for(i=0;i<nombreProduits-1;i++){
	                         	ind =i;
     	                     for(j=i+1;j<nombreProduits;j++){
     	                     if(produits[ind].prixHT<produits[j].prixHT){
     	                     	ind=j;
                                 	   }
										}
								if(i!=ind){
									v= produits[i];
									 produits[i]=produits[ind];
     			                  	 produits[ind]=v;
			                          }
								}
                                   afficherProduits();
							break;
                          case 4:
						sousTest=1;
							break;}
					}while(sousTest==0);
			
				break;
			case 4:
				system("cls");
				strcpy(codeR , " ");
				strcpy(dateN , " ");
				qteN=0;
				printf("Entrer le code du produit a recherche : ");
				scanf("%s",&codeR);
				printf("Enter la date d'aujourd'hui : ");
				scanf("%s",&dateN);
				printf("Enter la quantite achetee : ");
				scanf("%d",&qteN);
				
				acheterProduit(codeR,qteN,dateN);				
				break;
			case 5:
				system("cls");	
			    choix=0;
				sousTest=0;
				do{
					printf("1- Rechercher les produits Par Code \n");
					printf("2- Rechercher les produits Par Quantite \n");
					printf("3- Menu principale \n");
					printf("Saisir votre choix : ");
					scanf("%d",&choix);
						int QuantiteR;
					switch(choix){
						case 1:	
						strcpy(codeR , " ");
				printf("Entrer le code du produit : ");
				scanf("%s",&codeR);
				recherchecode(codeR);					
							break;
						case 2:
			     	
				printf("Entrer la Quantite du produit : ");
				scanf("%d",&QuantiteR);
				rechercheQuantite(QuantiteR);
							break;
						case 3:
							sousTest=1;
							break;
						default: 
							break;
					}
				}while(sousTest==0);
				
				break;
				break;
			case 6:
				system("cls");
				etatstock();
				break;
			case 7:
				system("cls");
				strcpy(codeR , " ");
				qteN=0;
				printf("Entrer le code du produit : ");
				scanf("%s",&codeR);
				printf("Entrer la quantite : ");
				scanf("%d",&qteN);
				alimenterStock(codeR,qteN);
				break;
			case 8:
				system("cls");
				strcpy(codeR , " ");
				printf("Entrer le code du produit a supprime : ");
				scanf("%s",&codeR);
				Supprimer(codeR);		
				break;
			case 9:

				printf("entrer la date \n");
				scanf("%s",&date);
				statistique(date);
				break;
			case 10:
				system("cls");
				test=1;
				printf("Fin Du Programme");
				break;
			default: 
				break;			
		}
	}while(test==0);
	return 0;
}
