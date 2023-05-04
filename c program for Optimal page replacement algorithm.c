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

    int* table = (int*) calloc(frames, sizeof(int)); // initialize all elements to 0
    int* next = (int*) malloc(n * sizeof(int)); // initialize all elements to n
    int page_faults = 0;
    int page_hits = 0;
    for (int i = 0; i < n; i++) {
        // initialize next to the next occurrence of each page
        next[i] = n;
        for (int j = i + 1; j < n; j++) {
            if (pages[j] == pages[i]) {
                next[i] = j;
                break;
            }
        }
        // check if page is already in memory
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (table[j] == pages[i]) {
                found = 1;
                page_hits++;
                break;
            }
        }
        // if page is not in memory, find the page with the farthest next occurrence
        if (!found) {
            int farthest = 0, farthest_index = 0;
            for (int j = 0; j < frames; j++) {
                if (next[table[j]] > farthest) {
                    farthest = next[table[j]];
                    farthest_index = j;
                }
            }
            table[farthest_index] = pages[i];
            page_faults++;
        }
    }

    printf("Total page faults: %d\n", page_faults);
    printf("Total page hits: %d\n", page_hits);

    free(pages);
    free(table);
    free(next);

    return 0;
}
