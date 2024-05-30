#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Structure to hold contact information
struct contact {
    char name[50];
    char phone[20];
    char email[50];
};

// Array to hold all contacts
struct contact contacts[MAX_CONTACTS];

// Current number of contacts
int num_contacts = 0;

// Function to add a new contact
void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Cannot add new contact - maximum number of contacts reached.\n");
        return;
    }

    struct contact new_contact;

    printf("Enter name: ");
    scanf("%s", new_contact.name);

    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);

    printf("Enter email address: ");
    scanf("%s", new_contact.email);

    contacts[num_contacts] = new_contact;
    num_contacts++;

    printf("Contact added successfully.\n");
}

// Function to display all contacts
void display_contacts() {
    if (num_contacts == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("%-20s %-20s %-20s\n", "Name", "Phone", "Email");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%-20s %-20s %-20s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by name
void search_contact() {
    if (num_contacts == 0) {
        printf("No contacts to search.\n");
        return;
    }

    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, contacts[i].name) == 0) {
            printf("%-20s %-20s %-20s\n", "Name", "Phone", "Email");
            printf("--------------------------------------------------------------\n");
            printf("%-20s %-20s %-20s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }

    printf("Contact not found.\n");
}

// Function to delete a contact by name
void delete_contact() {
    if (num_contacts == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    char delete_name[50];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(delete_name, contacts[i].name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j+1];
            }
            num_contacts--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("Contact Manager\n");
        printf("---------------\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if(choice == 1)
            add_contact();
        else if(choice == 2)
            display_contacts();
        else if(choice == 3)
            search_contact();
        else if(choice == 4)
            delete_contact();
        else if(choice == 5)
            return 0;
        else{
            printf("Invalid Selection");
            exit(0);
        }
    }

}