#include<iostream>
#include<vector>
#include<chrono>

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

std::vector<int> prefix_average(const std::vector<int> v)
{
    std::vector<int> result(v.size());
    for(int i = 0; i < v.size(); i++){
        int sum = 0;
        for(int j = 0; j <= i; j++){
            sum += v[j];
        }
        result[i] = sum / (i + 1);
    }
    return result;
}

std::vector<int> prefix_average_optimized(const std::vector<int> v)
{
    std::vector<int> result(v.size());
    int prefix_sum = 0;
    for(int i = 0; i < v.size(); i++){
        prefix_sum += v[i];
        result[i] = prefix_sum / (i + 1);
    }
    return result;
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <size>" << std::endl;
        return 1;
    }
    int size = std::stoi(argv[1]);
    std::vector<int> v(size);
    for(int i = 0; i < size; i++){
        v[i] = i + 1; // Fill the vector with values from 1 to size
    }

    Timer timer;
    prefix_average(v);
    double time_naive = timer.elapsed();
    std::cout << "Naive prefix average time: " << time_naive << " seconds" << std::endl;

    timer.reset();
    prefix_average_optimized(v);
    double time_optimized = timer.elapsed();
    std::cout << "Optimized prefix average time: " << time_optimized << " seconds" << std::endl;

    double speedup = time_naive / time_optimized;
    std::cout << "Speedup: " << speedup << "x" << std::endl;

    return 0;
}

