class Solution {
public:
    struct StringHash
    {
        char hash[26];
        
        StringHash(const string& str)
        {
            fill(hash, hash+26, 0);
            for(auto& ch : str)
                ++ hash[ch - 'a'];
        }
        
        bool operator<(const StringHash& sh) const
        {
            for(size_t i = 0; i < 26; ++i)
                if ( this->hash[i] < sh.hash[i] )
                    return true;
                else if ( this->hash[i] > sh.hash[i] )
                    return false;
            return false;
        }
    };

    vector<vector<string>> groupAnagrams(vector<string> &strs) 
    {
        map<StringHash, vector<string>> hash_map;
        
        for (auto &s : strs) {
            hash_map[StringHash(s)].push_back(s);
        }
        vector<vector<string>> result;
        for (auto &pair : hash_map) {
            result.push_back(pair.second);
        }
        return result;
    }
};
