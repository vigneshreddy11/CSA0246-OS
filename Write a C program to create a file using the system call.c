#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 100

int main() {
    char filename[100];
    int fd, nbytes;
    char data[MAX_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Create a new file or truncate an existing file
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        printf("File creation failed.\n");
        return 1;
    }

    printf("Enter data to write to the file (max %d characters):\n", MAX_SIZE);
    scanf(" %[^\n]s", data);

    // Write data to the file
    nbytes = write(fd, data, sizeof(data));
    if (nbytes == -1) {
        printf("Write to file failed.\n");
        close(fd);
        return 1;
    }

    printf("Data written to the file successfully.\n");

    // Close the file
    close(fd);

    // Reopen the file in read-only mode
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("File open failed.\n");
        return 1;
    }

    printf("Reading data from the file:\n");

    // Read and print data from the file
    while ((nbytes = read(fd, data, sizeof(data))) > 0) {
        write(STDOUT_FILENO, data, nbytes);
    }

    if (nbytes == -1) {
        printf("Read from file failed.\n");
        close(fd);
        return 1;
    }

    // Close the file
    close(fd);

    return 0;
}
