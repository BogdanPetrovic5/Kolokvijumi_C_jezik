#include <stdio.h>
void sortiraj_naizmenicno(int vrsta_matrice[], int dimenzije_matrice){
	int temp;
	//Jedan od laksih nacina je da prvo sortiramo niz u opadajuci primer: 1 2 3 4 5 -> 5 4 3 2 1
	for (int i = 0; i < dimenzije_matrice-1; i++) {
		for (int j = i+1; j < dimenzije_matrice; j++) {
			if (vrsta_matrice[i] < vrsta_matrice[j]) {
				temp = vrsta_matrice[i];
				vrsta_matrice[i] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
			}
		}
	}
	// Posto je ideja svaki element prevucemo na svoje mesto, moramo imati i jednu
	// pomocnu promenljivu, koja ce cuvati oridjiji dimenziju matrice, a kopiju smanjivati kad 
	// zeljeni element prevucemo na svoje mesto.
	int pomocna_duzina = dimenzije_matrice;
	//K promenljiva ce nam to omogudjiti.
	int k;
	for (int i = 1; i < pomocna_duzina; i++, pomocna_duzina--) {
		for (int j = i+1, k = i; j < pomocna_duzina; j++, k++) {
				//i setujemo na jedan, posto je najvec vec na svom mestu.
				//i < pomocna duzina, pomocna duzina se smanjuje kada drugi najveci stavimo na poslednje mesto
				//u unutrasnjoj imamo 2 brojaca, jedan ide ispred a to je 'j', 'k' ide uvek za njim, iza,
				// i non stop elementi sa indexima 'j' i 'k' se menjanu dakle primer
				// ako imamo 5 4 3 2 1 ->(1.) 5 3 4 2 1 -> (2.) 5 3 2 4 1 -> 5 3 2 1 4
				// iduca iteracija spoljasnje petlje je i = 2, element[1] je sad 3 i on je na svom mestun njega nema potrebe menjati i zato nam i=2 odgovara, 
				// ostaje samo da se zamene 2 i 1
				// konacno 5 3 1 2 4
				temp = vrsta_matrice[k];
				vrsta_matrice[k] = vrsta_matrice[j];
				vrsta_matrice[j] = temp;
		}
	}
}
void nova_matrica(int matrica[50][50], int dimenzije_matrice) {
	// Pravimo pomocni niz 'pomocna_vrsta' u koju smestamo red matrice i saljemo funkciji sortiraj matricu
	int pomocna_vrsta[50];
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			//Punjenje pomocnog niza
			pomocna_vrsta[j] = matrica[i][j];
		}
		//Slanje..
		sortiraj_naizmenicno(pomocna_vrsta, dimenzije_matrice);
		for (int j = 0; j < dimenzije_matrice; j++) {
			//Reformiranje vec postojece vrste u matrici
			matrica[i][j] = pomocna_vrsta[j];
		}
	}
	printf("\n");

}
void izbaci_sa_k_poz(int vrsta_matrice[], int duzina_matrice, int k) {
	//Izbacivanje sa glavne dijagonale
	for (int i = k; i < duzina_matrice; i++) {
		vrsta_matrice[i] = vrsta_matrice[i + 1];
	}
	

}
void ucitaj_matricu(int matrica[50][50], int dimenzije_matrice) {
	//Ucitavanje matrice
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			scanf("%d", &matrica[i][j]);
		}
	}
}
void stampaj_matricu(int matrica[50][50], int red, int kolona) {
	//Stampanje matrice
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			printf("%d ", matrica[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	//Alociranje memorije za matricu
	int matrica[50][50];
	int dimenzije_matrice;
	printf("Unesi duzinu kvadratne matrice, kolone i redove: ");
	scanf("%d", &dimenzije_matrice);
	printf("Unesi matricu: ");
	printf("\n");
	//Pozivanje funkcije, ucitaj_matricu
	ucitaj_matricu(matrica, dimenzije_matrice);
	printf("\n");
	//Pozivanje funkcije, stampaj_matricu
	stampaj_matricu(matrica, dimenzije_matrice, dimenzije_matrice);
	printf("\n");
	//Sortiranje matrice
	nova_matrica(matrica, dimenzije_matrice);
	//Pozivanje funkcije, stampaj_matricu, sortirana.
	stampaj_matricu(matrica, dimenzije_matrice, dimenzije_matrice);
	printf("\n");
	int k = 0;
	int pomocni_niz[50];
	//Jos jedan pomocni niz..za slanje sortirane matrice, red po red, 
	//kako bi se izbacio element po elemeent.
	for (int i = 0; i < dimenzije_matrice; i++) {
		for (int j = 0; j < dimenzije_matrice; j++) {
			pomocni_niz[j] = matrica[i][j];
		}
		izbaci_sa_k_poz(pomocni_niz, dimenzije_matrice, k);
		for (int j = 0; j < dimenzije_matrice; j++) {
			matrica[i][j] = pomocni_niz[j];
		}
		//'k' ce prvo biti 0 i izbacice sa nulte poz, 
		//a onda ce se povecati i kao takvo opet poslati.
		k += 1;
	}
	int duzina_kolone_nova = dimenzije_matrice - 1;
	
	stampaj_matricu(matrica, dimenzije_matrice, duzina_kolone_nova);
}