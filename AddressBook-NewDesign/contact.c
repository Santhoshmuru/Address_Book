#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//**************************************************list Contacts**********************************************/
void listContacts(AddressBook *addressBook)//Bubble sort outer loop
{
    for(int i = 0;i < addressBook->contactCount - 1;i++)    //To check the contactcount
    {
        for (int j = 0; j < addressBook->contactCount - 1; j++) // Innner loop
        {
            if ((strcasecmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)) > 0)
            {
                Contact temp;   //Temporary storage for swap
                temp = addressBook->contacts[j];  
                addressBook->contacts[j] = addressBook->contacts[j+1]; //swap
                addressBook->contacts[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("Contact Name : %s\n", addressBook->contacts[i].name);
        printf("Contact Number : %s\n", addressBook->contacts[i].phone);
        printf("Contact email : %s\n", addressBook->contacts[i].email);
        printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    }
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}
/*********************************************************Create Name********************************************************/
void createContact(AddressBook *addressBook)
{
    char name[50];
    int i = 0, name_count = 0;
    do
    {
        printf("Enter the Name : ");
        getchar();
        scanf("%[^\n]", name);//name from user
        getchar();//buffer
        name_count = validate_name(name);//validate name
        if (name_count == 0)
        {
            printf("Name saved ✅\n");
            printf("**************\n");
        }
    } while (name_count);
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);//copy name

    /*************************************************Number*************************************************/
    char number[20];
    int count = 0;

    do
    {
        printf("Enter the Number : ");
        scanf("%s", number);
        getchar();
        count = validate_number(number);//validate number
        for (int i = 0; i < addressBook->contactCount; i++)//contact number loop
        {
            if (!strcmp(number, addressBook->contacts[i].phone) && (count == 0))//compare
            {
                
                printf("*** Number already Exits,use alternative number ! ***\n");
                
                count = 1;
            }
        }
    } while (count);
            printf("Number Saved ✅\n");
            printf("***************\n");
    strcpy(addressBook->contacts[addressBook->contactCount].phone, number);//copy number
    /****************************************************EmailL******************************************************/
    char email[50];
    int email_count = 0;
    do
    {
        printf("Enter the Email : ");
        scanf("%s", email);
        getchar();
        email_count = validate_email(email);//validate email
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (!strcmp(email, addressBook->contacts[i].email) && (email_count == 0))//compare email
            {
               
                printf(" *** Email already Exits,use alternative Email ! ***\n");
                
                count = 1;
            }
        }
        
        
    } while (email_count);
            printf("Saved Email ✅\n");
            printf("***************\n");
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);//copy the email id
    addressBook->contactCount++; //contact increment
}
/*********************************************************Search Contact*********************************************/
void searchContact(AddressBook *addressBook, int *arr)
{
    int option;
    
    printf(" Menu for Search Option \n");
    printf("************************\n");
    do
    {

        printf("1.Search by Name\n");
        printf("2.Search by Number\n");
        printf("3.Search by Email\n");
        printf("4.Exit\n");
        printf("\n");
        printf("Enter the search option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            search_name(addressBook, arr);//searchname 
            break;
        }
        case 2:
        {
            search_number(addressBook);//search number
            break;
        }
        case 3:
        {
            search_email(addressBook);//search email
            break;
        }
        case 4:
            break;
        default:
        {
           
            printf("*** Invalid Try Again ! ****\n");
        }
        }
    } while (option != 4);//exit
}
/***************************************************Edit Contact****************************************/
void editContact(AddressBook *addressBook, int *arr)
{
    int choice;
   
    printf("Menu for Edit Option \n");
    printf("*********************\n");
    do
    {
        printf("1.Edit by Name \n");
        printf("2.Edit by Number \n");
        printf("3.Edit by Email Id \n");
        printf("4.Exit\n");
        printf("\n");
        printf("Enter you choice : ");
        scanf("%d", &choice);
        {
            switch (choice)
            {
            case 1:
                edit_name(addressBook, arr);//edit name
                break;
            case 2:
                edit_number(addressBook);//edit number
                break;
            case 3:
                edit_email(addressBook);//edit email id
                break;
            default:

                printf("*** Invalid try again ! *** \n");
            }
        }
    } while (choice != 4);//exit
}
/**********************************************Delete Contact**********************************************/

