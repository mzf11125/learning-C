#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void fileOpen() {
    FILE* file = fopen("phonebook.txt", "r");
    
    if (!file) {
        printf("Creating a new file.\n");
        file = fopen("phonebook.txt", "w");
        
        if (file) {
            printf("New file created successfully.\n");
            fclose(file);
        } else {
            printf("Failed to create a new file.\n");
        }
        
        
    } else {
        printf("File opened for reading.\n");
        fclose(file);
    }
	return;  
}
	
	char line[100];
	while(fgets(line, sizeof(line), file)){
		printf("%s", line);
	}
	
	fclose(file);
	return;
};	
	

void search() {
    char name[20];
    printf("Enter the name you want to search for: ");
    scanf("%19s", name); 

    FILE* file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    int found = 0; 

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            printf("%s", line);
            found = 1; 
        }
    }

    fclose(file);

    if (!found) {
        printf("Name not found.\n");
    }
}

void displayFile() {
    FILE* file = fopen("phonebook.txt", "a+");  // Open the file in append and read mode
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}


void newrecord(){
	FILE* file = fopen("phonebook.txt", "a");
	fgetc(file);
	char name[20];
	char number[20];
	printf("Enter the name you want to add: ");
    scanf("%19s", name);

    printf("Enter the number you want to add: ");
    scanf("%19s", number); 
    
    fprintf(file, "Name: %s, Number: %s\n", name, number);

    fclose(file); 

};
void deleterecord() {
    char name[20];
    printf("Enter the name you want to delete: ");
    scanf("%19s", name); 

    FILE* file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            found = 1;
            continue; 
        }
        fprintf(tempFile, "%s", line); 
    }

    fclose(file);
    fclose(tempFile);

    if (!found) {
        printf("Name not found.\n");
    } else {
        remove("phonebook.txt");       
        rename("temp.txt", "phonebook.txt"); 
        printf("Record deleted successfully.\n");
    }
};

void modifyPhoneNumber() {
    char name[20];
    printf("Enter the name you want to modify: ");
    scanf("%19s", name);

    FILE* file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char tempFileName[] = "temp_phonebook.txt";
    FILE* tempFile = fopen(tempFileName, "w");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    char line[100];
    int nameFound = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            char newNumber[100];
            printf("Enter the new phone number: ");
            scanf("%99s", newNumber);
            fprintf(tempFile, "%s %s\n", name, newNumber);
            nameFound = 1;
        } else {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("phonebook.txt"); // Delete the old file
    rename(tempFileName, "phonebook.txt"); // Rename the temporary file to the original file name

    if (!nameFound) {
        printf("Name not found.\n");
    }
}

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
				displayFile();
				newrecord();
				break;
			case 2:
				displayFile();
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