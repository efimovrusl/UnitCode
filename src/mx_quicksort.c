#include "libmx.h"

// int mx_quicksort(char **arr, int left, int right) {
//     printf("args: %i\t%i\n", left, right);
//     int start;
//     int current;
//     char *buffer;
//     int counter = 0;
//     if (mx_strlen(arr[left]) == mx_strlen(arr[right])) return counter;
//     start = left;
//     current = left + 1;
//     while (true) {
//         // if ((*cmp)(start->agent, current->agent) < 0) {
//         if (mx_strlen(arr[start]) < mx_strlen(arr[current])) {
//             counter++;
//             buffer = arr[current];
//             arr[current] = arr[start];
//             arr[start] = buffer;
//         }
//         if (current == right) break;
//         current++;
//     }
//     buffer = arr[left];
//     arr[left] = arr[current];
//     arr[current] = buffer;
//     int prev_curr = current;
//     current--;
//     if (current <= right && current >= left) {
//         if (left != current + 1) {
//             counter += mx_quicksort(arr, left, current);
//         }
//     }
//     current = prev_curr + 1;
//     if (current <= right && current >= left) {
//         if (current != right + 1) {
//             counter += mx_quicksort(arr, current, right);
//         }
//     }
//     return counter;
// }

int mx_quicksort(char **arr, int first, int last) {
    int counter = 0;
    if (first < last) {
        int left = first, right = last;
        char *middle = arr[(left + right) / 2];
        do {
            while (mx_strlen(arr[left]) < mx_strlen(middle)) left++;
            while (mx_strlen(arr[right]) > mx_strlen(middle)) right--;
            if (left <= right) {
                char* tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                if (left != right && mx_strlen(arr[left]) != mx_strlen(arr[right])) {
                    counter++;                
                }
                left++;
                right--;
            }
        } while (left <= right);
        counter += mx_quicksort(arr, first, right);
        counter += mx_quicksort(arr, left, last);
    }
    return counter;
}

// int mx_quicksort(char **arr, int first, int last) {
//     int i, j, swaps = 0;
//     char *pivot, *temp;
//     if (first < last) {
//         pivot = arr[first];
//         i = first;
//         j = last;

//         while (i < j) {
//             while (1) {
//                 printf("arr[i]len:%i\tpivot_len:%i\n", mx_strlen(arr[i]), mx_strlen(pivot));
//                 // if (mx_strcmp(arr[i], pivot) < 0 && i < last)
//                 if (mx_strlen(arr[i]) < mx_strlen(pivot) && i < last)
//                     i++;
//                 else break;
//             } // number[i] <= number[pivot] && i < last)
//             while (1) {
//                 printf("arr[i]len:%i\tpivot_len:%i\n", mx_strlen(arr[i]), mx_strlen(pivot));
//                 // if (mx_strcmp(arr[j], pivot) > 0)
//                 if (mx_strlen(arr[j]) > mx_strlen(pivot))
//                     j--;
//                 else break;
//             } // number[j] > number[pivot])
//             if (i < j) {
//                 temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//                 swaps++;
//             }
//             printf("i:%i\tj:%i\tswaps:%i\n", i, j, swaps);
//         }

//         temp = pivot;
//         pivot = arr[j];
//         arr[j] = temp;
//         swaps += mx_quicksort(arr, first, j - 1);
//         swaps += mx_quicksort(arr, j + 1, last);
//     }
//     return swaps;
// }
