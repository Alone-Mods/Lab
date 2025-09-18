#include<stdio.h>

int a[100];
int n, front = -1, rear = -1;

void push()
{
if ((front == 0 && rear == n-1) || (front == (rear+1)%n))
{
printf("Deque is full\n");
}
else
{
if (front == -1)
{
front = 0;
rear = 0;
}
else if (front == 0)
{
front = n-1;
}
else
{
front = front-1;
}
printf("Enter item: ");
scanf("%d", &a[front]);
}
}

void insertion()
{
if ((front == 0 && rear == n-1) || (front == (rear+1)%n))
{
printf("Deque is full\n");
}
else
{
if (front == -1)
{
front = 0;
rear = 0;
}
else
{
rear = (rear+1)%n;
}
printf("Enter item: ");
scanf("%d", &a[rear]);
}
}

void pop()
{
if (front == -1)
{
printf("Deque is empty\n");
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

void ejection()
{
if (front == -1)
{
printf("Deque is empty\n");
}
else
{
printf("Deleted item is: %d\n", a[rear]);
if (front == rear)
{
front = -1;
rear = -1;
}
else if (rear == 0)
{
rear = n-1;
}
else
{
rear = rear-1;
}
}
}

void display()
{
int i;
if (front == -1)
{
printf("Deque is empty\n");
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
printf("Enter Deque Size: ");
scanf("%d", &n);
do
{
printf("\n1. Push\n2. Insertion\n3. Pop\n4. Ejection\n5. Display\n6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &c);
switch(c)
{
case 1:
push();
break;
case 2:
insertion();
break;
case 3:
pop();
break;
case 4:
ejection();
break;
case 5:
display();
break;
case 6:
break;
default:
printf("Invalid Choice\n");
}
} while(c != 6);
return 0;
}
