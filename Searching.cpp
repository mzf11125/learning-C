#include <stdio.h>
#include <string.h>

// swapping string gk perlu pointer atau passing by reference
void swapString(char nama1[], char nama2[]){
	char temp[20];
	strcpy(temp, nama1);
	strcpy(nama1, nama2);
	strcpy(nama2, temp);
}


void bubbleSort(char nama[][20], int size){
	
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-1-i; j++){
			
			if(strcmp(nama[j], nama[j+1]) > 0){
//				char temp[20] = nama[j];
//				nama[j] = nama[j+1];
//				nama[j+1] = temp;
				swapString(nama[j], nama[j+1]);
			}
		}
	}
}



int linearSearchName(char nama[][20], int size, char find[]){
	
	for(int i = 0; i < size; i++){
		
		if(strcmp(nama[i], find) == 0){
			return i;
		}
	}
	
	return -1;
}


int binarySearchName(char nama[][20], int size, char find[]){
	
	int left = 0;
	int right = size - 1;
	
	while(left <= right){
		
		int mid = left + (right - left) / 2;
		
		if(strcmp(find, nama[mid]) == 0){
			
			return mid;
		}
		else if(strcmp(find, nama[mid]) < 0){
			right = mid - 1;
		}
		else if(strcmp(find, nama[mid]) > 0){
			left = mid + 1;
		}
	}
	
	return -1;
}

int binarySearchNameUsingRecursion(char nama[][20], int left, int right, char find[]){
	
	while(left <= right){
		
		int mid = left + (right - left) / 2;
		
		if(strcmp(find, nama[mid]) == 0){
			
			return mid;
		}
		else if(strcmp(find, nama[mid]) < 0){
			return binarySearchNameUsingRecursion(nama, left, mid-1, find);
		}
		else if(strcmp(find, nama[mid]) > 0){
			return binarySearchNameUsingRecursion(nama, mid+1, right, find);
		}
	}
	
}

void printArr(char nama[][20], int size){
	
	for(int i = 0; i < size; i++){
		printf("%s ", nama[i]);
	}
	puts("");
}


int main(){
	
	char nama[5][20] = {"Irene", "Hanif", "Benny", "Jojo", "Lili"};
	char find[20];
	printf("Enter name to be searched: ");
	
	scanf("%[^\n]", &find); getchar();

/*		bagian linear search	
	int hasil = linearSearchName(nama, 5, find);
	
	if(hasil == -1){
		printf("Name %s is not found\n", find);
	}
	else{
		printf("Name %s is found at index %d\n", find, hasil);
	}
*/	
	
	bubbleSort(nama, 5);
	printArr(nama, 5);
	
	printf("%d\n", binarySearchName(nama, 5, find));
	
	return 0;
}
