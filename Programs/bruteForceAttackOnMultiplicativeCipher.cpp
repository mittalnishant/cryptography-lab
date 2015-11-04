#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
stack <int> s;
int cffs, cffb;
void calcInverse(int a, int b) {
	int newa = b;
	int newb = a % b;
	if(newa % newb == 0) {
		cffs = (a / b) * (-1);
		cffb = 1;
		return;
	}
	calcInverse(b, a % b);
	int store = cffs;
	cffs = cffb - (a / b) * (cffs);
	cffb = store;
}
int main() {
	string str;
	string strOutput;
	cout << "Enter the string: ";
	cin >> str;
	int b = 1;
	for(; b < 26; b += 2) {
		strOutput = "";
		if(b != 13) {
			calcInverse(b, 26);
			if(cffb < 0) {
				cffb += 26;
			}
			for(int i = 0; i < str.size(); i++) {
				char ch = (str[i] - 'A')* cffb % 26 + 'A';
				strOutput.push_back(ch);
			}
			cout << "Using key b = " << b << "whose inverse is " << cffb << " The string is " << strOutput << endl;
		}
	}
	return 0;
}
/*
Enter the string: VMHHQ
Using key b = 1 whose inverse is 1 The string is VMHHQ
Using key b = 3 whose inverse is 9 The string is HELLO
Using key b = 5 whose inverse is 21 The string is ZSRRY
Using key b = 7 whose inverse is 15 The string is DYBBG
Using key b = 9 whose inverse is 3 The string is LKVVW
Using key b = 11 whose inverse is 19 The string is JUDDS
Using key b = 15 whose inverse is 7 The string is RGXXI
Using key b = 17 whose inverse is 23 The string is PQFFE
Using key b = 19 whose inverse is 11 The string is XCZZU
Using key b = 21 whose inverse is 5 The string is BIJJC
Using key b = 23 whose inverse is 17 The string is TWPPM
Using key b = 25 whose inverse is 25 The string is FOTTK
*/