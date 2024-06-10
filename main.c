#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// represente un agent
typedef struct Agent{
    int id;
    char pseudo[50];
    char mdp[50];
}Agent;
// la structure qui sert à répresenter un compte
typedef struct Compte{
    int id;
    int solde;
    char datecreat[50];
    int idagent;
} Compte;

// structure qui permettra à creer un client(personne)
typedef struct Personne{
    int id;
    char nom[50];
    char postnom[50];
    char prenom[50];
    char datenaiss[50];
    char pays[50];
    char numtel[50];
    char addresse[50];
    Compte cpt;
} Personne;

int authentification(Agent agent){
    FILE *fichier = fopen("agent.txt", "r");

    if(fichier == NULL){
        printf("Erreur d'ouverture\n");
        return 1;
    }

    char id[50], pseudo[50], mdp[50];

    while(fscanf(fichier,"%s %s %s",id, pseudo, mdp) != EOF){
        if(strcmp(agent.pseudo, pseudo) == 0 && strcmp(agent.mdp, mdp) == 0)
            return 0;
    }
    return 1;
}
// cette fonction verifie si un compte existe
int verifCompte(Compte cmpt){
}

// verifie si le montant entré correspond ou > au montant existant ds le solde
int verifSuffisance(Compte cmpt, int montant){
    if((cmpt.solde - montant) >= 5)
        return 1;
    return 0;
}

 // cette fonction return le nombre de comptes par jour , par un agent
 int nombreCompte(Agent agent){

 }

//permet de creer un compte bancaire
void createCompte(Personne *pers, int idagent){
    // creation du compte

    Compte cpt;

    // attribution du compte à user
    pers->cpt = cpt;
}

//ca permet de faire un dépot bancaire
void depot(){

}

// permet de faire un retrait d'argent
 void retrait(){
 }

int main(){
    int choix;
    Agent agent;

    printf("pseudo: ");
    scanf("%s", agent.pseudo);
    printf("mot de passe : ");
    scanf("%s", agent.mdp);

    if(authentification(agent) == 0){
        printf("MENU\n");
        printf("=====\n");
        printf("(1)creer un compte\n");
        printf("(2)depot\n");
        printf("(3)retrait\n");
        printf("(4)quitter\n");
        printf("=>");
        scanf("%d", &choix);

        while(choix != 4){
            if(choix == 1 ){
                Personne p;

                // reccuperation des informations de la personne
                printf("entrez le nom de la personne : ");
                scanf("%s", p.nom);
                printf("quel est votre postnom");
                scanf("%s", p.postnom);
                printf("quel est votre prenom");
                scanf("%s", p.prenom);
                printf("quel est votre date de naissance");
                scanf("%s", p.datenaiss);
                printf("quel est votre addresse actuelle");
                scanf("%s", p.addresse);
                printf("quel est votre pays");
                scanf("%s", p.pays);
                printf("quel est votre numero de telephone");
                scanf("%s",p.numtel);



            }
            else if(choix == 2 ){
               printf("depot");
            }
            else if(choix == 3 ){
               printf("retrait");
            }

            printf("MENU\n");
            printf("=====\n");
            printf("(1)creer un compte\n");
            printf("(2)depot\n");
            printf("(3)retrait\n");
            printf("(4)quitter\n");
            printf("=>");
            scanf("%d", &choix);
        }
    }
    else
        printf("authentification echouee\n");



    printf("*******************FIN DU PROGRAMME************************");

    return 0;
}
