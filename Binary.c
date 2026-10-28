#include <stdio.h>
int main()
{
 int a[20], n, i, j, search, low = 0, mid, high, temp, flag = 0;
 printf("Enter array limit:");
 scanf("%d", &n);
 printf("\nEnter array elements:");
 for (i = 0; i < n; i++)
 scanf("%d", &a[i]);
 /* bubble sort (binary search needs sorted data) */
 for (i = 0; i < n - 1; i++)
 for (j = 0; j < n - i - 1; j++)
 if (a[j] > a[j + 1])
 {
 temp = a[j + 1];
 a[j + 1] = a[j];
 a[j] = temp;
 }
 printf("\nEnter the element to be searched:");
 scanf("%d", &search);
 high = n - 1;
 while (low <= high)
 {
 mid = (low + high) / 2;
 if (search == a[mid])
 {
 flag = 1;
 break;
 }
 else if (search < a[mid])
 high = mid - 1;
 else
 low = mid + 1;
 }
 if (flag == 0)
 printf("\nThe element is not present.");
 else
 printf("\nThe element is present.");
 printf("\n");
 return 0;
}
