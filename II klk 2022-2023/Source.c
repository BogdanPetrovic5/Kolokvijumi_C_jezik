#include <stdio.h>
void ucitaj_matricu(int matrica[][20], int red, int kolona){
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
	printf("\n");
}
void stampaj_matricu(int matrica[][20], int red,int kolona) {
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int broj_ne_nula(int poslednji_red[], int kolona, int poz_k) {
	int razliciti_od_nule = 0;
	for (int i = poz_k; i < kolona; i++) {
		if (poslednji_red[i] != 0) {
			razliciti_od_nule += 1;
		}
	}
	
	return razliciti_od_nule;
}
int proveri_polje(int polje) {
	if (polje == 1) return 1;
	else return 0;
}
void prebroji_mine(int matrica[][20], int raspored_mina[][20], int red, int kolona) {
	int kolona_mina = 0;
	int broj_mina = 0;
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			raspored_mina[i][j] = 0;
		}
	}
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			if ((i != 0 && i != red - 1) && (j != 0 && j != kolona - 1)) {
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j+1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j-1] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i+1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i+1][j+1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i+1][j-1] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i - 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				
			}
			if (i == 0 && j == 0) {
				if (matrica[i][j+1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i+1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i+1][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
			}
			if ((i == red - 1) && (j == kolona - 1)) {
				if (matrica[i][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}
			}

			if ((i == red - 1) && (j == 0)) {
				if (matrica[i][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
			}

			if ((i == 0) && (j < kolona - 1 && j > 0)) {
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i + 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i + 1][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i + 1][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				

			}
			if ((i == red - 1) && (j < kolona - 1 && j > 0)) {
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}

			}
			if ((i != 0 && i != red - 1) && j == 0) {
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j+1] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i+1][j] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i + 1][j+1] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i - 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j + 1] == 1) {
					raspored_mina[i][j] += 1;
				}
			}

			if ((i != 0 && i != red - 1) && j == kolona - 1) {
				if (matrica[i][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i + 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i + 1][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}

				if (matrica[i - 1][j] == 1) {
					raspored_mina[i][j] += 1;
				}
				if (matrica[i - 1][j - 1] == 1) {
					raspored_mina[i][j] += 1;
				}
			}
			
			
		}
	}
}
int main() {
	int matrica[20][20];
	int red, kolona;
	int poz_k;
	printf("Ucitaj duzinu reda: ");
	scanf("%d", &red);
	printf("Ucitaj duzinu kolona: ");
	scanf("%d", &kolona);

	ucitaj_matricu(matrica, red, kolona);
	stampaj_matricu(matrica, red, kolona);
	printf("Ucitaj poziciju K: ");
	scanf("%d", &poz_k);

	int razliciti_od_nule = broj_ne_nula(matrica[red - 1], kolona, poz_k);
	printf("Razliciti od nule: %d", razliciti_od_nule);
	printf("\n");
	int polje = 0;
	int sredina_matrice = 0;
	int mina = 0;
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			polje = matrica[i][j];
			mina = proveri_polje(polje);
			if (i == ((red - 1) / 2) && j == ((kolona - 1) / 2)) {
				if (mina == 1) {
					sredina_matrice = 1;
				}
			}
		}
		
	}
	printf("\n");
	if (sredina_matrice == 1) {
		printf("Na sredini matrice se nalazi mina!");
	}else printf("Na sredini matrice se NE nalazi mina!");
	printf("\n");
	int raspored_mina[20][20];
	prebroji_mine(matrica, raspored_mina, red, kolona);
	printf("Raspored mina: \n");
	stampaj_matricu(raspored_mina, red, kolona);

	int pozicija_1;
	int pozicija_2;
	printf("\n");
	printf("Unesi poziciju 1: ");
	scanf("%d", &pozicija_1);
	printf("Unesi poziciju 2: ");
	scanf("%d", &pozicija_2);
	polje = matrica[pozicija_1][pozicija_2];
	mina = proveri_polje(polje);
	if (mina == 1) {
		printf("Kraj igre!");
		mina = 2;
	}
	int niz_kolona[20];
	int broj_mina_red = broj_ne_nula(raspored_mina[pozicija_1], kolona, pozicija_2 + 1);
	//Za kolone...
	for (int i = pozicija_2; i < kolona; i++) {
		for (int j = 0; j < red; j++) {
			niz_kolona[j] = raspored_mina[j][i];
		}
		break;
	}
	int broj_mina_kolona = broj_ne_nula(niz_kolona, red, pozicija_1 + 1);
	
	while (mina < 1) {
		printf("%d %d \n", broj_mina_red, broj_mina_kolona);

		printf("Unesi poziciju 1: ");
		scanf("%d", &pozicija_1);
		printf("Unesi poziciju 2: ");
		scanf("%d", &pozicija_2);
		polje = matrica[pozicija_1][pozicija_2];
		mina = proveri_polje(polje);
		broj_mina_red = broj_ne_nula(raspored_mina[pozicija_1], kolona, pozicija_2 + 1);
		//Za kolone...
		for (int i = pozicija_2; i < kolona; i++) {
			for (int j = 0; j < red; j++) {
				niz_kolona[j] = raspored_mina[j][i];
			}
			break;
		}
		broj_mina_kolona = broj_ne_nula(niz_kolona, red, pozicija_1 + 1);
	}
	if (mina == 1) {
		printf("Kraj igre!");
	}
}