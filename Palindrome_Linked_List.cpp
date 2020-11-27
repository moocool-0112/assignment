//Palindrome Linked List
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;
class LinkedList;

class node {
private:
	
public:
	int data;
	node *next;
	node() :data(0), next(0) {};
	node(int a) :data(a), next(0) {};

	friend class LinkedList;
};
class LinkedList {
private:
	
public:
	node *first;
	LinkedList() :first(0) {};
	void Push_back(int x);
	void Reverse();
};
string splite(string in, string *data, int &times) {//這邊會保留所有負號
	int pos = 0;
	int pos2 = 0;
	int j = 0;
	int n = in.length();
	for (int i = 0; pos2 < n; i++) {//分割
		pos2 = in.find_first_of(">", pos);
		while (pos == pos2) {
			pos = pos2 + 1;
			pos2 = in.find_first_of(">", pos);
		}
		pos2 = in.find_first_of(">", pos);
		data[j] = in.substr(pos, pos2 - pos);
		//cout << data[j] << " pos: " << pos << " pos2 " << pos2 << endl;//
		j++;
		times++;
		if (pos2 == -1 || pos == -1)return *data;
		pos = pos2;
	}
	return *data;
}
int change(string *number, int *n, int times) {//這邊要多處理負號的部分
	int len = 0;
	int tmp = 0;
	int t = 0;
	for (int i = 0; i < times; i++) {

		if (number[i] != " ") {
			if (number[i][0] == '-') {
				t = 1;
				len = number[i].length() - 1;
				while (len > 0) {
					if (number[i][t] == '-')break;
					tmp *= 10;
					tmp += (int)(number[i][t]) - 48;
					t++;
					len--;
				}
				tmp = -tmp;
			}
			else {
				t = 0;
				len = number[i].length();
				while (len > 0) {
					if (number[i][t] == '-')break;
					tmp *= 10;
					tmp += (int)(number[i][t]) - 48;//bug
					t++;
					len--;
				}
			}
		}
		n[i] = tmp;
		tmp = 0;
	}
	return *n;
}
int main() {
	string st;
	string data[100];
	int n[100];
	int times = 0;
	st = { "1->2->2->1" };
	//cin >> st;
	splite(st, data, times);//切割
	change(data, n, times);//轉型態
	LinkedList list;
	LinkedList re_list;
	for (int i = 0; i < times; i++) {
		list.Push_back(n[i]);
		re_list.Push_back(n[i]);
	}
	re_list.Reverse();
	node *current = list.first;
	node *re_current = re_list.first;
	while (current->next!= NULL) {
		if (current->data != re_current->data) {
			cout << "False";
			system("pause");
			return 0;
		}
		current = current->next;
		re_current = re_current->next;
	}
	cout << "True";
	system("pause");
	return 0;
}
void LinkedList::Push_back(int x) {
	node *newNode = new node(x); 
	if (first == 0) {                      
		first = newNode;
		return;
	}
	node *current = first;
	while (current->next != 0) {           
		current = current->next;
	}
	current->next = newNode;              
}
void LinkedList::Reverse() {

	if (this->first == 0 || this->first->next == 0) {
		return;
	}

	node *previous = 0,
		*current = this->first,
		*preceding = this->first->next;

	while (preceding != 0) {
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = preceding->next;
	}                                 

	current->next = previous;          
	this->first = current;
}