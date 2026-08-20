#include<stdio.h>
struct process{
	int pid;//process id 
	int at;//arrival time 
	int bt;//brust time
	int st;//start time
	int ct;//completion time
	int tat;//turn around time
	int wt;//waiting time  
};
int main(){
	int i,n,time=0;
	struct process p[10];
	struct process temp;
	
	float avg_tat=0 , avg_wt=0;
	printf("enter no of process");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		p[i].pid=i+1;
		
		printf("enter the arrival time of process%d",p[i].pid);
		scanf("%d",&p[i].at);
		
		printf("enter the brust time of process%d",p[i].pid);
		scanf("%d",&p[i].bt);
		}
		for(i=0;i<n;i++){
			if(time < p[i].at)
			time=p[i].at;
			
			time=time+p[i].bt;
			}
			
			p[i].ct =time;
			p[i].tat = p[i].ct - p[i].at;
			p[i].wt = p[i].tat - p[i].bt;
			
			avg_tat = avg_tat + p[i].tat;
			avg_wt = avg_wt + p[i].wt;
			
			printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
			
			for(i=0;i<n;i++){
			printf("p%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
			}
			avg_tat = avg_tat/n;
			avg_wt = avg_wt/n;
			
			printf("\naverage tat =%.2f",avg_tat);
			printf("\naverage wt =%.2f",avg_wt);
			return 0;
			}
			
