#include <stdio.h>
void sortiraj_naizmenicno(int vrsta_matrice[], int dimenzije_matrice){
	int temp;
	for (int i = 0; i < dimenzije_matrice-1; i++) {
		for (int j = i+1; j < dimenzije_matrice; j++) {
			if (vrsta_matrice[i] < vrsta_matrice[j]) {
				temp = vrsta_matrice[i];
				vrsta_matrice[i] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
			}
		}
	}
	int pomocna_duzina = dimenzije_matrice;
	int k;
	for (int i = 1; i < pomocna_duzina; i++, pomocna_duzina--) {
		for (int j = i+1, k = i; j < pomocna_duzina; j++, k++) {
				temp = vrsta_matrice[k];
				vrsta_matrice[k] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
		}
	}
}
void nova_matrica(int matrica[50][50], int dimenzije_matrice) {
	int pomocna_vrsta[50];
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			pomocna_vrsta[j] = matrica[i][j];
		}
		sortiraj_naizmenicno(pomocna_vrsta, dimenzije_matrice);
		for (int j = 0; j < dimenzije_matrice; j++) {
			matrica[i][j] = pomocna_vrsta[j];
		}
	}
	printf("\n");

}
void izbaci_sa_k_poz(int vrsta_matrice[], int duzina_matrice, int k) {
	for (int i = k; i < duzina_matrice; i++) {
		vrsta_matrice[i] = vrsta_matrice[i + 1];
	}
	printf("\n");

}
void ucitaj_matricu(int matrica[50][50], int dimenzije_matrice) {
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
}
void stampaj_matricu(int matrica[50][50], int red, int kolona) {
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	int matrica[50][50];
	int dimenzije_matrice;
	printf("Unesi duzinu kvadratne matrice, kolone i redove: ");
	scanf("%d", &dimenzije_matrice);
	printf("Unesi matricu: ");
	printf("\n");
	ucitaj_matricu(matrica, dimenzije_matrice);
	printf("\n");
	stampaj_matricu(matrica, dimenzije_matrice, dimenzije_matrice);
	printf("\n");
	nova_matrica(matrica, dimenzije_matrice);
	stampaj_matricu(matrica, dimenzije_matrice, dimenzije_matrice);
	printf("\n");
	int k = 0;
	int pomocni_niz[50];
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			pomocni_niz[j] = matrica[i][j];
		}
		izbaci_sa_k_poz(pomocni_niz, dimenzije_matrice, k);
		for (int j = 0; j < dimenzije_matrice; j++) {
			matrica[i][j] = pomocni_niz[j];
		}
		k += 1;
	}
	int duzina_kolone_nova = dimenzije_matrice - 1;
	printf("\n");
	stampaj_matricu(matrica, dimenzije_matrice, duzina_kolone_nova);
}