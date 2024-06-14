#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "fonction.h"

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
