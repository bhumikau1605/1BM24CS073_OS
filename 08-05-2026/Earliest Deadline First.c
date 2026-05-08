#include <stdio.h>
#include <limits.h>
typedef struct
{
    int id;
    int ex_time;
    int p;
    int d;
    int r_time;
    int nr;
    int ad;

} Task;
int get_edf_task(Task tasks[], int n)
{
    int min_d = INT_MAX;
    int selected = -1;
    for(int i = 0; i < n; i++)
    {
        if(tasks[i].r_time > 0)
        {
            if(tasks[i].ad < min_d)
            {
                min_d =
                    tasks[i].ad;
                selected = i;
            }
        }
    }
    return selected;
}
int main()
{
    int n, total_time;
    printf("Enter Number of Tasks: ");
    scanf("%d", &n);
    Task tasks[n];
    for(int i = 0; i < n; i++)
    {
        tasks[i].id = i + 1;
        printf("\nTask %d\n", i + 1);
        printf("Execution Time: ");
        scanf("%d", &tasks[i].ex_time);
        printf("p: ");
        scanf("%d", &tasks[i].p);
        printf("d: ");
        scanf("%d", &tasks[i].d);
        tasks[i].r_time = 0;
        tasks[i].nr = 0;
        tasks[i].ad = 0;
    }
    printf("\nEnter Total Simulation Time: ");
    scanf("%d", &total_time);
    printf("\n================================");
    printf("\n Earliest d First (EDF)");
    printf("\n================================");
    printf("\n\nTime\tRunning Task");
    printf("\n-------------------------\n");
    for(int t = 0; t < total_time; t++)
    {
        for(int i = 0; i < n; i++)
        {
            if(t == tasks[i].nr)
            {
                tasks[i].r_time =
                    tasks[i].ex_time;
                tasks[i].ad  =
                    t + tasks[i].d;
                tasks[i].nr +=
                    tasks[i].p;
            }
        }
        int current = get_edf_task(tasks, n);
        if(current != -1)
        {
            printf("%d\tTask %d\n",t,tasks[current].id);
            tasks[current].r_time--;
        }
        else
        {
            printf("%d\tIdle\n", t);
        }
    }
    return 0;
}
