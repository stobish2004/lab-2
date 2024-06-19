#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
private:
    std::vector<int> heap;

    // Helper function to maintain the heap property after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Helper function to maintain the heap property after removal
    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChildIndex = 2 * index + 1;
            int rightChildIndex = 2 * index + 2;
            int largestIndex = index;

            if (leftChildIndex < size && heap[leftChildIndex] > heap[largestIndex]) {
                largestIndex = leftChildIndex;
            }
            if (rightChildIndex < size && heap[rightChildIndex] > heap[largestIndex]) {
                largestIndex = rightChildIndex;
            }
            if (largestIndex != index) {
                std::swap(heap[index], heap[largestIndex]);
                index = largestIndex;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap() {}

    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Get the maximum element from the heap
    int getMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // Remove and return the maximum element from the heap
    int extractMax() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    // Check if the heap is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Get the size of the heap
    int size() const {
        return heap.size();
    }

    // Print the heap (for debugging purposes)
    void printHeap() const {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);

    std::cout << "Heap elements: ";
    maxHeap.printHeap();

    std::cout << "Maximum element: " << maxHeap.getMax() << std::endl;

    std::cout << "Extracting maximum: " << maxHeap.extractMax() << std::endl;

    std::cout << "Heap elements after extraction: ";
    maxHeap.printHeap();

    return 0;
}
