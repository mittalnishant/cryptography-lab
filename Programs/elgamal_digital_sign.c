#include<stdio.h>
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
	int m,p,d,r;
	//User enter a large prime number, say 123
	printf("Enter message:\n");
	scanf("%d",&m);
	//Simulation: 3119,127,307
	printf("enter p,d and r:\n");
	scanf("%d %d %d",&p,&d,&r);
	
//	int e1=2;
//	printf("debug");
	int e1=premitive_root(p);
	int e2=powmod(e1,d,p);
//	printf("e1=%d e2=%d",e1,e2);
	// signature generation
	int s1=powmod(e1,r,p);
	int cal1=(m-d*s1);
	cal1=cal1%(p-1)+p-1;
	cal1=cal1%(p-1);
	int cal2=inverse(p-1,r);
	int s2=(cal1*cal2)%(p-1);
	
	// signature verification
	int v1= powmod(e1,m,p);
	int v2= (powmod(e2,s1,p)*powmod(s1,s2,p))%p;
//	printf("ca1=%d cal2=%d\nv1=%d v2=%d\ns1=%d s2=%d\n",cal1,cal2,v1,v2,s1,s2);
	printf("Using Elgaml Digital Signature Technique... \nVerfying Signature... \n");
	if(v1==v2)
		printf("signature verified\n");
	else
		printf("signature rejected\n");
	return 0;	
}
