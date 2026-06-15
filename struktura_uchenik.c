#include <stdio.h>
#include <string.h>

#define BROJ_OCENKI 4
#define MIN_OCENKA 2
#define MAX_OCENKA 6

typedef struct {
    int nomer_v_klasa;
    int godishni_ocenki[BROJ_OCENKI];
    float sreden_uspeh;
    char ime[40];
} Uchenik;

int main(void) {
    Uchenik u;
    int i;
    int suma = 0;

    u.nomer_v_klasa = 12;
    strcpy(u.ime, "Maria");

    u.godishni_ocenki[0] = 5;
    u.godishni_ocenki[1] = 6;
    u.godishni_ocenki[2] = 5;
    u.godishni_ocenki[3] = 6;

    for (i = 0; i < BROJ_OCENKI; i++) {
        int o = u.godishni_ocenki[i];
        if (o < MIN_OCENKA || o > MAX_OCENKA) {
            printf("Greshka: vsichki ocenki trqbva da sa mejdu %d i %d.\n", MIN_OCENKA, MAX_OCENKA);
            return 1;
        }
        suma += o;
    }
    u.sreden_uspeh = (float)suma / BROJ_OCENKI;

    printf("Ime: %s\n", u.ime);
    printf("Nomer v klasa: %d\n", u.nomer_v_klasa);
    printf("Godishni ocenki: ");
    for (i = 0; i < BROJ_OCENKI; i++) {
        printf("%d ", u.godishni_ocenki[i]);
    }
    printf("\nSreden uspeh: %.2f\n", u.sreden_uspeh);

    return 0;
}
