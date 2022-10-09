class Solution {
public:
    int flag = 0;
    
    int solve(string &s, unordered_set<string> &dict, int start, int i, vector<vector<int>> &dp)
    {
        if(i == s.size()-1)
        {
            string tmp = s.substr(start, i-start+1);
            if(dict.find(tmp) != dict.end())
            {
                flag = 1;
                return 1;
            }
            return 0;
        }
        
        if(flag == 1) return 1;
        
        if(dp[i][start] != -1) return dp[i][start];
        
        
        int res = 0;
        string tmp = s.substr(start, i-start+1);
        if(dict.find(tmp) != dict.end())
        {
            res = max(res, solve(s, dict, i+1, i+1, dp));
        }
        
        res = max(res, solve(s, dict, start, i+1, dp));
        
        return dp[i][start] = res;
    }
    
    
    bool wordBreak(string s, vector<string>& word) {
        
        unordered_set<string> dict;
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, -1));
        
        for(int i=0; i<word.size(); i++)
        {
            dict.insert(word[i]);
        }
        
        return solve(s, dict, 0, 0, dp);
        
    }
};