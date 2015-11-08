#include<bits/stdc++.h>
using namespace std;
long long int ft(long long int b,long long int c,long long int d,int t)
{
        long long int val;
        if(t<20)
                val=((b&c)|(~b&d));
        else if(t<40)
                val=b^c^d;
        else if(t<60)
                val=(b&c)|(b&d)|(c&d);
        else
                val=b^c^d;
        return val;
}
long long int kt(int t)
{
        long long int val;
        if(t>=0 && t<20)
                val=0x5a827999;
        else if(t<40)
                val=0x6ed9eba1;
        else if(t<60)
                val=0x8f1bbcdc;
        else
                val=0xca6261d6;
        return val;
}
long long int rightcir(long long int val)
{
        long long int x=val>>31;
        val=val<<1;
        val=val|x;
        x=1;
        x=x<<32;
        val=val|x;
        val=val^x;
        return val;
}

int main()
{
        unsigned int h0=0x67452301,h1=0xefcdab89,h2=0x98badcfe,h3=0x10325476,h4=0xc3d2e1f0;
        long long int w[80];
        w[0]=0x78654384;
        w[1]=0x6754abc4;
        w[2]=0xacb67543;
        w[3]=0xefdc4543;
        w[4]=0xcdfe4562;
        w[5]=0xeacd4562;
        w[6]=0xcdafe498;
        w[7]=0xcdef6798;
        w[8]=0x765432cd;
        w[9]=0xcd347514;
        w[10]=0xbcade672;
        w[11]=0xcdae4573;
        w[12]=0xcdaef454;
        w[13]=0x6754891a;
        w[14]=0x7898703c;
        w[15]=0x5627545a;
        for(int i=16;i<80;i++)
        {
                w[i]=rightcir(w[i-3]^w[i-8]^w[i-14]^w[i-16]);
        }
        long long int a=h0,b=h1,c=h2,d=h3,e=h4,T;
        for(int t=0;t<80;t++)
        {
                for(int i=0;i<5;i++)    T=rightcir(a);
                T=T+ft(b,c,d,t)+e+w[t]+kt(t);
                e=d;
                d=c;
                for(int i=0;i<30;i++) c=b;
                b=a;
                a=T;
        }
        h0=(h0+a)%0x100000000;
        h1=(h1+b)%0x100000000;
        h2=(h2+c)%0x100000000;
        h3=(h3+d)%0x100000000;
        h4=(h4+e)%0x100000000;
        printf("%x %x %x %x %x\n",h0,h1,h2,h3,h4);
        return 0;
}
