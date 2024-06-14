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
