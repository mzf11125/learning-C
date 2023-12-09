#include <stdio.h>
int main(){
    FILE *fp = fopen("testdata.in","r");
    if (fp==NULL){
        printf("The file does not exist!");
    }
    int T;
    fscanf(fp, "%d", &T);
    while (T>0){
        char X[100];
        fscanf(fp, "%s", X);
        int N;
        fscanf(fp, "%d", &N);
        char kapital;
        int c[26]={0};
        for (int i=0; i<N; i++){
            int j=0;
            fscanf(fp, "%c", &kapital);
            char a,b;
            fscanf(fp, "%c %c", &a, &b);
            c[a-65]++;
            while (X[j]!='\0'){
                if (X[j]==a && c[a-65]<=1){
                    X[j]=b;
                }
                j++;
            }
        }
        int d[26]={0};
        int j=0;
        while (X[j]!='\0'){
            int z=X[j]-65;
            d[z]++;
            j++;
            c[j]++;
        }
        for (int i=0; i<26; i++){
            if (d[i]>0){
                printf("%c %d\n", i+65, d[i]);
                d[i]=0;
            }
        }
        T--;
    }
    fclose(fp);
}
