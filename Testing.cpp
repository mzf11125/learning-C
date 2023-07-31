#include<stdio.h>

int main(){
	
// 	Data types
//	integer - int	--> numbers {1,2,3,4,5}
// 	character - char --> {A,B,C,D,1,2,3,4,-,+}
//	float --> coma "," 1.5, 2.5, 3.5
//	double --> coma number that is bigger than float\
//	long (similar as integer) but bigger
//	boolean -- bool --> true or false

//	variable --> place to keep data for certain types of data 
//	[type data] [variable name] = [contain]
//	"" = string 
//	array of character 

//    int angka = 10;
//    char a = 'a';
//    float coma = 1.5;
//    double coma2 = 2.5;

//    char name[51] = "Zidan";
    
//    printf("Angkanya = %d, Character = %c\n", angka, a);
//    printf("coma = %.2f, Coma2 = %2.lf\n", coma, coma2);
//	printf("Nama Saya %s\n", name);
	
//	ASCII --> every character has ASCII number
// 	ctrl + / --> //    
//	printf("hello world!");
//	prinf() only pint string
//	printf("%d %c\n", a, 72);

//	input = scanf() & is for directory
//	int input;
//	printf("Input a number: ");
//	scanf("%d", &input);
//	getchar();
//	printf("Your input: %d\n", input);
//	
//	char name[51];
//	printf("Enter your name: ");
//	scanf("%[^\n]", name);
//	getchar();//This is a function to use to take input of a single character from the standart input stream present in the stdin library
//	printf("Your name is %s\n", name);
//	printf("Hello %s!\n", name);

//	Arithmetic operation -> +-*/%
//	int a = 5;
//	int b = 7;
//	int total = a+b;
//	printf("The result of %d + %d is %d\n", a, b, total);
//	total = a-b;
//	printf("The result of %d - %d is %d\n", a, b, total);
//	total = a*b;
//	printf("The result of %d * %d is %d\n", a, b, total);	
//	total = a/b;
//	printf("The result of %d / %d is %d\n", a, b, total);
//	total = a%b;
//	printf("The result of %d mod %d is %d\n", a, b, total);
	
//	logical operation and relational operation
//	relational operation 
//  The result is always true or false
//	< > <= >= 
//	true = 1
//	false = 0

//	printf("%d\n", 5 < 7);
//	printf("%d\n", 7 < 5);
//	printf("%d\n", 5 > 7);
//	printf("%d\n", 7 > 5);
//	printf("%d\n", 5 <= 7);
//	printf("%d\n", 7 <= 5);
//	printf("%d\n", 5 >= 7);
//	printf("%d\n", 7 >= 5);
//	Logical opration/ logical operator
// && || !

int a;//Declare variable a
int b;//Declare variable b
	scanf("%d %d", &a, &b);
	
//	selection
	if (a==b){
		printf("A is equal to B\n");
	}
//	else if(a > b && a > 5){
//		printf("A is greater than B\n");
//	}
// || or
//else if(a < b || a > 5){
//		printf("A is not smaller than B\n");
//	}
	else if(!(a<b)){
		printf("A is not smaller than B\n");
	}

	else {
		printf("A is not equal to B\n");
	}
	
	return 0;
}
