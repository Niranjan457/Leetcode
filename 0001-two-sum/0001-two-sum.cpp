class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int>mpp;
          int n = nums.size();
          vector<int>ans;
         for(int i=0;i<n;i++)
         {
             int compliment =target-nums[i];
             if(mpp.find(compliment)!=mpp.end())
             {
                ans.push_back(mpp[compliment]);
                ans.push_back(i);
                return ans;
             }
             mpp[nums[i]]=i;
         }
        
         return {};
    }
};