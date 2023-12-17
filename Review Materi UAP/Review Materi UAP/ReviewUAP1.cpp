#include <stdio.h>
#include <string.h>

//Review Materi UAP
//15 Desember 2023
//Materi: Sorting,Searching dan File

/*
SOAL 1 : Sorting Nilai
======================
INPUT:
5
jason 65
adrian 87
cristoper 95
daniel 91
vincent 95

OUTPUT:
cristoper 95
vincent 95
daniel 91
adrian 87
jason 65

Sort berdasarkan nilai dari besar ke kecil

Jika terdapat nilai yang sama
sort berdasarkan nama sesuai urutan alphabet
*/

struct Sekolah{
	char nama[1001];
	int nilai;
}siswa[1001];

void swap(Sekolah *a, Sekolah *b){
	Sekolah temp = *a;
	*a = *b;
	*b = temp; 
}
int partition(int low, int high){
	
	int pivotIdx = high;
	int i = (low-1);
	
	for(int j=low;j<high;j++){
		if(siswa[j].nilai>siswa[pivotIdx].nilai){
			i++;
			swap(&siswa[i],&siswa[j]);
		}else if(siswa[j].nilai==siswa[pivotIdx].nilai){
			if(strcmp(siswa[j].nama,siswa[pivotIdx].nama)<0){
				i++;
				swap(&siswa[i],&siswa[j]);
			}
		}
	}
	i++;
	swap(&siswa[i],&siswa[pivotIdx]);
	return i;
}

void quickSort(int low, int high){
	if(low>=high){
		return;
	}
	int pi = partition(low,high);
	
	quickSort(low,pi-1);
	quickSort(pi+1,high);
}

int main(){
	int T;
	scanf("%d", &T);getchar();
	for(int tc = 0;tc<T;tc++){
		scanf("%s %d",&siswa[tc].nama, &siswa[tc].nilai);getchar();
	}
	quickSort(0,T-1);
	for(int tc = 0;tc<T;tc++){
		printf("%s %d\n",siswa[tc].nama, siswa[tc].nilai);
	}
	return 0;
}
