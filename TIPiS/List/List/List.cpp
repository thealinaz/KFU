//1.2.3
//чет не работает
#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node 
{
	int data;
	Node *next;

	Node(int data = 0, Node* next = NULL) 
	{
		this->data = data;
		this->next = next;
	}
};

struct List
{
	Node *top;
	Node *end;

	List()
	{
		top = end = NULL;
	}

	bool isEmpty(List list)
	{
		return top != NULL;
	}

	int length(List list)
	{
		int l = 0;
		for (Node *p = top; p != NULL; p = p->next)
			l++;
		return l;
	}

	void addLast(int data)
	{
		if (top != NULL) {
			for (Node *p = top; p != NULL; p = p->next)
				end = p;
			end->next = new Node(data);
		} else {
			top = new Node(data, top);
		}
	}

	void addFirst(int data)
	{
		top = new Node(data, top);
	}

	void deleteNumber(int data)
	{
		Node *prev = NULL;
		Node *curr = top;
		while (curr != NULL) {
			if (curr->data == data) {
				if (prev != NULL)
					prev->next = curr->next;
				if (curr == end)
					end = prev;
				delete curr;
				break;
			} else {
				prev = curr;
				curr = curr->next;
			}
		}
	}

	void deleteAllNumbers(int data)
	{
		Node *prev = NULL;
		Node *curr = top;
		while (curr != NULL) {
			if (curr->data == data) {
				if (prev != NULL)
					prev->next = curr->next;
				if (curr == end)
					end = prev;
				delete curr;
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}

	void show()
	{
		for (Node* p = top; p != NULL; p = p->next)
			cout << p->data << ' ';
		cout << endl;
	}
};

List mergeWithCondition(List list1, List list2)
{
	List list = list2;
	Node *p, *pp;
	for (p = list1.top; p != NULL; p = p->next)
			list.addLast(p->data);
	for (p = list1.top; p != NULL; p = p->next)
		for (pp = list2.top; pp != NULL; pp = pp->next)
			if (p->data == pp->data)
				list.deleteNumber(pp->data);
	return list;
}

int main()
{
	List list, list1, list2;
	int n1, n2, e;

	cout << "Enter number of elements at first list: ";
	cin >> n1;
	cout << "Enter data: ";
	for (int i = 0; i < n1; i++) {
		cin >> e;
		list1.addLast(e);
	}

	cout << "Enter number of elements at second list: ";
	cin >> n2;
	cout << "Enter data: ";
	for (int i = 0; i < n2; i++) {
		cin >> e;
		list1.addLast(e);
	}
	list = mergeWithCondition(list1, list2);
	list.show();
	system("pause");
    return 0;
}