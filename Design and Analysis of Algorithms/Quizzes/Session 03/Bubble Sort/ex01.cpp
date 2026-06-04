#include <iostream>
#include <vector>

std::vector<int> readInput()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    return arr;
}

int bubbleSort(std::vector<int>* arr)
{
    int comparisonCount = 0;
    int n = arr->size();
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
        {
            comparisonCount++;
            if (arr->at(j) > arr->at(j + 1))
            {
                std::swap((*arr)[j], (*arr)[j + 1]);
            }
        }

    return comparisonCount;
}

int main()
{
    freopen("ex01_inp.txt", "r", stdin);
    auto arr = readInput();
    auto comparisonCount = bubbleSort(&arr);

    std::cout << "Number of comparisons: " << comparisonCount << std::endl;
    for (const auto& num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}