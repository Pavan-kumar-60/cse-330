#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

#define CLEAN_BOARD "................"
#define Z(x, i, j) x[(i)+(j)*4]

void debug(const string B) {
    cout << B[0] << B[1] << B[2] << B[3] << endl;
    cout << B[4] << B[5] << B[6] << B[7] << endl;
    cout << B[8] << B[9] << B[10]<< B[11] << endl;
    cout << B[12]<< B[13]<< B[14]<< B[15] << endl;
}

bool has_figure(const string &b, char c) {
    return b.find(c) != std::string::npos;
}

vector<string> knight_moves(const string &B, int color, int i, int j) {
    vector<string> res;
    int sign = color == 1 ? 0 : 32;
    
    if (i+2 < 4 && j+1 < 4)
        if ((Z(B,i+2,j+1)&32) != sign || Z(B,i+2,j+1) == '.') { string M(B); Z(M,i+2,j+1) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    if (i+2 < 4 && j-1 >= 0)
        if ((Z(B,i+2,j-1)&32) != sign || Z(B,i+2,j-1) == '.') { string M(B); Z(M,i+2,j-1) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    if (i+1 < 4 && j+2 < 4)
        if ((Z(B,i+1,j+2)&32) != sign || Z(B,i+1,j+2) == '.') { string M(B); Z(M,i+1,j+2) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    if (i+1 < 4 && j-2 >= 0)
        if ((Z(B,i+1,j-2)&32) != sign || Z(B,i+1,j-2) == '.') { string M(B); Z(M,i+1,j-2) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    if (i-2 >= 0 && j+1 < 4)
        if ((Z(B,i-2,j+1)&32) != sign || Z(B,i-2,j+1) == '.') { string M(B); Z(M,i-2,j+1) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    if (i-2 >= 0 && j-1 >= 0)
        if ((Z(B,i-2,j-1)&32) != sign || Z(B,i-2,j-1) == '.') { string M(B); Z(M,i-2,j-1) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    if (i-1 >= 0 && j+2 < 4)
        if ((Z(B,i-1,j+2)&32) != sign || Z(B,i-1,j+2) == '.') { string M(B); Z(M,i-1,j+2) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    if (i-1 >= 0 && j-2 >= 0)
        if ((Z(B,i-1,j-2)&32) != sign || Z(B,i-1,j-2) == '.') { string M(B); Z(M,i-1,j-2) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M); }
    return res;
}

vector<string> bishop_moves(const string &B, int color, int i, int j) {
    vector<string> res;
    int sign = color == 1 ? 0 : 32;
    
    int ii=i-1, jj=j-1;
    while (ii>=0 && jj>=0) {
        if (Z(B,ii,jj) == '.') {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,ii,jj)&32) != sign) {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        --ii;--jj;
    }
    
    ii=i+1, jj=j-1;
    while (ii<4 && jj>=0) {
        if (Z(B,ii,jj) == '.') {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,ii,jj)&32) != sign) {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        ++ii;--jj;
    }
    
    ii=i+1, jj=j+1;
    while (ii<4 && jj<4) {
        if (Z(B,ii,jj) == '.') {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,ii,jj)&32) != sign) {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        ++ii;++jj;
    }
    
    ii=i-1, jj=j+1;
    while (ii>=0 && jj<4) {
        if (Z(B,ii,jj) == '.') {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,ii,jj)&32) != sign) {
            string M(B); Z(M,ii,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        --ii;++jj;
    }
    
    return res;
}

vector<string> rook_moves(const string &B, int color, int i, int j) {
    vector<string> res;
    int sign = color == 1 ? 0 : 32;
    
    int ii=i-1;
    while (ii>=0) {
        if (Z(B,ii,j) == '.') {
            string M(B); Z(M,ii,j) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,ii,j)&32) != sign) {
            string M(B); Z(M,ii,j) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        --ii;
    }

    ii=i+1;
    while (ii<4) {
        if (Z(B,ii,j) == '.') {
            string M(B); Z(M,ii,j) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,ii,j)&32) != sign) {
            string M(B); Z(M,ii,j) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        ++ii;
    }
    
    int jj=j-1;
    while (jj>=0) {
        if (Z(B,i,jj) == '.') {
            string M(B); Z(M,i,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,i,jj)&32) != sign) {
            string M(B); Z(M,i,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        --jj;
    }
    
    jj=j+1;
    while (jj<4) {
        if (Z(B,i,jj) == '.') {
            string M(B); Z(M,i,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
        }
        else if ((Z(B,i,jj)&32) != sign) {
            string M(B); Z(M,i,jj) = Z(M,i,j); Z(M,i,j) = '.'; res.push_back(M);
            break;
        }
        else { break; }
        ++jj;
    }
    
    return res;
}

vector<string> pawn_moves(const string &B, int color, int i, int j) {
    vector<string> res;

    if (color == 1) {
        if (Z(B,i,j+1) == '.') {
            string M(B); Z(M,i,j) = '.';
            if (j == 2) {
                Z(M,i,j+1) = 'B'; res.push_back(M);
                Z(M,i,j+1) = 'R'; res.push_back(M);
                Z(M,i,j+1) = 'N'; res.push_back(M);
            }
            else {
                Z(M,i,j+1) = 'P'; res.push_back(M);
            }            
        }
        if (i!=3 && (Z(B,i+1,j+1) == 'q' || Z(B,i+1,j+1) == 'b' || Z(B,i+1,j+1) == 'r' || Z(B,i+1,j+1) == 'n' || Z(B,i+1,j+1) == 'p')) {
            string M(B); Z(M,i,j) = '.';
            if (j == 2) {
                Z(M,i+1,j+1) = 'B'; res.push_back(M);
                Z(M,i+1,j+1) = 'R'; res.push_back(M);
                Z(M,i+1,j+1) = 'N'; res.push_back(M);
            }
            else {
                Z(M,i+1,j+1) = 'P'; res.push_back(M);
            }            
        }
        if (i!=0 && (Z(B,i-1,j+1) == 'q' || Z(B,i-1,j+1) == 'b' || Z(B,i-1,j+1) == 'r' || Z(B,i-1,j+1) == 'n' || Z(B,i-1,j+1) == 'p')) {
            string M(B); Z(M,i,j) = '.';
            if (j == 2) {
                Z(M,i-1,j+1) = 'B'; res.push_back(M);
                Z(M,i-1,j+1) = 'R'; res.push_back(M);
                Z(M,i-1,j+1) = 'N'; res.push_back(M);
            }
            else {
                Z(M,i-1,j+1) = 'P'; res.push_back(M);
            }            
        }
    }
    else {
        if (Z(B,i,j-1) == '.') {
            string M(B); Z(M,i,j) = '.';
            if (j == 1) {
                Z(M,i,j-1) = 'b'; res.push_back(M);
                Z(M,i,j-1) = 'r'; res.push_back(M);
                Z(M,i,j-1) = 'n'; res.push_back(M);
            }
            else {
                Z(M,i,j-1) = 'p'; res.push_back(M);
            }            
        }
        if (i!=3 && (Z(B,i+1,j-1) == 'Q' || Z(B,i+1,j-1) == 'B' || Z(B,i+1,j-1) == 'R' || Z(B,i+1,j-1) == 'N' || Z(B,i+1,j-1) == 'P')) {
            string M(B); Z(M,i,j) = '.';
            if (j == 1) {
                Z(M,i+1,j-1) = 'b'; res.push_back(M);
                Z(M,i+1,j-1) = 'r'; res.push_back(M);
                Z(M,i+1,j-1) = 'n'; res.push_back(M);
            }
            else {
                Z(M,i+1,j-1) = 'p'; res.push_back(M);
            }            
        }
        if (i!=0 && (Z(B,i-1,j-1) == 'Q' || Z(B,i-1,j-1) == 'B' || Z(B,i-1,j-1) == 'R' || Z(B,i-1,j-1) == 'N' || Z(B,i-1,j-1) == 'P')) {
            string M(B); Z(M,i,j) = '.';
            if (j == 1) {
                Z(M,i-1,j-1) = 'b'; res.push_back(M);
                Z(M,i-1,j-1) = 'r'; res.push_back(M);
                Z(M,i-1,j-1) = 'n'; res.push_back(M);
            }
            else {
                Z(M,i-1,j-1) = 'p'; res.push_back(M);
            }            
        }
    }
    
    return res;
}

vector<string> queen_moves(const string &B, int color, int i, int j) {
    vector<string> res;
    
    vector<string> A1 = bishop_moves(B, color, i, j);
    vector<string> A2 = rook_moves(B, color, i, j);
    
    res.insert(res.end(), A1.begin(), A1.end());
    res.insert(res.end(), A2.begin(), A2.end());
    
    return res;
}

int moves_to_win(const string &B, int depth, int max_depth) {
    if (depth >= max_depth) return 1000000;

    vector<string> moves;
    for(int j=0; j<4; ++j) {
        for(int i=0; i<4; ++i) {
            switch(Z(B, i, j)) {
                case 'Q':
                {
                    vector<string> Q = queen_moves(B, 1, i, j);
                    moves.insert(moves.end(), Q.begin(), Q.end());
                    break;
                }
                case 'N':
                {
                    vector<string> N = knight_moves(B, 1, i, j);
                    moves.insert(moves.end(), N.begin(), N.end());
                    break;
                }
                case 'B':
                {
                    vector<string> Bi = bishop_moves(B, 1, i, j);
                    moves.insert(moves.end(), Bi.begin(), Bi.end());
                    break;
                }
                case 'R':
                {
                    vector<string> R = rook_moves(B, 1, i, j);
                    moves.insert(moves.end(), R.begin(), R.end());
                    break;
                }
                case 'P':
                {
                    vector<string> P = pawn_moves(B, 1, i, j);
                    moves.insert(moves.end(), P.begin(), P.end());
                    break;
                }
            }
        }
    }
    
    int ans = 1000000;
    vector<string> good_moves;
    
    for(string m: moves)
        if (!has_figure(m, 'q'))
            return depth+1;
        
    if (depth+2 > max_depth)
        return ans;
        
    for(string m: moves) {
        vector<string> op_moves;
        for(int j=0; j<4; ++j) {
            for(int i=0; i<4; ++i) {
                switch(Z(m, i, j)) {
                    case 'q':
                    {
                        vector<string> Q = queen_moves(m, 2, i, j);
                        op_moves.insert(op_moves.end(), Q.begin(), Q.end());
                        break;
                    }
                    case 'n':
                    {
                        vector<string> N = knight_moves(m, 2, i, j);
                        op_moves.insert(op_moves.end(), N.begin(), N.end());
                        break;
                    }
                    case 'b':
                    {
                        vector<string> Bi = bishop_moves(m, 2, i, j);
                        op_moves.insert(op_moves.end(), Bi.begin(), Bi.end());
                        break;
                    }
                    case 'r':
                    {
                        vector<string> R = rook_moves(m, 2, i, j);
                        op_moves.insert(op_moves.end(), R.begin(), R.end());
                        break;
                    }
                    case 'p':
                    {
                        vector<string> P = pawn_moves(m, 2, i, j);
                        op_moves.insert(op_moves.end(), P.begin(), P.end());
                        break;
                    }
                }
            }
        }
        
        bool is_good = true;
        for(auto o: op_moves) {
            if (!has_figure(o, 'Q')) {
                is_good = false;
                break;
            }
        }
        
        if (is_good) {
            int ans_next = 0;
            for(auto o: op_moves) {
                ans_next = max(ans_next, moves_to_win(o, depth+2, max_depth));
                if (ans_next > max_depth) break;
            }
            ans = min(ans, ans_next);
        }
    }

    return ans;
}

int main() {
    int T; cin >> T;
    for(int t=0; t<T; ++t) {
        string B(CLEAN_BOARD);
        
        int w,b,m; cin >> w >> b >> m;
        
        for(int i=0; i<w; ++i) {
            char f, col; cin >> f >> col;
            int row; cin >> row;
            B[col-'A' + (row-1)*4] = f;
        }
        for(int i=0; i<b; ++i) {
            char f, col; cin >> f >> col;
            int row; cin >> row;
            B[col-'A' + (row-1)*4] = f + ('a' - 'A');
        }

        cout << (moves_to_win(B, 0, m%2==0 ? m-1 : m) <= m ? "YES" : "NO") << endl;
    }
    return 0;
}
