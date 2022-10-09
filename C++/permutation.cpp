class Solution {
     vector<vector<int>>ans;
public:
    vector<vector<int>> permute(vector<int>& A) {
        int n = A.size();
        solve(A,n);
        return ans;
        
    }
    void solve(vector<int>& a, int size)
    {
        if (size == 1) {
           ans.push_back(a);
            return;
        }

        for (int i = 0; i < size; i++) {
            solve(a, size - 1);
            if (size % 2 == 1)
                swap(a[0], a[size - 1]);
            else
                swap(a[i], a[size - 1]);
        }
    }

   
};