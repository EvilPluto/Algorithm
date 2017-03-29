//#include <stdio.h>
//#include <stdlib.h>
//
//void get_time(int *hour, int *min, int *second, int const time_diff_second)
//{
//    int secondForAdd = time_diff_second;
//    int minForAdd = 0;
//    int hourForAdd = 0;
//    
//    if (time_diff_second >= 0) {
//        *second += secondForAdd;
//        while (*second >= 60) {
//            *second -= 60;
//            minForAdd++;
//        }
//        *min += minForAdd;
//        while (*min >= 60) {
//            *min -= 60;
//            hourForAdd++;
//        }
//        *hour += hourForAdd;
//        while (*hour >= 24) {
//            *hour -= 24;
//        }
//    } else {
//        *second += secondForAdd;
//        while (*second < 0) {
//            *second += 60;
//            minForAdd--;
//        }
//        *min += minForAdd;
//        while (*min < 0) {
//            *min += 60;
//            hourForAdd--;
//        }
//        *hour += hourForAdd;
//        while (*hour < 0) {
//            *hour += 24;
//        }
//    }
//}
//
//int main()
//{
//    int hour, min, second, time_diff_second;
//    
//    while (scanf("%d:%d:%d,%d", &hour, &min, &second, &time_diff_second) != EOF) {
//        
//        get_time(&hour, &min, &second, time_diff_second);
//        printf("%02d %02d %02d\n", hour, min, second);
//    }
//}

#include <stdio.h>

void ball(int w, int h, int x, int n)
{
    int y = 0;
    int vx = 1, vy = 1;
    
    while(n > 0) {
        
        x += vx;
        y += vy;
        
        if (x >= w || x <= 0) {
            vx = -vx;
        }
        
        if (y >= h || y <= 0) {
            vy = -vy;
        }
        
        if (y <= 0) {
            printf("%d ", x);
            --n;
        }
    }
    
    printf("\n");
}

int main()
{
    int w, h, x, n;
    while(scanf("%d%d%d%d", &w, &h, &x, &n) != EOF) {
        ball(w, h, x, n);
    }
}
