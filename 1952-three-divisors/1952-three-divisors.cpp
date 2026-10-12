class Solution {
public:
     bool isprime(int n)
     {
       int  count=0;
        for(int i=1;i<=n/i;i++)
        {
            if(n%i==0)
            {
                count+=2;
            }

        }
        if(count>2)
         return false;
        else
          return true;
     }
    bool isThree(int n) {
          
           if(n==1)
             return false;
             int x = sqrt(n);

             if(1LL*x*x==n)
             {
                if(isprime(x))
                {
                    return true;
                }
                else
                return false;
             }
             else
               return false;
            
               
        

          

       
    }
};