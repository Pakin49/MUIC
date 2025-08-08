#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
void mergeSort(int A[], int low, int high);
void merge(int A[], int low, int mid, int high);
void findTriplets(int A[], int size);

char *printArray(int *arr, int n, int start = 0)
{
  cout << "[";
  for (int i = start; i < start + n; i++)
    cout << arr[i] << (i == start + n - 1 ? "" : ", ");
  cout << "]";
  return (char *)("");
}

int main()
{
  int n;
  cout << "Enter the number of elements from 3-3000: " << endl;
  cin >> n;
  int A[n];

  srand(time(0));
  int lowerBound = -3, upperBound = 3;
  for (int i = 0; i < n; i++)
    A[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
  cout << "Original array: " << printArray(A, n) << endl;
  int size = sizeof(A) / sizeof(int);

  mergeSort(A, 0, n - 1);
  cout << "Sorted array: " << printArray(A, n) << endl;
  findTriplets(A, size);
}

void mergeSort(int A[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(A, low, mid);
    mergeSort(A, mid + 1, high);
    merge(A, low, mid, high);
  }
}

void merge(int A[], int low, int mid, int high)
{

  int nl = mid - low + 1;
  int nr = high - mid;
  int L[nl], R[nr];

  for (int i = 0; i < nl; i++)
  {
    L[i] = A[low + i];
  }

  for (int i = 0; i < nr; i++)
  {
    R[i] = A[mid + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = low;

  while (i < nl && j < nr)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < nl)
  {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < nr)
  {
    A[k] = R[j];
    j++;
    k++;
  }
}

void findTriplets(int A[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int left = i + 1;
    int right = size - 1;
    while (left < right)
    {
      int sum = A[i] + A[left] + A[right];
      if (sum == 0)
      {
        cout << A[i] << ", " << A[left] << ", " << A[right] << endl;
        left++;
        right--;
      }
      else if (sum < 0)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
  }
}

/* Time complexity analysis:
In merge sort, the time complexity is O(nlogn) because the algorithm is recursive.
When the algorithm is called, it divides the array into two halves and calls itself recursively.

The time complexity of the merge function is O(n) because it iterates through the array once.

The time complexity of the findTriplets function is O(n^2) because it iterates through the array twice.

The total time complexity of the program is O(nlogn + n^2) = O(nlogn)
*/
