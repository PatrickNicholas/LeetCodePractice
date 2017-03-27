class Solution {
public:
    string getPermutation(int n, int k) {
        int pTable[10] = {1};
        string result;
        vector<char> numSet;
        for(int i = 1; i <= 9; i++){
            pTable[i] = i * pTable[i - 1];
            numSet.push_back('0'+i);
        }
        while(n > 0){
            int temp = (k - 1) / pTable[n - 1];
            result += numSet[temp];
            numSet.erase(numSet.begin() + temp);
            k = k - temp * pTable[n - 1];
            n--;
        }
        return result;
    }
};
