#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 100;

char field[SIZE + 2][SIZE + 2];
char buffer[SIZE * SIZE];
void printField(char field[][SIZE + 2], int i, int n, int m)
{
    printf("Field #%d:\n", i);
    int l = 0;
    for (int u=1; u <=n; u++){
        for (int v=1;  v<=m; v++) {
            buffer[l++]=field[u][v];
        }
        buffer[l++]='\n';
    }
    buffer[l]='\0';
    printf("%s",buffer);
}

void loadField(char field[][SIZE + 2], int n, int m)
{
    for (int u=1; u<=n; u++) {
        for (int v=1;  v<=m; v++) {
            char c = getchar();
            if ('*' == c) {
                field[u][v] = c;
                for (int uu = u - 1; uu <= u + 1; uu++) 
                    for (int vv = v - 1 ; vv <= v + 1; vv++)
                        if ('*' != field[uu][vv])
                            field[uu][vv]++;
            }
        }
        getchar();
    }
}

int main() {
    int n = 0;
    int m = 0;
    int i = 0;

    while (scanf("%d %d", &n, &m)){
        if (!m && !n)
            break;
        if (i)
            printf("\n");
        memset(field, '0', sizeof(field[0][0]) * (SIZE + 2) * (SIZE + 2));
        getchar();
        loadField(field, n, m);
        printField(field, ++i, n, m);
         
    };
}
