#include <iostream>
using namespace std;
int main() {
	string str, strOutput = "";
	cout << "Enter the plaintext: ";
	cin >> str;
	int n;
	int array[26];
	int i;
	cout << "Enter private key size: ";
	cin >> n;
	cout << "Enter the private key: ";
	for(i = 0; i < n; i++) {
		cin >> array[i];
	}
	int k = 0;
	for(i = 0; i < str.size(); i++) {
		if(k % n == 0) {
			k = 0;
		}
		char ch = (str[i] + array[k++] - 'A') % 26 + 'A';
		strOutput.push_back(ch);
	}
	cout << "Cipher Text: " << strOutput << endl;
	return 0;
}
/*
Enter the plaintext: HELLOWORLD
Enter private key size: 3
Enter the private key: ABC
Cipher Text: HORLYCOBRD
*/