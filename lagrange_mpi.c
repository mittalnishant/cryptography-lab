#include <stdio.h>
#include <mpi.h>
/* x   :  1  3  5   7
   f(x):  5  15 25  35 */
float a[4][2]={{1,5},{3,15},{5,25},{7,35}};
float cal_l_nu(float x,int z)
{
    float ans=1.0;
    int i;
    for(i=0;i<4;i++){
        if(i!=z)
        ans=ans*(float)(x-a[i][0]);
    }
    return ans;
}
float cal_l_den(int x)
{
    int j;
    float ans=1.0;
    for(j=0;j<4;j++)
    {
        if(j==x)
            continue;
        else
            ans=ans*(float)(a[x][0]-a[j][0]);    
    }
    return ans;
}
int main(int argc,char* argv[])
{
    int my_rank,p,source,dest,tag=0;
    float val;
    float ans,x;
    float in=13.0;    
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&p);
    if(my_rank!=0)
    {
        x=cal_l_nu(in,my_rank-1)/cal_l_den(my_rank-1);
        x=x*a[my_rank-1][1];
    //    printf("rank=%d x=%f\n",my_rank,x);
        MPI_Send(&x,1,MPI_FLOAT,dest,tag,MPI_COMM_WORLD);
    }
    else
    {
        ans=0;
        for(source=1;source<p;source++)
        {
            MPI_Recv(&val,1,MPI_FLOAT,source,tag,MPI_COMM_WORLD,&status);
            ans+=val;
        }
        printf("ans is: %f at x=%f\n ",ans,in);    
    }
    MPI_Finalize();
}