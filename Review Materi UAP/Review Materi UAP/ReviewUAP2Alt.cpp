#include <stdio.h>
#include <string.h>

//Review Materi UAP
//15 Desember 2023
//Materi: Sorting,Searching dan File

/*
SOAL 2 : Sorting Judul Buku dari file
=====================================
INPUT: 
To Kill a Mockingbird#Harper Lee
Harry Potter and the Sorcerer Stone#JK Rowling
Hunger Games#Suzanne Collins
Lord of The Rings#Tolkien
Alchemist#Paulo Coelho

OUTPUT:
Alchemist - Paulo Coelho
Harry Potter and the Sorcerer Stone - JK Rowling
Hunger Games - Suzanne Collins
Lord of The Rings - Tolkien
To Kill a Mockingbird - Harper Lee
*/

struct Book{
	char title[1001];
	char author[1001];
}list[1001];

void swap(Book *a, Book *b){
	Book temp = *a;
	*a = *b;
	*b = temp; 
}

int partition(int low, int high){
	
	int pivotIdx = high;
	int i = (low-1);
	
	for(int j=low;j<high;j++){
			if(strcmp(list[j].title,list[pivotIdx].title)<0){
				i++;
				swap(&list[i],&list[j]);
			}
	}
	i++;
	swap(&list[i],&list[pivotIdx]);
	return i;
}

void quickSort(int low, int high){
	if(low>=high){
		return;
	}
	int partitionIdx = partition(low,high);
	
	quickSort(low,partitionIdx-1);
	quickSort(partitionIdx+1,high);
}

int main(){
	FILE *fp = fopen("data1.txt", "r");
	int count =0;
	while(!feof(fp)){
		fscanf(fp,"%[^#]#%[^\n]\n",&list[count].title, &list[count].author);
		count++;
	}
	
	quickSort(0,count-1);
	for(int tc = 0;tc<count;tc++){
		printf("%s - %s\n",list[tc].title, list[tc].author);
	}
	fclose(fp);
	return 0;
}
