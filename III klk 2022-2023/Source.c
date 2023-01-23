#include <stdio.h>
#include <string.h>
typedef struct knjiga {
	int ISBN;
	char naziv_knjige[30];
	char ime_autora[30];
}knjiga;
typedef struct polica {
	char naziv_police[2];
	int broj_knjiga;
	int niz_ISBN[50];
}polica;
int unos_knjiga(knjiga knjige[], char naziv_fajla[]) {
	FILE* knjige_fajl = fopen(naziv_fajla, "r");
	int broj_knjiga;
	fscanf(knjige_fajl, "%d", &broj_knjiga);
	printf("%d", broj_knjiga);
	char prazan_char;
	for (int i = 0; i < broj_knjiga; i++) {
		fscanf(knjige_fajl, "%d", &knjige[i].ISBN);
		prazan_char = fgetc(knjige_fajl);
		fgets(knjige[i].naziv_knjige, 30, knjige_fajl);
		knjige[i].naziv_knjige[strlen(knjige[i].naziv_knjige) - 1] = '\0';
		fgets(knjige[i].ime_autora, 30, knjige_fajl);
		knjige[i].ime_autora[strlen(knjige[i].ime_autora) - 1] = '\0';
	}
	for (int i = 0; i < broj_knjiga; i++) {
		printf("%d %s %s", knjige[i].ISBN, knjige[i].ime_autora, knjige[i].naziv_knjige);
		printf("\n");
	}
	return broj_knjiga;
}
void ispis_knjiga(knjiga knjige[], int broj_knjiga, char naziv_fajla[]) {
	FILE* izlaz_fajl = fopen(naziv_fajla, "a");
	for (int i = 0; i < broj_knjiga; i++) {
		if (knjige[i].ISBN != 0) {
			fprintf(izlaz_fajl, "%d", knjige[i].ISBN);
			fprintf(izlaz_fajl, " %s", knjige[i].naziv_knjige);
			fprintf(izlaz_fajl, " %s", knjige[i].ime_autora);
			fprintf(izlaz_fajl, "%c", '\n');
		}
		
	}
	fprintf(izlaz_fajl, "%s", "-----------------------------------");
	fprintf(izlaz_fajl, "%c", '\n');
	fclose(izlaz_fajl);
}
int rasporedi_knjige(knjiga knjige[], polica police[], int broj_knjiga) {
	const int MAX_BR_KNJIGA_NA_POLICI = 10;
	int brojac = 0;
	knjiga temp;
	for (int i = 0; i < broj_knjiga - 1; i++) {
		for (int j = i + 1; j < broj_knjiga; j++) {
			if (strcmp(knjige[i].naziv_knjige, knjige[j].naziv_knjige) > 0) {
				temp = knjige[i];
				knjige[i] = knjige[j];
				knjige[j] = temp;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < broj_knjiga; i++) {
		printf("%s", knjige[i].naziv_knjige);
		printf("\n");
	}
	int index = 0;
	int index_1 = 0;
	int neubacen = 0;
	int slovo = 65;
	int slovo_1 = 66;
	int i = 0;
	
	while(i < broj_knjiga){
		if (knjige[i].naziv_knjige[0] == slovo || knjige[i].naziv_knjige[0] == slovo_1) {
			if ((brojac + 1) <= MAX_BR_KNJIGA_NA_POLICI) {
				police[index].niz_ISBN[index_1] = knjige[i].ISBN;
				index_1 += 1;
				brojac += 1;
				police[index].naziv_police[0] = (char)slovo;
				police[index].naziv_police[1] = (char)slovo_1;
				police[index].naziv_police[2] = '\0';
				police[index].broj_knjiga = brojac;
			}
			i += 1;
		}else {
			slovo += 2;
			slovo_1 += 2;
			if (knjige[i].naziv_knjige[0] == slovo || knjige[i].naziv_knjige[0] == slovo_1) {
				index += 1;
				index_1 = 0;
				brojac = 0;
			}
		}
	}
	index += 1;
	printf("%d", index);
	printf("\n");
	
	printf("\n");
	for (int i = 0; i < index; i++) {
		printf("%s", police[i].naziv_police);
		printf("\n");
		for (int j = 0; j < broj_knjiga; j++) {
			for (int l = 0; l < police[i].broj_knjiga; l++) {
				if (knjige[j].ISBN == police[i].niz_ISBN[l]) {
					printf("%s \n", knjige[j].naziv_knjige);
					
				}
			}
		}
		
	}
	return index;
}
void ispis_polica(knjiga knjige[], polica police[], int broj_knjiga, int broj_polica, char naziv_fajla[]) {
	FILE* izlazni_fajl = fopen(naziv_fajla, "a");
	printf("\n");
	for (int i = 0; i < broj_polica; i++) {
		fprintf(izlazni_fajl, "%s", police[i].naziv_police);
		fprintf(izlazni_fajl, "%c", '\n');
		for (int j = 0; j < broj_knjiga; j++) {
			for (int l = 0; l < police[i].broj_knjiga; l++) {
				if (knjige[j].ISBN == police[i].niz_ISBN[l]) {
					fprintf(izlazni_fajl,"%s", knjige[j].naziv_knjige);
					fprintf(izlazni_fajl , "%c", '\n');
					knjige[j].ISBN = 0;

				}
			}
		}

	}
	fprintf(izlazni_fajl, "%s", "-----------------------------------");
	fprintf(izlazni_fajl, "%c", '\n');
	fclose(izlazni_fajl);
}
int main() {
	knjiga knjige[20];
	polica police[20];
	int broj_knjiga;
	char naziv_fajla[20];
	char naziv_fajla_1[20];
	int broj_polica;
	int broj_poziva_f = 0;
	printf("Unesi naziv fajla za citanje: ");
	scanf("%s", naziv_fajla);
	printf("Unesi naziv izlaznog fajla: ");
	scanf("%s", naziv_fajla_1);
	broj_knjiga = unos_knjiga(knjige, naziv_fajla);
	ispis_knjiga(knjige, broj_knjiga, naziv_fajla_1, broj_poziva_f);
	broj_polica = rasporedi_knjige(knjige, police, broj_knjiga);
	ispis_polica(knjige, police, broj_knjiga, broj_polica, naziv_fajla_1);
	ispis_knjiga(knjige, broj_knjiga, naziv_fajla_1, broj_poziva_f);
}