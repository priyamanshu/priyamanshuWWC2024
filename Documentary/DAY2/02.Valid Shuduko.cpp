#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Initialize hash sets for rows, columns, and sub-boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        // Iterate through the board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];

                // Skip empty cells
                if (num == '.') continue;

                // Calculate the index of the 3x3 sub-box
                int boxIndex = (i / 3) * 3 + j / 3;

                // Check for duplicates in the row, column, or sub-box
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                    return false;
                }

                // Insert the number into the corresponding row, column, and sub-box sets
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }

        return true; // Board is valid
    }
};

int main() {
    Solution solution;

    // Example Sudoku board (partially filled)
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool isValid = solution.isValidSudoku(board);

    cout << (isValid ? "The Sudoku board is valid." : "The Sudoku board is invalid.") << endl;

    return 0;
}