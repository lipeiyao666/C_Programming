#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 定义圣诞树的层数
#define TREE_LAYERS 10  
// 定义颜色数组，这里选择几种常见的ANSI颜色代码来实现彩色效果（前景色代码）
const int colors[] = {31, 32, 33, 34, 35, 36};  
// 定义闪烁的延迟时间（单位：毫秒），可调整闪烁速度
#define BLINK_DELAY 500  

// 清屏函数，用于在每次更新圣诞树显示前清屏
void clearScreen() {
    system("clear");
}

// 设置文本颜色的函数，使用ANSI转义序列来改变输出文本的颜色
void setTextColor(int color) {
    printf("\033[%dm", color);
    fflush(stdout);
}

// 绘制一层圣诞树的函数
void drawTreeLayer(int layer, int width) {
    int i, j;
    for (i = 0; i < layer; i++) {
        for (j = 0; j < width - i; j++) {
            printf(" ");
        }
        setTextColor(colors[rand() % (sizeof(colors) / sizeof(colors[0]))]);
        for (j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// 绘制树干的函数
void drawTreeTrunk(int trunk_height, int width) {
    int i;
    for (i = 0; i < trunk_height; i++) {
        int spaces = width - 1;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        setTextColor(33);  // 设置树干为黄色
        printf("|\n");
    }
}

int main() {
    int layer_width = TREE_LAYERS * 2 - 1;
    while (1) {
        clearScreen();
        for (int layer = 1; layer <= TREE_LAYERS; layer++) {
            drawTreeLayer(layer, layer_width);
        }
        drawTreeTrunk(3, layer_width);

        // 通过设置不同颜色以及延迟来实现闪烁效果
        for (int color_index = 0; color_index < sizeof(colors) / sizeof(colors[0]); color_index++) {
            setTextColor(colors[color_index]);
            clearScreen();
            for (int layer = 1; layer <= TREE_LAYERS; layer++) {
                drawTreeLayer(layer, layer_width);
            }
            drawTreeTrunk(3, layer_width);
            usleep(BLINK_DELAY * 1000);  // 将毫秒换算成微秒进行延迟
        }

    }
    return 0;
}
