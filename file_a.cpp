//#include <stdio.h>
//#include <string.h>
//
//// Define a struct to store student information
//struct Student {
//    char firstName[50];
//    char lastName[50];
//};
//
//// Function to compare two students based on their order
//int compareOrder(const struct Student *a, const struct Student *b, const char orderList[][50], int orderListSize) {
//    int indexA = -1, indexB = -1;
//    for (int i = 0; i < orderListSize; ++i) {
//        if (strcmp(a->firstName, orderList[i]) == 0) {
//            indexA = i;
//        }
//        if (strcmp(b->firstName, orderList[i]) == 0) {
//            indexB = i;
//        }
//    }
//
//    return indexA - indexB;
//}
//
//
//void selectionSort(struct Student arr[], int n, const char orderList[][50], int orderListSize) {
//    int i, j, minIndex;
//    struct Student temp;
//    for (i = 0; i < n - 1; ++i) {
//        minIndex = i;
//        for (j = i + 1; j < n; ++j) {
//            if (compareOrder(&arr[j], &arr[minIndex], orderList, orderListSize) < 0) {
//                minIndex = j;
//            }
//        }
//        temp = arr[i];
//        arr[i] = arr[minIndex];
//        arr[minIndex] = temp;
//    }
//}
//
//
//struct Student *linearSearch(struct Student arr[], int n, const char *key) {
//    for (int i = 0; i < n; ++i) {
//        if (strcmp(arr[i].firstName, key) == 0) {
//            return &arr[i];
//        }
//    }
//    return NULL;
//}
//
//// Function to print the result in the specified format
//void printResult(int caseNumber, const char *result) {
//    printf("Case #%d: %s\n", caseNumber, result);
//}
//
////int main() {
////    FILE *file = fopen("testdataidk.txt", "r");
////
////    if (!file) {
////        printf("Error opening file!\n");
////        return 1;
////    }
////
////    int numStudents;
////    fscanf(file, "%d", &numStudents);
////
////    
////    struct Student students[numStudents];
////    for (int i = 0; i < numStudents; ++i) {
////        fscanf(file, "%[^#]#%[^\n]\n", students[i].firstName, students[i].lastName);
////    }
////
////    int orderListSize;
////    fscanf(file, "%d", &orderListSize);
////
////    
////    char orderList[orderListSize][50];
////    for (int i = 0; i < orderListSize; ++i) {
////        fscanf(file, "%s", orderList[i]);
////    }
////
////    
////    selectionSort(students, numStudents, orderList, orderListSize);
////
////    int numPrint;
////    fscanf(file, "%d", &numPrint);
////
////    char studentToPrint[50];
////    for (int i = 0; i < numPrint; ++i) {
////        fscanf(file, "%s", studentToPrint);
////
////        
////        struct Student *found = linearSearch(students, numStudents, studentToPrint);
////
////        
////        if (found != NULL) {
////            printResult(i + 1, found->lastName);
////        } else {
////            printResult(i + 1, "N/A");
////        }
////    }
////
////    fclose(file);
////
////    return 0;
////}
//
//int main() {
//    FILE *file = fopen("testdataidk.txt", "r");
//
//    if (!file) {
//        printf("Error opening file!\n");
//        return 1;
//    }
//
//    int numStudents;
//    fscanf(file, "%d", &numStudents);
//
//    printf("Number of Students: %d\n", numStudents);
//
//    // Read and store student data
//    struct Student students[numStudents];
//    for (int i = 0; i < numStudents; ++i) {
//        fscanf(file, "%[^#]#%[^\n]\n", students[i].firstName, students[i].lastName);
//        printf("Student %d: %s %s\n", i + 1, students[i].firstName, students[i].lastName);
//    }
//
//    int orderListSize;
//    fscanf(file, "%d", &orderListSize);
//
//    printf("Order List Size: %d\n", orderListSize);
//
//    // Read order list from the file
//    char orderList[orderListSize][50];
//    for (int i = 0; i < orderListSize; ++i) {
//        fscanf(file, "%s", orderList[i]);
//        printf("Order List %d: %s\n", i + 1, orderList[i]);
//    }
//
//    // Sort students array using selection sort
//    selectionSort(students, numStudents, orderList, orderListSize);
//
//    int numPrint;
//    fscanf(file, "%d", &numPrint);
//
//    printf("Number of Prints: %d\n", numPrint);
//
//    char studentToPrint[50];
//    for (int i = 0; i < numPrint; ++i) {
//        fscanf(file, "%s", studentToPrint);
//        printf("Student to Print %d: %s\n", i + 1, studentToPrint);
//
//        // Use linear search to find the student
//        struct Student *found = linearSearch(students, numStudents, studentToPrint);
//
//        // Print the result in the specified format
//        if (found != NULL) {
//            printResult(i + 1, found->lastName);
//        } else {
//            printResult(i + 1, "N/A");
//        }
//    }
//
//    fclose(file);
//
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//// Define a struct to store student information
//struct Student {
//    char firstName[50];
//    char lastName[50];
//};
//
//// Function to compare two students based on their order
//int compareOrder(const struct Student *a, const struct Student *b, const char orderList[][50], int orderListSize) {
//    int indexA = -1, indexB = -1;
//    for (int i = 0; i < orderListSize; ++i) {
//        if (strcmp(a->firstName, orderList[i]) == 0) {
//            indexA = i;
//        }
//        if (strcmp(b->firstName, orderList[i]) == 0) {
//            indexB = i;
//        }
//    }
//
//    return indexA - indexB;
//}
//
//// Function to perform selection sort
//void selectionSort(struct Student arr[], int n, const char orderList[][50], int orderListSize) {
//    int i, j, minIndex;
//    struct Student temp;
//    for (i = 0; i < n - 1; ++i) {
//        minIndex = i;
//        for (j = i + 1; j < n; ++j) {
//            if (compareOrder(&arr[j], &arr[minIndex], orderList, orderListSize) < 0) {
//                minIndex = j;
//            }
//        }
//        temp = arr[i];
//        arr[i] = arr[minIndex];
//        arr[minIndex] = temp;
//    }
//}
//
//// Function to perform linear search
//struct Student *linearSearch(struct Student arr[], int n, const char *key) {
//    for (int i = 0; i < n; ++i) {
//        if (strcmp(arr[i].firstName, key) == 0) {
//            return &arr[i];
//        }
//    }
//    return NULL;
//}
//
//// Function to print the result in the specified format
//void printResult(int caseNumber, const char *result) {
//    printf("Case #%d: %s\n", caseNumber, result);
//}
//
//int main() {
//    FILE *file = fopen("testdataidk.txt", "r");
//
//    if (!file) {
//        printf("Error opening file!\n");
//        return 1;
//    }
//
//    int numStudents;
//    fscanf(file, "%d", &numStudents);
//
//    printf("Number of Students: %d\n", numStudents);
//
//    // Read and store student data
//    struct Student students[numStudents];
//    for (int i = 0; i < numStudents; ++i) {
//        fscanf(file, "%[^#]#%[^\n]\n", students[i].firstName, students[i].lastName);
//        printf("Student %d: %s %s\n", i + 1, students[i].firstName, students[i].lastName);
//    }
//
//    int orderListSize;
//    fscanf(file, "%d", &orderListSize);
//
//    printf("Order List Size: %d\n", orderListSize);
//
//    // Read order list from the file
//    char orderList[orderListSize][50];
//    for (int i = 0; i < orderListSize; ++i) {
//        fscanf(file, "%s", orderList[i]);
//        printf("Order List %d: %s\n", i + 1, orderList[i]);
//    }
//
//    // Sort students array using selection sort
//    selectionSort(students, numStudents, orderList, orderListSize);
//
//    // Read the number of prints
//    int numPrint;
//    if (fscanf(file, "%d", &numPrint) != 1) {
//        printf("Error reading the number of prints!\n");
//        fclose(file);
//        return 1;
//    }
//
//    printf("Number of Prints: %d\n", numPrint);
//
//    // Check for end of file
//    if (feof(file)) {
//        printf("End of file reached unexpectedly!\n");
//        fclose(file);
//        return 1;
//    }
//
//    char studentToPrint[50];
//    for (int i = 0; i < numPrint; ++i) {
//        fscanf(file, "%s", studentToPrint);
//        printf("Student to Print %d: %s\n", i + 1, studentToPrint);
//
//        // Use linear search to find the student
//        struct Student *found = linearSearch(students, numStudents, studentToPrint);
//
//        // Print the result in the specified format
//        if (found != NULL) {
//            printResult(i + 1, found->lastName);
//        } else {
//            printResult(i + 1, "N/A");
//        }
//    }
//
//    fclose(file);
//
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//
//// Define a struct to store student information
//struct Student {
//    char firstName[50];
//    char lastName[50];
//};
//
//// Function to compare two students based on their order
//int compareOrder(const struct Student *a, const struct Student *b, const char orderList[][50], int orderListSize) {
//    int indexA = -1, indexB = -1;
//    for (int i = 0; i < orderListSize; ++i) {
//        if (strcmp(a->firstName, orderList[i]) == 0) {
//            indexA = i;
//        }
//        if (strcmp(b->firstName, orderList[i]) == 0) {
//            indexB = i;
//        }
//    }
//
//    return indexA - indexB;
//}
//
//// Function to perform selection sort
//void selectionSort(struct Student arr[], int n, const char orderList[][50], int orderListSize) {
//    int i, j, minIndex;
//    struct Student temp;
//    for (i = 0; i < n - 1; ++i) {
//        minIndex = i;
//        for (j = i + 1; j < n; ++j) {
//            if (compareOrder(&arr[j], &arr[minIndex], orderList, orderListSize) < 0) {
//                minIndex = j;
//            }
//        }
//        temp = arr[i];
//        arr[i] = arr[minIndex];
//        arr[minIndex] = temp;
//    }
//}
//
//// Function to perform linear search
//struct Student *linearSearch(struct Student arr[], int n, const char *key) {
//    for (int i = 0; i < n; ++i) {
//        if (strcmp(arr[i].firstName, key) == 0) {
//            return &arr[i];
//        }
//    }
//    return NULL;
//}
//
//// Function to print the result in the specified format
//void printResult(int caseNumber, const char *result) {
//    printf("Case #%d: %s\n", caseNumber, result);
//}
//
//int main() {
//    FILE *file = fopen("testdataidk.txt", "r");
//
//    if (!file) {
//        printf("Error opening file!\n");
//        return 1;
//    }
//
//    int numStudents;
//    if (fscanf(file, "%d", &numStudents) != 1) {
//        printf("Error reading the number of students!\n");
//        fclose(file);
//        return 1;
//    }
//
//    printf("Number of Students: %d\n", numStudents);
//
//    // Read and store student data
//    struct Student students[numStudents];
//    for (int i = 0; i < numStudents; ++i) {
//        if (fscanf(file, "%[^#]#%[^\n]\n", students[i].firstName, students[i].lastName) != 2) {
//            printf("Error reading student data!\n");
//            fclose(file);
//            return 1;
//        }
//        printf("Student %d: %s %s\n", i + 1, students[i].firstName, students[i].lastName);
//    }
//
//    int orderListSize;
//    if (fscanf(file, "%d", &orderListSize) != 1) {
//        printf("Error reading the order list size!\n");
//        fclose(file);
//        return 1;
//    }
//
//    printf("Order List Size: %d\n", orderListSize);
//
//    // Read order list from the file
//    char orderList[orderListSize][50];
//    for (int i = 0; i < orderListSize; ++i) {
//        if (fscanf(file, "%s", orderList[i]) != 1) {
//            printf("Error reading order list!\n");
//            fclose(file);
//            return 1;
//        }
//        printf("Order List %d: %s\n", i + 1, orderList[i]);
//    }
//
//    // Sort students array using selection sort
//    selectionSort(students, numStudents, orderList, orderListSize);
//
//    // Read the number of prints
//    int numPrint;
//    if (fscanf(file, "%d", &numPrint) != 1) {
//        printf("Error reading the number of prints!\n");
//        fclose(file);
//        return 1;
//    }
//
//    printf("Number of Prints: %d\n", numPrint);
//
//    // Check for end of file
//    if (feof(file)) {
//        printf("End of file reached unexpectedly!\n");
//        fclose(file);
//        return 1;
//    }
//
//    char studentToPrint[50];
//    for (int i = 0; i < numPrint; ++i) {
//        if (fscanf(file, "%s", studentToPrint) != 1) {
//            printf("Error reading student to print!\n");
//            fclose(file);
//            return 1;
//        }
//        printf("Student to Print %d: %s\n", i + 1, studentToPrint);
//
//        // Use linear search to find the student
//        struct Student *found = linearSearch(students, numStudents, studentToPrint);
//
//        // Print the result in the specified format
//        if (found != NULL) {
//            printResult(i + 1, found->lastName);
//        } else {
//            printResult(i + 1, "N/A");
//        }
//    }
//
//    fclose(file);
//
//    return 0;
//}
#include <stdio.h>
#include <string.h>

