#include <stdio.h>

#define MAX 100

int main() {
    int n, TQ;
    int AT[MAX], BT[MAX], RT[MAX];
    int CT[MAX], WT[MAX], TAT[MAX];
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};

    int time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i);
        scanf("%d %d", &AT[i], &BT[i]);
        RT[i] = BT[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &TQ);


    for (int i = 0; i < n; i++) {
        if (AT[i] <= time) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    while (completed < n) {

        if (front == rear) {
            time++;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && AT[i] <= time) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int p = queue[front++];

        if (RT[p] > TQ) {
            time += TQ;
            RT[p] -= TQ;
        } else {
            time += RT[p];
            RT[p] = 0;
            CT[p] = time;
            completed++;
        }


        for (int i = 0; i < n; i++) {
            if (!visited[i] && AT[i] <= time) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }


        if (RT[p] > 0) {
            queue[rear++] = p;
        }
    }

    float totalTAT = 0, totalWT = 0;

    for (int i = 0; i < n; i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        totalTAT += TAT[i];
        totalWT += WT[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i, AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}

