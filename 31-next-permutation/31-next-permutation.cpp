class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i >= 0){
            if(nums[i] < nums[i+1]) break;
            i--;
        }
        if(i==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = n-1;
        int mini = INT_MAX;
        while(j > i){
            if(nums[j] > nums[i]){
                break;
            }
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
        return;
    }
};