#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <assert.h>


struct recipe{
	char ID[], menu[101];
	int DishPrice;
	int DishStock;
	recipe* next;
}*head, *tail;

//struct customer{
//	char ID[], menu[101];
//	int DishPrice;
//	int DishStock;
//	recipe* next;
//}*head, *tail;


//int getnextID{
//	statin
//}

//void popDishName{
//	
//};

//struc

//void rand_str(char *dest, size_t length) {
//    char charset[] = "0123456789"
//                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    while (length-- > 0) {
//        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
//        *dest++ = charset[index];
//    }
//    *dest = '\0';
//} // Randomize id number

//void pushHead(int age, char name[]){
//	Person* newPerson = createNewPerson(age,name);
//	if(head == NULL){
//		head = tail = newPerson; //newPerson sebagai struct yang baru akan menjadi head dan tails yang baru
//		//Struct akan diperiksa apakah pointer struct pertama kosong atau tidak
//	}
//	else{
//		newPerson->next = head;
//		head = newPerson;
//	}
//}



//void {
//	
//}
//
//void {
//}

int main(){
	int option;
	struct recipe;
	option = 0;
	puts("1. Insert New Dish");
	puts("2. Update Dish");
	puts("3. Delete Dish");
	puts("4. Add Customer");
	puts("5. Customer List");
	puts("6. Order");
	puts("7. Payment");
	puts("8. Exit	");
	printf(">> ");
	scanf("%d", &option);getchar();	
	
	if (option == 1){
		system("cls");
		puts("Input Dish Name [Must have minimum 2 words and every word start with capital], 0 to cancel:");
		scanf("")
	}
	
	else if(option == 2){
		system("cls");
		FILE *fp;
		char ch[101];
		fp = fopen("dish.txt", "r");
		while (!feof(fscan("dish.txt"))){
			getchar(ch);
			printf("\n");
		}
	}
	else if(option == 3){
		
	}
	else if(option == 4){
		
	}
	else if(option == 5){
		
	}
	else if(option == 6){
		
	}
	else if(option == 7){
		
	}
}


