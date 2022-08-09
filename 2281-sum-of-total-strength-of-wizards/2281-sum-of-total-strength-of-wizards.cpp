class Solution {
public:
    int mod = 1e9 + 7;
    int totalStrength(vector<int>& s) {
        long long res = 0, n = s.size();
        vector<long long> pre1(n+1), pre2(n+1), suf1(n+1), suf2(n+1),st;
        
        for(long long i=0;i<n;i++){
            pre1[i+1] = (pre1[i]+s[i])%mod;
            suf1[i+1] = (suf1[i]+s[i]*(i+1))%mod;
        }
        for(long long i=n-1;i>=0;i--){
            pre2[i] = (pre2[i+1]+s[i])%mod;
            suf2[i] = (suf2[i+1]+s[i]*(n-i))%mod;
        }
        
        for(long long i=0;i<=n;i++){
            while(!st.empty() && (i==n || s[st.back()]>=s[i])){
                long long top = st.back();
                st.pop_back();
                long long l = st.empty()?0:st.back()+1;
                long long sl = (mod+suf1[top+1]-suf1[l]-l*(pre1[top+1]-pre1[l])%mod)%mod;
                long long sr = (mod+suf2[top+1]-suf2[i]-(n-i)*(pre2[top+1]-pre2[i]))%mod;
                long long sa = (sr*(top-l+1)+sl*(i-top))%mod;
                res = (res+sa*s[top])%mod;
            }
            st.push_back(i);
        }
        return res;
    }
};