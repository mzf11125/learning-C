#include <stdio.h>

FILE *fp;

struct Orders{
	
	int quantity;
	char makanan[255];
	int hargaSatuan;
	int total;
	
};

int main(){

	// buka file
	fp = fopen("testdata.txt", "r");
	
	char string[255];
	// fscanf utk read file
	fscanf(fp, "%[^\n]\n", string);		// \n di akhiran buat baca enter, (membaca Hello World)
	printf("%s\n", string);
	fscanf(fp, "%[^\n]\n", string);		// \n di akhiran buat baca enter, (membaca This is Binus University
	printf("%s\n", string);
	
/*	Klo mw baca smpe akhir file pke looping
	while(!feof(fp)){
		fscanf(fp, "%[^\n]\n", string);		// \n di akhiran buat baca enter, (membaca This is Binus University
		printf("%s\n", string);
	}
*/
	fclose(fp);
	// klo udh close, variable FILE *fp bisa dipake buat akses file lain
	
	
	struct Orders ord[100];	
	fp = fopen("transaksiRestoran.txt", "r");
	
	int i = 0;
	while(!feof(fp)){
		fscanf(fp, "%d-%[^\-]-%d\n", &ord[i].quantity, &ord[i].makanan, &ord[i].hargaSatuan);	// \n utk pindah line
		ord[i].total = ord[i].quantity * ord[i].hargaSatuan;
		i++;
	}
	
	
	for(int j = 0; j < i; j++){
		printf("%-3d | %-20s | %-10d | %-10d\n", ord[j].quantity, ord[j].makanan, ord[j].hargaSatuan, ord[j].total);		//-3 itu biar rapi 
	}
	
	fclose(fp);
	
	return 0;
}



/*
Mode dalam fopen (yang bisa dipake di oj cuma read data)

1. Read = r
2. Write = w	// jika sudah ada data, data yg lama akan di replace dengan data baru (overwrite)
3. Append = a	// menambahkan data

*/
