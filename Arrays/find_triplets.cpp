#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findTripletsWithSumX(vector<int> vec, const int& val){
   
    sort(vec.begin(), vec.end());

    int l, r;
    int n = vec.size();

    for(int i = 0; i < n-2; i++){
        l = i+1;
        r = n-1;

        while(l<r){
            int sum = vec[i] + vec[l] + vec[r];

            if(sum == val){
                cout<<"Triplets are: "<<vec[i]<<", "<<vec[l]<<", "<<vec[r]<<" whose sum is equal to: "<<val<<endl;
                return;
            } 
            else if(sum < val) l++;
            else r--;
        }
    }

    cout<<"Triplets not found whose sum is equal to "<<val<<endl;
    
}

int main(){

    // For vec, val = 0
    vector<int> vec{0, -1, 2, -3, 1 };
    // For vec2, val = 22
    vector<int> vec2{1, 4, 45, 6, 10, 8 };

    findTripletsWithSumX(vec, 0);
    findTripletsWithSumX(vec2, 22);

    return 0;

}