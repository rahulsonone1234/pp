#include<stdio.h>
#include<omp.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int s=44;
    int s1=s/10;
    int s2=s%10;

    int i, j, thread_id, cnt;
	cnt=0; 
	double startTime = omp_get_wtime();
	    for(i=0;i<n;i++)
	    {
		for(j=0;j<m;j++)
		{
		    if(a[i][j]==s1)
		    {
		        if(a[i][j+1]==s2)
		        {
		            cnt++;
		            a[i][j]=0;
		            a[i][j+1]=0;
		        }
		        if(a[i+1][j+1]==s2)
		        {
		            cnt++;
		            a[i][j]=0;
		            a[i+1][j+1]=0;
		        }
		        if(a[i+1][j]==s2)
		        {
		            cnt++;
		            a[i][j]=0;
		            a[i+1][j]=0;
		        }
		        if(a[i-1][j+1]==s2)
		        {
		            cnt++;
		            a[i][j]=0;
		            a[i-1][j+1]=0;
		        }
		    }
		}
	    }
 double endTime = omp_get_wtime();
  printf("%lf",endTime - startTime);

    printf("\n %d ", cnt);
    return 0;
}
/*
4 8 3 6 2 1 9 3 5 2 9 6 4 9 1
6 5 8 1 4 3 3 1 4 1 4 8 6 7 7
2 3 6 7 1 0 6 7 0 4 1 3 0 6 8
8 7 2 6 2 5 8 1 2 7 0 2 7 7 6
7 8 1 8 7 0 4 5 6 9 5 9 3 2 0
3 0 1 5 1 5 4 7 0 4 2 8 5 6 6
2 6 3 5 0 8 5 1 6 4 5 1 3 7 1
7 1 0 3 7 0 2 4 4 6 7 4 1 2 9
1 9 5 4 5 3 7 1 2 1 4 9 3 0 3
2 1 3 8 7 0 9 0 0 8 1 8 2 3 9
9 7 5 2 9 2 9 8 6 6 1 9 1 8 7
1 3 7 9 1 0 5 9 5 0 3 1 9 4 3
3 2 1 1 2 6 7 6 6 3 1 0 1 4 0
7 5 9 8 5 7 9 6 9 1 9 2 0 7 7
9 7 2 0 7 2 1 9 6 4 5 5 7 1 8
3 7 1 4 8 7 6 8 4 9 0 6 2 0 7
*/
//to compile use =>    gcc serial_implementaion.c
//to run use  =>    ./a.out
