#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); 

    if (N>=0 && N<=50){
    long long total_outcomes = 1;
    for (int i = 0; i < N; i++) {
        total_outcomes *= 2; 
    }


    long long no_wins_outcomes = 1;

    for (int i = 0; i < N; i++) {
        no_wins_outcomes *= 1; 
    }

    
    long long at_least_one_win_outcomes = total_outcomes - no_wins_outcomes;

    printf("%lld\n", at_least_one_win_outcomes);
    
    }
    
    else{
        printf("Too big of a number\n");
    }

    return 0;
}
