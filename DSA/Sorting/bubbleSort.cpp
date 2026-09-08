#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    
    // Traverse through all elements in the vector
    for (int i = 0; i < n; i++) {
        swapped = false;
        
        // The last 'i' elements are already sorted and in place
        for (int j = 0; j < n - i - 1; j++) {
            
            // Swap if the current element is greater than the next one
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // Optimization: If no elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    bubbleSort(numbers);
    
    // Print the sorted array
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}