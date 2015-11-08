#include<stdio.h>
#include<string.h>
#include "mpi.h"
int main(int argc,char *argv[])
{
   int i,n;
   float fx[100],x[100],lag[100],xIn,sum,prod,sent[100];
   n=4;
   x[0]=1.0;
   fx[0]=1.0;
   x[1]=2.0;
   fx[1]=4.0;
   x[2]=3.0;
   fx[2]=9.0;
   x[3]=4.0;
   fx[3]=16.0;
   xIn=2.5;
   
//   printf("\n enter number of entries\n");
//   scanf("%d",&n);
//   printf("\n enter x and fx \n");
 //  for(i=0;i<n;i++)
 //  scanf("%f%f",&x[i],&fx[i]);
   int my_rank;
   int numtasks;
    numtasks=(n+1);
   int source;
   int dest;
   int tag=0;
   
   MPI_Status status;
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
   MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
      numtasks=(n+1);
   sum=0;

   if(my_rank!=n)
   {
     int i,j=my_rank;
     float temp;
     lag[j]=1.0;
          
     temp=xIn-x[j];
     for(i=0;i<j;i++)
     {
     	dest=i;
     	sent[j]=temp/(x[i]-x[j]);
     	MPI_Send(&sent[j],10,MPI_FLOAT, dest, tag, MPI_COMM_WORLD); 
     }
     for(i=j+1;i<n;i++)
     {
     	dest=i;
     	sent[j]=temp/(x[i]-x[j]);
     	MPI_Send(&sent[j],10,MPI_FLOAT, dest, tag, MPI_COMM_WORLD); 
     }
     
     for(i=0;i<j;i++)
     {
     	source=i;
     	MPI_Recv(&sent[i],10, MPI_FLOAT, source, tag, MPI_COMM_WORLD,&status);
     	lag[j]=lag[j]*sent[i];
     }
     for(i=j+1;i<n;i++)
     {
     	source=i;
     	MPI_Recv(&sent[i],10, MPI_FLOAT, source, tag, MPI_COMM_WORLD,&status);
     	lag[j]=lag[j]*sent[i];
     }
     
     prod=lag[j]*fx[j];
     printf("\n prod is %f\n",prod);
     dest=n;
	MPI_Send(&prod,10,MPI_FLOAT, dest, tag, MPI_COMM_WORLD); 
     
   }
   
   else
   {
  
   for(source=0;source<n;source++)
     {
      MPI_Recv(&prod,10, MPI_FLOAT, source, tag, MPI_COMM_WORLD,&status);
    	sum=sum+prod;
    	
    	}
    	printf("\n sum is %f\n",sum);
   }
   MPI_Finalize();
   return 0;
}   