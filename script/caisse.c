#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generer_valeur_a_payer() {
    srand(time(NULL));
    double valeur_a_payer = (rand() % 100000) / 100.0;
    return valeur_a_payer;
}

void rendre_monnaie(double* monnaie_a_rendre) {
    int billets[] = {2000, 1000, 500, 200, 100, 50, 25};
    int pieces[] = {20, 10, 5, 1};
    int nb_billets = sizeof(billets) / sizeof(billets[0]);
    int nb_pieces = sizeof(pieces) / sizeof(pieces[0]);

    for (int i = 0; i < nb_billets; i++) {
        if (*monnaie_a_rendre >= billets[i]) {
            int nb_billets_a_rendre = *monnaie_a_rendre / billets[i];
            *monnaie_a_rendre -= nb_billets_a_rendre * billets[i];
            printf("Billets de Rs%d: %d\n", billets[i], nb_billets_a_rendre);
        }
    }
for (int i = 0; i < nb_pieces; i++) {
        if (*monnaie_a_rendre >= pieces[i]) {
            int nb_pieces_a_rendre = *monnaie_a_rendre / pieces[i];
            *monnaie_a_rendre -= nb_pieces_a_rendre * pieces[i];
            printf("Pièces de Rs%d: %d\n", pieces[i], nb_pieces_a_rendre);
        }
    }
}

#define NB_BILLETS 7
#define NB_PIECES 4

int stocks_billets[NB_BILLETS] = {100, 100, 100, 100, 100, 100, 100};
int stocks_pieces[NB_PIECES] = {100, 100, 100, 100};

int main() {
    double valeur_a_payer, valeur_donnee;
    int fin_de_stock = 0;

    valeur_a_payer = generer_valeur_a_payer();

    do {
        printf("Valeur à payer: Rs%.2f\n", valeur_a_payer);
        printf("Entrez la valeur que vous voulez donner: ");
        scanf("%lf", &valeur_donnee);
 if (valeur_donnee < valeur_a_payer) {
            printf("La valeur donnée est insuffisante.\n");
        }

    } while (valeur_donnee < valeur_a_payer);

    double monnaie_a_rendre = valeur_donnee - valeur_a_payer;
    rendre_monnaie(&monnaie_a_rendre);

    // vérifier les stocks de billets
    for (int i = 0; i < NB_BILLETS; i++) {
        if (stocks_billets[i] == 0) {
            fin_de_stock = 1;
            break;
        }
    }

    // vérifier les stocks de pièces
    for (int i = 0; i < NB_PIECES; i++) {
        if (stocks_pieces[i] == 0) {
            fin_de_stock = 1;
            break;
        }
    }

    if (fin_de_stock) {
printf("La caisse est vide, vous ne pouvez plus faire de transactions.\n");
        return 1;
    }

    return 0;
}

