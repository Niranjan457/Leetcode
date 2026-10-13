class Solution {
      private: int check(int mid, vector<int>&nums)
      {   if(mid==nums.size()-1) return 1;
        if(nums[mid]>nums[mid+1])
           return 1;
        else
          return 0;
      }
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(check(mid,nums)==1)
            {
                ans=mid;
                high=mid-1;

            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};