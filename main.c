#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Activité OpenClassRoom : Amélioration Plus ou Moins.
Codé par Wargof - https://wargof.net
*/

int main() {
	printf("Bienvenue sur le jeu 'Le nombre mystère' !\n");
	// Choix difficulté
	int diff = 0, maxi = 0, on = 1;
	while(on == 1) {
		printf("Choississez une difficulté .. \n");
		printf("1. De 1 à 100\n");
		printf("2. De 1 à 1000\n");
		printf("3. De 1 à 10000\n");
		scanf("%d", &diff);
		switch(diff) {
			case 1:
				maxi = 100;
				break;
			case 2:
				maxi = 1000;
				break;
			case 3:
				maxi = 10000;
				break;
			default:
				printf("Choix incorrect !\n");
				break;
		}
		// Génération d'un nombre aléatoire entre 0 & 100
		srand(time(NULL));
		const int MIN = 1;
		int nombreMystere;
		nombreMystere = (rand() % (maxi - MIN + 1)) + MIN;
		// Fin de la génération du nombre aléatoire
		int saisie;
		int coups = 0;
		printf("Ce programme a généré un nombre aléatoire entre 1 et %d, devinez le ! \n", maxi);
		// Boucle
		while (saisie != nombreMystere) {
			printf("Quel est le nombre mystère ? \n");
			scanf("%d", &saisie);
			// Conditions
			if (saisie < nombreMystere) {
				printf("%d est inférieur au nombre mystère ! \n", saisie);
				coups++;
			}
			else if (saisie > nombreMystere) {
				printf("%d est supérieur au nombre mystère ! \n", saisie);
				coups++;
			}
			else if (saisie == nombreMystere) {
				printf("Bravo ! %d était bien le nombre mystère ! \n", saisie);
				printf("Le nombre mystère a été trouvé en %d coups ! \n\n", coups);
				do {
					printf("Voulez-vous rejouer ?\n");
					printf("Entrez 1 pour rejouer ou 0 pour quitter ..\n");
					scanf("%d", &on);
				} while(on != 0 && on !=1);
			}
			else {
				printf("Condition improbable .. \n");
			}
		}
	}

	return 0;
}