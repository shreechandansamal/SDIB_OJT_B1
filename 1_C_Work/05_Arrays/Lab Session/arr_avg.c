#include<stdio.h>

int main()
{
    int n,i,sum =0,v;
    float avg;
    printf("\nEnter the size of array:- ");
    scanf("%d",&n);
    int arr[n];

    for( i = 0; i<n; i++)
    {
        printf("\nEnter the %d element :- ",(i+1));
        v =0;
        scanf("%d",&v);
        arr[i] = v;
    }
    printf("\nThe entered array is :- ");
    for(i = 0; i< n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    for(i = 0; i< n; i++)
    {
        sum += arr[i];
    }
    avg = sum/n;
    printf("\nThe average of the elements of the array is %f ", avg);
}