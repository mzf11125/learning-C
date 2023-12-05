#include <stdio.h>
#include <string.h>

//Pivpot in this code is always at the end

int iterativeBinarySearch(char nama[5][20], int left, int right, char find[20]){
	while (left <= right){
		int mid = left + (right-left)/2;
		if(strcmp(nama[mid], find)){
			return mid;
		}else if(strcmp(find, nama[mid])>0){
			//Kecilkan area search kita ke arah kiri/arah value yang lebih kecil
			return right = mid - 1;
		}else if(strcmp(find, nama[mid])<0){
			//Kecilkan arah search ke arah yang lebih besar
			//Kiri/arah value yang lebih kecil
			left = mid+1;
		}
		
	}
	return -1;
}

void recursiveBinarySearch(char nama[5][20], int left, int right, char find[20]){
		while (left <= right){
		int mid = (left + right)/2;
		if(strcmp(nama[mid], find)){
			return mid;
		}else if(strcmp(find, nama[mid])>0){
			//Kecilkan area search kita ke arah kiri/arah value yang lebih kecil
			return recursiveBinarySearch(nama, 0, mid + 1, find);
//			right = mid - 1;
		}else if(strcmp(find, nama[mid])<0){
			//Kecilkan arah search ke arah yang lebih besar
			//Kiri/arah value yang lebih kecil
//			left = mid+1;
			return recursiveveBinarySearch(nama, 0, mid - 1, find);
		}
		
	}
	return -1;
}


void swap(char nama1[], char nama2[]){
	char temp[20];
	strcpy(temp, nama1);
	strcpy(nama1, nama2);
	strcpy(nama2, temp);
}

void print(char nama[5][20], int n){
	for(int i = 0; i < n; i++){
		printf("Case #%d: %s\n", i +1, nama[i]);	
	}
}

void bubbleSort(char nama[5][20], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(nama[j], nama[j + 1]) > 0) {
                swap(nama[j], nama[j + 1]);
            }
        }
    }
}

int linearSearch(char nama[5][20], int n, char find[]){
	for(int i = 0; i < n; i++){
		if(strcmp(nama[i], find)==0)return i+ 1;		
	}
	return -1;
}

int main(){
	char nama[5][20]={"Irene", "Hanif", "Benny", "Sussy", "John"};
	char find[20];
//	printf("Enter name to be searched: ");
//	scanf("%[^\n]", &find);getchar();
//	int hasil = linearSearch(nama, 5, find);
//	if(hasil == -1)printf("Not found");
//	else printf("%d", hasil);
	bubbleSort(nama, 5);
	print(nama, 5);
	int hasil = iterativeBinarySearch(nama, 0, 4, find);
	printf("Ada di array %d", hasil);
}

