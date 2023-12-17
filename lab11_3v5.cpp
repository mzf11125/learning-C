#include <stdio.h>
#include <stdbool.h> // Include the necessary header for the boolean type

int board[8][8] = {0};

int number_move[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int letter_move[8] = {1, -1, -2, -2, 1, -1, 2, 2};

// Fix the absolute_value function to return the absolute value
int absolute_value(int i){
	if(i < 0){
		i *= -1;
	}
	return i; // Return the absolute value
}

bool result = false; // Make result false, boolean is true or false

void check_move(int letter1, int number1, int letter2, int number2, int letter3, int number3, int total){
	if(number3 < 0 || number3 > 7 || letter3 < 0 || letter3 > 7){
		return; // Stop the function if move is out of bound
	}
	if(number3 == number2 && letter3 == letter2){
		result = true; // True because the second and third move are equal
		return;
	}
	if(total <= 0){ // Fix the condition to check if total is less than or equal to zero
		return; // Break if total is less than or equal to zero
	}
	if(absolute_value(letter1 - letter2) < absolute_value(letter3 - letter2) && absolute_value(number1 - number2) < absolute_value(number3 - number2)){
		return;	
	}
	for(int i = 0; i < 8; i++){
		if(result == true){ // Result is true, so break the for loop
			break;
		}
		else{
			check_move(letter1, number1, letter2, number2, letter3 + letter_move[i], number3 + number_move[i], total - 1); // Recursion
		}
	}            
}

int main(){
	long long tc;
	scanf("%lld", &tc);
	getchar();

	for(int i = 0; i < tc; i++){
		long long total;
		scanf("%lld", &total); 
		getchar();
		char letter1, letter2;
		int number1, number2;
		scanf("%c%d %c%d", &letter1, &number1, &letter2, &number2);
		getchar();
		letter1 -= 'A';
		letter2 -= 'A';
		number1 -= 1;
		number2 -= 1;
		result = false;
		check_move(letter1, number1, letter2, number2, letter1, number1, total * 2);
		if(result)
			printf("Case #%d: YES\n", i + 1);
		else
			printf("Case #%d: NO\n", i + 1);
	}
	
	return 0; // Add a return statement at the end of the main function
}
