#include <stdio.h>

// Bubble Sort Function
void bubblesort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        int isSwap=0;//means false
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwap=1;//means true
            }
        }
        // for ex for i=2 the array got sorted so they does not need to compare and hence 
        // for i=3 no swapping occurs and if no swapping it exits
        if(!isSwap){
            return;
        }
    }
}

int main() {
    int n;

    // Input number of elements
    printf("Enter how many numbers you want to enter: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bubble sort
    bubblesort(arr, n);

    // Output sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*
Sure! Let's do a **dry run of Bubble Sort without the optimization flag** (so it always does `n-1` passes), using this example array:

### 🧪 Array: `[5, 1, 4, 2, 8]`

Number of elements `n = 5`
Total passes = `n - 1 = 4`

---

### 🔁 **Pass 1**

Compare and swap adjacent elements:

| Compare | Swap? | Array After       |
| ------- | ----- | ----------------- |
| 5 vs 1  | Yes   | `[1, 5, 4, 2, 8]` |
| 5 vs 4  | Yes   | `[1, 4, 5, 2, 8]` |
| 5 vs 2  | Yes   | `[1, 4, 2, 5, 8]` |
| 5 vs 8  | No    | `[1, 4, 2, 5, 8]` |

🔸 **Largest number (8)** is now at the end.

---

### 🔁 **Pass 2**

| Compare | Swap? | Array After       |
| ------- | ----- | ----------------- |
| 1 vs 4  | No    | `[1, 4, 2, 5, 8]` |
| 4 vs 2  | Yes   | `[1, 2, 4, 5, 8]` |
| 4 vs 5  | No    | `[1, 2, 4, 5, 8]` |

🔸 **Second largest (5)** is now in place.

---

### 🔁 **Pass 3**

| Compare | Swap? | Array After       |
| ------- | ----- | ----------------- |
| 1 vs 2  | No    | `[1, 2, 4, 5, 8]` |
| 2 vs 4  | No    | `[1, 2, 4, 5, 8]` |

🔸 No changes, but Bubble Sort doesn't know it's sorted, so it continues.

---

### 🔁 **Pass 4**

| Compare | Swap? | Array After       |
| ------- | ----- | ----------------- |
| 1 vs 2  | No    | `[1, 2, 4, 5, 8]` |

🔸 Still no swaps.

---

### ✅ Final Sorted Array:

```
[1, 2, 4, 5, 8]
```

---

### ⏱ Number of Passes: 4


*/