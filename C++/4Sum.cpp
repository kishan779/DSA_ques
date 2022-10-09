class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>vec;
        for(int i=0;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                int low=j+1;
                int high=n-1;
                while(low<high)
                {
                   long long int sum=(long long int)nums[i]+nums[j]+nums[low]+nums[high];
                    if(sum==target)
                    {
                        vector<int> v{nums[i],nums[j],nums[low],nums[high]};
                        vec.insert(v);
                        low++;
                        high--;                                             
                    }
                    else if(sum<target)                                          
                      low++;
                     else high--;
                }
            }
        }
    
    vector<vector<int>> mp;
	copy(vec.begin(), vec.end(),inserter(mp, mp.begin()));
      return mp;                                                               
    }
};
