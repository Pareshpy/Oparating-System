#include <stdio.h>
int i;
int display(int proc ,int at[],int bt[])//Question table
{
//	display the data which user is input 
	printf("\n\n---Question table---");
	printf("\nProcess\tAT\tBT\n");
	printf("----------------------------");
	for(i=1;i<=proc;i++)
	{
		printf("\nP%d\t%d\t%d",i,at[i],bt[i]);
	}
}

int claculating_ct(int proc, int ct[], int bt[])
{
	ct[0]=0;
	for(i=1;i<=proc;i++)
	{
		ct[i]=ct[i-1]+bt[i];
	}
}

int claculating_tat(int proc,int ct[], int tat[], int at[])
{
	for(i=1;i<=proc;i++)
	{
		tat[i]=ct[i]-at[i];
	}
}

int calculating_wt(int proc,int wt[], int tat[], int bt[])
{
	for(i=1;i<=proc;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
}

int display_gantt_chart(int proc, int at[], int ct[])
{
	printf("\n\n---Gantt Chart---");
	printf("\n");
	for(i=1;i<=proc;i++)
	{
		printf("|P%d\t",i);
	}
	printf("|\n");
	printf("0");
	for(i=1;i<=proc;i++)
	{
		printf("  \t%d",ct[i]);
	}
}
int display_answer_table(int proc, int at[], int bt[], int ct[], int tat[], int wt[]){
	printf("\n\n---Answer Table---");
	printf("\n-------------------------------------------------------------------------------------------------");
	printf("\n|\tProcess\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|");
	printf("\n-------------------------------------------------------------------------------------------------");
	for(i=1;i<=proc;i++)
	{
		printf("\n|\tP%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|",i,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("\n-------------------------------------------------------------------------------------------------");
}
int calculating_avgtat(int proc,int tat[], float avgtat)
{
	for(i=1;i<=proc;i++)
	{
		avgtat=avgtat+tat[i];
	}
	avgtat=avgtat/proc;
	printf("\navarage tat = %.2f",avgtat);
}
int calculating_avgwt(int proc, int wt[], float avgwt)
{
	for(i=1;i<=proc;i++)
	{
		avgwt=avgwt+wt[i];
	}
	avgwt=avgwt/proc;	
	printf("\navarage wt = %.2f\n\n\n",avgwt);
}
int main()
{
	int proc, i ;
	float avgtat=0;
	float avgwt=0;
	
//	intput section
	printf("Enter how manny process you want:\t");
	scanf("%d",&proc);
	int  at[proc], bt[proc], ct[proc], tat[proc], wt[proc], rt[proc];
	for(i=1;i<=proc;i++)
	{
	printf("\n\nEnter the arival time(at) of p%d:\t",i);
	scanf("%d",&at[i]);
	printf("\nEnter the burst time(bt) of p%d:\t\t",i);
	scanf("%d",&bt[i]);
	}
// 	display section
	display(proc,at,bt);
	
// 	calculating Section{		
	//	clulating CT
		claculating_ct(proc,ct,bt);	
	//	calculating TAT
		claculating_tat(proc,ct,tat,at);
	//	calculating waittime 
		calculating_wt(proc,wt,tat,bt);
//}
//	printing section
//	Grantt chart
	display_gantt_chart(proc,at,ct);	
//	final answer table
	display_answer_table(proc,at,bt,ct,tat,wt);
	//	avarage tat and wt{
		//	avg tat
			calculating_avgtat(proc,tat,avgtat);
		//	avg wt
			calculating_avgwt(proc,wt,avgwt);//}
	
	return 0;
}
