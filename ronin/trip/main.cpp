#include <cstdio>

long round (long x) {
    long adj = x % 10;
    return x - adj;
}

int main() {
    const static int NStudents = 1000;
    int expenses[NStudents];

    int n = 0;
    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }
        int dollars, cents;
        long sum = 0;
        for (int i = 0; i < n ; i++) {
            scanf("%d.%d", &dollars, &cents);
            expenses[i] = (dollars * 1000) + cents * 10;
            sum += expenses[i];
        }
        long avg = sum / n;
        long taken = 0;
        long given = 0;
        for (int i = 0; i < n ; i++) {
            if (expenses[i] > avg) {
                given += round(expenses[i] - avg);
            }
            else if (expenses[i] <= avg) {
                taken += round(avg - expenses[i]);
            }            
        }
        long total = taken > given ? taken : given;
        printf("$%ld.%02ld\n", total/1000, (total % 1000)/10);
    };
}
