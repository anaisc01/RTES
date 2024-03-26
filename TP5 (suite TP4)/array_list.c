

#include <stdio.h>

int main() {
    int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(list) / sizeof(list[0]);
    int value = 7;
    int found = 0; // Indicateur pour savoir si la valeur a été trouvée

    for (int i = 0; i < size; i++) {
        if (list[i] == value) {
            printf("Valeur %d trouv%ce %c l'indice %d.\n", value, 130, 133, i);
            found = 1; // La valeur a été trouvée
            break; // Arrêter la boucle après avoir trouvé la valeur
        }
    }

    if (!found) {
        printf("Valeur %d non trouv%ce dans le tableau.\n", value, 130);
              /*
                   %c
                   130 = é
                   133 = à
                   138 = è
                   135 = ç
                   136 = ê
                   */
    }

    return 0;
}