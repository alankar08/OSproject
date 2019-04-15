#include<stdio.h>
int main()
{
	int i,n,at[10],temp,bt[10],rt[10],rt1[10],arr[10],timemax=6,time,j,k,timemax1=10;
	float avg_wt[10],avg_at[10],wt[10],tat[10];
x:	printf("\n\n\n\n * Enter number of processes\n =>");
	scanf("%d",&n);
	printf("\n--------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("\n * Enter arrival time of process P%d\n =>",i);
		scanf("%d",&at[i]);
		printf("\n * Enter burst time of process P%d\n =>",i);
		scanf("%d",&bt[i]);
		printf("_______________________________________\n");
	}
		for(i=0;i<n;i++)
		{
			for(time=0;time<=timemax;time++)
			{
				if(bt[i]>0 && bt[i]>=timemax)
				{
					rt[i]=bt[i];
					rt[i]-=timemax;
				
				}
				else if(bt[i]>0 && bt[i]<timemax)
				{
					rt[i]=bt[i];
					rt[i]=0;
				}
				else
				{
					printf("\nBurst Time cannot be negative");
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(rt[i]>0){
			
			for(time=0;time<timemax1;time++)
			{
					if(rt[i]>0 && rt[i]>=timemax1)
				{
					rt1[i]=rt[i];
					rt1[i]-=timemax1;
				}
				else if(rt[i]>0 && rt[i]<timemax1)
				{
					rt1[i]=rt[i];
					rt1[i]=0;
				}
				else
				{
					printf("\nBurst Time cannot be negative");
					break;
				}
			}
		}
		}
		for(i=0;i<=n;i++)
		{
		
		arr[i]=rt1[i];
		
	}
		for(i=0;i<n;i++)
		{
			if(arr[i]<arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
			for(i=0;i<n;i++)
			{
				arr[i]=0;
			}
			for(i=0;i<n;i++)
			{
				wt[i]=0;
				for(k=0;k<i;k++)
				{
					wt[k]+=bt[k];
				}
				
			}
			float wt1=0;
			float tat1=0;
			for(i=0;i<n;i++)
			{
				tat[i]=bt[i]+wt[i];
				avg_wt[i]+=wt[i];
				avg_at[i]+=tat[i];
				wt1=wt1+wt[i];
				tat1=tat1+tat[i];
			}
			avg_wt[i]/=i;
			avg_at[i]/=i;
			printf("\n\nProcess     Arrival Time      Burst Time\n\n");
			for(i=0;i<n;i++)
			{
				printf("P[%d]\t\t%d\t\t%d\n",i,at[i],bt[i]);
			}
			
			printf("\n\n             * Average Waiting Time is :: %f  ",wt1/n);
			printf("\n\n             * Average Turn Around Time is :: %f  \n",tat1);	
			printf("\n  ---------------------------- x ---- x -----------------------------------");
			goto x;
			return 0;		
		}
		
 


