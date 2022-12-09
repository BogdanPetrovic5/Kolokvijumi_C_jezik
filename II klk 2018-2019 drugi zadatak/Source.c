#include <stdio.h>
int nadji_presek(int kolona_1[], int kolona_2[], int duzina_niza) {
	//Provera elemenata dve kolone
	for (int i = 0; i < duzina_niza; i++) {
		//Ukoliko bar jedan element nije jednak odgovarajucem u drugoj vrati kec.
		if (kolona_1[i] != kolona_2[i]) {
			return 1;
		}
	}
	//Ako se nista ne desi vrati 0 kao sto pise
	return 0;
}
int f_nova_matrica(int matrica[50][50],int nova_matrica[50][50], int redovi, int kolone) {
	int vrednost;
	int vrsta = 0;//Vrsta, sluzi da bi se brojala vrsta nove matrice
	int index=-1;//Index -1 za uporedjivanje

	for (int i = 0; i < redovi; i++) {
		for (int j = i+1; j < redovi; j++) {
			//Saljemo matricu red po red(moze ovako bez pomocnog niza jer mi ovako saljemo pointer na niz jedne matrice), dok za kolonu ne moze.
			vrednost = nadji_presek(matrica[i], matrica[j], kolone);
			//Ako vrednost bude jednaka 0 to znaci da je jedna kolona ista drugoj i pamtimo taj index
			//i odma izlazimo kako bi smo sacuvali bas taj, jer moze da se desi da u matrici ima vise istih kolona ne samo dve
			if (vrednost < 1) {
				index = j;
				break;
			}
		}
		//Pita da li je vrednost > 0 ako jeste pitaj je l je index razlicit od i ako oba prodju ulazi dalje.
		//Primer ako imamo
		/*	1 2 3 4
			3 4 5 6
			1 2 3 4
			4 5 2 3*/
		//Prvi red nece sigurno upisati jer vrednost nije veca od 0, u slucaju da je na prvom indexu reda bio neki drugi red
		//koji nema parnjaka tj nema jednakih drugih redova, njega ce upisati, jer je pocetna vrednost indexa uvek -1
		//dakle oba uslova prolaze
		//sad kad smo mi sacuvali index pronadjenog parnjaka prvog reda, spoljna for petlja kada dodje do tog kojeg je nasao, u ovom slucaju 
		//indexa 2, pitace je l je 'i' jednak 'j', isti su, automatski drugi deo uslova ne prolazi, i nece upisati ovaj red u novu matricu i ako 
		// red sa indexom 2 razlicit od narednog reda. Bas zbog prethodno sacuvanog indexa i break naredbe
		if (vrednost > 0 && index != i) {
			for (int j = 0; j < kolone; j++) {
					nova_matrica[vrsta][j] = matrica[i][j];
			}
			vrsta += 1;
		}

		
			
	}
	//vracamo vrstu.
	return vrsta;
}
void ucitaj_matricu(int matrica[50][50], int redovi, int kolone) {
	for (int i = 0; i < redovi; i++) {
		for (int j = 0; j < kolone; j++) {
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
int main() {
	int matrica[30][30];
	int nova_matrica[30][30];
	int pomocni_niz[30];
	int pomocni_niz_1[30];
	int redovi, kolone;
	int broj_redova;
	printf("Unesi redove: ");
	scanf("%d", &redovi);
	printf("Unesi kolone: ");
	scanf("%d", &kolone);
	printf("\n");
	printf("Unesi matricu:\n");
	ucitaj_matricu(matrica, redovi, kolone);
	printf("Matrica u originalnom izdanju xD:\n");
	stampaj_matricu(matrica, redovi, kolone);
	printf("\n");
	//Provera prve dve kolone...
	for (int i = 0; i < redovi; i++) {
		pomocni_niz[i] = matrica[i][0];
	}
	for (int i = 0; i < redovi; i++) {
		pomocni_niz_1[i] = matrica[i][1];
	}
	//Primanje povratne vrednosti...
	int vrednost_funkcije = nadji_presek(pomocni_niz, pomocni_niz_1, redovi);
	if (vrednost_funkcije == 1) printf("NEMA");
	else printf("IMA");
	printf("\n");
	broj_redova = f_nova_matrica(matrica,nova_matrica ,redovi, kolone);
	printf("Nova matrica:\n");
	stampaj_matricu(nova_matrica, broj_redova, kolone);
}