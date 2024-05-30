#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    while (1) {
        system("clear"); // clear the screen

        time_t current_time = time(NULL);
        printf("Current time: %s", ctime(&current_time));

        sleep(1); // wait for 1 second before updating the time
    }

    return 0;
}
