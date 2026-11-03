
#include <stdio.h>

int main() {
    int at[5] = {0, 0, 0, 0, 0};
    int bt[5] = {5, 3, 2, 1, 4};

    int current_time = 0;
    int complete_count = 0;

    int ct[5], tat[5], wt[5], rt[5];
    int completed[5] = {0};
    int started[5] = {0};

    while (complete_count < 5) {
        int shortest = -1;
        int min_bt = 999;

        for (int i = 0; i < 5; i++) {
            if (at[i] <= current_time &&
                completed[i] == 0 &&
                bt[i] < min_bt) {

                min_bt = bt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        if (started[shortest] == 0) {
            rt[shortest] = current_time - at[shortest];
            started[shortest] = 1;
        }

        current_time += bt[shortest];

        ct[shortest] = current_time;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        completed[shortest] = 1;
        complete_count++;
    }

    printf("Process\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}
