/* NAME : SANTHOSH.A.M
  DATE  : 19/09/25
  DESCRIPTION :  An address book is used to save contact details such as names, phone numbers, and emails. It lets you add new contacts, change contact details, remove old ones, and find people easily. A digital address book makes this faster and simpler, helping to keep all contacts neat and organized.*/
#include <stdio.h>
#include "contact.h"

int main()
{
    int choice;
    int arr[100];//declare arr and size
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save contacts\n");
        printf("7. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createContact(&addressBook);//create contact
            break;
        case 2:
            searchContact(&addressBook,arr);//search contact
            break;
        case 3:
            editContact(&addressBook,arr);//Edit contact
            break;
        case 4:
            deleteContact(&addressBook,arr);//deletecontact
            break;
        case 5:
            listContacts(&addressBook);//list contacts
            break;
        case 6:
            printf("Saving...😊\n");
            saveContactsToFile(&addressBook);//save contacts
            break;
        case 7:
            break;
        default:
            printf("*** Invalid choice. Please try again ! ***\n");
        }
    } while (choice != 7);//exit

    return 0;
}
