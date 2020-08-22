#include "mainh.h"


int main()
{
    char lettre= 0;
    int coup = 10;
    char copiemot[50] = "";
    int i = 0 , a = 0 ;
    int identique = 88;
    int choix = 0 ;
    int nombreN = 0 ;
    int caractereActuel = 0 ;
    char motATrouver[50] = "";
    int nombreMystere = 0 ;
    int cpt = 0 , caractereLu = 0 ;
    int tailleC = 0 ;


    choix = menu();

    if(choix = 1)
    {
    FILE* fichier = NULL ;

    fichier = fopen("dico.txt" , "r");

   if(fichier != NULL)
   {
       do
       {
         caractereActuel = fgetc(fichier);
         if(caractereActuel == '\n')
            {
                nombreN++ ;
            }

       }while (caractereActuel != EOF);



       rewind(fichier);

        const int  MAX = nombreN , MIN = 1 ;
        srand(time(NULL));
        nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

        do
       {
         caractereLu = fgetc(fichier);
         if(caractereLu == '\n')
            {
                cpt++ ;
            }

       }while (cpt < nombreMystere);
        fgets(motATrouver,50,fichier);

        tailleC = strlen(motATrouver);
        i=0;

       for(i = 0 ; i<tailleC-1 ; i++)
       {
           copiemot[i] = '*' ;
       }
       copiemot[tailleC]='\0';
       motATrouver[tailleC-1]= '\0';


   }
    fclose(fichier);
    }

    if(choix = 1 )
    {
        coup = 10;
        while (getchar() != '\n') ; // clean buffer menu()

    do
    {
        // on remmet a 0 les variables modifiées plus bas
        i = 0 ;
        a= 1 ;
        system("cls");
        pendu(coup);

        printf("\nIl vous reste %d coups a jouer.\n",coup);
        printf("Le mot secret est %s\n", copiemot);
        printf("Proposez une lettre :  ");
        lettre = lireCaractere(); // fonction clean buffer + scanf

        for(i = 0 ; i < tailleC ; i++)
        {
            if(motATrouver[i] == lettre) // on vérifie si si la lettre est presente dans le mot a trouver
            {
                copiemot[i] = lettre;  // on la copie dans le mot affiché a l'ecran
                a = 0 ; // booléen pour ne pas faire descendre les coups si lettre touver
            }
        }

        if(a == 1)
        {
         coup-- ;
        }
        if(coup == 0 )
        {

            system("cls");
            pendu(coup);
            printf("\nIl vous reste %d coup a jouer.\n",coup);
            printf("Le mot secret est %s\n", motATrouver);
            loose(); // message de defaite plus retour menu
        }

        identique = strcmp(motATrouver , copiemot); // fonction string.h qui compare les deux tab et renvoie 0 si identique

    }while(identique!= 0 ); // si les deux chaines sont indentiques partie gagnéesystem("cls");
    system("cls");
    pendu(coup);
    printf("\nIl vous reste %d coup a jouer.\n",coup);
    printf("Le mot secret est %s\n", motATrouver);
    win(); // message de victoire plus retour menu

    }

    return 0;
}
