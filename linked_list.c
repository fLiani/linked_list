#include <stdio.h>
#include <stdlib.h>

struct sPerson
{
    int age;
    struct sPerson* next;
};

struct sPerson* getNewPerson(const int age)
{
    struct sPerson* newPerson = NULL;
    newPerson = malloc(sizeof(struct sPerson));
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

void printPerson(const struct sPerson *person, const char *comment)
{
    if(person == NULL)
    {
        printf("%s is NULL\n", comment);
    }
    else
    {
        printf("%s:\n age:%d\n address: %p\n next: %p\n", comment, person->age, person, person->next);
    }
}

int main()
{
    printf("** START LINK LIST **\n");

    struct sPerson *head = NULL;
    struct sPerson *added = NULL;


    printf("** END LINK LIST **\n");

    return 0;
}