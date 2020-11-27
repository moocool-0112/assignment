//Min Stack
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;


string splite(string in,string *data,int &times) {
	int pos = 0;
	int pos2 = 0;
	int j = 0;
	int n = in.length();
	for (int i = 0; pos2 < n;i++) {//分割
		pos2 = in.find_first_of(",[]\"", pos);
		while (pos == pos2) {
			pos = pos2 + 1;
			pos2 = in.find_first_of(",[]\"", pos);
		}
		pos2 = in.find_first_of(",[]\"", pos);
		data[j] = in.substr(pos, pos2 - pos);
		//cout << data[j] << " pos: " << pos << " pos2 " << pos2 << endl;//
		j++;
		times++;
		if (pos2 == -1 || pos == -1)return *data;
		pos = pos2;	
	}
	return *data  ;
}
string splite_num(string in, string *number) {
	int pos = 0;
	int pos2 = 0;
	int j = 0;
	for (int i = 1; pos2 < in.length()-1; i++) {//分割
		pos = in.find_first_of("[", pos + 1);
		pos2 = in.find_first_of("]", pos);
		while (pos == pos2 - 1) {
			number[j] = '0';
			j++;
			pos = in.find_first_of("[", pos + 1);
			pos2 = in.find_first_of("]", pos);
		}
		if (pos == -1 || pos2 == -1) {
			return *number;
		}
		number[j] = in.substr(pos+1, pos2 - pos-1);
		//cout << data[j] << " pos: " << pos << " pos2 " << pos2 << endl;//
		j++;
		pos = pos2;
	}
	return *number;
}
class MinStack {
public:
	MinStack() {}
	int push(int n);
	void pop();
	int top();
	int getMin();
	void setMin(int n);
	
private:
	int stack[1000];
	int c = -1;//top位置
	int n_top;
	int min = 1000;

};
int change(string *number,int *n,int times){
	int len = 0;
	int tmp = 0;
	int t = 0;
	for (int i=0; i < times; i++) {

		if (number[i] != " ") {
			if (number[i][0] == '-') {
				t = 1;
				len = number[i].length() - 1;
				while (len > 0) {
					tmp *= 10;
					tmp += (int)(number[i][t])-48;
					t++;
					len--;
				}
				tmp = -tmp;
			}
			else {
				t = 0;
				len = number[i].length();
				while (len > 0) {
					tmp *= 10;
					tmp += (int)(number[i][t])-48;//bug
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
	string dic[5] = { "MinStack","push","pop","top","getMin" };
	string in;
	string data[1000];
	string number[100];
	MinStack *minstack=new MinStack;
	int n[100];
	int times = 0;
	cin >> in;
	//in = {"""MinStack\",\"push\",\"push\",\"push\",\"getMin\",\"pop\",\"top\",\"getMin\""}; //測資
	splite(in, data,times);//切割字串
	cin >> in;
	//in = {"[[],[-2],[0],[-3],[],[],[],[]"}; //測資
	splite_num(in, number);//切割字串
	/*for (int i = 0; i < times-1; i++) {
		cout << data[i] << " " << number[i] << " " << endl;
	}*/
	change(number, n, times);//將字串轉成int型態
	cout << "[";
	int choice;
	for (int i = 0; i < times-1; i++) {
		
		for (int j = 0; j < 5; j++) {if (data[i] == dic[j])choice = j;}
		if (choice == 0) {
			MinStack *minstack = new MinStack();
			cout << "null,";
		}
		switch (choice)
		{
		case 0:
			break;
		case 1:minstack->push(n[i]);
			cout << "null,";
			break;
		case 2:minstack->pop();
			cout << "null,";
			break;
		case 3:cout<<minstack->top()<<",";
			break;
		case 4:cout << minstack->getMin()<<",";
			break;
		default:
			break;
		}
		choice = 0;
	}
	cout << "]";

	system("pause");
	return 0;
}

int MinStack::push(int n) {
	//cout << "input: " << n << endl;
	c++;
	stack[c] = n;
	if (stack[c] <this->getMin()) {
		this->setMin(stack[c]);
	}
	return this->top();
}
void MinStack::pop(){
	c--;
	this->setMin(1000);
	for (int i = 0; i <= c; i++) { //find min
		if (stack[i] < this->getMin()) {
			this->setMin(stack[i]);
		}
	}

}
int MinStack::top(){
	return stack[c];
}
int MinStack::getMin(){
	return this->min;
}
void MinStack::setMin(int n) {
	min = n;
}