#include <iostream>
using namespace std;
long long int e, f;
long long int n;

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
long long int power(long long int plaintext, long long int e) {
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
long long int convertToNum(string str) {
	int i;
	long long int ans = 0;
	for(i = 0; i < str.size(); i++) {
		ans = (ans * 26 + str[i] - 65) % n;
	}
	return ans;
}
int main() {
	cout << "Enter the common modulus: ";
	cin >> n;
	cout << "Enter the public key 1: ";
	cin >> e;
	cout << "Enter the public key 2: ";
	cin >> f;
	string cipher1;
	string cipher2;
	string ans = "";
	long long cipherNum1, cipherNum2;
	long long int plaintext;
	cout << "Enter the cipher text for key 1: ";
	cin >> cipher1;
	cout << "Enter the cipher text for key 2: ";
	cin >> cipher2;
	cipherNum1 = convertToNum(cipher1);
	cipherNum2 = convertToNum(cipher2);
	long long int x, y;
	if(e < f) {
		calcInverse(f, e);
		y = cffb;
		x = cffs;
	} else {
		calcInverse(e, f);
		y = cffs;
		x = cffb;
	}
	if(y < 0) {
		calcInverse(n, cipherNum2);
		plaintext = (power(cipherNum1, x) * power(cffs, -y)) % n;
	} else if(x < 0) {
		calcInverse(n, cipherNum1);
		plaintext = (power(cffs, -x) * power(cipherNum2, y)) % n;
	}
	while(plaintext) {
		int rem = plaintext % 26;
		string s = "";
		s.push_back(rem + 65);
		ans = s + ans;
		plaintext /= 26;
	}
	cout << "The plaintext is: ";
	cout << ans << endl;
	return 0;
}
/*
Enter the common modulus: 159197
Enter the public key 1: 343
Enter the public key 2: 2197
Enter the cipher text for key 1: PPJ
Enter the cipher text for key 2: HEVP
The plaintext is: NO
*/