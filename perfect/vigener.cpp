#include<bits/stdc++.h>
using namespace std;

void showEncr(string str, int key[], int n)
{
        int len = str.size();
        int i=0, count = 0;
        while(i<len)
        {
                int c = (str[i]-'A'+key[count])%26;
                char ch = 'A'+c;
                cout << ch;
                count = (count+1)%n;
                i++;
        }
        cout<<endl;
}

int main()
{
        int n;
        cout<<"Enter count in keys: ";
        cin >> n;
        int i;
        int key[n+9];
        for(i=0;i<n;i++)
                cin >> key[i];
        string str;
        cout<<"Enter the text:";
        cin >> str;
        showEncr(str, key, n);
        return 0;
}