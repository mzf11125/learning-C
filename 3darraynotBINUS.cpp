#include <stdio.h>

// Function prototypes
void read_matrix(int m, int n, int a[10][10]);
void print_matrix(int m, int n, int a[10][10]);
void mat_add(int m1[10][10], int m2[10][10], int m3[10][10], int r1, int c1, int r2, int c2);
void mat_mul(int m1[10][10], int m2[10][10], int m3[10][10], int r1, int c1, int r2, int c2);
void transpose(int m1[10][10], int m2[10][10], int r1, int c1);
int menu(void);

int main() {
    // Variable declarations
    int m1, m2, n1, n2;
    int mat1[10][10], mat2[10][10], mat3[10][10];
    int op, ch = 3;

    // Main program loop
    while (ch != 0) {
        // Display menu and get user choice
        ch = menu();

        // Switch statement for different options
        switch (ch) {
            case 1:
                // Read first matrix
                printf("Enter dimensions of the first matrix: ");
                scanf("%d%d", &m1, &n1);
                read_matrix(m1, n1, mat1);
                break;
            case 2:
                // Read and print matrix
                printf("Enter dimensions of the matrix: ");
                scanf("%d%d", &m1, &n1);
                read_matrix(m1, n1, mat1);
                print_matrix(m1, n1, mat1);
                break;
            case 3:
                // Add two matrices
                printf("Enter dimensions of the first matrix: ");
                scanf("%d%d", &m1, &n1);
                printf("Enter dimensions of the second matrix: ");
                scanf("%d%d", &m2, &n2);

                // Check if addition is possible
                if (m1 != m2 || n1 != n2) {
                    printf("Addition is not possible.\n");
                    break;
                }

                // Read matrices
                read_matrix(m1, n1, mat1);
                read_matrix(m2, n2, mat2);

                // Add matrices
                mat_add(mat1, mat2, mat3, m1, n1, m2, n2);

                // Print result
                print_matrix(m1, n1, mat3);
                break;
            case 4:
                // Multiply two matrices
                printf("Enter dimensions of the first matrix: ");
                scanf("%d%d", &m1, &n1);
                printf("Enter dimensions of the second matrix: ");
                scanf("%d%d", &m2, &n2);

                // Check if multiplication is possible
                if (n1 != m2) {
                    printf("Multiplication is not possible.\n");
                    break;
                }

                // Read matrices
                read_matrix(m1, n1, mat1);
                read_matrix(m2, n2, mat2);

                // Multiply matrices
                mat_mul(mat1, mat2, mat3, m1, n1, m2, n2);

                // Print result
                print_matrix(m1, n2, mat3);
                break;
            case 5:
                // Transpose a matrix
                printf("Enter dimensions of the matrix: ");
                scanf("%d%d", &m1, &n1);

                // Read matrix
                read_matrix(m1, n1, mat1);

                // Transpose matrix
                transpose(mat1, mat2, m1, n1);

                // Print result
                print_matrix(n1, m1, mat2);
                break;
            case 0:
                // Exit program
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }

    return 0;
}

// Function to read a matrix
void read_matrix(int m, int n, int a[10][10]) {
    int i, j;
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

// Function to print a matrix
void print_matrix(int m, int n, int a[10][10]) {
    int i, j;
    printf("The matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void mat_add(int m1[10][10], int m2[10][10], int m3[10][10], int r1, int c1, int r2, int c2) {
    if (r1 != r2 || c1 != c2) {
        printf("Matrices must have the same dimensions to be added.\n");
        return;
    }

    int i, j;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices
void mat_mul(int m1[10][10], int m2[10][10], int m3[10][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        printf("First matrix's columns must equal the second matrix's rows for multiplication.\n");
        return;
    }

    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            m3[i][j] = 0;
            for (k = 0; k < c1; k++) {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transpose(int m1[10][10], int m2[10][10], int r1, int c1) {
    int i, j;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            m2[j][i] = m1[i][j]; // Swap i and j to achieve transpose
        }
    }
}

// Function to display menu and get user choice
int menu(void) {
    int op;
    printf("\nMatrix Operations Menu:\n");
    printf("1. Read a matrix\n");
    printf("2. Print a matrix\n");
    printf("3. Add two matrices\n");
    printf("4. Multiply two matrices\n");
    printf("5. Transpose a matrix\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &op);
    return op;
}
