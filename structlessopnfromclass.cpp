#include <stdio.h> //documentation is in the code buddy
#include <string.h>

struct Mahasiswa{
	char nim[11];
	char nama[100];
	char agama[100];
	int uts, tm, uas;
	double gpa;
};

struct Mahasiswa mhs1 = {"1400118402", "Saya", "Atheist",90, 80, 95, 0.000005};

int main(){
	//initialize variable in struct
	strcpy(mhs1.nama, "Saya tidak bisa");
	printf("masukan nim anda: ");
	scanf("%[^\n]", &mhs1.nim);
	getchar();
	printf("masukan nama anda: ");
	scanf("%[^\n]", &mhs1.nama);
	getchar();
	printf("masukan agama anda: ");
	scanf("%[^\n]", &mhs1.agama);
	getchar();
	printf("masukan nilai uts anda: ");
	scanf("%d", &mhs1.uts);
	getchar();
	printf("masukan nilai tm anda: ");
	scanf("%d", &mhs1.tm);
	getchar();
	printf("masukan nilai uas anda: ");
	scanf("%d", &mhs1.uas);
	getchar();
	printf("masukan gpa anda: ");
	scanf("%lf", &mhs1.gpa);
	getchar();
	printf("nim: %s\n", mhs1.nim);
	printf("nama: %s\n", mhs1.nama);
	printf("agama: %s\n", mhs1.agama);
	printf("uts: %d\n", mhs1.uts);
	printf("tm: %d\n", mhs1.tm);
	printf("uas: %d\n", mhs1.uas);
	printf("gpa: %lf\n", mhs1.gpa);

	return 0;
}