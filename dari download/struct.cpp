#include <stdio.h>
#include <string.h>

struct Nilai{
	int uts, tm, uas;
};

struct Mahasiswa{
	
	char nim[11];
	char nama[100];
	
//	int uts, tm, uas;		// mau kita ubah pke nested struct
	struct Nilai nl;
	double gpa;
};

struct Mahasiswa mhs1{"1401118402", "Irene", 90, 80, 95, 3.86};

void iniArrayOfStruct(struct Mahasiswa mhs[]){
	
	strcpy(mhs[2].nama, "Jenni");
	mhs[2].nl.uts = 60;
	mhs[2].nl.uas = 85;
	mhs[2].nl.tm = 67;
	mhs[2].gpa = 4;
	
}

void iniStruct(struct Mahasiswa *mhs1){
	mhs1->nl.uas = 87;	// nl gk pke pointer (->) gra2 bkn jenis data pointer
}

int main (){
	
	// inisialisasi variable dalam struct
	
//	strcpy(mhs1.nama, "Irene Anindaputra");
//	mhs1.nl.tm = 100;	// cara ngakses nested struct
//	mhs1.nl.uts = 80;
//	
//	printf("Masukkan NIM anda: ");
//	scanf("%[^\n]", &mhs1.nim); getchar();
//	
//	printf("Masukkan IPK anda: ");
//	scanf("%lf", &mhs1.gpa); getchar();
//	printf("NIM anda adalah: %s\n", mhs1.nim);
//	printf("IPK anda adalah: %.2lf\n", mhs1.gpa);
//	printf("Nilai UTS anda adalah: %d\n", mhs1.nl.uts);
	
	
	iniStruct(&mhs1);
	printf("Nilai UAS %d\n", mhs1.nl.uas);
	
	// array of struct
	struct Mahasiswa mhs[100] = {{"987654321", "Vincent", 100, 95, 95, 3.96}, {"123456789", "Rex", 90, 80, 75, 3.7}};
	printf("%s\n", mhs[1].nama);
	
	iniArrayOfStruct(mhs);
	for(int i = 0; i < 3; i++){
		printf("Hi %s, nilai UTS anda %d, IPK anda %.2lf\n", mhs[i].nama, mhs[i].nl.uts, mhs[i].gpa);
	}
	
	return 0;
}
