#include <iostream>
#include <vector>

std::vector<int> readInput()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    return arr;
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
    freopen("ex03_inp.txt", "r", stdin);
    std::vector<int> arr = readInput();

    std::vector<int> sorted_arr = merge_sort(arr);
    for (int num : sorted_arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}