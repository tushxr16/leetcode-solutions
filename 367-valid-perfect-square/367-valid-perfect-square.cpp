class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int lo = 1, hi = num;
        while(lo<=hi){
            long long int mid = (lo+hi)/2;
            if(mid*mid==num)return true;
            else if(mid*mid>num)hi = mid-1;
            else lo = mid+1;
        }
        return false;
    }
};