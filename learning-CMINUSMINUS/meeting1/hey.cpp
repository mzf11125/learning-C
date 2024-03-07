#include <iostream>
using namespace std;

struct Student
{
    string Nama;
    string NIM;
    int umur;

    Student(string Nama, string NIM, int umur)
    {
        this->Nama = Nama;
        this->NIM = NIM;
        this->umur = umur;
    }

    void display()
    {
        cout << "Nama: " << Nama << endl;
        cout << "NIM: " << NIM << endl;
        cout << "umur: " << umur << endl;
    }
};

int main()
{
    string Nama, NIM;
    int umur;
    cin >> Nama >> NIM >> umur;

    Student A(Nama, NIM, umur);

    A.display();

    return 0;
}