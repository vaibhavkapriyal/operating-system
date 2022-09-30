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
   int sum_tat=0;
   int sum_wt=0;
   int  n;  
  struct proc p[10],tmp; 
  int i,j;
  printf("Enter the number if processes you want to enter:");
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
  printf("Process Id  Arrival Time  Brust Time  Turn Around Time  Wating Time  Completion time\n");
  printf("   %d		     %d		 %d		%d		%d	     %d\n",p[0].no,p[0].at,p[0].bt,p[0].tat,p[0].wt,p[0].ct);
  for(int i=1;i<n;i++)
  {
    if(p[i].at>=p[i-1].ct){
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
  printf("Total weight time :%d \n",sum_wt);
  
  return 0;
 }	
