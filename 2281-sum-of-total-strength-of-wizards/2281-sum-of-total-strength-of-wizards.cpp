class Solution {
public:
    int mod = 1e9 + 7;
    int totalStrength(vector<int>& s) {
        long long res = 0, size = s.size();
    vector<int> first1(size + 1), last1(size + 1),first2(size + 1), last2(size + 1),st; 
    for (long long i = 0; i < size; i++) 
        first1[i + 1] = (first1[i] + s[i]) % mod, last1[i + 1] = (last1[i] + (i + 1) * s[i]) % mod;
    for (int i = size - 1; i >= 0; i--) 
        first2[i] = (first2[i + 1] + s[i]) % mod, last2[i] = (last2[i + 1] + (size - i) * s[i]) % mod; 
    for (int start = 0; start <= size; start++) {
        while(!st.empty() && (start == size || s[st.back()] >= s[start])) {
            int top_last = st.back();
            st.pop_back();
			long long left;
			if(st.empty()) left = 0;
			else left = st.back()+1;
            long long sum_of_left = (mod + last1[top_last + 1] - last1[left] - left * (first1[top_last + 1] - first1[left]) % mod) % mod;
            long long sum_of_right = (mod + last2[top_last + 1] - last2[start] - (size - start) * (first2[top_last + 1] - first2[start])) % mod;
            long long sum_of_all = (sum_of_right * (top_last - left + 1) + sum_of_left * (start - top_last)) % mod;
			res = (res+sum_of_all * s[top_last]) % mod;
        }
        st.push_back(start);
    }
    return res;
    }
};