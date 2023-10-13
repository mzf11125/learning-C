#include<stdio.h>
#include<stdlib.h>

//Modul 5 - 13 Oktober 2023
//Stack => itu lifo = last in, first out, push head dulu abis itu pop head
//Queue => itu filo

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

void peek(){
	if(head == NULL){
		printf("Data Kosong\n");
	}else{
		printf("Data teratas : %d\n", head->value);
	}
}

int main(){
	pushHead(10);
	pushHead(20);
	peek();
	return 0;
}
