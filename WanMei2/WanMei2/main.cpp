#include <stdio.h>
void ball(int w, int h, int x, int n)
{
    for (int i=1; i<=n; i++) {
        int tempEndX = 0;
        int count = 0; // 碰撞次数
        bool isRight = true; // 下一次方向
        if (isRight) {
            tempEndX = x + 2 * h;
        } else {
            if (2 * h >= x) {
                tempEndX = 2 * h - x;
                count = 1;
            } else {
                tempEndX = x - 2 * h;
                count = 1;
            }
        }
        
        while (tempEndX >= w) {
            count++;
            tempEndX -= w;
        }
        
        if (count % 2 == 1) {
            isRight = isRight ^ 1;
        }
        
        if (isRight) {
            printf("%d ", tempEndX);
        } else {
            tempEndX = w - tempEndX;
            printf("%d ", tempEndX);
        }
        x = tempEndX;
    }
}

int main()
{
    int w, h, x, n;
    while(scanf("%d%d%d%d", &w, &h, &x, &n) != EOF) {
        ball(w, h, x, n);
    }
}
