#include <stdio.h>
#include <stdbool.h>

// Optimized Bubble Sort: stops early if the array becomes sorted
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        // after i passes the last i elements are already in place
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = true;
            }
        }
        // if no two elements were swapped in inner loop, array is sorted
        if (!swapped) break;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        if (i + 1 < n) printf(" ");
    }
    printf("\n");
}

int main(void) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    bubble_sort(arr, n);

    printf("Sorted array (ascending):\n");
    print_array(arr, n);

    return 0;
}
