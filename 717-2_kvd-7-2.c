#include "stdio.h"

int print(int *arr,int arr_len){
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

int makeheap(int* arr, int i, int lenght){
    int imax;
    int temp;
        if ((2 * i + 2) < lenght)
            {
                if (arr[2 * i + 1] < arr[2 * i + 2]) imax = 2 * i + 2;
                else imax = 2 * i + 1;
            }
            else imax = 2 * i + 1;
            if (imax >= lenght) return i;
            if (arr[i] < arr[imax])
            {
                temp = arr[i];
                arr[i] = arr[imax];
                arr[imax] = temp;
                if (imax < lenght / 2) i = imax;
            }
            return i;
    }

void sorting_function(int* arr, int arr_len){
     for (int i = arr_len / 2 - 1; i >= 0; --i)
            {
                long prev = i;
                i = makeheap(arr, i, arr_len);
                if (prev != i) ++i;
            }
    int temp;
     for (int k = arr_len - 1; k > 0; --k)
            {
                temp = arr[0];
                arr[0] = arr[k];
                arr[k] = temp;
                int i = 0, prev = -1;
                while (i != prev)
                {
                    prev = i;
                    i = makeheap(arr, i, k);
                }
            }
        }

int main(){
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i< size; i++)
    {
        scanf("%d",&arr[i]);
    }
    sorting_function(arr,size);
    print(arr,size);

 }