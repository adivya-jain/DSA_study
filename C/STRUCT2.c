#include <stdio.h>
#include <string.h>
typedef struct student
{
    int rn;
    char name[100];
    char addr[100];
    char con[15];
    char email[20];
} std;

void validate(std *ptr)
{
    do
    {
        printf("\nDear %s please type correct email ID: ", ptr->name);
        fflush(stdin);
        scanf("%s", ptr->email);
    } while (!(strstr(ptr->email, "gmail.com") || strstr(ptr->email, "yahoo.com")));
}

void insert(std *ptr)
{
    printf("Enter rn: ");
    scanf("%d", &ptr->rn);
    printf("Enter name: ");
    fflush(stdin);
    gets(ptr->name);
    printf("Enter addr: ");
    fflush(stdin);
    gets(ptr->addr);
    printf("Enter contact no: ");
    fflush(stdin);
    scanf("%s", ptr->con);
    validate(ptr);
    printf("\nRecord has been stored !!!\n");
}

void update(std *ptr, int n)
{
    int i, id;
    printf("\n\nRecord Update system\n\n");
    printf("Enter roll no to be searched: ");
    scanf("%d", &id);
    fflush(stdin);
    for (i = 0; i < n; i++)
    {
        if (ptr->rn == id)
        {
            break;
        }
        ptr++;
    }

    printf("\nPress 1> Update name");
    printf("\nPress 2> Update Address");
    printf("\nPress 3> Update Contact");
    printf("\nPress 4> Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &i);
    fflush(stdin);
    switch (i)
    {
    case 1:
        printf("Enter new name: ");
        gets(ptr->name);
        break;
    case 2:
        printf("Enter new address: ");
        gets(ptr->addr);
        break;
    case 3:
        printf("Enter new contact no: ");
        gets(ptr->con);
        break;
    case 4:
        return;
    default:
        printf("\nWrong input\n");
    }
    printf("\nRecord Updated !!! \n\n");
}

void disp(std ptr)
{
    printf("\nrn: %d", ptr.rn);
    printf("\nname: ");
    puts(ptr.name);
    printf("\nAddress: ");
    puts(ptr.addr);
    printf("\nContact no: %s", ptr.con);
}

int main()
{
    std a[10];
    int i;
    for (i = 0; i < 2; i++)
    {
        insert(&a[i]);
    }
    update(&a[0], 2);
    printf("\nDisplaying records: \n\n");
    for (i = 0; i < 2; i++)
    {
        disp(a[i]);
    }
    return 0;
}