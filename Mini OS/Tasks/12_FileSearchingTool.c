#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    char ch;
    FILE *fp;

    printf("Enter the filename: ");
    fgets(filename, 100, stdin);
    
    // Replace newline character with null terminator
    int len = strlen(filename);
    if (filename[len-1] == '\n') {
        filename[len-1] = '\0';
    }

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    printf("File found. Do you want to see the content of file? (y/n) ");

    ch = getchar();

    if (ch == 'y' || ch == 'Y') {
        printf("\nContent of the file %s:\n\n", filename);
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
    }

    fclose(fp);
    return 0;
}
