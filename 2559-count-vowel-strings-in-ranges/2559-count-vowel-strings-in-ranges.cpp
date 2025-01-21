class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    bool isVowelString(string& word) {
        char front = word[0];
        char back = word.back();

        return isVowel(front) && isVowel(back);
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> preCount(words.size() + 1, 0);

        for(int i = 0; i < words.size(); i++) {
            preCount[i+1] = preCount[i];
            if (isVowelString(words[i])) {
                preCount[i+1]++;
            }
        }

        vector<int> result(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            int left = queries[i][0], right = queries[i][1];
            result[i] = (preCount[right+1] - preCount[left]);
        }
        return result;
    }
};