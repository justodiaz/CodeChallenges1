#include <iostream>

using namespace std;

class Node{
	Node *next;
	int data;

	public:
	Node(int d){
		next = NULL;
		data = d;
	}

	int getData(){ return data; }
	Node *getNext() { return next; }
	void setData(int d){ data = d; } 
	void setNext(Node *next){ this->next = next; }
};

class List{
	string name;
	Node *head;
	int sz;

	void _printList(Node *p){
		if(!p) return;
		cout << p->getData() << " ";
		_printList(p->getNext());
	}

	public:
	List(string name){ //constructor
		this->name = name;
		head = NULL;
		sz = 0;
	}
	List(){ //no arg constructor
		name = "";
		head = NULL;
		sz = 0;
	}

	List(const List &ls){ //copy constructor
		name = ls.name;
		sz = ls.sz;

		if(!ls.head)
			head = NULL;
		else{
			head = new Node((ls.head)->getData());

			Node *me = head;
			Node *pt = (ls.head)->getNext();
			while(pt){

				me->setNext(new Node(pt->getData()));

				me = me->getNext();
				pt = pt->getNext();
			}
		}

	}

	Node *_getRefNode(int n, Node *h){
		if(n == 1) return h;

		return _getRefNode(n-1, h->getNext());
	}

	List& operator=(List &ls){ //copy assingment
		clear();

		name = ls.name;
		sz = ls.sz;

		if(!ls.head)
			head = NULL;
		else{
			head = new Node((ls.head)->getData());

			Node *me = head;
			Node *pt = (ls.head)->getNext();
			while(pt){

				me->setNext(new Node(pt->getData()));

				me = me->getNext();
				pt = pt->getNext();
			}
		}

		return *this;
	}

	~List() { clear(); } //destructor

	List &add(int d){
		if(head == NULL)
			head = new Node(d);
		else{
			Node *pt = head;
			while(pt->getNext() != NULL)
				pt = pt->getNext();

			pt->setNext(new Node(d));
		}

		sz++;

		return *this;
	}
	
	int size(){ return sz; }

	void printList(){
		if(!head) { cout << "Empty List" << endl; return; }

		cout << "[ " ;
		_printList(head);
		cout << "]" << endl;

	}

	void clear(){
		Node *p, *c;

		p = head;
		while(p){
			c = p->getNext();
			p->setData(0); //nullify data
			p->setNext(NULL);
			delete p;
			p = c;
		}

		sz = 0;
		head = NULL;
		cout << "List " << name <<  " cleared." << endl;
		name = "";
	}

	void myNameIs(){
		cout << "Hi, my name is " << name << endl;
	
	}

	Node *getRefNode(int n){
		if(n<1 || n > sz){
			cout << "out of range node" << endl;
			return NULL;
		}

		return _getRefNode(n, head);
	}

	void removeNodeByRef(Node *node){
		if(!node) return;

		Node *p = NULL, *c = node;

		while(c->getNext()){
			p = c;
			c = c->getNext();
			p->setData(c->getData());
		}

		if(p){
			delete c;
			p->setNext(NULL);
			sz--;
		}
		else{
			cout << "Error can't delete last node in linked list" << endl;
		}

	}	

		
};

int main(){
	List ls("Biggie");
	List *ls2 = new List("Jack");
	//ls
	ls.myNameIs();

	ls.add(5).add(3).add(6).add(7);

	cout << "List size: " << ls.size() << endl;
	ls.printList();


	ls.removeNodeByRef(ls.getRefNode(3)); //2nd

	ls.printList();
	//ls2
	ls2->myNameIs();
	ls2->add(1);
	delete ls2; //must deallocate and use destructor


	//ls3
	List ls3(ls); //deep copy (same as List ls3 = ls)

	ls3.printList(); //should be same as ls

	ls.add(7);
	ls3.add(10);

	ls.printList(); //they should differ, be different lists
	ls3.printList();

	//ls4

	List ls4 = ls; //calling copy constructor not operator=
	ls.add(11);

	ls.printList();
	ls4.printList();

	ls4 = ls3; //call to clear!

	ls4.printList();

	//ls5

	return 0;
}
