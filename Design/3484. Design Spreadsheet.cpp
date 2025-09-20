/*------------------------------------
Data Structures Used: Vector
  Time Complexity: O(1), O(1), O(1)
  Space Complexity: O(n)
-------------------------------------*/

class Spreadsheet {
public:
    vector<vector<int>> xls;

    Spreadsheet(int rows) {
        xls.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = (cell[0] - 'A');
        int row = stoi(cell.substr(1)) - 1;
        xls[row][col] = value;
    }

    int getCellValue(string cell) {
        int col = (cell[0] - 'A');
        int row = stoi(cell.substr(1)) - 1; 
        return xls[row][col];
    }

    bool isReference(string &operand) {
        return (operand[0] >= 'A' && operand[0] <= 'Z'); 
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int getValue(string formula) {
        if (formula[0] != '=') return stoi(formula);

        formula = formula.substr(1);

        int plusPos = formula.find('+');
        string firstOperand = formula.substr(0, plusPos);
        string secondOperand = formula.substr(plusPos + 1);

        int firstVal = isReference(firstOperand) ? getCellValue(firstOperand) : stoi(firstOperand);
        int secondVal = isReference(secondOperand) ? getCellValue(secondOperand) : stoi(secondOperand);

        return firstVal + secondVal;
    }
};

/*
Question Link: https://leetcode.com/problems/design-spreadsheet/
Author: M.R.Naganathan
*/
