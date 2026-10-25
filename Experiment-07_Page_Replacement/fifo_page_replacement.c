#include <stdio.h>

int main() {
    int j, n, i, s;
    
    printf("Enter the frame size: ");
    scanf("%d", &s);
    int f[s];
    
    printf("Enter the reference string size: ");
    scanf("%d", &n);
    int a[n];
    
    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int page_fault = 0;
    int page_hit = 0;
    int front = 0;
    
    for (i = 0; i < s; i++) {
        f[i] = -1;
    }
    
    printf("\nPage\tFrames Status\n");
    printf("---------------------\n");
    
    for (i = 0; i < n; i++) {
        int found = 0;
        
        for (j = 0; j < s; j++) {
            if (f[j] == a[i]) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            f[front] = a[i];
            front = (front + 1) % s;
            page_fault++;
        } else {
            page_hit++;
        }
        
        printf("%d\t", a[i]);
        for (j = 0; j < s; j++) {
            if (f[j] != -1) {
                printf("%d ", f[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    
    printf("\nTotal Page Faults: %d\n", page_fault);
    printf("Total Page Hits: %d\n", page_hit);
    
    return 0;
}
