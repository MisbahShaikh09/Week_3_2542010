#include<stdio.h>
#define max 4

int q[max];        
int r = 0, f = 0, cnt = 0;

void add();    
void give();   
void show();   

int main()
{
    int ch;
    do {
       printf("\n--- Bus Pass Distribution System ---\n1. Add Student\n2. Distribute Bus Pass\n3. Show Waiting Students\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: add(); break;
            case 2: give(); break;
            case 3: show(); break;
            case 4: printf("Exiting system...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(ch != 4);

    return 0;
}


void add()
{
    int roll;
    if (cnt == max)
        printf("\nWaiting list is full");
    else
    {
        printf("Enter Student Roll Number: ");
        scanf("%d", &roll);
        q[r] = roll;
        r = (r + 1) % max;
        cnt++;
        printf("Student added to waiting list");
    }
}


void give()
{
    if (cnt == 0)
        printf("\nNo students waiting");
    else
    {
        printf("\nBus pass distributed to Roll No: %d", q[f]);
        f = (f + 1) % max;
        cnt--;
    }
}


void show()
{
    int i;
    if (cnt == 0)
        printf("\nNo students in waiting list");
    else
    {
        printf("\nWaiting students: ");
        i = f;
        while (i != r)
        {
            printf("%d ", q[i]);
            i = (i + 1) % max;
        }
    }
}
