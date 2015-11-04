#include<bits/stdc++.h>
using namespace std;
const int mod = 26;
int hash[26];

void getPlain(string str)
{
        int len = str.size();
        int i;
        for(i=0; i<len; i++)
        {
                hash[str[i]-'A']++;
        }
        int max = 0;
        for(i=1; i<26; i++)
        {
                if(hash[max]<hash[i])
                {
                        max = i;
                }
        }
        int a = max-4;
        i = 0;
        while(i<len)
        {
                int x = str[i]-'A'-a;
                if(x<0)
                        x += mod;
                char ch = 'A'+x;
                cout<<ch;
                i++;
        }
        cout<<endl;
}

int main()
{
        string str;
        str = "TLLATLHALSLWOHUAAHUR";
        cout << "Cipher Text is:\n";
        cout << str << endl;
        cout << "PlainText is:\n";
        getPlain(str);
        cout << endl;
        return 0;
}