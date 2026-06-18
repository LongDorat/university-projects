#include <iostream>
#include <vector>

int partitionLomuto(std::vector<int>& arr, int low, int high, int& swapCount) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            ++swapCount;
        }
    }
    std::swap(arr[i + 1], arr[high]);
    ++swapCount;
    return i + 1;
}

void quickSortLomuto(std::vector<int>& arr, int low, int high, int& swapCount) {
    if (low < high) {
        int pi = partitionLomuto(arr, low, high, swapCount);
        quickSortLomuto(arr, low, pi - 1, swapCount);
        quickSortLomuto(arr, pi + 1, high, swapCount);
    }
}

int partitionHoare(std::vector<int>& arr, int low, int high, int& swapCount) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);

        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }
        std::swap(arr[i], arr[j]);
        ++swapCount;
    }
}

void quickSortHoare(std::vector<int>& arr, int low, int high, int& swapCount) {
    if (low < high) {
        int pi = partitionHoare(arr, low, high, swapCount);
        quickSortHoare(arr, low, pi, swapCount);
        quickSortHoare(arr, pi + 1, high, swapCount);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    std::cin >> n;

    std::vector<int> arr_1(n);
    std::vector<int> arr_2(n);
    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;
        arr_1[i] = temp;
        arr_2[i] = temp;
    }

    int LomutoSwapCount = 0;
    int HoareSwapCount = 0;

    quickSortLomuto(arr_1, 0, n - 1, LomutoSwapCount);
    for (const auto& num : arr_1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Lomuto Swap Count: " << LomutoSwapCount << std::endl;

    quickSortHoare(arr_2, 0, n - 1, HoareSwapCount);
    for (const auto& num : arr_2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Hoare Swap Count: " << HoareSwapCount << std::endl;

    return 0;
}