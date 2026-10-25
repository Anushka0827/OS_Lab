#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10];
    int flag1, flag2, i, j, pos, faults = 0, counter = 0;

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames Status\n");
    printf("---------------------\n");

    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                temp[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    temp[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            pos = findLRU(temp, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            temp[pos] = counter;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", no_of_pages - faults);

    return 0;
}
