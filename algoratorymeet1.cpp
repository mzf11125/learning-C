#include<stdio.h>

int count = 0;

//Function -> simplify code
//void function
void printhello(){
	printf("Hello");
}


//non-void function => can return data
int sum(int a, int b){
	int hasil = a + b;
	return hasil;
}

//Recursive => Fungsi memanggil fungsinya
int factorial(int n){
	if(n==0 || n==1){
		return 1;
		count++;
	}
	else return n * factorial(n-1);
}

//int return(int z){
//	return z;
//}

int main(){
	//Recursive(floodfill+variation, rumus)
	//Sorting(greedy method(bubble sort), divide and conquer(merge sort, heap sort, ))
	//Statistik => cari median, q1, q3, IQR(Interquartile Range(q3-q1))
	//Struct(sorting, searching)
	//Searching => Cari Data
	//File => buka file, load file, sorting/searching
	//int hasil = sum(1,2);
	//printf("%d\n",hasil);
	//printhello();
	printf("%d\n", factorial(5));
	//printf("%d\n", return(2));
	//Recursive => Fungsi memanggil diri sendiri
	//Looping vs recursion => Search in google

	return 0;
	
}