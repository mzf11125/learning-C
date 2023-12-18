#include<stdio.h>
#include<string.h>

struct mahasiswa{
	char nama[100];
	char nim[11];
	int age;
};

int main(){
	//Sorting -> Pengurutan (Bubble Sort)
	int n; //Banyak data
	scanf("%d",&n);
	//Array of Struct
	mahasiswa listmahasiswa[n];
	
	for(int i=0;i<n;i++){
		scanf("%s %s %d",listmahasiswa[i].nama, listmahasiswa[i].nim, &listmahasiswa[i].age);
	}
	
	//Sorting mahasiswa berdasarkan NIM dari paling kecil ke besar
	for(int i = 0 ; i< n-1;i++){
		for(int j=i+1 ; j<n;j++){
			if(strcmp(listmahasiswa[i].nim,listmahasiswa[j].nim)>0){
				mahasiswa temp = listmahasiswa[i];
				listmahasiswa[i] = listmahasiswa[j];
				listmahasiswa[j] = temp;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		printf("%s %s %d\n",listmahasiswa[i].nama, listmahasiswa[i].nim, listmahasiswa[i].age);
	}
	
	
	return 0;
}
