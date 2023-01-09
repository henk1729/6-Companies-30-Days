class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0, exponentOf5=1, num;
        while((num=(int)pow(5, exponentOf5))<=n){
            ans+=n/num;
            exponentOf5++;
        }
        return ans;
    }
};
