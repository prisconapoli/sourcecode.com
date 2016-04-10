#include <cstdio>
#include <cstring>
using namespace std;

const static int MAX = 1000000;
typedef long int Cache[MAX];
Cache cache;

inline long int cicleLength(long int n) {
    long int length = 0;
    long int orig = n;
    while (true) {
        if (n < MAX && cache[n - 1]) {
            length += cache[n -1];
            break;
        } else {
            if (n & 1) {
                n = (3 * n + 1) >> 1;
                length += 2;
            } else {
                n = n >> 1;
                length++;
            }
        }
    }
    if (!cache[orig - 1])
        cache[orig - 1] = length;

    return length;
}

inline long calculate(int i, int j) {
    long int max = 0;
    for (int counter = i; counter <=j; counter++) { 
        long int t = cicleLength(counter);
        if (t > max)
            max = t;
    }
    return max; 
}

int main() {
    cache[0] = 1;
    int i = 0;
    int j = 0;
    do {
        if (scanf("%d %d", &i, &j) == EOF)
            break;
        printf("%d %d %ld\n",i, j, ( i < j )? calculate(i,j) : calculate(j, i));
    } while (true);
}
