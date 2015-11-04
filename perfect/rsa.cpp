#include<bits/stdc++.h>
using namespace std;

int getEncrypt(long long int num ,long long int e, long long int n)
{
        long long int res = num;
        long long int ans = 1;
        while(e)
        {
                if(e&1)
                        ans  = (ans*res)%n;
                res = (res*res)%n;
                e = e>>1;
        }
        return ans;
}

void encrypt(string str, int e,  int p, int q)
{
        int n = p*q;
        int len = str.size();
        int i=0;
        int num = 0;
        for(i=0; i<len; i++)
        {
                num = num*26+(str[i]-'A');
        }
        cout<<getEncrypt(num, e, n);
}

int main()
{
        string str = "NO";
        int p = 397;
        int q = 401;
        int e = 343;
        cout << "plaintext: " << str << endl;
        cout << "p: " << p << endl;
        cout << "q: " << q << endl;
        cout << "e: " << e << endl;
        cout << "encrypted msg is:\n";
        encrypt(str, e, p, q);
        cout << endl;
        return 0;
}