// Sum of 10 Random Number's Inputed by User

#include <stdio.h>

int sumall(int *, int, int);

int main()
{
    int i, sum = 0, a = 0, array[10];
    printf("Enter Elements: ");
    for (i = 0; i <= 9; i++)
    {
        scanf("%d", &array[i]);
    }
    sum = sumall(array, sum, a);
    printf("Sum is: %d", sum);
    return 0;
}

int sumall(int *ptr, int su, int i)
{
    if (i <= 9)
    {
        su = su + *ptr;
        ptr++;
        i++;
        return (sumall(ptr, su, i));
    }
    return (su);
}