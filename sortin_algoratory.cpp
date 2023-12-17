#include<stdio.h>
#include<string.h>


struct Mahasiswa{
	char nama[100];
	char nim[11];
	int age;
};

int main(){
	//struct 
	//Sorting -> Pengurutan (Bubble Sort)
	//int arr[5] = {10,4,9,7,5};
	int n;
	scanf("%d", &n);
	//array of struct
	Mahasiswa listmahasiswa[n];
	
	
//	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%s %s %d",listmahasiswa[i].nama, listmahasiswa[i].nim, &listmahasiswa[i].age);
	}
	//Sorting mahasiswa berdasarkan nim dari kecil ke yang gede
	//Sorting kecil ke besar
	for(int i = 0; i < 5; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(listmahasiswa[i].nim,listmahasiswa[j].nim)>0){
				Mahasiswa temp = listmahasiswa[i];
				listmahasiswa[i] = listmahasiswa[j];
				temp = listmahasiswa[j];
			} 
		}
	}
	
	for(int i=0;i<n;i++){
		printf("%s %s %d", listmahasiswa[i].nama, listmahasiswa[i].nim, &listmahasiswa[i].age);
	}
	
}