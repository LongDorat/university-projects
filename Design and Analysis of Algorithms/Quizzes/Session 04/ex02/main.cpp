#include <iostream>
#include <vector>
#include <chrono>

class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}
    void reset() { start_time = std::chrono::high_resolution_clock::now(); }
    double elapsed() const {
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(end_time - start_time).count();
    }
private:
    std::chrono::high_resolution_clock::time_point start_time;
};

int partitionHoare(std::vector<int>& arr, int low, int high, int& swaps) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        std::swap(arr[i], arr[j]);
        swaps++;
    }
}

void quickSort(std::vector<int>& arr, int low, int high, int& swaps) {
    if (low < high) {
        int pi = partitionHoare(arr, low, high, swaps);
        quickSort(arr, low, pi, swaps);
        quickSort(arr, pi + 1, high, swaps);
    }
}

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right)
{
    std::vector<int> merged;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i]);
            ++i;
        } else {
            merged.push_back(right[j]);
            ++j;
        }
    }

    while (i < left.size()) {
        merged.push_back(left[i]);
        ++i;
    }

    while (j < right.size()) {
        merged.push_back(right[j]);
        ++j;
    }

    return merged;
}

std::vector<int> merge_sort(std::vector<int>& arr)
{
    if (arr.size() <= 1) {
        return arr;
    }

    int haft = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + haft);
    std::vector<int> right(arr.begin() + haft, arr.end());

    auto left_inversions = merge_sort(left);
    auto right_inversions = merge_sort(right);

    return merge(left_inversions, right_inversions);
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

    int quickSortSwaps = 0;

    Timer timer;
    quickSort(arr_1, 0, n - 1, quickSortSwaps);
    double elapsed_time = timer.elapsed();

    std::cout << "Quick Sort Swaps: " << quickSortSwaps << std::endl;
    std::cout << "Quick Sort Time: " << elapsed_time << " seconds" << std::endl;

    timer.reset();
    auto sorted_arr = merge_sort(arr_2);
    elapsed_time = timer.elapsed();

    std::cout << "Merge Sort Time: " << elapsed_time << " seconds" << std::endl;

    return 0;
}