#include<stdio.h>
#include<string.h>

//Modul 4 - 12 Oktober 2023
//Data Struct

/*Data struct : untuk mengelompokkan data
Contoh=> Seorang Mahasiswa mempunyai:
		-Nama
		-Umur
		-GPA
		semuanya merupakan atribut dari Mahasiswa

*/

struct Mahasiswa{
	char name[101];
	int age;
	double gpa;
};

int main(){
	Mahasiswa a;//jika tidak menggunakan dev-c+= maka di depan nama harus ditaruh "struct"
	strcpy(a.name,"Clive");	//memasukkan nama ke dalam Mahasiswa a dengan menggunakan strcpy
	a.age = 10;
	a.gpa = 3.5;
	
	Mahasiswa peoples[5];
	strcpy(peoples[0].name, "Budi");
	peoples[0].age = 15;
	peoples[0].gpa = 3.2;
	
	strcpy(peoples[1].name, "Jojo");
	peoples[1].age = 17;
	peoples[1].gpa = 4.0;
	
	strcpy(peoples[2].name, "Lili");
	peoples[2].age = 23;
	peoples[2].gpa = 3.82;
	
	strcpy(peoples[3].name, "Bibi");
	peoples[3].age = 31;
	peoples[3].gpa = 3.62;

	for(int i=0;i<3;i++){
	printf("Nama: %s\nUmur: %d\nGPA: %lf\n\n", peoples[i].name, peoples[i].age,peoples[i].gpa);
}
	printf("%d", sizeof(Mahasiswa));//berapa byte yang dikasih untuk struct Mahasiswa
	return 0;
}
