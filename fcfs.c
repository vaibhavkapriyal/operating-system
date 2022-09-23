#include<stdio.h>

 
struct proc
{
 int a_t;
 int b_t;
 int no;
 int c_t;
 int ta_t;
 int w_t;
};
 
 
struct proc read(int i)
{
 struct proc p;
 printf("\n\n The process no.:%d.\n",i);
 p.no=i;
 printf("Enter the arrival time:");
 scanf("%d",&p.a_t);
 printf("Enter the burst time:");
 scanf("%d",&p.b_t);
 return p;
}

int main()
{
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
   if(p[j].a_t>p[j+1].a_t)
   {
    tmp=p[j];
    p[j]=p[j+1];
    p[j+1]=tmp;
   }
  }
  
  p[0].c_t=p[0].a_t+p[0].b_t;
  p[0].ta_t=p[0].c_t-p[0].a_t;
  p[0].w_t=p[0].ta_t-p[0].b_t;
  int sum_tat=sum_tat+p[0].ta_t;
  int sum_wt+sum_wt+p[0].w_t;
  
  for(i=0;i<n;i++)
  {
     if()
  }
  
 for(i=0;i<n;i++)
  printf("%d ",p[i].no); 
 return 0;
}
