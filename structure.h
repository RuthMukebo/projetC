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