// Define a struct to store student information
struct Student {
    char firstName[50];
    char lastName[50];
};

// Function to compare two students based on their order
int compareOrder(const struct Student *a, const struct Student *b, const char orderList[][50], int orderListSize) {
    int indexA = -1, indexB = -1;
    for (int i = 0; i < orderListSize; ++i) {
        if (strcmp(a->firstName, orderList[i]) == 0) {
            indexA = i;
        }
        if (strcmp(b->firstName, orderList[i]) == 0) {
            indexB = i;
        }
    }

    return indexA - indexB;
}

// Function to perform selection sort
void selectionSort(struct Student arr[], int n, const char orderList[][50], int orderListSize) {
    int i, j, minIndex;
    struct Student temp;
    for (i = 0; i < n - 1; ++i) {
        minIndex = i;
        for (j = i + 1; j < n; ++j) {
            if (compareOrder(&arr[j], &arr[minIndex], orderList, orderListSize) < 0) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to perform linear search
struct Student *linearSearch(struct Student arr[], int n, const char *key) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(arr[i].firstName, key) == 0) {
            return &arr[i];
        }
    }
    return NULL;
}

// Function to print the result in the specified format
void printResult(int caseNumber, const char *result) {
    printf("Case #%d: %s\n", caseNumber, result);
}

