#include <stdio.h>
#include <string.h>


struct Mahasiswa{
    char name[101];
    int age;
    double gpa;
};

int main()
{
    Mahasiswa a;
    strcpy(a.name, "Jason");
    a.age = 10;
    a.gpa = 3.5;
    
    Mahasiswa peoples[5];
    strcpy(peoples[0].name, "Budi");
    peoples[0].age = 15;
    peoples[0].gpa = 3.2;
    
    strcpy(peoples[1].name, "Jojo");
    peoples[1].age = 12;
    peoples[1].gpa = 3.7;
    
    strcpy(peoples[2].name, "Kiki");
    peoples[2].age = 18;
    peoples[2].gpa = 3.3;    
    
    for (int i = 0; i < 3; i++){
        printf("%s %d %lf\n", peoples[i].name, peoples[i].age, peoples[i].gpa);
    }
    
    printf("Nama: %s, Age: %d, Gpa: %lf\n", a.name, a.age, a.gpa);
    
    printf("%lld", sizeof(Mahasiswa));
    
    

    return 0;
}


