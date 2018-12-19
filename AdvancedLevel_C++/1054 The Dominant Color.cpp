#include <iostream>
#include <map>

using namespace std;

int main() {
    int m, n;
    int image[610][810];
    map<int, int> mmap;
    scanf("%d %d", &m, &n);
    int half = m * n / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &image[i][j]);
            mmap[image[i][j]]++;
            if (mmap[image[i][j]] > half) {
                printf("%d", image[i][j]);
                return 0;
            }
        }
    }

    return 0;
}
