#include <stdio.h>

int main() {
    int at[5] = {0, 0, 0, 0, 0};
    int bt[5] = {5, 3, 2, 1, 4};
    int time_quantum = 2;

    int current_time = 0;
    int complete_count = 0;

    int ct[5], tat[5], wt[5], rt[5];
    int remaining_bt[5];
    int started[5] = {0};

    int queue[100], front = 0, rear = 0;

    for (int i = 0; i < 5; i++) {
        remaining_bt[i] = bt[i];
        rt[i] = -1;
        queue[rear++] = i;
    }

    while (complete_count < 5) {
        int current = queue[front++];

        if (started[current] == 0) {
            rt[current] = current_time - at[current];
            started[current] = 1;
        }

        if (remaining_bt[current] > time_quantum) {
            current_time += time_quantum;
            remaining_bt[current] -= time_quantum;
        } else {
            current_time += remaining_bt[current];
            remaining_bt[current] = 0;

            ct[current] = current_time;
            tat[current] = ct[current] - at[current];
            wt[current] = tat[current] - bt[current];

            complete_count++;
        }

        if (remaining_bt[current] > 0) {
            queue[rear++] = current;
        }
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}
