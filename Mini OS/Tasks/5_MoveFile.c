#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char old_path[100], new_path[100];
    printf("Enter old path of file: ");
    fgets(old_path, 100, stdin);
    old_path[strcspn(old_path, "\n")] = 0; // remove newline character

    printf("Enter new path of file: ");
    fgets(new_path, 100, stdin);
    new_path[strcspn(new_path, "\n")] = 0; // remove newline character

    int result = rename(old_path, new_path);
    if (result == 0) {
        printf("File moved successfully.\n");
        system("ls -l"); // refresh directory listing
    } else {
        printf("Error moving file.\n");
        perror("rename");
    }
    return 0;
}
