#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, frames;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int* pages = (int*) malloc(n * sizeof(int));
    printf("Enter the page references: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int* table = (int*) malloc(frames * sizeof(int));
    int* used = (int*) calloc(frames, sizeof(int)); // initialize all elements to 0
    int page_faults = 0;
    int page_hits = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        // check if page is already in memory
        for (int j = 0; j < frames; j++) {
            if (table[j] == pages[i]) {
                found = 1;
                used[j] = i;
                page_hits++;
                break;
            }
        }
        // if page is not in memory, find least recently used page to replace
        if (!found) {
            int min_used = used[0], min_index = 0;
            for (int j = 1; j < frames; j++) {
                if (used[j] < min_used) {
                    min_used = used[j];
                    min_index = j;
                }
            }
            table[min_index] = pages[i];
            used[min_index] = i;
            page_faults++;
        }
    }

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hits);

    free(pages);
    free(table);
    free(used);

    return 0;
}
