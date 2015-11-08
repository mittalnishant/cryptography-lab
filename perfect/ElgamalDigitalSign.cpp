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
			if(powmod(a,i,p)==1 && i==p-1)
				return a;
			else if(powmod(a,i,p)==1 && i!=p-1)
				break;
		}
	}
}
int inverse(int a,int b)
{
	int inv=1;
	while((inv*b-1)%a!=0)
		inv++;
	return inv;
}
int main()
{
	int p=3119;
	int m=320;
	int d=127;
	int r=307;
//	int e1=2;
//	printf("debug");
	int e1=premitive_root(p);
	int e2=powmod(e1,d,p);

	cout << "p: " << p << endl;
	cout << "m: " << m << endl;
	cout << "d: " << d << endl;
	cout << "r: " << r << endl;
	cout << "e1: " << e1 << endl;
	cout << "e2: " << e2 << endl;

//	printf("e1=%d e2=%d",e1,e2);
	// signature generation
	int s1=powmod(e1,r,p);
	int cal1=(m-d*s1);
	cal1=cal1%(p-1)+p-1;
	cal1=cal1%(p-1);
	int cal2=inverse(p-1,r);
	int s2=(cal1*cal2)%(p-1);
	
	cout << "S1 " << s1 << endl;
	cout << "S2 " << s2 << endl;

	// signature verification
	int v1= powmod(e1,m,p);
	int v2= (powmod(e2,s1,p)*powmod(s1,s2,p))%p;
//	printf("ca1=%d cal2=%d\nv1=%d v2=%d\ns1=%d s2=%d\n",cal1,cal2,v1,v2,s1,s2);
	cout << "V1 " << v1 << endl;
	cout << "V2 " << v2 << endl;
	if(v1==v2)
		printf("signature verified\n");
	else
		printf("signature rejected\n");
	return 0;	
}
