#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++)

        for (j = 1; j < n - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void printArray(int arr[], int size) {
    int i;
    for (i = 1; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int array[], int low, int high) {

    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            i++;

            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
    printf("Choose option\n1. Manual inserting\n2. Automatic random inserting");
    int choice = 0;

    do {
        printf("\nType your choice: ");
        scanf("%d", &choice);
    } while (choice == 0);

    int tab[1000];
    char tmp[20];

    int i = 0;
    if (choice == 1) {
        printf("%s", "\n");
        gets(tmp);
        do {
            tab[i] = atoi(tmp);
            i += 1;
            gets(tmp);
        } while (tmp[0] != '\000');
    } else if (choice == 2) {
        int n = 0;
        printf("%s", "\nHow many random generated numbers you want?: ");
        scanf("%d", &n);
        srand(time(NULL));
        for (i = 1; i < n + 1; i += 1) {
            tab[i] = rand() % 1000;
        }
    }

    printf("\nChoose option of sorting\n1. QuickSort\n2. BubbleSort");
    do {
        printf("\nType your choice: ");
        scanf("%d", &choice);
    } while (choice == 0);

    switch (choice) {
        case 1:
            quickSort(tab, 1, i);
            break;
        case 2:
            bubbleSort(tab, i);
            break;
    }
    printArray(tab, i);


    return 0;


}
