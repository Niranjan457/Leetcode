class Solution {
public:
   void backtrack(vector<vector<int>>&res, vector<int>&ans,vector<int>&nums,vector<bool>&valid,int n)
   {
    if(ans.size()==n)
    {
          res.push_back(ans);
          return;
    }

    for(int i=0;i<n;i++)
    {
        if(valid[i]==0)
        {
            ans.push_back(nums[i]);
            valid[i]=1;
            backtrack(res,ans,nums,valid,n);
            //popit;
            valid[i]=0;
            ans.pop_back();
        }
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>>res;
       vector<int>ans;
       int n = nums.size();
       vector<bool>valid(n,0);

       backtrack(res,ans,nums,valid,n);
       return res;

       //tc: O(n!)*O(n)
       //sc: O(n)
        
    }
};