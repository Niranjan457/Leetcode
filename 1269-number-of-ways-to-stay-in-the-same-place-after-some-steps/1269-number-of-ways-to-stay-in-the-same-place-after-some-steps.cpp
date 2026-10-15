class Solution {

       int mod=1e9+7;

       int solve(int idx,int steps, int pos, int arrLen,vector<vector<int>>&dp)
       { 
          
        //basecase 
           if(pos<0 || pos>=arrLen)
              return 0;
          if(idx==steps)
            {
                if(pos==0)
                   return 1;
                else
                 return 0;
            }
              if(dp[idx][pos]!=-1)
                  return dp[idx][pos];
            int ans=0;
        ans=(ans+solve(idx+1,steps,pos+1,arrLen,dp))%mod;
        ans=(ans+solve(idx+1,steps,pos-1,arrLen,dp))%mod;
        ans=(ans+solve(idx+1,steps,pos,arrLen,dp))%mod;
         return dp[idx][pos]= ans;
       }
public:
    int numWays(int steps, int arrLen) {
         int n = min(arrLen, steps / 2 + 1);
         vector<vector<int>>dp(steps+1,vector<int>(n,-1));
        return solve(0,steps,0,n,dp);
        
    }
};