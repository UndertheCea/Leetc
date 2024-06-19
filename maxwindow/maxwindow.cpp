#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;  
        int n = nums.size();
    }
    inline int parent(int i){
        return (i-1)/2;
    }
    inline int left_child(int i){
        return 2*i + 1;
    }
    inline int right_child(int i){
        return 2*i + 2;
    }
    // heapify starts from the parent node 
    void heapify(vector<int> nums, int i){
        int size = nums.size();
        int largest = nums[i];
        // check if either child is larger than the parent
        if (largest < nums[left_child(i)] && left_child(i) < size){
            largest = nums[left_child(i)];
        }
        if (largest < nums[right_child(i)] && right_child(i) < size){
            largest = nums[right_child(i)];
        }
        // if larger
        if (largest != nums[i]){
            swap(nums[i], nums[largest]);
            heapify(nums, largest);
        }
    }
    void insert(vector<int> nums, int i){
        int size = nums.size();
        if (size == 0){
            nums.push_back(i);
        }
        else{
            nums.push_back(i);
            for (int j = parent(size); j >= 0; j--){
                heapify(nums, j);
                j = parent(j);
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
    int k = 5;
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    cout << "this is the answer" << endl;                                                                                                                                                  
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
