#include <stdio.h>
#include <string.h>

struct Words{
    
    char shortAlp[55];
    char Alp[55];
    char arrToPrint[255];
};

int linearSearch(Words singkatan[], int size, char findString[]){
    
    for(int i = 0; i < size; i++){
        
        if(strcmp(singkatan[i].shortAlp, findString) == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    
    FILE *fp = fopen("testdata.in", "r");
    
    int testcase;
    fscanf(fp, "%d\n", &testcase);
    
    struct Words singkatan[105];
    
    for(int i = 0; i < testcase; i++){    
        fscanf(fp, "%[^#]#%[^\n]\n", &singkatan[i].shortAlp, &singkatan[i].Alp);
    }
    
    int numOfSentences;
    fscanf(fp, "%d\n", &numOfSentences);
    
    for(int i = 0; i < numOfSentences; i++){
    	
        printf("Case #%d:\n", i+1);
        char string[105];
        fscanf(fp, "%[^\n]\n", &string);
        
        char *token = strtok(string, " ");
        
        int index = 0;
        while(token != NULL){    // token if there is words and not null
        
            int foundAtIndex = linearSearch(singkatan, testcase, token);
            
            if(foundAtIndex != -1){
                strcpy(singkatan[index].arrToPrint, singkatan[foundAtIndex].Alp);
            }
            else if(foundAtIndex == -1){
                strcpy(singkatan[index].arrToPrint, token);
            }
            index++;
            token = strtok(NULL, " ");        // Take the words after so everything is converted
        }
        
        for(int j = 0; j < index; j++){
            if(j == index-1){
                printf("%s\n", singkatan[j].arrToPrint);
            }
            else{
                printf("%s ", singkatan[j].arrToPrint);
            }
        }
    }
    
    
    return 0;
}