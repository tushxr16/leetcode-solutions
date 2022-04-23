class Solution {
public:
    map<string,string> mp;
    int i=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = "http://tinurl.com/"+to_string(i);
        mp.insert({s,longUrl});
        i++;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));