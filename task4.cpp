#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

//bubble sort
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//selection sort
void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//insertion sort
void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

long long timeSort(void (*sortFunc)(vector<int>&), vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

vector<int> generateArray(int size) {
    vector<int> arr(size);
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

int main() {
    vector<int> sizes = {100, 1000, 5000, 10000};

    cout << "Size\tBubble\tSelection\tInsertion\n";

    for(int size : sizes) {
        vector<int> arr = generateArray(size);

        long long bubble = timeSort(bubbleSort, arr);
        long long selection = timeSort(selectionSort, arr);
        long long insertion = timeSort(insertionSort, arr);

        cout << size << "\t" << bubble << "ms\t"
             << selection << "ms\t"
             << insertion << "ms\n";
    }

    return 0;
}
