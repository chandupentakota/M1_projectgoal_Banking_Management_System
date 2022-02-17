#include <stdio.h>

struct custmr
{
    int acc_no;
    char name[80];
    int balance;
};

void accept(struct custmr[], int);
void display(struct custmr[], int);
int search(struct custmr[], int, int);
void deposit(struct custmr[], int, int, int);
void withdraw(struct custmr[], int, int, int);

int main()
{
    struct custmr data[20];
    int n, choice, acc_no, amount, index;

    printf("Banking System\n\n");
    printf("Num of custmr records you want to enter? : ");
    scanf("%d", &n);
    accept(data, n);
    do
    {

        printf("\nBanking System Menu :\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to deposit amount.\n");
        printf("Press 4 to withdraw amount.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display(data, n);
                break;
            case 2:
                printf("Enter acc num to search : ");
                scanf("%d", &acc_no);
                index = search(data, n, acc_no);
                if (index ==  - 1)
                {
                    printf("Record not found : ");
                }
                else
                {
                    printf("A/c Num: %d\nName: %s\nBalance: %d\n",
                        data[index].acc_no, data[index].name,
                        data[index].balance);
                }
                break;
            case 3:
                printf("Enter acc num : ");
                scanf("%d", &acc_no);
                printf("Enter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, acc_no, amount);
                break;
            case 4:
                printf("Enter acc num : ");
                scanf("%d", &acc_no);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, acc_no, amount);
        }
    }
    while (choice != 0);

    return 0;
}

void accept(struct custmr list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter acc_no : ");
        scanf("%d", &list[i].acc_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        list[i].balance = 0;
    } 
}

void display(struct custmr list[80], int s)
{
    int i;

    printf("\n\nA/c No\tName\tBalance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].acc_no, list[i].name,
            list[i].balance);
    } 
}

int search(struct custmr list[80], int s, int num)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].acc_no == num)
        {
            return i;
        } 
    }
    return  - 1;
}

void deposit(struct custmr list[], int s, int num, int amt)
{
    int i = search(list, s, num);
    if (i ==  - 1)
    {
        printf("Record not found");
    } 
    else
    {
        list[i].balance += amt;
    }
}

void withdraw(struct custmr list[], int s, int num, int amt)
{
    int i = search(list, s, num);
    if (i ==  - 1)
    {
        printf("Record not found\n");
    } 
    else if (list[i].balance < amt)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].balance -= amt;
    }
}
