#include <iostream>
using namespace std;
int matrix[4][4] = {{9, 7, 11, 13}, {4, 7, 5, 6}, {2, 21, 14, 9}, {3, 23, 21, 8}};
int decr[4][4] = {{2, 15, 22, 3}, {15, 0, 19, 3}, {9, 9, 3, 11}, {17, 0, 4, 7}};
int mult[100][4];
int createMatrix(string temp) {
	int cnt = 0, i;
	int row = 0;
	for(i = 0; i < temp.size(); i++) {
		mult[row][cnt % 4] = temp[i] - 'a';
		cnt++;
		if(cnt % 4 == 0) {
			row++;
		} 
	}
	while(cnt % 4 != 0) {
		mult[row][cnt % 4] = 'z' - 'a';
		cnt++;
		if(cnt % 4 == 0)
			row++;
	}
	row--;
	return row;
}
string encrypt(string temp) {
	int i, j, k;
	string ret = "";
	int finalMat[100][4];
	int rows = createMatrix(temp);
	for(i = 0; i <= rows; i++) {
		for(j = 0; j < 4; j++) {
			finalMat[i][j] = 0;
			for(k = 0; k < 4; k++) {
				finalMat[i][j] = (finalMat[i][j] + mult[i][k] * matrix[k][j]) % 26;
			}
		}
	}
	for(i = 0; i <= rows; i++) {
		for(j = 0; j < 4; j++) {
			ret.push_back('a' + finalMat[i][j]);	
		}
	}
	return ret;
}

string decrypt(string temp1) {
	int i, j, k;
	string ret = "";
	int finalMat[100][4];
	int rows = createMatrix(temp1);
	for(i = 0; i <= rows; i++) {
		for(j = 0; j < 4; j++) {
			finalMat[i][j] = 0;
			for(k = 0; k < 4; k++) {
				finalMat[i][j] = (finalMat[i][j] + mult[i][k] * decr[k][j]) % 26;
			}
		}
	}
	for(i = 0; i <= rows; i++) {
		for(j = 0; j < 4; j++) {
			ret.push_back('a' + finalMat[i][j]);	
		}
	}
	return ret;
}


int main() {
	string str, strOutput = "", decrypted = "";
	cout << "Enter the string to be encrypted: ";
	cin >> str;
	strOutput = encrypt(str);
	cout << "Encrypted text " << strOutput << endl;
	decrypted = decrypt(strOutput);
	cout << "Decrypted text " << decrypted;
	return 0;
}
/*
Enter the string to be encrypted: codeisready
Encrypted text ohknihghfiss
Decrypted text codeisreadyz
*/