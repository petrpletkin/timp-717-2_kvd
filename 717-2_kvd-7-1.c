#include "stdio.h"

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

 int split_function(int* arr, int left, int right) 
   {
       int temp;
       int marker = left;
       for ( int i = left; i <= right; i++ ) 
       {
           if ( arr[i] < arr[right] )
           {
               temp = arr[marker];
               arr[marker] = arr[i];
               arr[i] = temp;
               marker += 1;
           }
       }
       
       temp = arr[marker];
       arr[marker] = arr[right];
       arr[right] = temp; 
       return marker;
   }

void sorting_function(int* arr, int left, int right)
   {
       if ( left >= right ) 
       {
           return;
       }
       int i = split_function(arr, left, right);
       sorting_function (arr, left, i-1);
       sorting_function (arr, i+1, right);
   }

int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i< size; i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting_function(arr,0,size-1);
    print(arr,size);
}