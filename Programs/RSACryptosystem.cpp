#include <iostream>
using namespace std;
long long int p = 397, q = 401;
long long int n = p * q;
long long int eulerN = (p - 1) * (q - 1);
long long int e = 343;
long long int d;

long long int cffs, cffb;

void calcInverse(long long int a, long long int b) {
	long long int newa = b;
	long long int newb = a % b;
	if(newa % newb == 0) {
		cffs = (a / b) * (-1);
		cffb = 1;
		return;
	}
	calcInverse(b, a % b);
	long long int store = cffs;
	cffs = cffb - (a / b) * (cffs);
	cffb = store;
}
long long int encrypt(long long int plaintext, long long int e) {

	long long int ans = 1;
	while(e) {
		if(e & 1) {
			ans = (ans * plaintext) % n;
		}
		plaintext = (plaintext * plaintext) % n;
		e = e >> 1;
	}
	return ans;
}
int main() {
	int i;
	string str;
	cout << "Enter the text to be encrypted: ";
 	cin >> str;
	string output = "";
	string output2 = "";
	long long int plaintext = 0;
	for(i = 0; i < str.size(); i++) {
		plaintext = (plaintext * 26 + str[i] - 65) % n;
	}
	long long int ciphertext = encrypt(plaintext, e);
	long long int temp = ciphertext;
	while(temp) {
		int rem = temp % 26;
		string s = "";
		s.push_back(rem + 65);
		output = s + output;
		temp = temp / 26;
	}
	cout << "After encryption: ";
	cout << output << endl;

	calcInverse(eulerN, e);
	d = cffs;
	if(d < 0) {
		d += eulerN;
	}
	long long int decrypted = encrypt(ciphertext, d);
	temp = decrypted;

	while(temp) {
		int rem = temp % 26;
		string s = "";
		s.push_back(rem + 65);
		output2 = s + output2;
		temp = temp / 26;
	}
	cout << "After Decryption: ";
	cout << output2 << endl;
	return 0;
}
/*
Enter the text to be encrypted: NO
After encryption: PPJ
After Decryption: NO
*/