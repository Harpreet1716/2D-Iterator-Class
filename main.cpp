#include <iostream>
#include <vector>

class TwoDIterator {
private:
    std::vector<std::vector<int>> arrays; // Stores the 2D array of integers
    size_t row; // Tracks the current row index
    size_t col; // Tracks the current column index within a row

    // Helper function to move the iterator to the next valid position
    void moveToNextValid() {
        // Increment row and reset column to 0 when the end of a row is reached
        while (row < arrays.size() && col == arrays[row].size()) {
            ++row;
            col = 0;
        }
    }

public:
    // Constructor that initializes the 2D iterator with a vector of vectors of integers
    TwoDIterator(std::vector<std::vector<int>>& arr) : arrays(arr), row(0), col(0) {
        // Move the iterator to the first valid position
        moveToNextValid();
    }

    // Function to retrieve the next integer in the 2D array
    int next() {
        // Check if there are more elements available in the array
        if (!hasNext()) {
            throw std::out_of_range("No more elements in the array of arrays.");
        }

        // Retrieve the current value, move to the next column, and adjust the iterator position
        int val = arrays[row][col];
        ++col;
        moveToNextValid();
        return val;
    }

    // Function to check if there are more elements available in the 2D array
    bool hasNext() {
        return row < arrays.size();
    }
};

// Main function demonstrating the usage of the TwoDIterator class
int main() {
    // Example 2D array
    std::vector<std::vector<int>> input = { {1, 2}, {3}, {}, {4, 5, 6} };

    // Create a TwoDIterator object using the input array
    TwoDIterator iterator(input);

    // Iterate through the 2D array and print each element
    while (iterator.hasNext()) {
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}
