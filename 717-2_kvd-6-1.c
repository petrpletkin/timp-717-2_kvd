#include "stdio.h"

int sorting_function(int *arr,int arr_len)
{ int tmp = 0;
  int d = arr_len; 
  int yes_no = 0;
  int sum = 0;

    while(yes_no || (d>1))
    {
        if( d > 1)
        {d = d/1.24733;}
        else 
        { d = 1; }
        yes_no = 0;
        for(int i = 0; d + i < arr_len; i++)
        {
            if(arr[i] > arr[d+i])
            {
                tmp = arr[i];
                arr[i] = arr[d+i];
                arr[d+i] = tmp;
                sum++;
                yes_no = 1;
            }
        }     
            
    }
    return sum;
}

int print(int *arr,int arr_len)
{
    for(int i = 0; i < arr_len; i++)
    {
        if(i<arr_len-1)
        {
            printf("%d ",arr[i]);
        }else
        {
            printf("%d",arr[i]);
        }
    }
     printf("\n");
    return 0;
}
int main()
{
    int n; 
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting_function(arr,n);
    print(arr,n);

}