/* LE JEU DU NEUTRON */

# include <stdio.h>
# define NBLIG 5
# define NBCOL 5

# define PION_BLEU '+'//représentation choisie pour les pions bleus
# define PION_ROUGE '-'//représentation choisie pour les pions rouges
# define NEUTRON '*'//représentation choisie pour le neutron
# define VIDE 'o'//représentation choisie pour les cases vides

# define VRAI 1
# define FAUX 0

# define reset "\033[0m"
# define reverse "\033[7m"

# define rouge "\033[;31m"
# define vert "\033[;32m"
# define bleu "\033[;34m"

void initialisation (char M[][NBCOL]){
    int i,j; //indices de parcours du tableau

    /* Parcours du damier */
    for (j=0;j<NBCOL;j++){
        M[0][j]=PION_BLEU; //mise en place des pions bleus
        for (i=1;i<NBLIG-1;i++){
            M[i][j]=VIDE; //mise en place des cases vides
        }
        M[4][j]=PION_ROUGE; //mise en place des pions rouges
    }
    M[2][2]=NEUTRON; //mise en place du neutron
}

void affichage_plateau_couleurs(char M[][NBCOL]){
    int i,j; //indices de parcours du tableau

    printf("-------- JEU DU NEUTRON --------\n\n");

    /* Parcours du damier */
    for (i=0;i<5;i++){
        printf("     +---+---+---+---+---+\n");
        printf("%4d",5-i);
        for (j=0;j<5;j++){
            if (M[i][j]==PION_BLEU){
                printf(" | %s%s %s",rouge,reverse,reset);
            }
            else if (M[i][j]==PION_ROUGE){
                printf(" | %s%s %s",bleu,reverse,reset);
            }
            else if (M[i][j]==NEUTRON){
                printf(" | %s%s %s",vert,reverse,reset);
            }
            else if (M[i][j]==VIDE){
                printf(" |  ");
            }
        }
        printf(" |\n");
    }
    printf("     +---+---+---+---+---+\n    ");
    for (j=1;j<=5;j++){
        printf("%4d",j);
    }
    printf("\n");
}

