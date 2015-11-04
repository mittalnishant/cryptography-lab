#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned int uint;
vector<uint> plaintext;
vector<uint> words;
uint H0 = 0x67452301, H1 = 0xefcdab89, H2 = 0x98badcfe, H3 = 10325476, H4 = 0xc3d2e1f0;
uint k;
uint leftShift(uint x, int n) {
	if(n > 32) {
		n %= 32;
	}
	uint y = (x << n) | (x >> (32 - n));
	return y;
}
void createWords() {
	int i;
	for(i = 0; i < plaintext.size(); i++) {
		words.push_back(plaintext[i]);
	}
	for(i = 16; i < 80; i++) {
		uint wordT = leftShift(words[i - 3] ^ words[i - 8] ^ words[i - 14] ^ words[i - 16], 1);
		words.push_back(wordT);
	}
}
uint functionT(uint B, uint C, uint D, int t) {
	if(t < 20) {
		k = 0x5a827999;
		return (B & C) | (~(B) & D);
	} else if(t < 40) {
		k = 0x6ed9eba1;
		return B ^ C ^ D;
	} else if(t < 60) {
		k = 0x8f1bbcdc;
		return (B & C) | (B & D) | (C & D);
	} else {
		k = 0xca6261d6;
		return B ^ C ^ D;
	}
}
void performHash() {
 uint A = H0, B = H1, C = H2, D = H3, E = H4;
	int i;
	for(i = 0; i < 80; i++) {
		uint t = leftShift(A, 5) + functionT(B, C, D, i) + E + words[i] + k;
		E = D;
		D = C;
		C = leftShift(B, 30);
		B = A;
		A = t;
	}
	H0 = H0 + A;
	H1 = H1 + B;
	H2 = H2 + C;
	H3 = H3 + D;
	H4 = H4 + E;
}
uint convertToHex(char ch) {
	if(ch >= '0' && ch <= '9')
		return 0x0 + ch - '0';
	else
		return 0xa + ch - 'a';
}
int main() {
	string str = "aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbcccccccccc";
	cout << "The plaintext to be hashed ";
	cout << str << endl;
	int i;
	int length = str.size() * 4;
	int lengthPlus = length;
	if(length % 32 != 0) {
		int modVal = length % 32;
		int toBeAdded = 32 - modVal;
		toBeAdded -= 4;
		lengthPlus += 4;
		str.push_back('8');
		for(i = 0; i < toBeAdded; i += 4) {
			str.push_back('0');
			lengthPlus += 4;
		}
	}
	uint t;
	for(i = 0; i < str.size(); i += 8) {
		t = convertToHex(str[i]);
		t <<= 4;
		t |= convertToHex(str[i + 1]);
		t <<= 4;
		t |= convertToHex(str[i + 2]);
		t <<= 4;
		t |= convertToHex(str[i + 3]);
		t <<= 4;
		t |= convertToHex(str[i + 4]);
		t <<= 4;
		t |= convertToHex(str[i + 5]);
		t <<= 4;
		t |= convertToHex(str[i + 6]);
		t <<= 4;
		t |= convertToHex(str[i + 7]);
		plaintext.push_back(t);
	}
	uint size = length;
	for(; lengthPlus < 448; lengthPlus += 32) {
		plaintext.push_back(0);
	}
	plaintext.push_back(0);
	plaintext.push_back(size);
	createWords();
	performHash();
	cout << "The hashed value is ";
	cout << hex << H0 << H1 << H2 << H3 << H4 << endl;
	return 0;
}
/*
The plaintext to be hashed aaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbcccccccccc
The hashed value is 6afbba22a3ba85f6c9e9fa81729384acddafe32d
*/