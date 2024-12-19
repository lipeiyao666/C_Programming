#include <stdio.h>
#include <unistd.h>  // 用于usleep函数，实现延迟效果

// 定义模拟的LED数量
#define LED_COUNT 10  
// 控制动画的延迟时间（单位：毫秒），可以根据实际调整速度
#define DELAY_TIME 300  

// 清屏函数，使用system("clear")在Linux下清屏
void clearScreen() {
    system("clear");
}

// 设置光标位置的函数，使用ANSI转义序列来控制
void setCursorPosition(int row, int col) {
    printf("\033[%d;%df", row, col);
    fflush(stdout);
}

int main() {
    char leds[LED_COUNT];
    int i, j;

    while (1) {
        for (i = 0; i < LED_COUNT; i++) {
            // 初始化所有LED为熄灭状态（用空格表示）
            for (j = 0; j < LED_COUNT; j++) {
                leds[j] =' ';
            }
            // 将当前位置的LED设置为点亮（用*表示）
            leds[i] = '*';

            clearScreen();
            for (j = 0; j < LED_COUNT; j++) {
                setCursorPosition(0, j * 2);  // 假设每个LED占据两个字符位置宽度，这里简单调整水平坐标，从第0行开始显示
                printf("%c", leds[j]);
            }
            // 使用usleep函数实现延迟，将毫秒换算成微秒（1毫秒 = 1000微秒）
            usleep(DELAY_TIME * 1000);
        }
    }
    return 0;
}
