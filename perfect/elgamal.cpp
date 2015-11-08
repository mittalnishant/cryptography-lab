#include<bits/stdc++.h>
using namespace std;
int powmod(int a,int b,int m)
{
        int ans=1;
        int d=a;
        while(b)
        {
                if(b&1)
                        ans=(ans*d)%m;
                d=(d*d)%m;
                b>>=1;
        }
        return ans;
}
int premitive_root(int p)
{
        int i,a;
        for(a=2;a<p;a++)
        {
                for(i=2;i<p;i++)
                {
                        if(powmod(a,i,p)==1)
                                return a;
                }
        }
}
int main()
{
        int p=10007;
        int m=456;
        cout << "msg is: " << m << endl;
        int e1=premitive_root(p);
        int d=p/2,r=7;
        int e2=powmod(e1,d,p);
        int c1=powmod(e1,r,p);
        int c2=(m%p*powmod(e2,r,p))%p;
        
        cout << "C1: " << c1 << endl;
        cout << "C2: " << c2 << endl;
        int decrypt=(c2*powmod(powmod(c1,d,p),p-2,p))%p;
        printf("decrypted message is: %d\n",decrypt);
        return 0;
}
