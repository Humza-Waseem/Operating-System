#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];

    printf("Enter filename: ");
    fgets(filename, 100, stdin);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    printf("File created successfully.\n");

    fclose(fp);
    return 0;
}
