#include<stdio.h>
int main(){
    int pid[20], ct[20], tat[20], wt[20], at[20], bt[20], i, n;
    float twt=0.0, ttat=0.0, awt, att;
    printf("\nNAME: BHUMIKA U | USN: 1BM24CS073 | DATE: 06-03-2026\n");
    printf("Enter the number of Processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter process id: ");
        scanf("%d",&pid[i]);
        printf("Enter Arrival time: ");
        scanf("%d",&at[i]);
        printf("Enter Burst time: ");
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++){
        if(at[i]>at[i+1]){
            int x=at[i];
            at[i]=at[i+1];
            at[i+1]=x;
            int temp=pid[i];
            pid[i]=pid[i+1];
            pid[i+1]=temp;
            int btemp=bt[i];
            bt[i]=bt[i+1];
            bt[i+1]=btemp;
        }
    }
    ct[0]=at[0]+bt[0];
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++){
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
            wt[i]=0;
        }else{
            wt[i]=ct[i-1]-at[i];
            ct[i]=ct[i-1]+bt[i];
        }
        tat[i]=wt[i]+bt[i];
    }
    for(i=0;i<n;i++){
        twt+=wt[i];
        ttat+=tat[i];
    }
    awt=(twt/n);
    att=(ttat/n);
    printf("\n Process |\tAT |\tBT |\tCT |\tWT |\tTAT\n ");
    for(i=0;i<n;i++){
            printf("\n\tP%d \t%d \t%d \t%d \t%d \t%d",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);;

    }
    printf("\n\nAverage Waiting Time: %.2f",awt);
    printf("\n\nAverage Turnaround Time: %.2f",ttat);
    return 0;
}
