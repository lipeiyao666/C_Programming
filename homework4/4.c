#include <stdio.h>

// 交换两个整数的函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序函数
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex!= i)
        {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前的数组：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("排序后的数组：");for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;


B
B

C
C
C
C
}
