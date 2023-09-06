/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int start,step,stop;
    printf("Masukan nilai start:");
    scanf("%d", &start);
    printf("Masukan nilai stop:");
    scanf("%d", &stop);
    
    if(step !=0){
    for (int i = start; i<=stop; i++){
     printf("%d ", i);   
    }else {
        printf("ERRRORORORROROROROROROROROROROROORO!!!!!!!! YOUVE BEEN HACKED!!!!");
    }
    }
    return 0;
}

