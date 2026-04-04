#include <stdio.h>
#include <stdlib.h>
struct Client{
    char nom[20];
    char prenom[20];
    int CIN;
    int Age;
};

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

void RecEva(FILE *reco){
    reco=fopen("recommendation.txt","r");
    char ch[1000];
    fgets(ch,1000,reco);
    printf("%s",ch);
    fclose(reco);
}

struct date{
   int j;
   int m;
   int an;
   int hr;
};

struct Reserv{
    int Numserv;
    struct date d;
};

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
            if (a%2==0 ){j=29;}
            else{j=28;}
    }
    if (n<1 || n>j){test=0;}
    return test;
}

void CreeReserv(){
    struct Reserv r;
    printf("Si vous souhaitez effectuer une reservation choisissez le numero de service souhaite. \n");
    scanf("%d",&r.Numserv);
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


void recom(){
    FILE *reco;
    char note[10];
    char cm[1000];
    printf("Nous serons heureux de connaitre votre avis \n");
    printf("Notez-nous sur 10 \n");
    scanf("%s",note);
    printf("Ecrivez-nous un commentaire\n");
    scanf("%s",cm);
    reco=fopen("recommendation.txt","a");
    fprintf(reco,note);
    fprintf(reco,"\n");
    fprintf(reco,cm);
    fprintf(reco,"\n");
    fclose(reco);
}

int main()
{   FILE *reco;
    int rep;
    struct Client c;
    printf("Bienvenue\n");
    printf("Etes-vous un nouveau cliente \n");
    printf("1-Oui \n");
    printf("2-Non \n");
    scanf("%d",&rep);
    if (rep==1){
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
        CreeReserv();
        recom();
    }

    return 0;
}
