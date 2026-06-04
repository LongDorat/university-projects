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

int insertionSort(std::vector<int>* arr)
{
    int comparisonCount = 0;
    for (size_t i = 1; i < arr->size(); ++i)
    {
        int key = (*arr)[i];
        int j = i - 1;

        while (j >= 0 && (*arr)[j] > key)
        {
            comparisonCount++;
            (*arr)[j + 1] = (*arr)[j];
            j--;
        }
        if (j >= 0) // Count the comparison that fails the while loop
            comparisonCount++;

        (*arr)[j + 1] = key;
    }
    return comparisonCount;
}

int main()
{
    freopen("ex03_inp.txt", "r", stdin);
    auto arr = readInput();
    auto comparisonCount = insertionSort(&arr);

    std::cout << "Number of comparisons: " << comparisonCount << std::endl;
    for (const auto& num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}