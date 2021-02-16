#include "biblio.h"


void init(T_Bibliotheque *ptrB)
{
ptrB->nbLivres=0;
}

int ajouterLivre(T_Bibliotheque  *ptrB)
{
if (ptrB->nbLivres<CAPACITE_BIBLIO)
	{
	saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
	ptrB->nbLivres++;
	return 1;
	}
return 0;
}


int afficherBibliotheque(const T_Bibliotheque  *ptrB) {
int i;
if(ptrB->nbLivres==0)
	return 0;
	else
		{
		for(i=0;i<ptrB->nbLivres;i++)
			{
      printf("%d- ",i);
			afficherLivre( &(ptrB->etagere[i])  );
			}
		return 1;
		}
}


int rechercherBibliotheque(T_Bibliotheque *ptrB)
{
int j, occurences=0;
char recherche[MAX];
if(ptrB->nbLivres==0)
{
	return 0;
}
	else
    {
    fgets(recherche, MAX, stdin);
    recherche[strlen(recherche)-1]='\0';
    for(j=0;j<ptrB->nbLivres;j++)
      {
        //printf("%d \n",(strcmp(recherche,(ptrB->etagere[j]).titre))); TEST DU STRCMP
        if (strcmp(recherche,(ptrB->etagere[j]).titre)==0)
          {
            printf("%d - ", j);
            afficherLivre( &(ptrB->etagere[j])  );
            occurences++;
          }
      }
      printf("Il y a %d",occurences);
      printf(" occurences \n");
      
    }
if (occurences==0) return 0;
    else return 1;
}

int rechercheAuteur(T_Bibliotheque *ptrB)
{
int j, occurences=0;
char recherche[MAX];
if(ptrB->nbLivres==0)
	return 0;
	else
    {
    fgets(recherche, MAX, stdin);
    recherche[strlen(recherche)-1]='\0';
    for(j=0;j<ptrB->nbLivres;j++)
      {
        //printf("%d \n",(strcmp(recherche,(ptrB->etagere[j]).auteur)));
        if (strcmp(recherche,(ptrB->etagere[j]).auteur)==0)
          {
            printf("%d - ", j);
            afficherLivre( &(ptrB->etagere[j])  );
            occurences++;
          }
        
      }
    if (occurences==0) return 0;
    else return 1;

    }

}


int supprimerLivre(T_Bibliotheque *ptrB, int pos)
{
  int i;

  if (ptrB->nbLivres==0 || pos<0 || pos>(ptrB->nbLivres))
  {
    return 0;
  }
  else 
  {
    enleverLivre(&(ptrB->etagere[pos]));
    for(i=pos;i<(ptrB->nbLivres)-1;i++)
    {
      (ptrB->etagere[i])=(ptrB->etagere[i+1]);
    }
    ptrB->nbLivres=ptrB->nbLivres-1;
    return 1;
  }
}




