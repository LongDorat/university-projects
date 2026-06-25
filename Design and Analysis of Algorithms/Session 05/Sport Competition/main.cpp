#include<iostream>
#include<vector>
#include<random>

void generate_random()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9999);

    FILE* file = fopen("input.txt", "w");
    if (file) {
        fprintf(file, "100\n");
        std::vector<int> randomNumbers(100);
        for (int i = 0; i < 100; ++i) {
            randomNumbers[i] = dis(gen);
            fprintf(file, "%d\n", randomNumbers[i]);
        }
        int random_index = std::random_device{}() % 100;
        fprintf(file, "%d\n", randomNumbers[random_index]);
        fclose(file);
    }
}

int partition(std::vector<int>& arr, int low, int high)
{
    int pivotValue = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivotValue)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(std::vector<int>& arr, int low, int high)
{
    if (low >= high)
        return;

    int randomPivotIndex = std::random_device{}() % (high - low + 1) + low;
    std::swap(arr[high], arr[randomPivotIndex]);

    int pivotIndex = partition(arr, low, high);
    quick_sort(arr, low, pivotIndex - 1);
    quick_sort(arr, pivotIndex + 1, high);
}

std::pair<int, int> binary_search(const std::vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    int foundIndex = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            foundIndex = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    if (foundIndex == -1)
        return {-1, -1}; // Target not found

    // Expand from the found index to find the first and last occurrence
    int i = foundIndex;
    int j = foundIndex;
    while (i > 0 && arr[i - 1] == target)
        i--;
    while (j < arr.size() - 1 && arr[j + 1] == target)
        j++;
    return {i, j};
}

void run()
{
    freopen("input.txt", "r", stdin);
    int n;
    std::cin >> n;

    std::vector<int> scores = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> scores[i];
    }

    int score_to_find;
    std::cin >> score_to_find;
    std::cout << "Score to find: " << score_to_find << std::endl;

    quick_sort(scores, 0, n - 1);

    for (const auto& score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    std::pair<int, int> rank_range = binary_search(scores, score_to_find);
    if (rank_range.first != -1) {
        std::cout << "Score found first at index: " << rank_range.first << " (" << rank_range.first + 1 << "th rank)" << std::endl;
        std::cout << "There are " << (rank_range.second - rank_range.first + 1) << " occurrences of the score." << std::endl;
    } else {
        std::cout << "Score not found." << std::endl;
    }
}

int main()
{
    for (int i = 0; i < 5; ++i) {
        generate_random();
        run();
        std::cout << "------------------------" << std::endl;
    }
    return 0;
}