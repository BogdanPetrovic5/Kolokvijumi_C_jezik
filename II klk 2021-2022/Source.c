#include <stdio.h>

int nadji_podniz(int kolona_matrice[], int pod_niz[], int redovi, int duzina_podniza) {
	int index;
	int ima_podniz = 0;
	//Radi potpuno isto kao funkcija broj_ponavljanja
	for (int i = 0; i < redovi; i++) {
		ima_podniz = 0;
		for (int j = i, n = 0; j < i + duzina_podniza; j++, n++) {
			if (kolona_matrice[j] == pod_niz[n]) {
				index = i;
				ima_podniz += 1;
			}
		}
		//S tim sto ovde cim nadje index, prvi index, ona vraca tu vrednost i izlazi iz funkcije
		if (ima_podniz == duzina_podniza) return index;
		
	}
	//Ili ako ne nadje onda samo vrati -1
	if (ima_podniz < duzina_podniza) return -1;
}
int broj_ponavljanja(int matrica[50][50] , int pod_niz[], int niz_br_ponavljanja[], int kolone, int redovi, int duzina_podniza, int brojac) {
	int vrednost_funkcije_podniz;
	int kolona_matrice[50];
	int ima_podniz;
	int broj_ponavljanja = 0;
	for (int i = 0; i < kolone; i++) {
		for (int j = 0; j < redovi; j++) {
			//Punimo pomocni niz kolona_matrice kolonom same matrice kako bi smo njega slali
			kolona_matrice[j] = matrica[j][i]; 
		}
		//Funkciji nadji_podniz saljemo argumente
		vrednost_funkcije_podniz = nadji_podniz(kolona_matrice, pod_niz, redovi, duzina_podniza);
		//Ovde samo proveravamo da li je su povratne vrednosti dobre
		printf("%d ", vrednost_funkcije_podniz);
		//Ako je povratna vrednost veca od -1 proveri koliko ima ponavaljanja
		if (vrednost_funkcije_podniz > -1) {
			//Broj ponavljanja setujemo na nulu uvek nakon poziva funkcije nadji_podniz
			broj_ponavljanja = 0;
			for (int m = 0; m < redovi; m++) {
				//Setujemo neki brojcanik koji ce nam reci da li je svaki element iz podniza isti kao element u koloni
				ima_podniz = 0;
				/*Index J krece uvek od m, znaci prvo ce biti nula i proverice da li su elementi od J do M + duzina_podniza isti kao u pod_niz(kad je m == 1 i J ce biti)
				index n ce uvek kretati od 0 i kretati se do same duzine podniza i taj index koristi pod_niz*/
				for (int j = m, n = 0; j < m + duzina_podniza; j++, n++) {
					if (kolona_matrice[j] == pod_niz[n]) {
						/*Za svaki nadjeni isti element povecacemo ima_podniz za jedan, ako je ta varijabla
						jednaka varijabli duzina_podniza znaci samo da se u nizu od m-te pozicije do m+duzina_podniza nalazi sam pod_niz i da su svi el. isti*/
						ima_podniz += 1;
					}
				}
				//I ako je to jednako povecamo broj ponavljanja za jedan
				if (ima_podniz == duzina_podniza) broj_ponavljanja +=1;
			}
			//I ovde za svaki nadjeni podniz u svakoj koloni ispisujemo u konacan niz broj samih ponavljanja
			niz_br_ponavljanja[brojac] = broj_ponavljanja;
			
		}else niz_br_ponavljanja[brojac] = 0;
		//Ako je manja onda samo upisi nulu, nema potrebe da se broji
		//I ovde samo povecamo brojac za jedan
		brojac += 1;
	}
	
}
void ucitaj_matricu(int redovi, int kolone, int matrica[50][50]) {
	//Punjenje matrice
	int pomocni_red_mat[50];
	for (int i = 0; i < redovi; i++) {
		for (int j = 0; j < kolone; j++) {
			scanf("%d", &matrica[i][j]);
			
		}
	}
}
int stampaj_matricu(int matrica[50][50], int redovi, int kolone) {
	//Stampanje matrice
	for (int i = 0; i < redovi; i++) {
		for (int j = 0; j < kolone; j++) {
			printf("%d ", matrica[i][j]);
		}
	}
}
int main() {
	int redovi, kolone;
	int matrica[50][50];
	int pod_niz[50];
	int duzina_pod_niza;
	int pomocni_niz_matrice[50];
	int niz_br_ponavljanja[50];
	int brojac = 0;
	printf("Unesi redove: ");
	scanf("%d", &redovi);
	printf("Unesi kolone: ");
	scanf("%d", &kolone);
	ucitaj_matricu(redovi, kolone, matrica);
	printf("Unesi duzinu pod niza: ");
	scanf("%d", &duzina_pod_niza);
	//Pravimo pod niz koji cemo traziti u kolonama matrice//
	for (int i = 0; i < duzina_pod_niza; i++) {
		scanf("%d", &pod_niz[i]);
	}
	//Stampaj matricu funkcija, saljemo matricu i br kolona i redova
	stampaj_matricu(matrica, redovi, kolone);
	//funkcija broj ponavljanja
	broj_ponavljanja(matrica,pod_niz, niz_br_ponavljanja, kolone, redovi, duzina_pod_niza, brojac);
	printf("\n");
	//Stampanje koliko se u kojoj matrici nalazi dati niz
	for (int i = 0; i < kolone; i++) {
		printf("%d ", niz_br_ponavljanja[i]);
	}
}
