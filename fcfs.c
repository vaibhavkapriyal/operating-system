#include<stdio.h> 
struct proc
{
 int at;
 int bt;
 int no;
 int tat;
 int ct;
 int wt;
 
};
struct proc read(int i)
{
 struct proc p;
 printf("\n\n The process no.:%d.\n",i);
 p.no=i;
 printf("Enter the arrival time:");
 scanf("%d",&p.at);
 printf("Enter the burst time:");
 scanf("%d",&p.bt);
 return p;
}
 int main()
{
	printf("VAIBHAV KUMAR KAPRIYAL		60		A\n\n");
   int sum_tat=0;
   int sum_wt=0;
   int  n;
   float ideal=0,cycle,tp=0;  
  struct proc p[10],tmp; 
  int i,j;
  printf("Enter the number of processes you want to enter:");
  scanf("%d",&n);
 
 for(i=0;i<n;i++)
  p[i]=read(i);   
   for(i=0;i<n-1;i++)
  for(j=0;j<n-1-i;j++)    
  {
   if(p[j].at>p[j+1].at)
    {
    tmp=p[j];
    p[j]=p[j+1];
    p[j+1]=tmp;
   }
  }
  
  p[0].ct = p[0].at + p[0].bt;
  p[0].tat= p[0].ct - p[0].at;
  p[0].wt= p[0].tat - p[0].bt;
  sum_tat += p[0].tat;
  sum_wt += p[0].wt;
  printf("Process Id  Arrival Time  Brust Time  Turn Around Time  Waiting Time  Completion time\n");
  printf("   %d		     %d		 %d		%d		%d	     %d\n",p[0].no,p[0].at,p[0].bt,p[0].tat,p[0].wt,p[0].ct);
  for(i=1;i<n;i++)
  {
    if(p[i].at>=p[i-1].ct){
    	ideal=ideal+(p[i].at-p[i-1].ct);
      p[i].ct = p[i].at + p[i].bt;
      
     }
    else
    {
    	
      p[i].ct = p[i-1].ct +p[i].bt;
    }  
   p[i].tat= p[i].ct - p[i].at;
   p[i].wt= p[i].tat - p[i].bt;
    sum_tat += p[i].tat;
    sum_wt += p[i].wt;
    printf("   %d		     %d		 %d		%d		%d	     %d\n",p[i].no,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].ct);     
  }
  
  printf("Total turnaround :%d \n",sum_tat);
  printf("Average turnaround :%d \n",sum_tat/n);
  printf("Total waiting time :%0.2f \n",sum_wt);
  printf("Average waiting time :%0.2f \n",sum_wt/n);
  cycle=p[n-1].ct-p[0].at;
  float cpu=(cycle-ideal)/cycle*100;
  printf("Ideal Time :%0.2f \n",ideal);
  printf("Cycle Length :%0.2f \n",cycle);
  printf("CPU Utilization :%0.2f \n",cpu);
  tp=n/cycle;
   printf("throughput :%0.5f \n",tp);
  
  return 0;
 }	
