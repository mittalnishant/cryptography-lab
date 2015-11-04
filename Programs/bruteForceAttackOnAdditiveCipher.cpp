#include <iostream>
using namespace std;
#define MOD 26
int main() {
	string str;
	string strOutput;
	cout << "Enter the text to be decrypted: ";
	cin >> str;
	int b = 1;
	while(b < 26) {
		strOutput = "";
		int i;
		for(i = 0; i < str.size(); i++) {
			char ch = (str[i] - 'A' - b)%MOD;
			ch += 'A';
			if(ch < 'A') {
				ch += MOD;
			}
			strOutput.push_back(ch);
		}
		cout << "String after taking b = " << b << " is " << strOutput << endl;
		b++;
	}
	return 0;
}
/*
Enter the text to be decrypted: KHOOR
String after taking b = 1 is JGNNQ
String after taking b = 2 is IFMMP
String after taking b = 3 is HELLO
String after taking b = 4 is GDKKN
String after taking b = 5 is FCJJM
String after taking b = 6 is EBIIL
String after taking b = 7 is DAHHK
String after taking b = 8 is CZGGJ
String after taking b = 9 is BYFFI
String after taking b = 10 is AXEEH
String after taking b = 11 is ZWDDG
String after taking b = 12 is YVCCF
String after taking b = 13 is XUBBE
String after taking b = 14 is WTAAD
String after taking b = 15 is VSZZC
String after taking b = 16 is URYYB
String after taking b = 17 is TQXXA
String after taking b = 18 is SPWWZ
String after taking b = 19 is ROVVY
String after taking b = 20 is QNUUX
String after taking b = 21 is PMTTW
String after taking b = 22 is OLSSV
String after taking b = 23 is NKRRU
String after taking b = 24 is MJQQT
String after taking b = 25 is LIPPS
*/