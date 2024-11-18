#include <stdio.h>

void main() {
    int bt[20], wt[20], tat[20], n, i;
    int total_wt = 0, total_tat = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting times
    wt[0] = 0;  // First process has no waiting time
    for(i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];  // Waiting time = previous burst time + previous waiting time
    }

    // Calculate turnaround times
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  // Turnaround time = burst time + waiting time
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Output results
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    // Calculate and display averages
    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f", (float)total_tat / n);
}
