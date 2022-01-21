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

	Node* begin(){ //returns head of ll
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

	int search(int key){ //linear search
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

	int searchHelper(Node* start, int key){
		if(start==NULL){
			return -1;
		}	
		if(start->data == key){
			return 0;
		}
		//search on remaining part of the linked list
		int subIdx = searchHelper(start->next, key);
		if(subIdx==-1){
			return -1;
		}
		return subIdx+1;
	}

	int recursiveSearch(int key){
		int idx = searchHelper(head, key);
		return idx;
	}

	//Remove element from front
	void pop_front(){
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}

	void pop_back(){
		Node* secondLast = head;
		while(secondLast->next->next!=NULL){
			secondLast = secondLast->next;
		}
		secondLast->next = NULL;
		Node* temp = tail;
		delete tail;
		tail = temp;
	}

	//Delete element at particular pos
	void deleteInMiddle(int pos){
		Node* temp = head;
		for(int jump=1; jump<=pos-1; jump++){
			temp = temp->next;
		}

		Node* n = temp->next;
		temp->next = n->next;
		n->next = NULL;
		delete n; 
	}

	void reverse(Node* &head){
		Node * n;
		Node* curr = head;
		Node* prev = NULL;

		while(curr!=NULL){
			//save the next node
			n = curr->next;
			curr->next = prev;

			//update curr and prev
			prev = curr;
			curr = n;
		}
		head = prev;
	}
};


int main(int argc, char const *argv[])
{

	List l;
	l.push_back(1);
	l.push_back(0);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_back(6);

	// l.inserAtMiddle(2, 2);

	// l.pop_front(); //removes 1 from front
	// l.pop_back(); //removes 4 from back
	// l.deleteInMiddle(2);



	Node* head = l.begin();
	l.reverse(head);


	cout<<"The elements in ll are: ";

	while(head!=NULL){
		cout<<head->getData()<<" ";
		head = head->next;
	}

	// int key = 0;
	// cout<<endl<<l.recursiveSearch(key)<<endl;
	
	return 0;
}