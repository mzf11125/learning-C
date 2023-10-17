#include<stdio.h>
#include<stdlib.h>

//Modul 5 - 13 Oktober 2023
//double linked list

struct Data{
	int value;
	struct Data*next;
	struct Data*prev;//sama seperti linked list namun ditambakan pointer prev
}*head = NULL, *tail = NULL;

struct Data *newNote(int value){
	struct Data *node = (struct Data*) malloc(sizeof(struct Data));
	node -> value = value;
	node -> next = NULL;
	node -> prev = NULL;
	return node;//node berfungsi sebagai tempat menaruh head yang baru
}

void pushHead(int value){
	struct Data *node = newNote(value);
	if(head == NULL){
		head = tail = node;
	}else{
		node -> next = head;
		head -> prev = node;
		head = node;//konsep next, prev double linked list
		//Head dari struct lama dipindahkan ke struct baru, pointer next struct baru disambungkan ke struct lama dan pointer prev struct lama disambungkan ke struct baru yang sekarang menjadi head
	}
}

void pushTail(int value){
	struct Data *node = newNote(value);
	if(head == NULL){
		head = tail = node;
	}else{
		tail -> next = node;
		node -> prev = tail;
		tail = node;//konsep next, prev double linked list
		//Dari struct lama, pointer next struct lama disambungkan ke struct baru , pointer prev struct baru disambungkan ke struct lama,struct baru menjadi tail selanjutnya.
	}
}

void pushMid(int value){
	struct Data *node = newNote(value);
	if(head == NULL){
		head = tail = node;
	}else if(head-> value > value){
		pushHead(value);
	}else if(head -> value <= value){
		pushTail(value);
	}else{
		struct Data *curr = head;
		while(curr-> next -> value < value){
			curr = curr -> next;
		}
		node -> next = curr -> next;
		curr -> next -> prev = node;
		curr -> next = node;
		node -> prev = node;
	}
}

void popHead(){
	if(head == NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		free(head);//oleh karena itu head dan tail dihilangkan
		free(tail);//kondisi ini digunakan jika struct hanya 1 yang berarti dia merupakan head sekaligus tail
	}else{
		struct Data *temp = head;
		head = temp -> next;
		head -> prev = NULL;
		free(temp);
	}
}

void popTail(){
	if(head == NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		free(head);
		free(tail);
	}else{
		struct Data *temp = tail;
		tail = temp -> prev;
		tail -> next = NULL;
		free(temp);
	}
}

void popMid(int value){
	if(head == NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		free(head);
		free(tail);
	}else if(head -> value == value){
		popHead();
	}else if(tail -> value == value){
		popTail();
	}else{
		struct Data *curr = head;
		while(curr-> next->value!= value){
			curr = curr -> next;
		}
		struct Data *temp
		curr -> next = temp -> next;
		temp -> next -> prev = curr;
		temp -> next = NULL;
		temp -> prev = NULL;
		temp = NULL;
		free(temp);
	}
}

void search(int value){
	if(head == NULL){
		return;
	}else{
		struct Data *curr = head;
		while(curr -> value !=value && curr -> next != NULL){
			curr = curr -> next;
		}
		if (curr -> value == value){
			printf("Data Ketemu!\n");
		}else{
			printf("Data tidak ketemu!\n");
		}
	}
}

void printAll(){
	if(head == NULL){
		printf("No Data\n");
		return;
	}else{
		struct Data* curr = head;//print descending, kalo mau ascending ganti head dengan tail
		while(curr != NULL){
			printf("%d\n", curr->value);
			curr = curr -> next;
		}
	}
}

int main(){
	pushTail(10);
	pushHead(20);
	pushHead(30);
	pushHead(40);
	pushHead(50);
	printAll();

	return 0;
}
