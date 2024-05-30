#include <stdio.h>
#include <stdlib.h>

void create_file()
{
    FILE *fp;
    char file_name[50];
    printf("Enter file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        printf("Error creating file\n");
        return;
    }
    printf("File created successfully\n");
    fclose(fp);
}

void delete_file()
{
    char file_name[50];
    printf("Enter file name: ");
    scanf("%s", file_name);
    if (remove(file_name) == 0)
    {
        printf("File deleted successfully\n");
    }
    else
    {
        printf("No Such A file found\n");
    }
}

void save_file()
{
    FILE *fp;
    char file_name[50], content[500];
    printf("Enter file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    printf("Enter file content: ");
    scanf(" %[^\n]", content);
    fprintf(fp, "%s", content);
    printf("File saved successfully\n");
    fclose(fp);
}

void update_file()
{
    FILE *fp;
    char file_name[50], content[500];
    printf("Enter file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    printf("Enter the file content: ");
    scanf(" %[^\n]", content);
    fprintf(fp, "%s", content);
    printf("File updated successfully\n");
    fclose(fp);
}

void view_file()
{
    FILE *fp;
    char file_name[50], c;
    printf("Enter file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("No result fonud of file\n");
        return;
    }
    printf("File content:\n");
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fclose(fp);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nChoose an option:\n1. Create a file\n2. Delete a file\n3. Write into a file\n4. Append a file\n5. View file content\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                save_file();
                break;
            case 4:
                update_file();
                break;
            case 5:
                view_file();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
