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

int selectionSort(std::vector<int>* arr)
{
    int comparisonCount = 0;
    int n = arr->size();

    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            ++comparisonCount;
            if ((*arr)[j] < (*arr)[minIndex])
                minIndex = j;
        }
        std::swap((*arr)[i], (*arr)[minIndex]);
    }

    return comparisonCount;
}

int main()
{
    freopen("ex01_2_inp.txt", "r", stdin);
    auto arr = readInput();
    auto comparisonCount = selectionSort(&arr);

    std::cout << "Number of comparisons: " << comparisonCount << std::endl;
    for (const auto& num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}