#include<bits/stdc++.h>
using namespace std;
void bruteForce(string str)
{
	string s="";
	for(int i=1;i<26;i++)
	{
		s="";
		for(int j=0;j<str.size();j++)
		{
			char ch = ((str[j]-'a'+i)%26)+'a';
			s=s+ch;
		}
		cout << i <<" : " << s << endl;
	}
}
int main()
{
	string str;
	cout << "Enter ciphertext in small letters:\n";
	cin >> str;
	cout << "possible plaintexts:\n";
	bruteForce(str);
	return 0;
}