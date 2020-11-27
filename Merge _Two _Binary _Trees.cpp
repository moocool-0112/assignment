//Merge Two Binary Trees
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <fstream>
using namespace std;

void compute(string *st, int line, string *st_n, int &n1_root, int &n2_root) {

	int t = 0;
	for (int j = 0; j <st[j].length(); j++) {
		if (st[1][j] != 0 && n1_root == 0) {
			n1_root = j;
		}
		else if (st[1][j] != 0) {
			n2_root = j;
		}
	}

	for (int i = 1; i < line; i += 2) {
		st_n[i] = st[i];
	}
};

int main() {
	
	string in;
	int line = 0;
	int number[100][100];//¤G¤¸¾ð
	string st[100];
	string st_n[100];
	int n1_root = 0, n2_root = 0;//¥ª¥k¾ð®Úªº¦ì¸m
	int diff = 0;//¥ª¥k¾ð®Ú¦ì¸m®t¶Z
	
	//fstream file;
	//file.open("test.txt", ios::in);
	/*while (file) {
		getline(file, st[line]);
		line++;
	}*/
	while (cin >> in) {
		st[line] = in;
		line++;
	}

	compute(st, line, st_n,n1_root,n2_root);//§ä¥X®Úªº¦ì¸m
	for (int i = 1; i < line; i++) {
		for (int j = 0; j < st_n[i].length(); j++) {
			if (st_n[i][j] != ' ') {
				number[i][j] = (int)(st_n[i][j]) - 48;
			}
		}
	}
	n1_root = 0;
	n2_root = 0;
	for (int i = 0; i < 100; i++) {
		if (number[1][i] > 0 && n1_root == 0) {
			n1_root = i;
		}
		else if (number[1][i] > 0) {
			n2_root = i;
		}
	}
	diff = n2_root - n1_root;//¥ª¾ð®Ú¥k¾ð¶¡¹j
	for (int i = 1; i < line; i+=2) {
		for (int j = 0; j < 100; j++) {
			if (number[i][j] > 0 && number[i][j+diff] > 0) {//¥ª¾ð¦³­È,§PÂ_¥k¾ð¬O§_¦³­È
				number[i][j] += number[i][j + diff];
				number[i][j + diff] = NULL;
			}
			else if (number[i][j + diff] > 0) {//¥k¾ð¦³­È,¥ª¾ðµ¥©ó¥k¾ð­È
				number[i][j] = 0;
				number[i][j] = number[i][j + diff];
			}
		}
	}
	for (int i = 1; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (number[i][j] > 0 && number[i + 2][j - 2] > 0) {
				number[i + 1][j - 1] = 100;//Åª¨ì100¦L¥X"/"
			}
			if (number[i][j] > 0 && number[i + 2][j + 2] > 0) {
				number[i + 1][j + 1] = 200;//Åª¨ì200¦L¥X"\"
			}
		}
	}
	//output
	for (int i = 0; i < 100; i++) {
		if (i == n1_root)cout << "tree";
		else cout<<" ";
	}
	cout << endl;
	for (int i = 1; i < line+1; i++) {
		for (int j = 0; j < 100; j++) {
			if (number[i][j] > 99) {
				if (number[i][j] == 100)cout << "/";
				else cout << "\\";
			}
			else if (number[i][j] > 0) {
				cout << number[i][j];
			}
			else
				cout << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

