#include <iostream>
#include <cstddef>
using namespace std;

class DynamicArray {
private:
    int* dataArray;
    size_t currentCount;
    size_t maxCapacity;

    void resize() {
        size_t newCapacity = maxCapacity * 2;

        int* temp = new int[newCapacity];

        for (size_t i = 0; i < currentCount; i++) {
            temp[i] = dataArray[i];
        }

        delete[] dataArray;

        dataArray = temp;
        maxCapacity = newCapacity;
    }

public:

    DynamicArray(size_t initialCapacity = 5)
        : dataArray(new int[initialCapacity]),
          currentCount(0),
          maxCapacity(initialCapacity) {
    }

    ~DynamicArray() {
        delete[] dataArray;
    }

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    void addItem(int value) {
        if (currentCount >= maxCapacity) {
            resize();
        }

        dataArray[currentCount] = value;
        currentCount++;

        cout << "Added item: " << value << endl;
    }

    void removeItemAt(size_t index) {
        if (index >= currentCount) {
            cout << "Invalid index!" << endl;
            return;
        }

        for (size_t i = index; i < currentCount - 1; i++) {
            dataArray[i] = dataArray[i + 1];
        }

        currentCount--;

        cout << "Item removed from index " << index << endl;
    }

    int findItem(int target) const {
        for (size_t i = 0; i < currentCount; i++) {
            if (dataArray[i] == target) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }

    void printAll() const {
        cout << "Current List Contents: ";

        for (size_t i = 0; i < currentCount; i++) {
            cout << dataArray[i] << " ";
        }

        cout << endl;
    }

    size_t getCount() const {
        return currentCount;
    }

    size_t getCapacity() const {
        return maxCapacity;
    }
};

void processMatrix() {
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int t[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t[j][i] = m[i][j];
        }
    }

    cout << "Transposed Matrix:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << t[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    cout << "--- STARTING REFACTORED SUBSYSTEM ---" << endl;

    DynamicArray data;

    data.addItem(10);
    data.addItem(20);
    data.addItem(30);
    data.addItem(40);
    data.addItem(50);
    data.addItem(60);

    data.printAll();

    cout << "Found 30 at index: "
         << data.findItem(30) << endl;

    data.removeItemAt(2);

    data.printAll();

    data.removeItemAt(99);

    data.printAll();

    processMatrix();

    return 0;
}
