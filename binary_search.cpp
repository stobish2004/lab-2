#include <iostream>
#include <vector>

int binarySearchRecursive(const std::vector<int>& arr, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        } else {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array" << std::endl;
    }

    return 0;
}
