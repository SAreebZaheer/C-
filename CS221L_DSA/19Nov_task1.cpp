#include <iostream>

using namespace std;

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    // Choose the median of three (first, middle, last) as the pivot
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to implement Quick Sort recursively
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int grades[n];
    cout << "Enter the grades: ";
    for (int i = 0; i < n; i++) {
        cin >> grades[i];
    }

    quickSort(grades, 0, n - 1);

    cout << "Sorted grades (Descending): ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << endl;

    return 0;
}