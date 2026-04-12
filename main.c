//Projet salon de coiffure 
//Nourcenne Belhajhamida
//Zaineb Benhousine
//Nour Islem Rafrafi
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Enregistrement d'un client
struct Client{
    char nom[20];
    char prenom[20];
    int CIN;
    int Age;
};
//Menu de service
void Menu(){
        printf("Liste de services \n");
        printf("1-SERVISES DE COIFFURE\n");
        printf("11-Coupe de cheveux     10DT \n");
        printf("12-Coloration Complete  150DT \n");
        printf("13Meches               60DT \n");
        printf("14Lissage de keratine  35DT \n");
        printf("\n");
        printf("2-SERVICES D'ONGLES \n");
        printf("21Manucure Classique          15DT \n");
        printf("22Manucure gel                25DT \n");
        printf("23Pose d'ongles en acrylique  50DT \n");
        printf("\n");
        printf("3-SOINS DU VISAGE \n");
        printf("31Soin du visage base       100DT \n");
        printf("32Soin du visage anti-age   230DT \n");
        printf("\n");
        printf("4-MAQUILLAGE ET SOURCILS \n");
        printf("41Application de maquillage   80DT \n");
        printf("42Maquillage de mariee        100DT \n");
        printf("43Teinture de sourcils        90DT \n");
}
//Procedure affichage de recomendation
void RecEva(FILE *reco){
    reco=fopen("recommendation.txt","r");
    char ch[1000];
    fgets(ch,1000,reco);
    printf("%s",ch);
    fclose(reco);
}
//Enregistrement de reservation
struct date{
   int j;
   int m;
   int an;
   int hr;
};
struct Reserv{
    struct date d;
};
//Fonction verification d'un jour valide
int verifj(int n, int m, int a){
    int test=1;
    int j;
    switch (m){
        case 1:
            j=31;
            break;
        case 3:
            j=31;
            break;
        case 5:
            j=31;
            break;
        case 7:
            j=31;
            break;
        case 8:
            j=31;
            break;
        case 10:
            j=31;
            break;
        case 12:
            j=31;
            break;
        case 4:
            j=30;
            break;
        case 6:
            j=30;
            break;
        case 9:
            j=30;
            break;
        case 11:
            j=30;
            break;
        case 2:
            if ((a%4==0 && a%100!=0)){j=29;}
            else{j=28;}
    }
    if (n<1 || n>j){test=0;}
    return test;
}
//Procedure creation d'un reservation
void CreeReserv(){
    struct Reserv r;
    printf("La date de la reservation\n");
    do{printf("Mois\n");
    scanf("%d",&r.d.m);
    }while(r.d.m<1 || r.d.m>12);
    do{printf("Annee\n");
    scanf("%d",&r.d.an);
    }while(r.d.an<2026);
    do{printf("Jour\n");
    scanf("%d",&r.d.j);
    }while(verifj(r.d.j , r.d.m , r.d.an)==0);
    do{printf("Heure\n");
    scanf("%d",&r.d.hr);
    }while(r.d.hr<8 || r.d.hr>16);
}

//Procedure de saisie d'un recommendation
void recom(){
    FILE *reco;
    char note[10];
    char cm[1000];
    printf("Nous serons heureux de connaitre votre avis \n");
    printf("Notez-nous sur 10 \n");
    scanf("%s",note);
    printf("Ecrivez-nous un commentaire\n");
    scanf(" %[^\n]", cm);
    reco=fopen("recommendation.txt","a");
    fprintf(reco, "%s\n%s\n", note, cm);
    fclose(reco);
}
//Procedure ajoute un client dans un fichier Client.txt
void AjouteC(struct Client c,FILE *Client1){
    Client1=fopen("Client.txt","a");
    fprintf(Client1, "\n %s\n %s \n%d\n %d",c.nom,c.prenom,c.CIN,c.Age);
    fclose(Client1);
}
//Modification d'un reservation
void Modifres(){
    printf("Modifier la date \n");
    CreeReserv();
}
//enregistrement de pointage d'un employe
struct pointage{
    float HE;
    float HS;
    float S;
};
//Fonctions control de saisie pointage
float pentre(){
    float n;
    do{printf("Tapez l'heure d'entre\n");
    scanf("%f",&n);
    }while(n<8);
    return n;
}

float psortie(){
    float n;
    do{printf("Tapez l'heure de sortie\n");
    scanf("%f",&n);
    }while(n>17.15);
    return n;
}
//Calcule moyenne d'heure travailler
float moyenneh(float HE,float HS){
    float s=0;
    s=HS-HE;
    return s;
}
//Recherche s'il un client existe
int recher(int cin){
    FILE *f;
    struct Client c;
    int trouve=0;
    f=fopen("Client.txt","r");
    while(fscanf(f,"%s %s %d %d",c.nom,c.prenom,&c.CIN,&c.Age)!=EOF){
        if(c.CIN==cin){
            trouve=1;
            break;
        }
    }
    fclose(f);
    if(trouve==0){
        printf("Client non trouvé\n");
    }
    return trouve;

}

//Programme principale
int main()
{   FILE *Client1;
    FILE *reco;
    int rep;
    struct Client c;
    printf("______________________\n");
    printf("  GlowAndGo Salon\n");
    printf("______________________\n");
    printf("Bienvenue\n");
    int pp;
    printf("1-etes-vous un client\n ");
    printf("2-etes-vous un emplye\n");
    scanf("%d",&pp);
    //Si un Client
    if (pp==1){
        printf("Etes-vous un nouveau cliente \n");
        printf("1-Oui \n");
        printf("2-Non \n");
        scanf("%d",&rep);
        //Si un client nouveau
        if (rep==1){
            int Numserv;
            printf("Quel est ton nom \n");
            scanf("%s",c.nom);
            printf("Quel est ton prenom \n");
            scanf("%s",c.prenom);
            printf("Quel est ton CIN \n");
            scanf("%d",&c.CIN);
            printf("Quel est ton Age \n");
            scanf("%d",&c.Age);
            Menu();
            RecEva(reco);
            printf("Si vous souhaitez effectuer une reservation choisissez le numero de service souhaite. \n");
            scanf("%d",&Numserv);
            CreeReserv();
            recom();
            AjouteC(c,Client1);

        }//Si un client n'est pas nouveau
        else if (rep==2){
            int cin;
            printf("Entrez votre CIN\n");
            scanf("%d",&cin);
            if (recher(cin)==1){
                int op;
                printf("1-Modifier votre reservation\n");
                printf("2-Cree une nouvelle reservation\n");
                scanf("%d",&op);
                if (op==1){
                    Modifres();
                }
                else if (op==2){
                    int Numserv;
                    printf("Nous vous remercions de votre confidance, vous beneficiez d'une reduction de 25 pourcent sur votre prochain service.\n");
                    Menu();
                    printf("Si vous souhaitez effectuer une reservation choisissez le numero de service souhaite. \n");
                    scanf("%d",&Numserv);
                    RecEva(reco);
                    CreeReserv();
                    recom();
                }

            }
        }
    }//Si un employe
    else if (pp==2){
        char codeEm[100];
        do{printf("Tapez votre code securite\n");
        scanf("%s",codeEm);
        }while(codeEm=="GlowAndGo01");
        struct pointage p;
        p.HE=pentre();
        p.HS=psortie();
        p.S=moyenneh(p.HE,p.HS);
        printf("Somme d'heures travailler aujourd'hui %f\n",p.S);
    }

    return 0;
}
