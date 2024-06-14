#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// represente un agent
typedef struct Agent{
    int id;
    char pseudo[50];
    char mdp[50];
}Agent;
// la structure qui sert a representer un compte
typedef struct Compte{
    long long int id;
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
    long long int idCpt;
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
// int verifCompte(Compte cmpt){


// cette fonction return le nombre de comptes crees  par jour , par un agent
// int nombreCompte(Agent agent){
// }

long long int dernierIdCmpt(){
    FILE *fichier = fopen("compte.txt", "r");
    long long int valretour;
    if(fichier == NULL){
        printf("Erreur d'ouverture\n");
        exit(0);
    }

    char id[50], solde[50], idagent[50];

    while(1){
        if(fscanf(fichier,"%s %s %s",id, solde, idagent) == EOF)
            break;
    }
    
    fclose(fichier);
    valretour = atoll(id);
    
    return valretour;
}

//permet de creer un compte bancaire
void createCompte(Personne *pers, int idagent){

    //ouverture en mode ecriture sans ecraser les anciennes donnees
    FILE *fichierPersonne = fopen("personne.txt", "a+");
    FILE *fichierCompte = fopen("compte.txt", "a+");

    if(fichierPersonne == NULL || fichierCompte == NULL){
        printf("Erreur d'ouverture\n");
        exit(0);
    }

    Compte cpt;

    cpt.id = dernierIdCmpt() + 1;
    cpt.solde = 5;
    cpt.idagent = idagent;

    // attribution du compte au user
    pers->idCpt = cpt.id;

    //Enregistrement des de la personne et du compte
    char idCmp[14];
    char soldeCompte[50];
    char idAg[50];

    //conversion des entiers en chaine de caratere
    sprintf(idAg, "%d", cpt.idagent);
    sprintf(idCmp, "%lld", pers->idCpt);
    sprintf(soldeCompte, "%d", cpt.solde);

    //insersion des fichier
    fprintf(fichierCompte, "%s %s %s\n", idCmp, soldeCompte, idAg);
    fprintf(fichierPersonne, "%s %s %s %s %s %s %s %s\n", pers->nom, pers->postnom, pers->prenom, pers->datenaiss, pers->pays, pers->numtel, pers->addresse, idCmp);

    fclose(fichierCompte);
    fclose(fichierPersonne);
}

//ca permet de faire un dépot bancaire
void depot(char idCpt[14], int montant){
    FILE * fichiercompte = fopen("compte.txt", "r+");
    FILE * fichiertemp = fopen("temp.txt", "a+");

    if(fichiercompte == NULL || fichiertemp == NULL){
        printf("erreur d'ouverure\n");
        exit(0);
    }
    char ligne[100];
    char id[14];
    char solde[100];
    char idAg[50];

    //fgets  Lire le contenu du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichiercompte)){
        

        sscanf(ligne, "%s %s %s", id, solde, idAg);

        if(strcmp(idCpt, id) == 0){
            int sold = atoi(solde);
            montant += sold;

            sprintf(solde, "%d", montant);

        }

        fprintf(fichiertemp, "%s %s %s\n", id, solde,idAg);  
    }
    
    fclose(fichiertemp);
    fclose(fichiercompte);
    // supprimer l'ancien fichier et renommer le fichier temporaire
    remove("compte.txt");
    rename("temp.txt", "compte.txt");

}

// permet de faire un retrait d'argent
void retrait(char idCpt[14], int montant){
    FILE * fichiercompte = fopen("compte.txt", "r+");
    FILE * fichiertemp = fopen("temp.txt", "a+");

    if(fichiercompte == NULL || fichiertemp == NULL){
        printf("erreur d'ouverure\n");
        exit(0);
    }
    char ligne[100];
    char id[14];
    char solde[100];
    char idAg[50];

    //fgets  Lire le contenu du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichiercompte)){
        
        sscanf(ligne, "%s %s %s", id, solde, idAg);

        if(strcmp(idCpt, id) == 0){
            int sold = atoi(solde);
            int nvmontant;
            nvmontant = sold - montant;
            
            if(nvmontant >= 5){
                sprintf(solde, "%d", nvmontant);
            }
            else{
                puts("compte insuffisant");
                exit(0);
            }     
        }

        fprintf(fichiertemp, "%s %s %s\n", id, solde,idAg);  
    }
    
    fclose(fichiertemp);
    fclose(fichiercompte);
    // supprimer l'ancien fichier et renommer le fichier temporaire
    remove("compte.txt");
    rename("temp.txt", "compte.txt");

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
        
        int montant;
        char compte[14];

        while(choix != 4){
            if(choix == 1 ){
                Personne p;

                // reccuperation des informations de la personne
                printf("entrez le nom de la personne : ");
                scanf("%s", p.nom);
                printf("quel est votre postnom : ");
                scanf("%s", p.postnom);
                printf("quel est votre prenom : ");
                scanf("%s", p.prenom);
                printf("quel est votre date de naissance : ");
                scanf("%s", p.datenaiss);
                printf("quel est votre addresse actuelle : ");
                scanf("%s", p.addresse);
                printf("quel est votre pays : ");
                scanf("%s", p.pays);
                printf("quel est votre numero de telephone : ");
                scanf("%s",p.numtel);

                createCompte(&p, 1);
                system("cls");
                puts("***************compte cree avec succes***********");   

            }
            else if(choix == 2 ){
               
               printf("entrez le numero de compte : ");
               scanf("%ld", compte);

               // controle de sasie
               while(strlen(compte) != 14){
                    printf("numero du compte invalide recommencer : ");
                    scanf("%s", compte);
               }
               
               printf("entrez le montant : ");
               scanf("%d", &montant);

               depot(compte, montant);

               system("cls");
               puts("*********** depot effectue avec succes ******************");

            }
            else if(choix == 3 ){
               printf("entrez le numero du compte");
               scanf("%ld", compte);
               printf("entrez le montant : ");
               scanf("%d", &montant);
               retrait(compte, montant);

                system("cls");
               puts("*********** retrait effectue avec succes ******************");

               
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