void deleteContact(AddressBook *addressBook,int *arr)
{
    int choice;
    printf("-----------*****------------\n");
    printf("Menu for Delete contact \n");
    printf("-----------*****------------\n");
    do
    {
        printf("1.Delete by Name \n");
        printf("2.Delete by Number \n");
        printf("3.Delete by Email Id\n");
        printf("4.Exit\n");
        printf("\n");
        printf("Enter the Choice to Delete : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            delete_name(addressBook,arr);//delete name
            break;
        case 2:
            delete_phone(addressBook);//delete number
            break;
        case 3:
            delete_email(addressBook);//delete email
            break;

        case 4:
            return;

        default:
           
            printf("*** Invalid try again ! ***\n");
            break;
           
        }
    } while (choice != 4);//exit
}
/**************************************************Validate the Name*******************************************************/
int validate_name(char *name)//validate name
{
    int count = 0, i = 0;
    while (name[i] != '\0')
    {
        if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] == ' '))//lower and upper case
        {
            count = 1;
        }
        else
        {

            printf("*** Enter the valid name ! ***\n");
            return 1;
        }
        i++;
    }
    return 0;
}
/*********************************************************Validate the Number*********************************************/
int validate_number(char *number)//validate number
{
    int count = 0, i = 0, len;
    len = strlen(number);//length

    if (len != 10)//10 number only
    {
        printf("*** Enter the number consist of 10 number Only ! ***\n");
        return 1;
    }
    while (number[i] != '\0')
    {
        if (number[i] >= '0' && number[i] <= '9')//number only
        {
            count = 1;
        }
        else
        {
            printf("*** Enter the valid number ! ***\n");
            return 1;
        }
        i++;
    }
    return 0;
}

