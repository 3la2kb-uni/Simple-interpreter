#include <stdio.h>


  void heapify(Node* arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    Node* temp = malloc(sizeof(Node));

    if (left < n && arr[left]->value > arr[largest]->value)
      largest = left;

    if (right < n && arr[right]->value > arr[largest]->value)
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;
      heapify(arr, n, largest);
    }
  }

  // Main function to do heap sort
  void heapSort(Node* arr[], int n) {
      Node* temp = malloc(sizeof(Node));
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

  // Print an array
  void printArray(Node* arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%s = %f\n", arr[i]->data, arr[i]->value);
  }

  // Driver code
  int sortByVal() {

    int n = 5;

    heapify(contextArray,n,n);

    heapSort(contextArray, n);

    printf("\nSorted by value using heap sort \n");
    printArray(contextArray, n);
  }
