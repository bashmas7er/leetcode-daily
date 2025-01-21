class Solution {
enum {
    ZERO = '0',
    ONE = '1'
};
public:
    int maxScore(string s) {
        int score = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ONE) {
                score++;
            }
        }

        int maxScore = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == ZERO) {
                score++;
            } else {
                score--;
            }

            maxScore = max(score, maxScore);
        }

        return maxScore;
    }
};
