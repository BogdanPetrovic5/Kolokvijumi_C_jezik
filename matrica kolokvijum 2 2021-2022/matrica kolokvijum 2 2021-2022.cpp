// matrica kolokvijum 2 2021-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int nadji_podniz(int niz_a[], int niz_b[], int a, int b) {
	int i = 0;
	int j = 0;
	int index = 0;
	int l = 0;
	int counter_1;
	int counter = 0;

	while (i != a && j != b) {
		if (niz_a[i] == niz_b[j]) {
			i++;
			j++;
			if (j == b) {
				return index;
				
			}
			
			
		}else {
			index = i + 1;
			i++;
			j = 0;
		}
		
		
		
	}
	return -1;
}
void broj_ponavljanja(int matrica[50][50], int row, int col, int niz_b[], int duzina_niza_b, int niza_A[], int brojac_za_index) {
	int pomocni_niz[50];
	
	int broj_ponavljanja_1 = 0;
	int vrednost;
	int index = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			pomocni_niz[j] = matrica[j][i];
			index++;
			
		}
		index = 0;
		
		vrednost = nadji_podniz(pomocni_niz, niz_b, row, duzina_niza_b);
		int n = 0;
		int m = 0;
		if (vrednost > -1) {
			while (n != row && m != duzina_niza_b) {
				if (pomocni_niz[n] == niz_b[m]) {
					m++;
					n++;
					if (m == duzina_niza_b ) {
						m = 0;
						broj_ponavljanja_1++;
					}

				}
				else {
					n += 1;
					m = 0;
				}
				if (n == row) {
					niza_A[brojac_za_index] = broj_ponavljanja_1;
					brojac_za_index++;
					broj_ponavljanja_1 = 0;
				}
			}
		}
		else {
			niza_A[brojac_za_index] = 0;
			brojac_za_index++;
		}
	}

	for (int i = 0; i < brojac_za_index; i++) {
		std::cout << niza_A[i];
	}
}
void ucitaj_matricu(int matrica[50][50],int row, int col) {
	std::cout << "Ucitaj matricu: ";
	std::cout << std::endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cin >> matrica[i][j];
		}
	}


}
int main() {
	int row, col;
	int duzina_niz_a;
	int duzina_niz_b;
	int sifra_1 = 1;
	int sifra_2 = 0;
	int brojac_za_index = 0;
	int niz_sa_brojem_ponavljanja[50];
	int matrica[50][50];
	std::cout << "Unesi duzinu niza B: ";
	std::cin >> duzina_niz_b;
	
	
	int* niz_b = new int[duzina_niz_b];


	std::cout << std::endl;
	std::cout << "Unesi niz B: ";
	std::cout << std::endl;
	for (int i = 0; i < duzina_niz_b; i++) {
		std::cin >> niz_b[i];
	}
	
	std::cout << std::endl;
	std::cout << "Unesi duzininu redova i kolona: ";
	std::cin >> row >> col;
	std::cout << row;
	std::cout << col;
	ucitaj_matricu(matrica, row, col);
	broj_ponavljanja(matrica, row, col, niz_b, duzina_niz_b, niz_sa_brojem_ponavljanja, brojac_za_index);
	
	delete[] niz_b; 


	
}