class Solution {
public:
        void nge(vector<int>&ngearr,vector<int>&nums,int n)
        {

             stack<int>st;
             for(int i=n-1;i>=0;i--)
             {
                while(!st.empty() && nums[st.top()]<=nums[i])
                {
                    st.pop();

                }
                ngearr[i]=st.empty()?n:st.top();
                st.push(i);
             }

        }
        void pge(vector<int>&pgearr,vector<int>&nums, int n)
        {
                stack<int>st;
                for(int i=0;i<n;i++)
            
                {
                    while(!st.empty() && nums[st.top()]<nums[i])
                    {
                        st.pop();


                    }
                    pgearr[i]=st.empty()?-1:st.top();
                    st.push(i);
                }
        }
        void pse(vector<int>&psearr, vector<int>&nums, int n)
        {
                stack<int>st;
                for(int i=0;i<n;i++)
                
                {
                    while(!st.empty() && nums[st.top()]>nums[i])
                    {
                        st.pop();
                    }
                    psearr[i]=st.empty()?-1:st.top();
                    st.push(i);
                }
        }
        void nse(vector<int>&nsearr, vector<int>&nums, int n)
        {
                stack<int>st;
                for(int i=n-1;i>=0;i--)
                {
                    while(!st.empty() && nums[st.top()]>=nums[i])
                    {
                        st.pop();
                    }
                    nsearr[i]=st.empty()?n:st.top();
                    st.push(i);
                }
        }

       long long maxsum(vector<int>&nums)
       {
              int n = nums.size();
               vector<int>pgearr(n);
              vector<int>ngearr(n);
              pge(pgearr,nums,n);
              nge(ngearr,nums,n);

              long long total=0;
              for(int i=0;i<n;i++)
              {
                int left = i-pgearr[i];
                int right= ngearr[i]-i;
                total += 1LL* left*right*nums[i];
              }
              return total;


       }

       long long minsum(vector<int>&nums)
       {
        int n = nums.size();
         vector<int>psearr(n);
          vector<int>nsearr(n);
          pse(psearr,nums,n);
          nse(nsearr,nums,n);
          long long total=0;
        for(int i=0;i<n;i++)
        
        {
            int left = i-psearr[i];
            int right = nsearr[i]-i;
            total += 1LL*left*right*nums[i];
        }
        return total;
       }
    long long subArrayRanges(vector<int>& nums) {
       int total=0;
        int n = nums.size();
        //generate all the sumarray
         
         
          return maxsum(nums)-minsum(nums);
    }
};