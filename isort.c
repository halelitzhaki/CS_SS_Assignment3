#include <stdio.h>
#include <stdlib.h>

#define LEN 50

void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);

int main () {
    int arr[LEN];
    for(int i = 0; i < LEN; i++) {
        scanf("%d", arr + i);
    }
    insertion_sort(arr, LEN);
    for(int i = 0; i < LEN; i++) {
        if(i == LEN - 1) {
            printf("%d", *(arr +i ));
            break;
        }
        printf("%d,", *(arr+i));
    }
    return 0;
}

void shift_element(int* arr, int i) {
    for(int j = i + 1; j > 1; j--) {
        *(arr + j) = *(arr + j - 1);
    }
}

void insertion_sort(int* arr , int len) {
    for(int i = 1; i < len; i++) {
        int j = i - 1, key = *(arr + i);
        while(j >= 0 && *(arr + j) >= key) {
            shift_element(arr + j - 1, 1);
            j--;
        }
        *(arr + j + 1) = key;
    }
}
