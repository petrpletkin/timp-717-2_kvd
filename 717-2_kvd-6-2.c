#include "stdio.h"

int sorting_function(int *arr, int arr_len) //сортировка Шелла
    {
        int  j, d, temp = 0;
        int flag = 0;
        d = arr_len;
        d/=2;
        while(d)
        {
            for(int i = 0;i<arr_len-d;i++)
            {
                j = i;
                while(j>=0 && arr[j]>arr[j+d])
                {
                    temp = arr[j];
                    arr[j] = arr[j+d];
                    arr[j+d] = temp;
                    j--;
                    flag ++;
                }
            }
            d/=2;
        }
        return flag;
    }
void print(int *arr,int arr_len)
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
    }
int main()
{
    int n; scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting_function(arr,n);
    print(arr,n);
}