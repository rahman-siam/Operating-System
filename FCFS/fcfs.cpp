#include<iostream>
using namespace std;
int main(){
    int at[5]={0,1,2,3,4};
    int bt[5]={3,7,9,2,4};
    int ct[5],tat[5],wt[5],rt[5];

    int ctCount=0;

    for (int i = 0; i < 5; i++)
    {
        ctCount=bt[i]+ctCount;
        ct[i]=ctCount;

    }

    for (int i = 0; i < 5; i++)
    {
        tat[i]=ct[i]-at[i];
         wt[i]=tat[i]-bt[i];
         rt[i]=wt[i];
    }

    cout<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<"\t"<<"RT"<<"\n";

    for (int i = 0; i < 5; i++)
    {
            cout<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<"\t"<<rt[i]<<"\n";

    }
    return 0;

}