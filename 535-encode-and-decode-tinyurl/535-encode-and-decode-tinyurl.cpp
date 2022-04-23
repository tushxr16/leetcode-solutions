class Solution {
public:
    vector<string> v;
    int i=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = "http://tinurl.com/"+to_string(i);
        v.push_back(longUrl);
        i++;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string num;
        for(int i=shortUrl.size();i>-1;i--)
            if(shortUrl[i]!='/')
                num.push_back(shortUrl[i]);
            else break;
        for(int i=0;i<num.size()/2;i++)swap(num[i],num[num.size()-1-i]);
        return v[stoi(num)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));