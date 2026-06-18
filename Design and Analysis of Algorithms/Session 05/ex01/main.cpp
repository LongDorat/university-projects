#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int Partition(std::vector<int> &arr, int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    
    std::swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; ++i)
    {
        if (arr[i] < pivotValue)
        {
            std::swap(arr[storeIndex], arr[i]);
            ++storeIndex;
        }
    }

    std::swap(arr[right], arr[storeIndex]);
    return storeIndex;
}

int QuickSelect(std::vector<int> &arr, int left, int right, int k)
{
    if (arr.empty() || k < 1 || k > arr.size())
    {
        throw std::invalid_argument("Invalid input");
    }

    if (left == right)
    {
        return arr[left];
    }

    int pivotIndex = std::random_device{}() % (right - left + 1) + left;

    int partitionIndex = Partition(arr, left, right, pivotIndex);

    // Adjust into 0-based index for k
    int kthIndex = left + k - 1;

    if (partitionIndex == kthIndex)
    {
        return arr[kthIndex];
    }
    else if (kthIndex < partitionIndex)
    {
        return QuickSelect(arr, left, partitionIndex - 1, k);
    }
    else
    {
        return QuickSelect(arr, partitionIndex + 1, right, k - (partitionIndex - left + 1));
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    // DEBUG
    // std::cout << "Input array: ";
    // for (const auto &num : arr)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    
    // std::cout << "k: " << k << std::endl;

    // std::cout << "Sorted array: ";
    // std::vector<int> sortedArr = arr;
    // std::sort(sortedArr.begin(), sortedArr.end());
    // for (const auto &num : sortedArr)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    // END DEBUG

    try
    {
        int result = QuickSelect(arr, 0, n - 1, k);
        std::cout << result << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}