#include <stdio.h>
#include <string.h>

void displayFile() {
    FILE* file = fopen("phonebook.txt", "r");
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

void newRecord() {

    FILE* file = fopen("phonebook.txt", "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char name[20];
    char number[20];

    printf("Enter the name you want to add: ");
    scanf("%[^\n]", name);getchar();

    printf("Enter the number you want to add: ");
    scanf("%19s", number);getchar();

    fprintf(file, "Name: %s, Number: %s\n", name, number);
    printf("Record added sucessfully :)\n");

    fclose(file);
}

void search() {
	displayFile();
    char name[20];
    printf("Enter the name you want to search for(Case sensitive): ");
    scanf("%[^\n]", name);getchar();

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

void deleteRecord() {
    displayFile();  

    char name[20];
    printf("Enter the name you want to delete: ");
    scanf("%[^\n]", name);

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
}

void modifyPhoneNumber() {
    displayFile();  

    char name[20];
    printf("Enter the name you want to modify: ");
    scanf("%[^\n]", name);

    FILE* file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char tempFileName[] = "temp_phonebook.txt";
    FILE* tempFile = fopen(tempFileName, "w");
    if (!tempFile) {
        printf("Error creating a temporary file.\n");
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
            fprintf(tempFile, "Name: %s, Number: %s\n", name, newNumber);
            nameFound = 1;
        } else {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("phonebook.txt"); 
    rename(tempFileName, "phonebook.txt"); 

    if (!nameFound) {
        printf("Name not found.\n");
    }
}

int main() {
    int input = 0;

    do {
        puts("1. Add a new record");
        puts("2. Search for a name.");
        puts("3. Modify a phone number.");
        puts("4. Delete a record.");
        puts("5. Exit");
        scanf("%d", &input);getchar();

        switch (input) {
            case 1:
                newRecord();
                break;
            case 2:
                search();
                break;
            case 3:
                modifyPhoneNumber();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (input != 5);

    return 0;
}
