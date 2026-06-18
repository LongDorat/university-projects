#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int QuickSelect(std::vector<int>& arr, int left, int right, int k);

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

int MedianOfMedians(std::vector<int>&arr, int left, int right)
{
    int n = right - left + 1;
    if (n <= 5)
    {
        std::sort(arr.begin() + left, arr.begin() + right + 1);
        return left + n / 2;
    }

    int GroupCount = std::ceil(static_cast<double>(n) / 5);
    std::vector<int> medians(GroupCount);

    for (int i = 0; i < GroupCount; i++)
    {
        int groupLeft = left + i * 5;
        int groupRight = std::min(groupLeft + 4, right);
        int groupSize = groupRight - groupLeft + 1;

        std::sort(arr.begin() + groupLeft, arr.begin() + groupRight + 1);
        medians[i] = arr[groupLeft + groupSize / 2];
    }

    int medianOfMediansValue = QuickSelect(medians, 0, GroupCount - 1, (GroupCount + 1) / 2);
    
    for (int i = left; i <= right; i++)
    {
        if (arr[i] == medianOfMediansValue)
        {
            return i;
        }
    }

    return left; // Fallback
}

int QuickSelect(std::vector<int>& arr, int left, int right, int k)
{
    if (arr.empty() || k <= 0 || k > arr.size())
    {
        throw std::invalid_argument("Invalid input");
    }

    if (left == right)
    {
        return arr[left];
    }

    int pivotIndex = MedianOfMedians(arr, left, right);
    int partitionIndex = Partition(arr, left, right, pivotIndex);

    int kthIndex = k - 1; // Convert k to 0-based index

    if (kthIndex == partitionIndex)
    {
        return arr[partitionIndex];
    }
    else if (kthIndex < partitionIndex)
    {
        return QuickSelect(arr, left, partitionIndex - 1, k);
    }
    else
    {
        return QuickSelect(arr, partitionIndex + 1, right, k);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
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
        int kthSmallest = QuickSelect(arr, 0, n - 1, k);
        std::cout << "The " << k << "-th smallest element is: " << kthSmallest << std::endl;
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}