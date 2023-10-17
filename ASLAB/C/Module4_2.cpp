#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Modul 4_2 - 12 Oktober 2023
//Single Linked List
/*
-Di linked list, sebuah pointer akan digunakan di setiap struct dalam struct array untuk 
menyimpan alamat struct selanjutnya
-Struct pertama dalam struct array disebut sebagai head(sebuah pointer yang menyimpan alamat struct pertama)
Struct terakhir disebut sebagai tails(sebuah pointer yang menyimpan alamat struct alamat terakhir)
*/
struct Person{
	int age;
	char name[101];
	Person* next;
}*head,*tail;//biasanya pointer head dan tail ditaruh di akhir kurung kurawal struct
Person* createNewPerson(int age, char name[]){
	//dalam kurungnya berisi parameter/data yang nantinya dimasukkin
	Person* newPerson = (Person*)malloc(sizeof(Person));//malloc = memory allocation(membuat sebuah struct kosong yang sizenya sama seperti struct yang ditiru
	//malloc(sizeof(Person)=> void pointer
	//Person* di sebelah malloc merupakan typecast
	strcpy(newPerson->name, name);
	//tipe data yang menggunakan pointer tidak menggunakan . namun tanda panah->
	newPerson->age = age;
	//newPerson->age sama kaya mahasiswa.age
	newPerson->next = NULL;
	//next dalam struct pertama dikosongkan untuk memasukan struct newPerson yang baru
	return newPerson;
	//Push Head : mendorong posisi dari stuct pertama/menaruh struct baru newPerson di depan struct pertama
	//Push Tail: menaruh struct baru newPerson di belakang struct terakhir
}

void pushHead(int age, char name[]){
	Person* newPerson = createNewPerson(age,name);
	if(head == NULL){
		head = tail = newPerson; //newPerson sebagai struct yang baru akan menjadi head dan tails yang baru
		//Struct akan diperiksa apakah pointer struct pertama kosong atau tidak
	}
	else{
		newPerson->next = head;
		head = newPerson;
		//struct newPerson menjadi head yang baru
	}
}

void pushTail(int age, char name[]){
	Person* newPerson = createNewPerson(age,name);
	if(head == NULL){
		head = tail = newPerson;
	}else{
		tail->next = newPerson;
		tail = newPerson;
	}
}

//pushMid akan menambahkan data ke tengah, dan akan membandingkan diantara sebuah data
void pushMid(int age, char name[]){
	Person* newPerson = createNewPerson(age, name);
	if(head == NULL){
		head = tail = newPerson;
	}else if(age<= head->age){
		newPerson->next = head;
		head = newPerson;
		//jika age dari newPerson lebih kecil dibanding head maka dia akan dipindahkan ke depan head
	}else{
		Person* curr = head;
		while(curr->next != NULL && age > curr->next->age){
			curr = curr->next;
		}
		newPerson->next = curr->next;
		curr->next = newPerson;
	}
}

void popHead(){
	if(head==NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		free(head);
	}else{
		Person* temp = head;
		head = head->next;
		temp = NULL;
		free(temp);
	}
}

void popTail(){
	if(head==NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		free(head);
	}else{
		Person* temp = head;
		while(temp->next->next !=NULL){
			temp = temp->next;
		}//untuk menghapus tail maka kita harus looping dari struct awal ke struct yang sebelum tail
			temp->next = NULL;
			free(temp->next);
			tail = temp;
	}//tail yang sekarang dibikin menjadi NULL lalu dihilangkan atau difree, struct yang sebelum tail akan menjadi tail yang baru
}

void printData(){
	Person* curr = head;
	/*curr adalah pointer yang merupakan pointer yang mengganti alamat dirinya menjadi alamat struct selanjut
	curr menggantikan next. curr akan berpindah dari satu struct ke struct selanjutnya secara terus meneurs
	Istilahnya, curr adalah pointer yang menunjuk ke sebuah pointer seperti next*/
	while(curr!= NULL){
		printf("Nama : %s, Umur : %d\n",curr->name, curr->age);
		curr = curr->next;//artinya curr yang dari pointer struct sebelumnya akan berpindah pointer struct selanjutnya
	}
	//curr akan terus berpindah dari satu struct ke struct selanjutnya sampai struct yang terprint habis
}
//Push Head

int main(){
	pushMid(12, "Budi");
	pushMid(15, "Andi");
	pushMid(17, "Jojo");
	pushMid(10, "Anthony");
	pushMid(12, "Cici");
	
	popHead();//menghilangkan Head atau data yang paling awal
	popTail();//menghilangkan Tail atau data yang paling akhir
	printData();
}
