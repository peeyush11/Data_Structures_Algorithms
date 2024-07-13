#include <iostream>
#include <vector>
#include <algorithm>

void BubbleSort(std::vector<int>& vec){

    bool swapped;

    for(int i = 0; i < vec.size()-1; i++){
        swapped = false;
        for(int j = 0; j < vec.size()-i-1; j++){
            if(vec[j] > vec[j+1]){
                std::swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
}

int main(){

    std::vector<int> vec{6,0,3,5,100,55,10,200,37};
    BubbleSort(vec);

    for(auto& val:vec) std::cout<<val<<"\t";
    
    return 0;
}