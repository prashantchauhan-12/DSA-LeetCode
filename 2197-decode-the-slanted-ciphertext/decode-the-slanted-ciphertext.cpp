#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        
        int n = encodedText.size();
        int cols = n / rows;
        string res = "";

        // The original text follows a diagonal path starting from each column in the first row
        for (int j = 0; j < cols; ++j) {
            for (int r = 0, c = j; r < rows && c < cols; ++r, ++c) {
                // Calculate linear index: row * total_cols + current_col
                res += encodedText[r * cols + c];
            }
        }

        // The problem usually requires removing trailing spaces added by the grid
        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};