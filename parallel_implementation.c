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
	   #pragma omp parallel for 
	   for(i=0;i<n;i++)
	    {
		#pragma omp parallel for
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
    printf("\n%d ", cnt);
	
    return 0;
}