#include <bits/stdc++.h>


using namespace std;


struct Node{
	int val;
	Node *prev;
	Node *next;
	
	
	
	Node(){
		val = 0;
		prev = NULL;
		next = NULL;
	}
	
	Node(int val){
		this->val = val;
		next = NULL;
		prev = NULL;
	}

};

struct LinkedList {
private:
	Node *head;
	Node *tail;
	
public:
	LinkedList(){
		head = NULL;
		tail = NULL;	
	}
	
	void pushHead(int val){
		Node *newNode = new Node(val);
		if(head == NULL){
			head = newNode;
			tail = newNode;
			return;
		}
		
		newNode ->next = head;
		head->prev = newNode;
		head = newNode;
	}
	
	void pushTail(int val){
		Node *newNode = new Node(val);
		if(head == NULL){
			head = newNode;
			tail = newNode;
			return;
		}
		
		newNode ->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	
	void popHead(){
		if(head == NULL){
			return;
		}
		
		if(head == tail){
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}
		
		Node *deletedNode = head;
		head = head -> next;
		head -> prev= NULL;
		delete deletedNode;
	}
	
		void popTail(){
		if(tail == NULL){
			return;
		}
		
		if(head == tail){
			delete tail;
			head = NULL;
			tail = NULL;
			return;
		}
		
		Node *deletedNode = tail;
		tail = tail -> prev;
		tail -> next= NULL;
		delete deletedNode;
	}
	
	bool search(int val){
		Node *curNode = head;
		while(curNode != NULL){
			if(curNode->val = val){
//				return true;
				cout << "true" << endl;
				return true;
			}
			curNode = curNode -> next;
		}
		
		cout << "False" << endl;
		return false;
	}
	
	
	void forward(Node *curNode){
		if(curNode == NULL){
			return;
		}
		cout<<curNode->val<<" ";
		forward(curNode -> next);
	}
	void backward(Node *curNode){
				if(curNode == NULL){
			return;
		}
		
		backward(curNode->next);
		cout<< curNode->val <<" ";
	}
	
	void Debug(){
		cout<<"List: ";
		forward(head);
//		cout<<endl;
//		
//		cout<<"Tail: ";
		backward(tail);
		cout<<endl;
	}
	
		
};

int main(){
	LinkedList list;
	list.pushHead(10);
	list.Debug();
	list.pushHead(20);
	list.Debug();
	list.popHead();
	list.pushTail(30);
	list.Debug();
//	list.popTail();
	list.pushTail(50);
	list.Debug();
	cout << list.search(50) << endl;
}