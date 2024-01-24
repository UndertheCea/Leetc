#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; 
        int largest_in_wndow = 0;
        int second_largest_in_window = 0;
        int last = 0;
        int second_last = 0;


        for(int i = 0; i < nums.size(); i++){
            if (i < k-1 ){
                if (nums[i] > largest_in_wndow){
                    largest_in_wndow = nums[i];
                    last = i;
                }
                continue;
            }
            // check if largest is still in windows
            if (last > 0){
                if (nums[i] > largest_in_wndow){
                    largest_in_wndow = nums[i];
                    last = k;
                }
            }
            else{
                // find through the past k to find the max value
                largest_in_wndow = nums[i];
                for (int j = 0; j < k; j++){
                    if (nums[i-j] > largest_in_wndow){
                        largest_in_wndow = nums[i-j];
                        last = k-j;
                    }
                }
            }
            ans.push_back(largest_in_wndow);
            last--;
        }

        return ans;
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
