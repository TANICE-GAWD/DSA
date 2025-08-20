#include <iostream>
using namespace std;

long long merge(long long arr[], long long temp[], int left, int mid,
                int right) {
  int i = left, j = mid, k = left;
  long long inv = 0;
  while (i <= mid - 1 && j <= right) {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else {
      temp[k++] = arr[j++];
      inv += mid - i;
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  for (i = left; i <= right; i++)
    arr[i] = temp[i];
  return inv;
}

long long mergesort(long long arr[], long long temp[], int left, int right) {
  long long inv = 0;
  if (left < right) {
    int mid = (left + right) / 2;
    inv += mergesort(arr, temp, left, mid);
    inv += mergesort(arr, temp, mid + 1, right);
    inv += merge(arr, temp, left, mid + 1, right);
  }
  return inv;
}

int main() {
  long long arr[] = {2, 4, 1, 3, 5};
  int n = 5;
  long long temp[n];
  cout << mergesort(arr, temp, 0, n - 1) << endl;
}
