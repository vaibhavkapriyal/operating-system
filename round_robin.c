#include <stdio.h>
struct proc
{
    int at,bt,ct,st,tat,wt,no,rt;
};
 int main()
 {

      int n,i,t_tat=0,t_wt=0,t_rt=0,t_it=0,count=0,qt,temp,sq=0,st_c=0;
      float a_tat,a_wt,a_rt,cpu_u,tput;
      printf("Enter the no. of processes: ");
      scanf("%d",&n);
      struct proc p[n];

      int burst[n];

      for(i=0;i<n;i++)
      {
            p[i].no=i+1;
            printf("Process No.: %d\n",p[i].no);
            printf("Enter Arrival Time: ");
            scanf("%d",&p[i].at);
            printf("Enter Burst Time: ");
            scanf("%d",&p[i].bt);
            burst[i]=p[i].bt;
            printf("\n");
      }
       printf("Enter the Qunataum Time: ");
       scanf("%d",&qt);

      while(count!=n)
      {
            for(i=0,count=0;i<n;i++)
            {
                  temp=qt;
                  if(burst[i]==0)
                  {
                        count++;
                        continue;
                  }

                  if(burst[i]>qt)
                  {
                        burst[i]-=qt;
                  }
                  else
                  {
                        if(burst[i]>=0)
                        {
                              temp=burst[i];
                              burst[i]=0;
                        }
                  }
                  if(st_c<n)
                  {
                        p[i].st=sq;
                        st_c++;
                  }
                  sq+=temp;
                  p[i].ct=sq;
            }
      }
    printf("\n\n");
    printf("#P\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tST\t\tRT\n");
    for(int i=0;i<n;i++)
    {
      p[i].tat=p[i].ct-p[i].at;
      p[i].wt=p[i].tat-p[i].bt;
       p[i].rt=p[i].st-p[i].at;
      t_tat+=p[i].tat;
      t_wt+=p[i].wt;
      t_rt+=p[i].rt;
      printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].st,p[i].rt);
    }

     a_tat=(float)t_tat/n;
     a_wt=(float)t_wt/n;
      a_rt=(float)t_rt/n;
     printf("Average TurnAround Time: %0.2f\n",a_tat);
     printf("Average Waiting Time: %0.2f\n",a_wt);
     printf("Average Response Time: %0.2f\n",a_rt);
 }