#include<iostream>
using namespace std;

class Node {
	
public:
	int data;
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

	void inserAtMiddle(int data, int pos){
		if(pos==0){
			push_front(data);
		}
		else{
			Node* temp = head;
			//take temp to pos-1
			for(int jump=1; jump<=pos-1; jump++){
				temp = temp->next;
			}

			Node* n = new Node(data);
			n->next = temp->next;
			temp->next = n;
		}
	}

	int search(int key){
		Node * temp = head;

		int idx = 0;
		while(temp!=NULL){
			if(temp->data == key){
				return idx;
			}
			idx++;
			temp = temp->next;
		}
		return -1;
	}
};


int main(int argc, char const *argv[])
{

	List l;
	l.push_back(1);
	l.push_back(0);
	l.push_back(3);
	l.push_back(4);

	l.inserAtMiddle(2, 2);

	Node* head = l.begin();

	cout<<"The elements in ll are: ";

	while(head!=NULL){
		cout<<head->getData()<<" ";
		head = head->next;
	}

	cout<<endl<<"Enter the element you want to search: ";
	int key;
	cin>>key;
	cout<<l.search(key)<<endl;
	
	return 0;
}