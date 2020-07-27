class Solution {
public:
    map <int, string> mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int r = rand();
        while(mp.find(r) != mp.end())
            r = rand();
        mp[r] = longUrl;
        return "http://tinyurl.com/" + to_string(r);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl = shortUrl.substr(19);
        return mp[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
