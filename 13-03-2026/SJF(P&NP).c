#include<stdio.h>
int at[20], bt[20], ct[20], tat[20], pid[20], wt[20], rt[20], i=0, n, k, choice;
float twt=0.0, ttat=0.0, awt, att;
int done=0;
int completed[20];
int current_time=0, minbt=0, time=0;
int preemptive();
int nonpreemptive();
int main(){
    printf("Name: BHUMIKA U | USN: 1BM24CS073 | DATE: 13-03-2026 \n");
    printf("Enter the number of processes: \n");
    scanf("%d",&n);
    while(i<n){
        printf("Enter Process ID: ");
        scanf("%d",&pid[i]);
        printf("Enter Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Enter the Burst time: ");
        scanf("%d",&bt[i]);
        completed[i]=0;
        i++;
    }
    printf("Enter your choice: (1-Preemptive Scheduling 2-Non Preemptive Scheduling) : \n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("PREEMPTIVE SCHEDULING!\n");
        preemptive();
        break;
    case 2:
        printf("NONPREEMPTIVE SCHEDULING!\n");
        nonpreemptive();
        break;
    default:
        printf("Wrong choice choose again! \n");
    }
    return 0;
}
int preemptive(){
    int comp_count=0;
    int res[20];
    int started[20]={0};
    float twt2=0.0, ttat2=0.0;
    for(i=0;i<n;i++){
        rt[i]=bt[i];
    }
    while(comp_count<n){
        int minrt=9999, j=-1;
        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(rt[i]<minrt){
                    minrt=rt[i];
                    j=i;
                }
            }
        }
        if(j==-1){
            time++;
            continue;
        }
        if(started[j]==0){
            res[j]=time-at[j];
            started[j]=1;
        }
        rt[j]--;
        time++;
        if(rt[j]==0){
            comp_count++;
            ct[j]=time;
            tat[j]=ct[j]-at[j];
            wt[j]=tat[j]-bt[j];
            twt2+=wt[j];
            ttat2+=tat[j];
        }
    }
    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\tRT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], ct[i], wt[i], tat[i], res[i]);
    }
    printf("\nAvg Waiting Time: %.2f",twt2/n);
    printf("\nAvg Turnaround Time: %.2f",ttat2/n);
    return 0;

}
int nonpreemptive(){
    while(done<n){
        k=-1;
        minbt=9999;
        for(i=0;i<n;i++){
                if(at[i]<=current_time && completed[i]==0){
                        if(minbt>bt[i]){
                            minbt=bt[i];
                            k=i;
                        }
                }
        }
        if(k!=-1){
            ct[k]=current_time+bt[k];
            tat[k]=ct[k]-at[k];
            wt[k]=tat[k]-bt[k];
            current_time=ct[k];
            completed[k]=1;
            done++;
            twt+=wt[k];
            ttat+=tat[k];
        }
        else{
            current_time++;
        }
    }
    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAvg Waiting Time: %.2f",twt/n);
    printf("\nAvg Turnaround Time: %.2f",ttat/n);
    return 0;
}
