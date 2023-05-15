#include <stdio.h>

// Function to calculate the number of disk I/O operations for contiguous allocation
int contiguousAllocation(int blockSize, int position) {
    return 1; // In contiguous allocation, only one disk I/O operation is required
}

// Function to calculate the number of disk I/O operations for linked allocation
int linkedAllocation(int blockSize, int position) {
    int blockCount = 0;

    // Traverse the linked list until the desired position is reached
    while (blockSize > 0 && position > 0) {
        blockCount++;
        blockSize--;
        position--;
    }

    return blockCount + 1; // Add one more disk I/O operation for the new block
}

// Function to calculate the number of disk I/O operations for indexed (single-level) allocation
int indexedAllocation(int blockSize, int position) {
    int indexBlockCount = 1; // Number of disk I/O operations to read the index block
    int blockCount = 0;

    // Calculate the number of blocks to traverse in the index block
    int indexTraverse = position / blockSize;

    // Calculate the remaining position within the last block in the index block
    int indexPosition = position % blockSize;

    // Traverse the index block
    while (indexTraverse > 0) {
        indexBlockCount++;
        indexTraverse--;
    }

    // Read the desired block from disk
    blockCount++;

    // Read the block within the index block
    blockCount++;

    // Add one more disk I/O operation for the new block
    return indexBlockCount + blockCount;
}

int main() {
    int blockSize = 1; // Size of each block
    int fileLength = 100; // Number of blocks in the file
    int position;

    printf("Enter the position where the block needs to be added (1-%d): ", fileLength);
    scanf("%d", &position);

    if (position < 1 || position > fileLength) {
        printf("Invalid position. Please enter a valid position within the range.\n");
        return 0;
    }

    // Calculate disk I/O operations for contiguous allocation
    int contiguousOperations = contiguousAllocation(blockSize, position);

    // Calculate disk I/O operations for linked allocation
    int linkedOperations = linkedAllocation(blockSize, position);

    // Calculate disk I/O operations for indexed allocation
    int indexedOperations = indexedAllocation(blockSize, position);

    printf("Contiguous Allocation: %d disk I/O operations\n", contiguousOperations);
    printf("Linked Allocation: %d disk I/O operations\n", linkedOperations);
    printf("Indexed Allocation: %d disk I/O operations\n", indexedOperations);

    return 0;
}
