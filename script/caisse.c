#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generer_valeur_a_payer() {
    srand(time(NULL));
    double valeur_a_payer = (rand() % 100000) / 100.0;
    return valeur_a_payer;
}
double valeur_a_payer = generer_valeur_a_payer();
double valeur_donnee;

do {
    printf("Valeur à payer: Rs%.2f\n", valeur_a_payer);
    printf("Entrez la valeur que vous voulez donner: ");
    scanf("%lf", &valeur_donnee);

    if (valeur_donnee < valeur_a_payer) {printf("La valeur donnée est insuffisante.\n");
    }
} while (valeur_donnee < valeur_a_payer);

