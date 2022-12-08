#include <stdio.h>
void sortiraj_matricu(int vrsta_matrice[], int red, int k) {
	//prvi nacin
	int n = red;
	//brojaci ce se kretati kruzno zbog %n
	//Prvi put 'i' ce biti na k-toj poziciji a 'j' na 'i+1' primer:
	// 4 3 5 1 2, k je recimo 2. Sto znaci da ce i cjerati do 3 zakljucno s 3 ili ti kec kao index. A 'j' do 5 ili ti k(2) index
	// dakle pitace da li je 5(index 2) veci od 1(ind 3(i+1)) ako jest zameni mesta, jeste, dakle --->> 4 3 1 5 2 idemo dalje 
	// da li je [i] vece od [j] jedan nije vece od [j] u ovom slucaju el. 1 i 2, ne menja se, 'j' ce sad biti trenutna vrednost % n sto je zapravo n % n
	// a to je 0 i vraca se na pocetak, pita da li je [i] vece od [j](0 index), nije nista.. 
	// 'i' je sad k + 1, dakle [3] ili ti element 5 pita da li je 5 vece od 2 jeste zameni..itd dalje isti proces..
	for (int i = k; i != k - 1; i = (i + 1) % n) {
		for (int j = (i + 1) % n; j != k; j = (j + 1) % n) {
			if (vrsta_matrice[i] > vrsta_matrice[j]) {
				int temp = vrsta_matrice[i];
				vrsta_matrice[i] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
			}
		}
	}
	//Drugi nacin
	/*int temp;
	int n = red;
	//sortiramo samo u opadajucem
	for (int i = 0; i < red - 1; i++) {
		for (int j = i + 1; j < red; j++) {
			if (vrsta_matrice[j] > vrsta_matrice[i]) {
				temp = vrsta_matrice[i];
				vrsta_matrice[i] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
			}
			
		}
	}
	//Do k sortiramo rastuce
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++)
		{
			if (vrsta_matrice[j] < vrsta_matrice[i]) {
				int temp = vrsta_matrice[i];
				vrsta_matrice[i] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
			}
		
		}

	}
	//Od k sortiramo rastuce i resen problem
	for (int i = k; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (vrsta_matrice[j] < vrsta_matrice[i]) {
				int temp = vrsta_matrice[i];
				vrsta_matrice[i] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
			}
		}

	}*/	
}
void nova_matrica(int matrica[50][50], int dimenzije_matrice, int pozicija) {
	int k = pozicija;
	int pomocni_niz[50];
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			pomocni_niz[j] = matrica[i][j];
		}
		sortiraj_matricu(pomocni_niz, dimenzije_matrice, k);
		for (int j = 0; j < dimenzije_matrice; j++) {
			matrica[i][j] = pomocni_niz[j];
		}
	}
}
void stampaj_matricu(int matrica[50][50], int redovi, int kolone) {
	for (int i = 0; i < redovi; i++) {
		for (int j = 0; j < kolone; j++) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
}
void ucitaj_matricu(int matrica[][50], int dimenzije_matrice) {
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
}
izbaci_sa_k_poz(int vrsta_matrice[], int k, int duzina_matrice) {
	for (int i = k; i < duzina_matrice - 1; i++) {
		vrsta_matrice[i] = vrsta_matrice[i+1];
	}
}

int main() {
	int matrica[50][50];
	int dimenzije_matrice, kolone;
	int pomocni_niz[50];
	printf("Unesi dimenzije matrice: ");
	scanf("%d", &dimenzije_matrice);
	printf("Unesi matricu: ");
	printf("\n");
	ucitaj_matricu(matrica, dimenzije_matrice);
	kolone = dimenzije_matrice;
	printf("\n");
	stampaj_matricu(matrica, dimenzije_matrice, kolone);
	printf("\n");
	int k;
	printf("Unesi K: ");
	scanf("%d", &k);
	nova_matrica(matrica, dimenzije_matrice, k);
	printf("\n");
	k = dimenzije_matrice - 1;
	stampaj_matricu(matrica, dimenzije_matrice, kolone);
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			pomocni_niz[j] = matrica[i][j];
		}
		izbaci_sa_k_poz(pomocni_niz, k, dimenzije_matrice);
		for (int j = 0; j < dimenzije_matrice; j++) {
			matrica[i][j] = pomocni_niz[j];
		}
		k -= 1;
	}
	kolone -= 1;
	stampaj_matricu(matrica, dimenzije_matrice, kolone);
}