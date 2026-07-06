#include <iostream>
#include <vector>
#include <algorithm>

void HeapifyUp(std::vector<int> &arr, int i)
{
    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        std::swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MaxHeapify(std::vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(std::vector<int> &arr)
{
    int n = arr.size();
    int startIndex = (n / 2) - 1;

    for (int i = startIndex; i >= 0; i--)
    {
        MaxHeapify(arr, n, i);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    std::cin >> n;

    std::vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int element;
        std::cin >> element;
        arr.push_back(element);
    }
    BuildMaxHeap(arr);

    int jobCount;
    std::cin >> jobCount;
    std::vector<std::pair<int, int>> jobs;
    for (int i = 0; i < jobCount; i++)
    {
        int task;
        std::cin >> task;
        if (task == 1)
        {
            int x;
            std::cin >> x;
            jobs.push_back({task, x});
        }
        else
        {
            jobs.push_back({task, 0});
        }
    }

    for (auto job : jobs)
    {
        if (job.first == 1)
        {
            arr.push_back(job.second);
            HeapifyUp(arr, arr.size() - 1);
        }
        else
        {
            printf("%d\n", arr.front());
        }
    }

    return 0;
}