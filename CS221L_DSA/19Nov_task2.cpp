#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n1, n2;

    cout << "Enter the number of products in inventory 1: ";
    cin >> n1;

    int inventory1[n1];
    cout << "Enter the product IDs for inventory 1: ";
    for (int i = 0; i < n1; i++) {
        cin >> inventory1[i];
    }

    cout << "Enter the number of products in inventory 2: ";
    cin >> n2;

    int inventory2[n2];
    cout << "Enter the product IDs for inventory 2: ";
    for (int i = 0; i < n2; i++) {
        cin >> inventory2[i];
    }

    // Merge the two inventories into a single array
    int mergedInventorySize = n1 + n2;
    int mergedInventory[mergedInventorySize];
    for (int i = 0; i < n1; i++) {
        mergedInventory[i] = inventory1[i];
    }
    for (int i = 0; i < n2; i++) {
        mergedInventory[n1 + i] = inventory2[i];
    }

    mergeSort(mergedInventory, 0, mergedInventorySize - 1);

    cout << "Merged and sorted product IDs: ";
    for (int i = 0; i < mergedInventorySize; i++) {
        cout << mergedInventory[i] << " ";
    }
    cout << endl;

    return 0;
}