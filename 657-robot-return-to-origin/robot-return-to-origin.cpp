class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt1 = 0, cnt2 = 0;
        for (char ch : moves) {
            if (ch == 'L')
                cnt1++;
            else if (ch == 'R')
                cnt1--;
            else if (ch == 'U')
                cnt2++;
            else if (ch == 'D')
                cnt2--;
        }
        return cnt1 == 0 && cnt2 == 0;
    }
};