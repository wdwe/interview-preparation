#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

typedef vector<vector<int>> matrix;

bool is_magic(matrix &M) {
    for (auto &row: M) {
        int sum = 0;
        for (auto e: row)
            sum += e;
        if (sum != 15)
            return false;
    }

    for (int c = 0; c < 3; ++c) {
        int sum = 0;
        for (int r = 0; r < 3; ++r) {
            sum += M[r][c];
        }
        if (sum != 15)
            return false;
    }

    if (M[0][0] + M[1][1] + M[2][2] != 15)
        return false;

    if (M[0][2] + M[1][1] + M[2][0] != 15)
        return false;

    return true;
}

ostream& operator<<(ostream& out, const matrix &M) {
    for (auto it = M.cbegin(); it != M.cend(); ++it) {
        if (it != M.cbegin()) out << endl;
        auto row = *it;
        for (auto e_it = row.cbegin(); e_it != row.cend(); ++e_it) {
            if (e_it != row.cbegin()) out << ", ";
            out << *e_it;
        }
    }
    out << endl;
    return out;
}

void get_magic_matrices(vector<matrix> &matrices, matrix &M, int idx) {
    if (idx == 9) {
        // cout << M << endl;
        if (is_magic(M))
            matrices.push_back(M);
        return;
    }
    int r = idx / 3, c = idx % 3;
    for (int swap_idx = idx; swap_idx < 9; ++swap_idx) {
        int s_r = swap_idx / 3, s_c = swap_idx % 3;
        // cout << "r:" << r << " c:" << c << endl;
        swap(M[r][c], M[s_r][s_c]);
        get_magic_matrices(matrices, M, idx + 1);
        swap(M[r][c], M[s_r][s_c]);
    }
}

vector<matrix> all_magic_matrices() {
    matrix M(3, vector<int>(3, 0));
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            M[r][c] = r * 3 + c + 1;
        }
    }
    vector<matrix> magic_matrices;
    get_magic_matrices(magic_matrices, M, 0);
    return magic_matrices;
}



int formingMagicSquare(vector<vector<int>> s) {
    vector<matrix> magic_matrices = all_magic_matrices();
    cout << magic_matrices.size() << endl;
    int min_change = INT_MAX;
    for (matrix &M: magic_matrices) {
        int change = 0;
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c) {
                change += abs(M[r][c] - s[r][c]);
            }
        if (change < min_change)
            min_change = change;
    }
    return min_change;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
