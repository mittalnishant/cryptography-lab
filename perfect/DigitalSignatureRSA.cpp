#include <bits/stdc++.h>
using namespace std;
int powmod(int n,int m,int d)
{
    int ans=1;
    while(d--)
        ans=(ans*m)%n;
    return ans;
}
int fun(string str,int n)
{
    long long int ans=0;
    long long int mul=1;
    for(int i=str.size()-1;i>=0;i--)
    {
        ans=ans+(str[i]-'A')*mul;
        ans=ans%n;
        mul=mul*26;
    }
    return ans;
}
int main()
{
    string str;
    int p=3,q=11,n,d=3,e=7;
    n=p*q;
    int phi=(p-1)*(q-1);
    cout << "Enter message in capital\n";
    cin >> str; 
    int m=fun(str,n);
    cout << "m: " << m << endl;
    int s=powmod(n,m,d);
    cout << "s: " << s << endl;
    int v=powmod(n,s,e);
    cout << "v: " << v << endl;
    if(v==m)
        printf("message is accepted\n");
    else
        printf("message is rejected\n");
    return 0;
}