#include <iostream>
#include <vector>
#include <algorithm>

// Selection sort is an in-place algorithm
// time complexity: O(N^2), because to two nested loops.
// Space complexity: O(1), no extra space required.
void SelectionSort(std::vector<int>& vec){

    int min_idx;
    for(int i = 0; i < vec.size(); i++){
        min_idx = i;
        for(int j = i+1; j < vec.size(); j++){
            if(vec[min_idx] > vec[j]){
                min_idx = j;
            } 
        }
        std::swap(vec[i], vec[min_idx]);
    }
}


int main(){

    std::vector<int> vec{64,25,12,22,11};
    SelectionSort(vec);

    for(auto& val:vec) std::cout<<val<<"\t";

    return 0;
}