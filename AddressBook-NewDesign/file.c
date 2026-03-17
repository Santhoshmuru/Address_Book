#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *ptr;
    ptr = fopen("contacts.csv","w");//write
    fprintf(ptr,"%d\n",addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(ptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);//print in file
    }    
    fclose(ptr);//end
    
}


void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *ptr;
    ptr = fopen("contacts.csv","r");//read
    fscanf(ptr,"%d",&addressBook->contactCount);
    if (addressBook->contactCount == 0)
    {
        return;
    }
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(ptr," %[^,],%[^,],%[^\n]",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);//stored in file
    }
    fclose(ptr);//end
}
