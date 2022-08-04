class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ext = q, ref = p;
        int n = gcd(p,q);
        ext /= n, ref /= n;
        int ans = 1;
        if(!(ext&1) && (ref&1)){
            ans = 0;
        }
        else if((ext&1) && !(ref&1)){
            ans = 2;
        }
        return ans;
    }
};