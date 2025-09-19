class Spreadsheet {
public:
    Spreadsheet(int rows) {
        cells_.reserve(26 * rows);
    }

    void setCell(string cell, int value) { cells_[cell] = value; }

    void resetCell(string cell) { cells_[cell] = 0; }

    int getValue(string formula) {
        auto [x, y] = parseFormula_(formula);
        int a = 0, b = 0;

        if (isdigit(x[0]))
            a = stoi(x);
        else if (cells_.contains(x))
            a = cells_[x];

        if (isdigit(y[0]))
            b = stoi(y);
        else if (cells_.contains(y))
            b = cells_[y];

        return a + b;
    }

private:
    pair<string, string> parseFormula_(string formula) {
        pair<string, string> res;
        bool split = false;
        string cur;
        for (int i = 1; i < formula.size(); ++i) {
            if (formula[i] == '+') {
                res.first = cur;
                cur = "";
                continue;
            }
            cur += formula[i];
        }
        res.second = cur;
        return res;
    };

    unordered_map<string, int> cells_;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */