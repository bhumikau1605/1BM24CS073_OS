#include<stdio.h>

int preemptive();
int nonpreemptive();

int n, completed[20], current_time=0, choice;
int pid[20], at[20], bt[20], p[20];
int ct[20], tat[20], wt[20];

int main(){
    printf("Enter number of processes:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        printf("PID: "); scanf("%d",&pid[i]);
        printf("AT: "); scanf("%d",&at[i]);
        printf("BT: "); scanf("%d",&bt[i]);
        printf("Priority: "); scanf("%d",&p[i]);
        completed[i]=0;
    }

    printf("\n1.Preemptive  2.Non-preemptive\nChoice: ");
    scanf("%d",&choice);

    if(choice==1) preemptive();
    else nonpreemptive();

    return 0;
}

int preemptive(){
    int rem_time[20];
    int done=0;

    for(int i=0;i<n;i++)
        rem_time[i]=bt[i];

    while(done!=n){
        int minp=999, k=-1;

        // select process
        for(int i=0;i<n;i++){
            if(at[i]<=current_time && rem_time[i]>0){
                if(p[i] < minp){
                    minp = p[i];
                    k = i;
                }
            }
        }

        if(k==-1){
            current_time++;
        }
        else{
            rem_time[k]--;
            current_time++;

            if(rem_time[k]==0){
                ct[k]=current_time;
                completed[k]=1;
                done++;
            }
        }
    }

    float ttat=0, twt=0;

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        ttat+=tat[i];
        twt+=wt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }

    printf("\nAvg WT=%.2f",twt/n);
    printf("\nAvg TAT=%.2f",ttat/n);
}

int nonpreemptive(){
    int done=0;

    while(done!=n){
        int minp=999, k=-1;

        for(int i=0;i<n;i++){
            if(at[i]<=current_time && completed[i]==0){
                if(p[i] < minp){
                    minp=p[i];
                    k=i;
                }
            }
        }

        if(k==-1){
            current_time++;
        }
        else{
            current_time += bt[k];
            ct[k]=current_time;
            tat[k]=ct[k]-at[k];
            wt[k]=tat[k]-bt[k];

            completed[k]=1;
            done++;
        }
    }

    float ttat=0, twt=0;

    for(int i=0;i<n;i++){
        ttat+=tat[i];
        twt+=wt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }

    printf("\nAvg WT=%.2f",twt/n);
    printf("\nAvg TAT=%.2f",ttat/n);
}