/******************************************************************Validate the Email**************************************************/
int validate_email(char *email)//validate email
{
    int i = 0, len = 0, flag = 0, count = 0, temp = 0;
    len = strlen(email);
    while (email[i] != '\0')
    {
        if ((email[i] >= 'a' && email[i] <= 'z') || (email[i] >= '0' && email[i] <= '9') || (email[i] == '@') || (email[i] == '.'))
        {
            flag = 1;
        }
        else
        {
           
            printf("*** Enter the valid email id,use only lower case ! ***\n");
           
            return 1;
        }
        i++;
    }
    if (email[0] == '@')
    {
       
        printf("*** '@' cannot come first ! ***\n");
       
        return 1;
    }
    for (i = 0; email[i] != 0; i++)
    {
        if (email[i] == '@')
        {
            count++;
        }
    }
    if (count != 1)
    {
        
        printf("*** In email Don't use '@' multiple times,So reenter the email ! ***\n");
        return 1;
    }

    char *ptr1 = email;
    char *ptr2 = email;
    ptr1 = strstr(email, ".com");
    ptr2 = strchr(email, '.');
    if (ptr1 != ptr2)
    {
        printf(" *** '.' should be use only one time,So re enter the email ! ***\n");
        return 1;
    }
    char *ptr = email;
    while (((ptr = strstr(ptr, ".com")) != NULL))
    {
        temp++;
        ptr = ptr + 4;
    }
    if (temp != 1)
    {
        printf("*** Don't use '.com' multiple time,use only one time ! ****\n");
        return 1;
    }
    ptr = strstr(email, ".com");
    ptr = ptr + 4;
    if (*ptr != '\0')
    {
        printf("*** '.com' must be at the end of email ! **** \n");
        return 1;
    }
    else
    {
        return 0;
    }
}
/******************************************Search by Name*******************************************/
int search_name(AddressBook *addressBook, int *arr)
{
    char name[50];
    int count = 0, j;
    printf("Enter the Name : ");
    getchar();
    scanf("%[^\n]", name);
    getchar();
    count = validate_name(name);//validate name
    for (int i = 0; i < addressBook->contactCount; i++)//contact loop
    {
        if (!(strcmp(name, addressBook->contacts[i].name)))//compare name in contact count
        {
            if (count == 0)
            {   
                printf("Contact Found\n");
                printf("**************\n");
                printf("\n");
            }
            printf("Contact Number : %d\n", count + 1);
            printf("********************");
            printf("\n");
           
            printf("Name : %s\n", addressBook->contacts[i].name);
            printf("Number : %s\n", addressBook->contacts[i].phone);
            printf("Email : %s\n", addressBook->contacts[i].email);
            printf("******************************************\n");
            arr[count] = j;
            count++;
        }
    }
    if (count == 0)
    {
        printf("*** Contact not Found ! ***\n");
    }
    if (count == 1)
    {
        return j;
    }
    else
    {
        return count;
    }
}
/****************************************Search by Number*****************************************/
int search_number(AddressBook *addressBook)
{
    char number[20];
    int count = 0;
    printf("Enter the Number : ");
    getchar();
    scanf("%[^\n]", number);
    getchar();
    count = validate_number(number);// call validate number
    for (int i = 0; i < addressBook->contactCount; i++)//
    {
        if (!(strcmp(number, addressBook->contacts[i].phone)))//compare the number to contactcount
        {
            printf("Contact found \n");
            printf("**************\n");
            printf("\n");
           
            printf("Name : %s\n", addressBook->contacts[i].name);//name
            printf("Number : %s\n", addressBook->contacts[i].phone);//number
            printf("Email : %s\n", addressBook->contacts[i].email);//email
            printf("******************************************\n");
            count = 1;
        } 
    }
    if (count != 1)
        {
            printf("*** Contact not Found ! ***\n");
        }
}
/****************************************Search by Email Id**************************************************/
int search_email(AddressBook *addressBook)
{
    char email[50];
    int count = 0;
    printf("Enter the email: ");
    getchar();
    scanf("%[^\n]", email);
    getchar();
    count = validate_email(email);//call validate email function
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (!(strcmp(email, addressBook->contacts[i].email)))
        {
            printf("Contact Found\n");
            printf("*************\n");
            printf("\n");
            printf("Name : %s \n", addressBook->contacts[i].name);//name
            printf("Number : %s \n", addressBook->contacts[i].phone);//number
            printf("Email : %s \n", addressBook->contacts[i].email);//email id
            printf("******************************************\n");
            count = 1;
        }
    }
    if (count != 1)
    {
        printf("*** Contact not Found ! ***\n");
    }
}
/**************************************Edit contact by Name ***********************************/
void edit_name(AddressBook *addressBook, int *arr)
{
    int size, choose;
    size = search_name(addressBook, arr);//call search name function
    if (size == 0)
    {
        return;
    }
    while (1)
    {
        printf("Enter the contact : ");
        scanf("%d", &choose);
        if (choose <= size && choose > 0)
        {
            break;
        }
        else
        {
            printf("***Enter the valid choice ! ***\n");
            return;
        }
    }
    update_contact(addressBook, arr[choose - 1]);//stored updatecontact function
}
/************************************Edit contact by Number**************************/
void edit_number(AddressBook *addressBook)
{
    int index;
    index = search_number(addressBook);//call search number function
    if (index > 100)
    {
        return;
    }
    update_contact(addressBook, index);//stored updatecontact function
}
/**************************************************Edit contact by Email*************************/
void edit_email(AddressBook *addressBook)
{
    int index;
    index = search_email(addressBook);//call search function
    if (index > 100)
    {
        return;
    }
    update_contact(addressBook, index);//stored updatecontact function
}
/*********************************Update contact************************************/
void update_contact(AddressBook *addressBook, int choose)
{
    int choice, count = 0, i = 0;
    printf("The contact going to edit\n ");
    printf("**************************\n");
    printf("\n");
    printf("Contact name  : %s\n", addressBook->contacts[i].name);
    printf("Contact phone : %s\n", addressBook->contacts[i].phone);
    printf("Contact email : %s\n5", addressBook->contacts[i].email);
    printf("******************************************\n");
    char name[50];
    char number[20];
    char email[50];
    do
    {
    
        printf("Menu For Update option \n");
        printf("***********************\n");
        printf("\n");
        printf("1.Edit Name\n");
        printf("2.Edit phone\n");
        printf("3.Edit email\n");
        printf("4.Exit\n");
        printf("\n");
        printf("Enter the choice to  edit : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            do
            {
                printf("Enter the new name : ");
                getchar();
                scanf("%[^\n]", name);
                count = validate_name(name);//call validate name function
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                        count = 0;
                        if (!(strcmp(name, addressBook->contacts[i].name)) && count == 0)//string compare function
                        {
                            printf("*** The name already  saved,Try unique name ! ***\n");
                            count = 1;
                        }
                        else
                        {
                            count = 0;
                        }
                    }
                    if (count == 0)
                    {   
                        printf("Name updated successfully ✅\n");//update name
                        printf("****************************\n");
                    }
                } while (count);
                strcpy(addressBook->contacts[i].name, name);
                break;
            }

            case 2:
            {
                do
                {
                    printf("Enter the new number : ");
                    scanf("%s", number);
                    count = validate_number(number);//call validate number
                    for (int i = 0; i < addressBook->contactCount; i++)
                    {
                        count = 0;
                        if (!(strcmp(number, addressBook->contacts[i].phone)) && count == 0)
                        {
                            printf("*** The number already saved,Try unique number ! ***\n");
                            count = 1;
                            break;
                        }
                        else
                        {
                            count = 0;
                        }
                    }
                    if (count == 0)
                    {   
                        
                        printf("Number updated successfully ✅\n");//number update
                        printf("*******************************\n");
                    }
                } while (count);
                strcpy(addressBook->contacts[i].phone, number);
                break;
            }
            case 3:
            {
                do
                {
                    printf("Enter the new email : ");
                    scanf("%s", email);
                    count = validate_email(email);//call validate name
                    for (int i = 0; i < addressBook->contactCount; i++)
                    {
                        count = 0;
                        if (!(strcmp(email, addressBook->contacts[i].email)) && count == 0)
                        {
                            printf("*** The email already  saved,Try unique email ! ***\n");
                            count = 1;
                            break;
                        }
                        else
                        {
                            count = 0;
                        }
                    }
                    if (count == 0)
                    {
                        
                        printf("Email updated successfully ✅\n");//email update
                        printf("******************************\n");
                    }
                } while (count);

                strcpy(addressBook->contacts[i].email, email);//contactcount store email
                break;
            }
        }
    }while(choice !=4);
}
/************************************Delete contact by name*********************************/
void delete_name(AddressBook *addressBook, int *arr)
{
    int size, choose;
    size = search_name(addressBook,arr);//call search name
    if (size == 0)
    {
        return;
    }
    while (1)
    {
        printf("Enter the contact you want to Delete : ");
        scanf("%d", &choose);
        if (choose <= size && choose > 0)
        {
            break;
        }
        else
        {
            printf("*** Enter the valid choice ! ***\n");
        }
    }
    delete_contact(addressBook,arr[choose - 1]);
}
/***************************************Delete contact by phone*****************************/
void delete_phone(AddressBook *addressBook)
{
    int count = 0;
    count = search_number(addressBook);//call search number function
    for (; count < addressBook->contactCount - 1; count++)
    {
        addressBook->contacts[count] = addressBook->contacts[count + 1];
    }
}

/***************************************delete contact by email***************************/
void delete_email(AddressBook *addressBook)
{
    int count = 0;
    count = search_email(addressBook);//call search email function
    for (; count < addressBook->contactCount - 1; count++)
    {
        addressBook->contacts[count] = addressBook->contacts[count + 1];
    }
}
void delete_contact(AddressBook *addressBook, int choose)//delete contact
{
    int i;

    if (addressBook->contactCount == 100)
    {
        i = 2;
    }
    else
    {
        i = 1;
    }
    printf("The Contact Delete\n");
    printf("*******************\n");
    for (; choose < addressBook->contactCount - i; choose++)
    {
        addressBook->contacts[choose] = addressBook->contacts[choose + 1];
    }
    
    printf("Contact successfully Deleted ✅\n");//delete
    printf("********************************\n");
    addressBook->contactCount--;
}