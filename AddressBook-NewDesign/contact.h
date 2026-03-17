#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct
{
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct
{
    int contactCount;
    Contact contacts[100];
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook,int *arr);
void editContact(AddressBook *addressBook, int *arr);
void deleteContact(AddressBook *addressBook , int *arr);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);

int validate_number(char *number);
int validate_name(char *name);
int validate_email(char *email);

int search_name(AddressBook *addressBook,int *arr);
int search_number(AddressBook *addressBook);
int search_email(AddressBook *addressBook);

void edit_name(AddressBook *addressBook,int *arr);
void edit_number(AddressBook *addressBook);
void edit_email(AddressBook *addressBook);

void update_contact(AddressBook *addressBook,int choose);

void delete_name(AddressBook *addressBook,int *arr);
void delete_phone(AddressBook *addressBook);
void delete_email(AddressBook *addressBook);

void delete_contact(AddressBook *addressBook,int choose);
#endif
