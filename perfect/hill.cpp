#include<bits/stdc++.h>
using namespace std;
int keyM[3][3];

void getEncr(string str)
{
        int i=0, j=0, sum = 0;
        int len = str.size();

        while(i<len)
        {
                int a[3];
                a[0] = str[i]-'A';
                i++;
                if(i<len)
                {
                        a[1] = str[i++]-'A';
                        if(i<len)
                                a[2] = str[i++]-'A';
                        else
                                a[2] = 'P';
                }
                else
                {
                        a[1] = 'P';
                        a[2] = 'P';
                }
                j= 0;
                while(j<3)
                {
                        int c = (keyM[j][0]*a[0]+keyM[j][1]*a[1]+keyM[j][2]*a[2])%26;
                        char ch = 'A'+c;
                        cout << ch;
                        j++;
                }
        }
}
int main()
{
        string str, key;
        cout<<"Enter the key string of length 9: ";
        cin>>key;
        int i=0, j=0, k=0;
        while(k<9)
        {
                keyM[i][j] = key[k]-'A';
                j++;
                if(j%3==0)
                {
                        i++;
                        j=0;
                }
                k++;
        }
        cout<<"\nEnter the plain text in capitals: ";
        cin>>str;
        cout << "CipherText is: ";
        getEncr(str);
        cout << endl;
        return 0;
}