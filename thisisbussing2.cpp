#include <stdio.h>
#include <string.h>

void search(const char* name) {
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

void newrecord() {
    FILE* file = fopen("phonebook.txt", "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char name[20];
    char number[20];
    printf("Enter the name you want to add: ");
    scanf("%s", name);
    printf("Enter the number you want to add: ");
    scanf("%s", number);
    fprintf(file, "Name: %s, Number: %s\n", name, number);
    fclose(file);
}

void displayFile() {
    FILE* file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        printf("%s\n", line);
    }

    fclose(file);
}


void deleterecord(const char* name) {
    FILE* file = fopen("phonebook.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char line[100];
    FILE* temp = fopen("temp.txt", "w");
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            found = 1;
        } else {
            fputs(line, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (!found) {
        printf("Name not found.\n");
    } else {
        remove("phonebook.txt");
        rename("temp.txt", "phonebook.txt");
    }
}

void phonenumber(const char* name) {
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

int main() {
    int input = 0;
    do {
        puts("1. Add a new record");
        puts("2. Search for a name.");
        puts("3. Modify a phone number.");
        puts("4. Delete a record.");
        puts("5. Exit");
        scanf("%d", &input);

        switch (input) {
            case 1:
                displayFile();
                newrecord();
                displayFile();
                break;
            case 2: {
                displayFile();
                char name[20];
                printf("Enter the name you want to search for: ");
                scanf("%s", name);
                search(name);
                break;
            }
            case 3: {
                char name[20];
                displayFile();
                printf("Enter the name you want to modify: ");
                scanf("%s", name);
                phonenumber(name);
                break;
            }
            case 4: {
                char name[20];
                displayFile();
                printf("Enter the name you want to delete: ");
                scanf("%s", name);
                deleterecord(name);
                break;
            }
            case 5:
                return 0;
            default:
                break;
        }

    } while (input != 5);

    return 0;
}
