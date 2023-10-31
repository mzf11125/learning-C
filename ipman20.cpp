//ipman2.0 by JollyBee

//String s

//All number and dot

//total dots = 5
//Dot tidak adjent

//number tidak boleh 0 di depan
#include <stdio.h>
#include <string.h>

bool all_num_or_dot(char s[]){
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        if('0' <= s[i] && s[i] <= '9' || s[i] == '.'){
            continue;
        }
        else if (s[i] = '.'){
            continue;
        }
        else{
            return false;
        }
    }

}

int number_of_dot(char s[]){
    int n = strlen(s);
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '.')sum++;
    }
    return sum;
}

bool pos_dot (char s[]){
    int n = strlen(s);

    if (s[0] == '.' || s[n-1] == '.'){
        return false;
    }

    for (int i = 0; i < ; i++){
        if (s[i] == '.' && s[i+1] == '.'){
            return false;
        }
    }
    else{
        return true;
    }

}

void solve(int *a, int *b){
    char s [200];
    scanf("%s",s);

    if(all_num_or_dot(s) == false ||){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }

}

int main(){
    int t;
    scanf("%d",&t);

    for (int i = 1; i <= t; i++)
    {
        printf("Case #%d: ", i);
        solve();
        // int n;
        // scanf("%d",&n);
        // int arr[n];
        // for (int j = 0; j < n; j++)
        // {
        //     scanf("%d",&arr[j]);
        // }
        // int count = 0;
        // for (int j = 0; j < n; j++)
        // {
        //     if (arr[j] == 1)
        //     {
        //         count++;
        //     }
            
        // }
        // if (count % 2 == 0)
        // {
        //     printf("0\n");
        // }
        // else
        // {
        //     printf("1\n");
        // }
        
    }


}