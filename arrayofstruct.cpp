#include <stdio.h>
#include <string.h>


struct Mahasiswa{
	char nim[11];
	char nama[100];
	char agama[100];
	int uts, tm, uas;
	double gpa;
};

void initStruct(Mahasiswa &mhs) {
    strcpy(mhs.nim, "");
    strcpy(mhs.nama, "");
    strcpy(mhs.agama, "");
    mhs.uts = 0;
    mhs.tm = 0;
    mhs.uas = 0;
    mhs.gpa = 0.0;
}

int main(){
    struct Mahasiswa mhs[100];
    int n;
    printf("masukan jumlah mahasiswa: ");
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++){
        initStruct(mhs[i]);
        printf("masukan nim anda: ");
        scanf("%[^\n]", &mhs[i].nim);
        getchar();
        printf("masukan nama anda: ");
        scanf("%[^\n]", &mhs[i].nama);
        getchar();
        printf("masukan agama anda: ");
        scanf("%[^\n]", &mhs[i].agama);
        getchar();
        printf("masukan nilai uts anda: ");
        scanf("%d", &mhs[i].uts);
        getchar();
        printf("masukan nilai tm anda: ");
        scanf("%d", &mhs[i].tm);
        getchar();
        printf("masukan nilai uas anda: ");
        scanf("%d", &mhs[i].uas);
        getchar();
        printf("masukan gpa anda: ");
        scanf("%lf", &mhs[i].gpa);
        getchar();
    }
    for(int i=0; i<n; i++){
        printf("nim: %s\n", mhs[i].nim);
        printf("nama: %s\n", mhs[i].nama);
        printf("agama: %s\n", mhs[i].agama);
        printf("uts: %d\n", mhs[i].uts);
        printf("tm: %d\n", mhs[i].tm);
        printf("uas: %d\n", mhs[i].uas);
        printf("gpa: %lf\n", mhs[i].gpa);
    }
    return 0;
}