class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1,noOfZeros = 0,indexOfZero = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) totalProduct *= nums[i];
            else ++noOfZeros,indexOfZero = i;
        }
        vector <int> ans(nums.size(),0);
        if (noOfZeros > 1) return ans;
        else if (noOfZeros == 1) {
            ans[indexOfZero] = totalProduct;
            return ans;
        }
        for (int i = 0; i < nums.size(); ++i) ans[i] = (totalProduct)/nums[i];
        return ans;
    }
};
