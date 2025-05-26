#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Define the number of buckets

// Function to perform insertion sort on a bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    float bucket[MAX][MAX];  // Buckets
    int bucketSize[MAX] = {0};

    // Place elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * MAX;  // Scale value for indexing
        bucket[index][bucketSize[index]++] = arr[i];
    }

    // Sort individual buckets and merge back into original array
    int idx = 0;
    for (int i = 0; i < MAX; i++) {
        if (bucketSize[i] > 0) {
            insertionSort(bucket[i], bucketSize[i]);  // Sort bucket
            for (int j = 0; j < bucketSize[i]; j++) {
                arr[idx++] = bucket[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d floating-point numbers between 0 and 1:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}
// Great! Let's do a **dry run** of the Bucket Sort algorithm using the provided input array:

// ### **Input Array:**
// ```plaintext
// {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68}
// ```
// We have **10 elements**, so we use **10 buckets** (indexed 0-9).

// ---

// ### **Step 1: Bucket Placement**
// Each element is scaled by multiplying by 10 to determine its bucket index:

// | Element  | Index Calculation (`arr[i] * 10`) | Assigned Bucket |
// |----------|----------------------------------|----------------|
// | **0.78**  | `0.78 * 10 = 7.8`  | Bucket `7` |
// | **0.17**  | `0.17 * 10 = 1.7`  | Bucket `1` |
// | **0.39**  | `0.39 * 10 = 3.9`  | Bucket `3` |
// | **0.26**  | `0.26 * 10 = 2.6`  | Bucket `2` |
// | **0.72**  | `0.72 * 10 = 7.2`  | Bucket `7` |
// | **0.94**  | `0.94 * 10 = 9.4`  | Bucket `9` |
// | **0.21**  | `0.21 * 10 = 2.1`  | Bucket `2` |
// | **0.12**  | `0.12 * 10 = 1.2`  | Bucket `1` |
// | **0.23**  | `0.23 * 10 = 2.3`  | Bucket `2` |
// | **0.68**  | `0.68 * 10 = 6.8`  | Bucket `6` |

// ---

// ### **Step 2: Bucket Contents Before Sorting**
// ```plaintext
// Bucket 0:  (empty)
// Bucket 1:  {0.12, 0.17}
// Bucket 2:  {0.21, 0.23, 0.26}
// Bucket 3:  {0.39}
// Bucket 4:  (empty)
// Bucket 5:  (empty)
// Bucket 6:  {0.68}
// Bucket 7:  {0.72, 0.78}
// Bucket 8:  (empty)
// Bucket 9:  {0.94}
// ```

// ---

// ### **Step 3: Sorting Each Bucket**
// Buckets are individually sorted using **Insertion Sort**:

// ```plaintext
// Bucket 1 (Sorted): {0.12, 0.17}
// Bucket 2 (Sorted): {0.21, 0.23, 0.26}
// Bucket 3 (Sorted): {0.39}
// Bucket 6 (Sorted): {0.68}
// Bucket 7 (Sorted): {0.72, 0.78}
// Bucket 9 (Sorted): {0.94}
// ```

// ---

// ### **Step 4: Merge Sorted Buckets**
// We concatenate all sorted buckets:

// ```plaintext
// {0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94}
// ```

// ### **Final Sorted Array:**
// {0.12, 0.17, 0.21, 0.23, 0.26, 0.39, 0.68, 0.72, 0.78, 0.94}
