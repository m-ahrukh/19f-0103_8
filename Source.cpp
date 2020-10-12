#include<iostream>
using namespace std;
struct Node {
public:
	int data;
	Node* next;
};
class LinkedList {
	Node* head, * tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	void insert(int x) {
		Node* ptr = new Node;
		ptr->data = x; ptr->next = NULL;
		if (head == NULL) { 
			head = ptr; tail = ptr;
		}
		else {
			tail->next = ptr;
			tail = ptr;
		}
	}
	void reverse() {
		Node* current = head;
		Node* prev = NULL, * next = NULL;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void display() {
		Node* temp;
		temp = head;
		cout << "List is " << endl;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};
int main() {
	LinkedList l1;
	int num;
	char ch;
	do {
		cout << "Enter number you want to insert "; cin >> num;
		l1.insert(num);
		cout << "Enter Y if you want to insert again "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	l1.display();
	cout << endl;
	l1.reverse();
	cout << "After Reversing ";
	l1.display();
	cout << endl;
	system("pause");
	return 0;

}