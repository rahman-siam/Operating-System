
#include <stdio.h>

int main() {
    int at[5] = {1, 3, 5, 2, 4};
    int bt[5] = {5, 3, 2, 1, 4};
    int priority[5] = {4, 5, 2, 8, 3};

    int current_time = 0;
    int complete_count = 0;

    int ct[5], tat[5], wt[5], rt[5];
    int remaining_bt[5];
    int completed[5] = {0};
    int started[5] = {0};

    for (int i = 0; i < 5; i++) {
        remaining_bt[i] = bt[i];
        rt[i] = -1;
    }

    while (complete_count < 5) {
        int highest = -1;
        int min_priority = 999;

        for (int i = 0; i < 5; i++) {
            if (at[i] <= current_time &&
                completed[i] == 0 &&
                priority[i] < min_priority) {

                min_priority = priority[i];
                highest = i;
            }
        }

        if (highest == -1) {
            current_time++;
            continue;
        }

        if (started[highest] == 0) {
            rt[highest] = current_time - at[highest];
            started[highest] = 1;
        }

        remaining_bt[highest]--;
        current_time++;

        if (remaining_bt[highest] == 0) {
            ct[highest] = current_time;
            tat[highest] = ct[highest] - at[highest];
            wt[highest] = tat[highest] - bt[highest];

            completed[highest] = 1;
            complete_count++;
        }
    }

    printf("Process\tAT\tBT\tPriority\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], priority[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}
