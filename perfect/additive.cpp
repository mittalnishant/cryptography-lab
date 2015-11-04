#include<iostream>
using namespace std;
int mod = 26;

void encrypt(string str, int a)
{
        int len = str.size();
        int i;
        for(i=0; i<len; i++)
        {
                char ch = 'A'+((str[i]-'A')+a)%mod;
                cout<<ch;
        }
        cout<<endl;
}

int main()
{
        string str;
        int a;
        cout<<"Enter string in capital: ";
        cin>>str;
        cout<<"Enter Key: ";
        cin>>a;
        encrypt(str,a);
        return 0;
}
