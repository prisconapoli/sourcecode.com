#include <iostream>
#include <fstream>
#include <string>
using namespace std;

constexpr size_t XLowLimit = 1;
constexpr size_t XHighLimit = 20;
constexpr size_t NLowLimit = 1;
constexpr size_t NHighLimit = 100;
constexpr size_t SizeX = XHighLimit - XLowLimit + 1;
constexpr size_t SizeY = NHighLimit - NLowLimit + 1;

template <int x, int y>
struct matrix {
    constexpr matrix() : m() {
    for (size_t j = 0; j < y ; j++)
        for (size_t i = 0; i < x; i++) {
            m[i][j] = !((i + NLowLimit) % (j + XLowLimit));
        }
    }
    int m[x][x];
};

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 0;

    std::ios::sync_with_stdio(false);    
    constexpr auto a = matrix<SizeY, SizeX>();
    ifstream in(argv[1]);
    if (!in)
        return 0;
    int x,y,n;
    while (in >> x >> y >> n ) {
        if (   x < XLowLimit
            || x > XHighLimit 
            || y < XLowLimit 
            || y > XHighLimit 
            || n < NLowLimit
            || n > NHighLimit
        )
        continue;
        cout << "[" << x << " " << y << " " << n << "]" << endl;
        for (int i = 0; i <= n - NLowLimit; i++) {
            if (a.m[i][x - XLowLimit] && a.m[i][y - XLowLimit])
                cout << "FB";
            else if (a.m[i][x - XLowLimit]) 
                cout << "F";
            else if (a.m[i][y - XLowLimit])
                cout << "B";
            else
                cout << (i + NLowLimit);
            if (i < n)
                cout << " ";
        }
        cout << endl;
    }   
}
