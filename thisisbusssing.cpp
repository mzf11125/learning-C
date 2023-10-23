#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void fileOpen(){
	FILE* file = fopen("phonebook.txt", "r");
	if(!file){
		printf("Creating new file.\n");
		FILE* file = fopen("phonebook.txt", "w");
		return;
	}
	
	char line[100];
	while(fgets(line, sizeof(line), file)){
		printf("%s", line);
	}
	
	fclose(file);
};	
	

void search(){
	char name[20];
	printf("Enter the name you want to search for: ");
	scanf("%s", name);
	
	FILE* file = fopen("phonebook.txt", "r");
	if(!file){
		printf("Error opening file.\n");
		return;
	}
	
	char line[100];
	while(fgets(line, sizeof(line), file)){
		if(strstr(line, name)){
			printf("%s", line);
			return;
		}
	}
		
	fclose(file);
		
	printf("Name not found.\n");	
};


void newrecord(){
	FILE* file = fopen("phonebook.txt", "a");
	fgetc(file);
	char name[20];
	char number[20];
	printf("Enter the name you want to add: ");
	scanf("%s", name);
	printf("Enter the number you want to add: ");
	scanf("%s", number);

};
void deleterecord(){
	char name[20];
	printf("Enter the name you want to delete: ");
	scanf("%s", name);
	
	FILE* file = fopen("phonebook.txt", "r");
	if(!file){
		printf("Error opening file.\n");
		return;
	}
	
	char line[100];
	while(fgets(line, sizeof(line), file)){
		if(strstr(line, name)){
			printf("%s", line);
			return;
		}
	}
	
	fclose(file);
	
	printf("Name not found.\n");
	fclose(file);
};

void phonenumber(){
	char name[20];
	printf("Enter the name you want to modify: ");
	scanf("%s", name);
	
	FILE* file = fopen("phonebook.txt", "r");
	if(!file){
		printf("Error opening file.\n");
		return;
	}
	
	char line[100];
	while(fgets(line, sizeof(line), file)){
		if(strstr(line, name)){
			printf("%s", line);
			return;
		}
	}
	
	fclose(file);
	
	printf("Name not found.\n");
	fclose(file);		

};

int main(){
	int input = 0;
	do{
		puts("1. Add a new record");
		puts("2. Search for a name.");
		puts("3. Modify a phone number.");
		puts("4. Delete a record.");
		puts("5. Exit");
		scanf("%d", &input); getchar();
		switch(input){
			case 1:
				newrecord();
				break;
			case 2:
				search();
				break;
			case 3:
				phonenumber();
				break;
			case 4:
				deleterecord();
				break;
			case 5:
				return 0;
				break;
			default: 
				break;
		}
	
	}
	while((input <= 4 && input >= 1) || input < 1 || input > 4);
}