#include <stdio.h>
#include <stdlib.h>

// Function to find elements that appear more than n/3 times
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;

    // Step 1: Find the potential candidates
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Count the occurrences of the potential candidates
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        }
    }

    // Step 3: Check if candidates appear more than n/3 times
    *returnSize = 0;
    int* result = (int*)malloc(sizeof(int) * 2);
    if (count1 > numsSize / 3) {
        result[(*returnSize)++] = candidate1;
    }
    if (count2 > numsSize / 3 && candidate1 != candidate2) {
        result[(*returnSize)++] = candidate2;
    }

    return result;
}

int main() {
    int n;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(sizeof(int) * n);

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int* result;
    int returnSize;
    result = majorityElement(nums, n, &returnSize);

    // Output the result
    printf("\nElements appearing more than n/3 times:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // No explicit memory deallocation here

    return 0;
}
