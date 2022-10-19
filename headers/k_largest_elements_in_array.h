#pragma once

#include <vector>
#include <functional>

class KLargestElementsArray {
public:
    std::vector<int> getKLargestElements(const std::vector<int>& arr, int K);
};

auto KLargestElementsArray::getKLargestElements(const std::vector<int>& arr, int K) -> std::vector<int> {

    std::vector<int> heap{arr.begin(), arr.begin() + K};
    std::make_heap(heap.begin(), heap.end(), std::greater<int>());

    for(int i = K; i < arr.size(); ++i) {
        if(heap.front() < arr[i]) {
            std::pop_heap(heap.begin(), heap.end(), std::greater<int>());
            heap.pop_back();
            heap.push_back(arr[i]);
            std::push_heap(heap.begin(), heap.end(), std::greater<int>());
        }
    }
    
    return heap;
}