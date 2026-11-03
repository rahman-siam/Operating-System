#include<stdio.h>

int main(){
       int at[5] = {0, 1, 2, 3, 4};
       int bt[5] = {4, 3, 1, 2, 5};
       int ct[5], tat[5], wt[5], rt[5];

       int countCt=0;
       
       for (int i = 0; i < 5; i++)
       {
        countCt=countCt+bt[i];
        ct[i]=countCt;
       }

       for (int i = 0; i < 5; i++)
       {
        tat[i]=ct[i]-at[i];
         wt[i]=tat[i]-bt[i];
         rt[i]=wt[i];
       }
       
       printf("AT\tBT\tCT\tTAT\tWT\tRT\t\n");

       for (int i = 0; i < 5; i++)
       {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
       }
       
       
}