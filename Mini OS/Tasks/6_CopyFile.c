#include <stdio.h>
#include <stdlib.h>

int main()
{
    char source[100], dest[100];
    printf("Enter source file path: ");
    fgets(source, 100, stdin);
    printf("Enter destination file path: ");
    fgets(dest, 100, stdin);

    // Remove new line character from file paths
    int i = 0;
    while (source[i] != '\n')
        i++;
    source[i] = '\0';
    i = 0;
    while (dest[i] != '\n')
        i++;
    dest[i] = '\0';

    FILE *source_file, *dest_file;
    char ch;

    source_file = fopen(source, "rb");
    if (source_file == NULL)
    {
        printf("Error: Unable to open source file.\n");
        exit(1);
    }

    dest_file = fopen(dest, "wb");
    if (dest_file == NULL)
    {
        printf("Error: Unable to open destination file.\n");
        fclose(source_file);
        exit(1);
    }

    while ((ch = fgetc(source_file)) != EOF)
    {
        fputc(ch, dest_file);
    }

    printf("File copied successfully.\n");

    fclose(source_file);
    fclose(dest_file);
    return 0;
}
