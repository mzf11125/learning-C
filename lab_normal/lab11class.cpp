#include <stdio.h>
#include <string.h>

//Union
union Siswa{
	char name[100];
	int age;
};



//declare struct
struct mahasiswa{
	char name[100];
	int age;
} mhs2;//Declare outisde of int main

typedef struct Data{
	int angka;
	char huruf[100];
}D;



int main(){
	//Using the mahasiswa structure iniside of main
	struct mahasiswa mhs1;
	
	//Initialize the value in mhs1 using mahasiswa struct
	strcpy(mhs1.name, "Budi");
	mhs1.age=20;
	
	//Manually add value
	strcpy(mhs2.name, "Joko");
	mhs2.age=18;
	
	//Declare inside of iunt maine with struct inside of int main and add value at teh same time
	struct mahasiswa mhs3 = {
		"Caca", 24
	};
	
	//Print mhs1
	printf("Nama: %s, Umur: %d\n", mhs1.name, mhs1.age);
	printf("Nama: %s, Umur: %d\n", mhs2.name, mhs2.age);
	printf("Nama: %s, Umur: %d\n", mhs3.name, mhs3.age);
	
	//Array of struct
	struct mahasiswa listMahasiswa[101];
	//Acccess the array of struct
	
	strcpy(listMahasiswa[0].name, "Daniel");
	listMahasiswa[0].age = 17;
	
	//print the array of struct
	printf("Nama: %s, Umur: %d\n", listMahasiswa[0].name, listMahasiswa[0].age);
	
	int size = sizeof(struct mahasiswa);
	printf("Size of mahasiswa: %d\n", size);
	
	//Use array
	D data2{
		20, "Ok"
	};
	printf("Umur: %d, Nama: %s\n", data2.angka, data2.huruf);
	
	//Union
	union Siswa siswa1;
	strcpy(siswa1.name, "Vincent");
	siswa1.age=23;
	
	printf("Nama: %s, Umur: %d\n", siswa1.name, siswa1.age);
	
	int sizeunion = sizeof(union Siswa);
	printf("Size union = %d\n", sizeunion);
	

	
	
	return 0;
}
