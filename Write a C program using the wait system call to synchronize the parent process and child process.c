#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

int fibonacci(int n) {
    int first = 0, second = 1, next;

    printf("child process of Fibonacci Series are: ");

    for (int i = 0; i < n; ++i) {
        printf("%d ", first);

        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    }

    if (pid == 0) {
        // Child process
        fibonacci(10);
    } else {

        wait(NULL);

        printf(" parent process of Prime Numbers: ");
        for (int i = 2; i <= 30; ++i) {
            if (isPrime(i))
                printf("%d ", i);
        }

        printf("\n");
    }

    return 0;
}
