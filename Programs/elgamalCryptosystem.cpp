#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int p = 9979;
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
bool isPrimitive(int e) {
	int i;
	int ans = 1;
	for(i = 1; i < p; i++) {
		ans = (ans * e) % p;
		if(ans == 1) {
			return 0;
		}
	}
	return 1;
}
int powMod(int e1, int d) {
	int e2 = 1;
	while(d) {
		if(d & 1) {
			e2 = (e2 * e1) % p;
		}
		e1 = (e1 * e1) % p;
		d >>= 1;
	}
	return e2;
}
int main() {
	int P;
	cout << "Enter the plaintext to be encrypted ";
	cin >> P;
	int d = rand() % (p - 2) + 1;
	int i;
	int e1;
	for(e1 = 2; e1 < p; e1++) {
		if(isPrimitive(e1)) {
			break;
		}
	}
	int e2 = powMod(e1, d);
	int r = 4;
	int c1 = powMod(e1, r);
	//cout << powMod(e2, r);
	int c2 = (P * powMod(e2, r)) % p;
	//cout << P << endl;
	cout << "Encrypted text: C1: " <<c1 << " C2: " << c2 << endl;
	calcInverse(p, c1);
	int c1Inverse = cffs;
	int plaintext = (c2 * powMod(c1Inverse, d)) % p;
	if(plaintext < 0) {
		plaintext += p;
	}
	cout << "Decrypted plaintext: " << plaintext << endl;
	return 0;
}
/*
Enter the plaintext to be encrypted 48
Encrypted text: C1: 3689 C2: 7990
Decrypted plaintext: 48
*/