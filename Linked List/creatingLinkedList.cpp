#include<iostream>
using namespace std;

class Node {
	int data;
public:
	Node* next;

	Node(int d):data(d), next(NULL){}

	int getData(){
		return data;
	}
};

class List{
	Node* head;
	Node* tail;

public:
	List():head(NULL),tail(NULL){}

	Node* begin(){
		return head;
	}

	void push_front(int data){
		if(head==NULL){
			Node* n = new Node(data);
			head = tail = n;
		}
		else{
			Node* n = new Node(data);
			n->next = head;
			head = n;
		}
	}

	void push_back(int data){
		if(head == NULL){
			Node* n = new Node(data);
			head = tail = n;
		}
		else {
			Node* n = new Node(data);
			tail->next = n;
			tail = n;
		}
	}
};


int main(int argc, char const *argv[])
{

	List l;
	l.push_back(1);
	l.push_back(0);
	l.push_back(2);

	Node* head = l.begin();

	while(head!=NULL){
		cout<<head->getData()<<" ";
		head = head->next;
	}
	
	return 0;
}