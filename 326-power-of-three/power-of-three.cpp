class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        while(n!=1)
        {
            if(n%3==0)
        {
            n/=3;
        }
        else if(n%3!=0)
        {
            return false;
        }
        else  n=1;
        }
        return true;
    }
};