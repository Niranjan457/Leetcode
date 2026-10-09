class Solution {
public:

   void pse(vector<int>&pssearr,vector<int>&arr, int n)
   {
      stack<int>st;

      for(int i=0;i<n;i++)
      {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();

        }
        pssearr[i]=st.empty()?-1:st.top();
        st.push(i);
      }
   }
      void nse(vector<int>&nsearr,vector<int>&arr, int n)
      {
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            nsearr[i]=st.empty()?n:st.top();
            st.push(i);
        }
      }
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        int mod = (int)(1e9+7);

        vector<int>nsearr(n);
        vector<int>pssearr(n);
        nse(nsearr,arr,n);
        pse(pssearr,arr,n);
      long long total=0;

        for(int i=0;i<n;i++)
        {
            int left = i-pssearr[i];
            int right = nsearr[i]-i;
            total = (total+(1LL*left*right*arr[i])%mod)%mod;
        }


        return (int)total;

    
    }
};