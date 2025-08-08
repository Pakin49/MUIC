#include <cstdlib>
#include <iostream>
#include <time.h>
#define size 3000
void merge_sort(int a[], int low, int high);
void Merge(int a[], int low, int mid, int high);

int main() {
  srand(time(NULL));
  int a[size]; 

  for (int i = 0; i < size; i++) {
    int randomnumber = (rand() % 2000001) - 1000000;
    a[i] = randomnumber;
  }
  merge_sort(a, 0, size - 1);

  int head = 0, move = 1, tail = size - 1;
  //everything in thie while loop below is constant
  //this loop worst case is n times when every random number <0
  // the loop is in the for loop so = O(n^2)
  while (a[head] < 0) {
    move = head + 1, tail = size - 1;
    while (a[move] < a[tail]) {
      int sum = a[head] + a[move] + a[tail];
      if (sum < 0) 
        move++;
      else if (sum > 0) 
        tail--;
      else {
        printf("%6d %6d %6d\n", a[head], a[move], a[tail]);
        move++;
      }
    }
    head++;
  }
  // time complexity = O(n^2)+O(nlogn) = O(n^2)
}

void merge_sort(int a[size], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    Merge(a, low, mid, high);//O(n)
    //O(nlogn)
  }
}

void Merge(int a[size], int low, int mid, int high) {
  int b[size];
  int i0 = low, i1 = mid + 1; //O(1)
  for (int j = low; j <= high; j++) {
    if (i0 <= mid && (i1 > high || a[i0] <= a[i1])) {
      b[j] = a[i0];
      i0 += 1;
    } else {
      b[j] = a[i1];
      i1 += 1;
    }
  // everything inside is constant so this loop is O(n)
  }
  for (int i = low; i <= high; i++) //O(n)
    a[i] = b[i]; //O(1)
  // merge function = O(n)
}
