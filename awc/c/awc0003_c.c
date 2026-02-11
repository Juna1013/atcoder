#include <stdio.h>

long long temp[200000];

void merge(long long arr[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = 0;

    while (i < mid && j < right) {
        if (arr[i] >= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i < mid) temp[k++] = arr[i++];
    while (j < right) temp[k++] = arr[j++];

    for (int t = 0; t < k; t++) arr[left + t] = temp[t];
}

void merge_sort(long long arr[], int left, int right) {
    if (right - left <= 1) return;

    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid, right);
    merge(arr, left, mid, right);
}

int compare_desc(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y) return 1;
    if (x > y) return -1;
    return 0;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    long long A, B, diff[N];
    long long total_A = 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &A, &B);
        diff[i] = A - B;
        total_A += A;
    }

    merge_sort(diff, 0, N);

    long long discount = 0;
    for (int i = 0; i < K; i++) discount += diff[i];

    long long answer = total_A - discount;
    printf("%lld\n", answer);
    return 0;
}
