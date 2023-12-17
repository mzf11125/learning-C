#include <stdio.h>
#include <string.h>
int counter;


struct item{
	char name[100];
	int price;
}itemList[100];


void printFile(){
	
	for(int i = 0; i < counter; i++){
		printf("Nama: %s, Harga: %d\n", itemList[i].name, itemList[i].price);
	}
}


void readFile(){
	//Initialize counter = 0
	counter = 0;
	//Open file
	//Read fule
	FILE *fp = fopen("item.txt", "r");
	
	if(fp == NULL){
		puts("File not found");
		return;
	}
	
	while(!feof(fp)){
		fscanf(fp, "%[^#]#%d\n",
		itemList[counter].name, &itemList[counter].price);
		counter++;
	}
	
	fclose(fp);
}


void writeFile(){
	FILE *fp = fopen("item.txt", "w");
	if(fp == NULL){
		return;
	}
	fprintf(fp, "%s#%d\n", "Pencil", 100);
	fclose(fp);
	
}

void appendFile(){
	char name[255];
	int price;
	FILE *fp= fopen("item.txt","a"); 
	
	puts("Nama: ");
	scanf("\n");
	scanf("%s", name); getchar();
	puts("Price: ");
	scanf("%d", &price); getchar();
	
	//Write file, "a" --> append
	//Nyambungin dari data sebelumnya
//	FILE *fp = fopen("item.txt", "a");
	
	fprintf(fp, "%s#%d\n", name, price);
	
	
	fclose(fp);
	
}

int main(){
	readFile();
	printFile();
	appendFile();
//	writeFile();
	return 0;
}
