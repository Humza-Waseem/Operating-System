#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    FILE *fp;
    char filename[50], ch;
    int lines = 0, characters = 0, words = 0;

    printf("Enter any filename that exists in current directory: ");
    scanf("%s", filename);

    if (access(filename, F_OK) == -1)
    {
        printf("File %s does not exist\n", filename);
        exit(1);
    }

    if (access(filename, R_OK) == -1)
    {
        printf("You do not have permission to read file %s\n", filename);
        exit(1);
    }

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if (ch == '\n')
        {
            lines++;
            words++;
        }
        else if (ch == ' ')
        {
            words++;
        }
    }

    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);

    fclose(fp);

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("Current working directory: %s\n", cwd);
    }
    else
    {
        printf("Unable to get current working directory\n");
    }

    return 0;
}
