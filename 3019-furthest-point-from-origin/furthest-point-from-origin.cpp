class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dist = 0;
        int left = count(moves.begin(), moves.end(), 'L');
        int right = count(moves.begin(), moves.end(), 'R');
        int open = count(moves.begin(), moves.end(), '_');

        return abs(left - right) + open;
    }
};