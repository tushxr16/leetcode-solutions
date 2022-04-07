class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int s = 1, e = num;
        while(s<=e){
            long long int mid = s + (e-s)/2;
            long long int mid2 = mid*mid;
            if(mid2==num)return true;
            else if(mid2>num)e=mid-1;
            else s = mid+1;
        }
        return false;
    }
};