#include <stdio.h>
struct proc
{
    int at,bt,ct,st,tat,wt,no,rt,pt;
};

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int n,i,t_tat=0,t_wt=0,t_rt=0,t_it=0;
    float a_tat,a_wt,a_rt,cpu_u,tput;
    printf("Enter the no. of processes: ");
    scanf("%d",&n);
    struct proc p[n];

    int burst[n],is_c[n];

    for(i=0;i<n;i++)
    {
        p[i].no=i+1;
        printf("Process No.: %d\n",p[i].no);
        printf("Enter Arrival Time: ");
        scanf("%d",&p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d",&p[i].bt);
        printf("Enter Priority: ");
        scanf("%d",&p[i].pt);
        burst[i]=p[i].bt;
        is_c[i]=0;
        printf("\n");
    }

    int curr=0,c=0,prev=0;

    while (c!=n)
    {
        int idx=-1,mn=9999;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=curr && is_c[i]==0)
            {
                if(p[i].pt<mn)
                {
                    mn=p[i].pt;
                    idx=i;
                }

                if(p[i].pt==mn)
                {
                    if(p[i].at<p[idx].at)
                    {
                        mn=p[i].pt;
                        idx=i;
                    }
                }
            }
        }
        if(idx!=-1)
        {
            if(burst[idx]==p[idx].bt)
            {
                p[idx].st=curr;
                t_it=p[idx].st-prev;
            }
            burst[idx]=burst[idx]-1;
            curr++;
            prev=curr;

            if(burst[idx]==0)
            {
                p[idx].ct=curr;
                p[idx].tat=p[idx].ct-p[idx].at;
                p[idx].wt=p[idx].tat-p[idx].bt;
                p[idx].rt=p[idx].st-p[idx].at;
                t_tat+=p[idx].tat;
                t_wt+=p[idx].wt;
                t_rt+=p[idx].rt;

                is_c[idx]=1;
                c++;
            }
        }
        else
            curr++;
    }
    int min_at=9999,max_ct=-1;

    for(i=0;i<n;i++)
    {
        min_at=min(min_at,p[i].at);
        max_ct=max(max_ct,p[i].ct);
    }
    a_tat=(float)t_tat/n;
    a_wt=(float)t_wt/n;
    a_rt=(float)t_rt/n;
    cpu_u=((max_ct-t_it)/(float)max_ct)*100;
    tput=max_ct-min_at;
    printf("\n\n");
    printf("#P\t\tAT\t\tBT\t\tPRIO\t\tST\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].pt,p[i].st,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }

    printf("Average TurnAround Time: %f\n",a_tat);
    printf("Average Waiting Time: %f\n",a_wt);
    printf("Average Response Time: %f\n",a_rt);
    printf("CPU Utilization: %f\n",cpu_u);
    printf("ThroughPut: %f\n",tput);
    return 0;
}