#include<stdio.h>

int a[100];
int n, front = -1, rear = -1;

void enqueue()
{
if ((front == 0 && rear == n-1) || (front == (rear+1)%n))
{
printf("Queue is full\n");
}
else
{
if (front == -1)
{
front = 0;
}
rear = (rear+1)%n;
printf("Enter item: ");
scanf("%d", &a[rear]);
}
}

void dequeue()
{
if (front == -1)
{
printf("Queue is empty\n");
}
else
{
printf("Deleted item is: %d\n", a[front]);
if (front == rear)
{
front = -1;
rear = -1;
}
else
{
front = (front+1)%n;
}
}
}

void display()
{
int i;
if (front == -1)
{
printf("Queue is empty\n");
}
else
{
printf("Elements are:\n");
i = front;
while (1)
{
printf("%d ", a[i]);
if (i == rear)
break;
i = (i+1)%n;
}
printf("\n");
}
}

int main()
{
int c;
printf("Enter Queue Size: ");
scanf("%d", &n);
do
{
printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &c);
switch(c)
{
case 1:
enqueue();
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Invalid Choice\n");
}
} while(c != 4);
return 0;
}