void deplacement (char M[][NBCOL],int indlig,int indcol,int dir){
    int i,j; //indices de parcours du tableau

    /* Conversion de indlig et indcol par rapport à la matrice*/
    indlig=5-indlig;
    indcol=indcol-1;

    /* Quel déplacement ? */

    if (dir==1){
        i=indlig-1;
        
        /* Parcours des cases dans la direction 1 jusqu’à l’obstacle */
        while ((i>=0) && (M[i][indcol]==VIDE)){
            i--;
        }
        i++; //on récupère l'indice de la case avant le vide
        if (i!=indlig){
            M[i][indcol]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }

 else if (dir==2){
        i=indlig-1;
        j=indcol+1;
        /* Parcours des cases dans la direction 2 jusqu’à l’obstacle */
        while ((i>=0) && (j<5) && (M[i][j]==VIDE)){
            i--;
            j++;
        }
        /*on récupère l'indice de la case avant le vide*/
        i++;
        j--;
        /* déplacement possible ? */
        if ((i!=indlig) && (j!=indcol)){
            M[i][j]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }

    else if (dir==3){
        j=indcol+1;
        /* Parcours des cases dans la direction 3 jusqu’à l’obstacle */
        while ((j<5) && (M[indlig][j]==VIDE)){
            j++;
        }
        j--; //on récupère l'indice de la case avant le vide
        /* déplacement possible ? */
        if (j!=indcol){
            M[indlig][j]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }

     else if (dir==4){
        i=indlig+1;
        j=indcol+1;
        /* Parcours des cases dans la direction 7 jusqu’à l’obstacle */
        while ((i<5) && (j<5) && (M[i][j]==VIDE)){
            i++;
            j++;
        }
        /*on récupère l'indice de la case avant le vide*/
        i--;
        j--;
        /* déplacement possible ? */
        if ((i!=indlig) && (j!=indcol)){
            M[i][j]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }

    else if (dir==5){
        i=indlig+1;
        /* Parcours des cases dans la direction 5 jusqu’à l’obstacle */
        while ((i<5) && (M[i][indcol]==VIDE)){
            i++;
        }
        i--;//on récupère l'indice de la case avant le vide
        /* déplacement possible ? */
        if ((i!=indlig)){
            M[i][indcol]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }

   else if (dir==6)    {
        i=indlig+1;
        j=indcol-1;
        /* Parcours des cases dans la direction 6 jusqu’à l’obstacle */
        while ((i<5) && (j>=0) && (M[i][j]==VIDE)){
            i++;
            j--;
        }
        /*on récupère l'indice de la case avant le vide*/
        i--;
        j++;
        /* déplacement possible ? */
        if ((i!=indlig) && (j!=indcol)){
            M[i][j]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }


   else if (dir==7){
        j=indcol-1;
        /* Parcours des cases dans la direction 7 jusqu’à l’obstacle */
        while ((j>=0) && (M[indlig][j]==VIDE)){
            j--;
        }
        j++;//on récupère l'indice de la case avant le vide
        /* déplacement possible ? */
        if (j!=indcol){
            M[indlig][j]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }

    else if (dir==8){
        i=indlig-1;
        j=indcol-1;
        /* Parcours des cases dans la direction 6 jusqu’à l’obstacle */
        while ((i>=0) && (j>=0) && (M[i][j]==VIDE)){
            i--;
            j--;
        }
        /*on récupère l'indice de la case avant le vide*/
        i++;
        j++;
        /* déplacement possible ? */
        if ((i!=indlig) && (j!=indcol)){
            M[i][j]=M[indlig][indcol];
            M[indlig][indcol]=VIDE;
        }
    }
}

void position_neutron (char M[][NBCOL],int* indlig,int* indcol){
    int trouve;

    /* Initialisation */
    trouve=FAUX;
    *indlig=0;

    /* Parcours du damier à la recherche du neutron*/
    while ((*indlig<5)&&(trouve==FAUX)){
        *indcol=0;
        while ((*indcol<5)&&(trouve==FAUX)){
            if (M[*indlig][*indcol]!=NEUTRON){
                (*indcol)++;
            }
            else{
                trouve=VRAI;
            }
        }
        (*indlig)++;
    }

    /* Conversion des coordonées de la matrice */
    (*indlig)=6-(*indlig);
    (*indcol)=(*indcol+1);
}

int test_deplacement (char M[][NBCOL],int indlig,int indcol){
int i,j; //indices de parcours du tableau
int dir; //nombre correspondant à la direction de déplacement
int compteur; //total de cases voisines vides

    /* Conversion des coordonées */
    indlig=5-indlig;
    indcol=indcol-1;

    /* Initialisation */
    compteur=0;

    /* Parcours des cases voisines */
    for (dir=1;dir<=8;dir++){
        if (dir==1){
            i=indlig-1; //coordonnées de la case voisine dans la direction 1
            /* case voisine innoccupée ? */
            if ((i>=0)&&(M[i][indcol]==VIDE)){
                compteur++;
            }
        }
        else if (dir==2){
            /* coordonnées de la case voisine dans la direction 2 */
            i=indlig-1;
            j=indcol+1;
            /* case voisine innoccupée ? */
            if ((i>=0)&&(j<5)&&(M[i][j]==VIDE)){
                compteur++;
            }
        }
        else if (dir==3){
            j=indcol+1; //coordonnées de la case voisine dans la direction 3
            /* case voisine innoccupée ? */
            if ((j<5)&&(M[indlig][j]==VIDE))
            {
                compteur++;
            }
        }
        else if (dir==4){
            /* coordonnées de la case voisine dans la direction 4 */
            i=indlig+1;
            j=indcol+1;
            /* case voisine innoccupée ? */
            if ((i<5)&&(j<5)&&(M[i][j]==VIDE)){
                compteur++;
            }
        }
        else if (dir==5){
            i=indlig+1; //coordonnées de la case voisine dans la direction 5
            /* case voisine innoccupée ? */
            if ((i<5)&&(M[i][indcol]==VIDE)){
                compteur++;
            }
        }

        else if (dir==6){
            /* coordonnées de la case voisine dans la direction 6 */
            i=indlig+1;
            j=indcol-1;
            /* case voisine innoccupée ? */
            if ((i<5)&&(j>=0)&&(M[i][j]==VIDE)){
                compteur++;
            }
        }

        else if (dir==7){
            j=indcol-1; //coordonnées de la case voisine dans la direction 7
            /* case voisine innoccupée ? */
            if ((j>=0)&&(M[indlig][j]==VIDE)){
                compteur++;
            }
        }

        else if (dir==8){
            /* coordonnées de la case voisine dans la direction 8 */
            i=indlig-1;
            j=indcol-1;
            /* case voisine innoccupée ? */
            if ((i>=0)&&(j>=0)&&(M[i][j]==VIDE)){
                compteur++;
            }
        }
    }
    return(compteur>0); //si nombre de voisins>0 déplacement possible
}

int perdu(char M[][NBCOL], char pion){
    int i,j; // indices de parcours
    int entoure; // indique si le pion est entouré

    /* Initialisation */
    i=0;
    entoure=VRAI;

    /* Parcours du damier */
    while((i<5)&&(entoure)){
        j=0;
        while((j<5)&&(entoure)){
            /* Pion entouré ? */
            if((M[i][j]==pion)&&(test_deplacement(M, (5-i), (j+1))==VRAI)){ // si le pion n'est pas entouré et si le pions correspond au joueur concerné
                entoure=FAUX;
            }
            else{
                j++;
            }
        }
        i++;
    }
   return(entoure);
}

void lecture_pion(int *indlig, int *indcol){

    printf("Veuillez entrer les coordonnées du pion à déplacer sous la forme i,j :\n");
    scanf("%d,%d",indlig, indcol);

    /*lorsque les coordonnées du pion indlig, indcol sont incorrectes*/
    while((*indlig<=0)||(*indlig>5)||(*indcol<=0)||(*indcol>5)){
        printf("Les coordonnées ne sont pas valides\n");
        printf("Veuillez entrer les coordonnées du pion à déplacer sous la forme i,j :\n");
        scanf("%d,%d",indlig, indcol);
    }
}

void lecture_direction(int *dir){
    printf("Veuillez entrer la direction du déplacement :\n");
    scanf("%d",dir);
    while((*dir<1)||(*dir>8)){
        printf("Veuillez entrer une direction valide (entre 1 et 8) pour le déplacement :\n");
        scanf("%d",dir);
    }
}
    
 int main (){
    char M[NBLIG][NBCOL]; // tablau représentant le plateau de jeu
    int indlig,indcol; // indices de ligne et de colonne
    int dir; // chiffre correspondant à la direction
    int i,j;//indices de position du neutron
    int tour;//numéro du tour au fil du jeu

    /* Initialisation */
    initialisation(M);
    affichage_plateau_couleurs(M);

    /*Début du jeu : les bleus déplacent leur pion*/
    tour =0;
    printf("C'est au joueur bleu de commencer !\n");
    lecture_pion(&indlig,&indcol);
    
    while ((M[5-indlig][indcol-1]==PION_BLEU)||(M[5-indlig][indcol-1]==VIDE)){
        printf("Ce pion ne peut pas être déplacé !\n");
        lecture_pion(&indlig,&indcol);
    }
    
    lecture_direction(&dir);
    deplacement(M,1,indcol,dir);
    affichage_plateau_couleurs(M);
    tour++;

    /* Poursuite du jeu, avec alternativement les rouges et les bleus qui jouent
    et ceci tant que le neutron n'est pas dans un des camps, que les pions des joueurs ne sont pas bloqués et que le neutron n'est pas bloqué*/
    while ((i!=1)&&((i!=5)&&(perdu(M,PION_BLEU)==FAUX)&&(perdu(M,PION_ROUGE)==FAUX)&&(perdu(M,NEUTRON)==FAUX))){
        /* Les ROUGES jouent */
        if (tour%2 != 0){
            printf("C'est au joueur rouge de jouer !\n");

            /*Déplacement du Neutron*/
            position_neutron(M,&i,&j);
            lecture_direction(&dir);
            deplacement (M,i,j,dir);
            affichage_plateau_couleurs(M);
            position_neutron(M, &i, &j);

            if (i==5){//Le neutron est dans son camp
                printf("Le joueur rouge a gagné !\n");
            }
            else if(i==1){//Le joueur rouge a mis le neutron dans le camp bleu
                printf("Le joueur bleu a gagné !\n");
            }
            else{
                /*Déplacement du Pion*/
                lecture_pion(&indlig,&indcol);
            
                while ((M[5-indlig][indcol-1]==PION_ROUGE)||(M[5-indlig][indcol-1]==VIDE)){
                    printf("Ce pion ne peut pas être déplacé !\n");
                    lecture_pion(&indlig,&indcol);
                }
                lecture_direction(&dir);
                deplacement (M,indlig,indcol,dir);
                affichage_plateau_couleurs(M);
           }
        }

        /* Les BLEUS jouent */
        else{
            if (tour%2 == 0){
                printf("C'est au joueur bleu de jouer !\n");

                /* Déplacement du Neutron */
                position_neutron(M,&i,&j);
                lecture_direction(&dir);
                deplacement (M,i,j,dir);
                affichage_plateau_couleurs(M);
                position_neutron(M, &i, &j);
                
                if (i==1){////Le joueur bleu a mis le neutron dans son camp
                    printf("Le joueur bleu a gagné ! \n");
                }
                else if(i==5){//Le joueur bleu a mis le neutron dans le camp rouge
                    printf("Le joueur rouge a gagné !\n");
                }
                else{
                    /* Déplacement du Pion */
                    lecture_pion(&indlig,&indcol);
                    
                    while ((M[5-indlig][indcol-1]==PION_BLEU)||(M[5-indlig][indcol-1]==VIDE)){
                        printf("Ce pion ne peut pas être déplacé !\n");
                        lecture_pion(&indlig,&indcol);
                    }
                
                    lecture_direction(&dir);
                    deplacement (M,indlig,indcol,dir);
                    affichage_plateau_couleurs(M);
                }
            }
        }
        tour++;
    }

    /* Test sur la fin de partie : neutron bloqué, pions bloqués */
    if (perdu(M,NEUTRON)){
        printf("Gagné ! Le neutron est bloqué\n");
    }
    else if (perdu(M,PION_ROUGE)){
            printf("Perdu ! Les pions du joueur bleu ne peuvent pas être déplacés\n");
    }
    else if(perdu(M,PION_BLEU)){
            printf("Perdu ! Les pions du joueur rouge ne peuvent pas être déplacés\n");
    }
return 0;
}
