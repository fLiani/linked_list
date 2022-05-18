#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPerson
{
    int age;
    struct sPerson* next;
} Person;

Person* getNewPerson(const int age)
{
    Person* newPerson = NULL;
    newPerson = malloc(sizeof(Person));
    if(newPerson != NULL)
    {
        newPerson->next = NULL;
        newPerson->age = age;
        printf("Created new person at %p\n", newPerson);
    }
    else
    {
        printf("Memory allocation failed!\n");
    }
    return newPerson;
}

void printPerson(const Person *person, const char *comment)
{
    if(person == NULL)
    {
        printf("%s is NULL\n", comment);
    }
    else
    {
        printf("%s: age:%d\n", comment, person->age, person, person->next);
    }
}

void printList(Person* list)
{
    printf("Here is your list: \n");

    Person* pt;

    pt = list;

    if(pt == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        for(int i = 0; pt != NULL; i++)
        {
            printPerson(pt, "List");
            pt = pt->next;
        }
    }
}

void cleanUp(Person* list)
{
    Person* nextElem;
    while(list)
    {
        nextElem = list->next;
        printf("Cleaning age: %d\n", list->age);
        free(list);
        list = nextElem;
    }
}

int main()
{
    printf("** START LINK LIST **\n");

    Person *head = NULL;
    Person *added = NULL;

    char command[64];
    int age;

    printf("Type quit to exit.\n");

    while(1)
    {
        printf("Enter a command or value: ");
        fgets(command, 64, stdin);

        if(strcmp("quit\n", command) == 0)  // if type quit exit program
        {
            printf("Exiting program...\n");

            cleanUp(head);
            head = NULL;
            added = NULL;

            return 0;
        }
        else if(strcmp("print\n", command) == 0)
        {
            printf("Printing...\n");
            printList(head);
        }
        else if(sscanf(command, "%d", &age) != 0)
        {
            if(head == NULL)
            {
                head = getNewPerson(age);

                if(head != NULL)
                {
                    added = head;
                }
            }
            else
            {
                added->next = getNewPerson(age);

                if(added->next != NULL)
                {
                    added = added->next;
                }
            }

            printf("Person age added!\n");
        }
    }

    printf("** END LINK LIST **\n");

    return 0;
}