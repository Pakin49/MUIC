#include <iostream>
#include <limits>

using namespace std;

int maxSubArray(int arr[], int low, int high);
int maxCrossingSubArray(int arr[], int low, int mid, int high);

int main() {
    int arr[] = {-90, 50, -20, 10, -5, -10, 5, 10, -20, 20, 30, -40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubArray(arr, 0, n - 1);
    cout << "Maximum Sub Array Sum: " << maxSum << endl;
    return 0;
}

int maxSubArray(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int leftMax = maxSubArray(arr, low, mid);
    int rightMax = maxSubArray(arr, mid + 1, high);
    int crossMax = maxCrossingSubArray(arr, low, mid, high);
    return max(max(leftMax, rightMax), crossMax);
}

int maxCrossingSubArray(int arr[], int low, int mid, int high) {
    int leftSum = numeric_limits<int>::min();
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    int rightSum = numeric_limits<int>::min();
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}
