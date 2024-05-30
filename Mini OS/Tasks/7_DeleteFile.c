#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    char filename[100];

    printf("Enter filename to delete: ");
    fgets(filename, 100, stdin);

    // Remove the newline character from the end of the filename
    filename[strcspn(filename, "\n")] = 0;

    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        printf("Error deleting file '%s'.\n", filename);
    }

    return 0;
}
