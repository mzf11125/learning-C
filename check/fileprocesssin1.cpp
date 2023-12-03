////fileprocessing.cpp
//#include <stdio.h>
//#include <string.h>
//
//FILE* files = fopen("menu.txt", "r");
//
//struct orders{
//	int qty;
//	char makanan[100];
//	int harga_satuan;
//	int total;
//	
//};
//
//int main()
//{
//     if(files == NULL) {
//         printf("File not found\n");
//     }
//     else if (files != NULL)
//     {
////         char str[100];
////         while(fgets(str, 100, files) != NULL) {//Belum abis, print semua
////             printf("%s", str);
////         }
//		struct orders ord[100];
//		int i = 0;
//		while(!feof(files)) {//Belum abis, print semua
//			fscanf(files, %d-[^-]-%d\n, &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan);
//			i++;
//         }   
//		 for(int j = 0; j < i; j++){
//         	printf("%-3d | %-20s | %-10d", &ord[j].qty, ord[j].makanan, &ord[j].harga_satuan);
//		 }
//     
////    char strings[1000];
////    fscanf(files,"%[^\n]\n", strings);
////    printf("%s\n", strings);
//    fclose(files);
//    return 0;
//}

//fileprocessing.cpp
//#include <stdio.h>
//#include <string.h>
//
//FILE* files = fopen("menu.txt", "r");
//
//struct orders {
//    int qty;
//    char makanan[100];
//    int harga_satuan;
//    int total;
//};
//
//int main() {
//    if (files == NULL) {
//        printf("File not found\n");
//        return 1; // Add return statement to exit the program if the file is not found
//    }
//    else {
//        struct orders ord[100];
//        int i = 0;
//        while (fscanf(files, "%d-[^-]-%d\n", &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan)) {
//        	ord[i].total=ord[i].qty*ord[i].harga_satuan;
//            i++;
//        }
//
//        for (int j = 0; j < i; j++) {
//            printf("%-3d | %-20s | %-10d\n", ord[j].qty, ord[j].makanan, ord[j].harga_satuan);
//        }
//
//        fclose(files);
//        return 0;
//    }
//}

//fileprocessing.cpp
//#include <stdio.h>
//#include <string.h>
//
//FILE* files = fopen("menu.txt", "r");
//
//struct orders {
//    int qty;
//    char makanan[100];
//    int harga_satuan;
//    int total;
//};
//
//int main() {
//    if (files == NULL) {
//        printf("File not found\n");
//        return 1; // Add return statement to exit the program if the file is not found
//    }
//    else {
//        struct orders ord[100];
//        int i = 0;
//        // Corrected the fscanf format string and loop condition
////        while (fscanf(files, "%d-%99[^-]-%d\n", &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan) == 3) {
//		while(!feof(files))
//		{
//			fscanf(files, "%d-%99[^-]-%d\n", &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan);
////            ord[i].total = ord[i].qty * ord[i].harga_satuan;
//            i++;
//        }
//
//        for (int j = 0; j < i; j++) {
//            // Modified the printf format string to include total
//            printf("%-3d | %-20s | %-10d | %-10d | %-10d\n", ord[j].qty, ord[j].makanan, ord[j].harga_satuan, (ord[j].qty*ord[j].harga_satuan));
//        }
//
//        fclose(files);
//        return 0;
//    }
//}

////fileprocessing.cpp
//#include <stdio.h>
//#include <string.h>
//
//FILE* files = fopen("menu.txt", "r");
//
//struct orders{
//	int qty;
//	char makanan[100];
//	int harga_satuan;
//	int total;
//	
//};
//
//int main()
//{
//     if(files == NULL) {
//         printf("File not found\n");
//     }
//     else if (files != NULL)
//     {
////         char str[100];
////         while(fgets(str, 100, files) != NULL) {//Belum abis, print semua
////             printf("%s", str);
////         }
//		struct orders ord[100];
//		int i = 0;
//		while(!feof(files)) {//Belum abis, print semua
//			fscanf(files, %d-[^-]-%d\n, &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan);
//			i++;
//         }   
//		 for(int j = 0; j < i; j++){
//         	printf("%-3d | %-20s | %-10d", &ord[j].qty, ord[j].makanan, &ord[j].harga_satuan);
//		 }
//     
////    char strings[1000];
////    fscanf(files,"%[^\n]\n", strings);
////    printf("%s\n", strings);
//    fclose(files);
//    return 0;
//}

//fileprocessing.cpp
//#include <stdio.h>
//#include <string.h>
//
//FILE* files = fopen("menu.txt", "r");
//
//struct orders {
//    int qty;
//    char makanan[100];
//    int harga_satuan;
//    int total;
//};
//
//int main() {
//    if (files == NULL) {
//        printf("File not found\n");
//        return 1; // Add return statement to exit the program if the file is not found
//    }
//    else {
//        struct orders ord[100];
//        int i = 0;
//        while (fscanf(files, "%d-[^-]-%d\n", &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan)) {
//        	ord[i].total=ord[i].qty*ord[i].harga_satuan;
//            i++;
//        }
//
//        for (int j = 0; j < i; j++) {
//            printf("%-3d | %-20s | %-10d\n", ord[j].qty, ord[j].makanan, ord[j].harga_satuan);
//        }
//
//        fclose(files);
//        return 0;
//    }
//}

//fileprocessing.cpp
#include <stdio.h>
#include <string.h>

FILE* files = fopen("menu.txt", "r");

struct orders {
    int qty;
    char makanan[100];
    int harga_satuan;
    int total;
};

int main() {
    if (files == NULL) {
        printf("File not found\n");
        return 1; // Add return statement to exit the program if the file is not found
    }
    else {
        struct orders ord[100];
        int i = 0;
        // Corrected the fscanf format string and loop condition
//        while (fscanf(files, "%d-%99[^-]-%d\n", &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan) == 3) {
		while(!feof(files))
		{
			fscanf(files, "%d-%99[^-]-%d\n", &ord[i].qty, ord[i].makanan, &ord[i].harga_satuan);
            ord[i].total = ord[i].qty * ord[i].harga_satuan;
            i++;
        }

        for (int j = 0; j < i; j++) {
            // Modified the printf format string to include total
            printf("%-3d | %-20s | %-10d | %-10d\n", ord[j].qty, ord[j].makanan, ord[j].harga_satuan, rd[j].total);
        }
         
        printf("%d");

        fclose(files);
        return 0;
    }
}