int main() {
    FILE *file = fopen("testdataidk.txt", "r");

    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    int numStudents;
    if (fscanf(file, "%d", &numStudents) != 1) {
        printf("Error reading the number of students!\n");
        fclose(file);
        return 1;
    }

    printf("Number of Students: %d\n", numStudents);

    // Read and store student data
    struct Student students[numStudents];
    for (int i = 0; i < numStudents; ++i) {
        if (fscanf(file, "%[^#]#%[^\n]\n", students[i].firstName, students[i].lastName) != 2) {
            printf("Error reading student data!\n");
            fclose(file);
            return 1;
        }
        printf("Student %d: %s %s\n", i + 1, students[i].firstName, students[i].lastName);
    }

	int orderListAndPrintsSize;
	if (fscanf(file, "%d", &orderListAndPrintsSize) != 1) {
    	printf("Error reading the order list and prints size!\n");
    	fclose(file);
    	return 1;
	}	

	printf("Order List and Prints Size: %d\n", orderListAndPrintsSize);

	// Separate the value into orderListSize and numPrints
	int orderListSize = orderListAndPrintsSize;
	int numPrints = orderListAndPrintsSize;

	printf("Order List Size: %d\n", orderListSize);
	printf("Number of Prints: %d\n", numPrints);

    printf("Order List Size: %d\n", orderListSize);
    printf("Number of Prints: %d\n", numPrints);

    // Read order list from the file
    char orderList[orderListSize][50];
    for (int i = 0; i < orderListSize; ++i) {
        if (fscanf(file, "%s", orderList[i]) != 1) {
            printf("Error reading order list!\n");
            fclose(file);
            return 1;
        }
        printf("Order List %d: %s\n", i + 1, orderList[i]);
    }

    // Sort students array using selection sort
    selectionSort(students, numStudents, orderList, orderListSize);

    char studentToPrint[50];
    for (int i = 0; i < numPrints; ++i) {
        if (fscanf(file, "%s", studentToPrint) != 1) {
            printf("Error reading student to print!\n");
            fclose(file);
            return 1;
        }
        printf("Student to Print %d: %s\n", i + 1, studentToPrint);

        // Use linear search to find the student
        struct Student *found = linearSearch(students, numStudents, studentToPrint);

        // Print the result in the specified format
        if (found != NULL) {
            printResult(i + 1, found->lastName);
        } else {
            printResult(i + 1, "N/A");
        }
    }

    fclose(file);

    return 0;
}
