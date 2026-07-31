#include <iostream>
#include <vector>
#include <algorithm>

int findCompatibles(const std::vector<std::pair<int, int>>& arr)
{
    int count = 1;
    int highest = arr[0].second;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i].first >= highest)
        {
            ++count;
            highest = arr[i].second;
        }
    }
    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i].first;
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i].second;
    }
    std::sort(arr.begin(), arr.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    std::cout << "Sorted array based on the second element:\n";
    for (const auto& p : arr)
    {
        std::cout << p.first << " " << p.second << "\n";
    }

    std::cout << "Number of compatible pairs: " << findCompatibles(arr) << "\n";

    return 0;
}