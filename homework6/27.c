c
  
#include <stdio.h>
#include <stdlib.h>

// 定义不同颜色对应的ANSI转义序列的前景色代码
#define COLOR_RED    31
#define COLOR_GREEN  32
#define COLOR_YELLOW 33
#define COLOR_BLUE   34
#define COLOR_PURPLE 35
#define COLOR_CYAN   36

// 设置文本颜色的函数，使用ANSI转义序列来改变输出文本的颜色
void setTextColor(int color) {
    printf("\033[%dm", color);
    fflush(stdout);
}

// 输出用星号拼成的彩色的"好"字
void printGood() {
    setTextColor(COLOR_RED);
    printf("  ******  \n");
    setTextColor(COLOR_YELLOW);
    printf(" **    ** \n");
    setTextColor(COLOR_BLUE);
    printf("**      **\n");
    setTextColor(COLOR_GREEN);
    printf("**      **\n");
    setTextColor(COLOR_PURPLE);
    printf(" **    ** \n");
    setTextColor(COLOR_CYAN);
    printf("  ******  \n");
}

// 输出用星号拼成的彩色的"前"字
void printQian() {
    setTextColor(COLOR_BLUE);
    printf("  ******  \n");
    setTextColor(COLOR_GREEN);
    printf(" **    ** \n");
    setTextColor(COLOR_YELLOW);
    printf("**      **\n");
    setTextColor(COLOR_RED);
    printf("  ******  \n");
    setTextColor(COLOR_PURPLE);
    printf("      **  \n");
    setTextColor(COLOR_CYAN);
    printf("      **  \n");
}

// 输出用星号拼成的彩色的"程"字
void printCheng() {
    setTextColor(COLOR_PURPLE);
    printf("  ******  \n");
    setTextColor(COLOR_CYAN);
    printf(" **    ** \n");
    setTextColor(COLOR_BLUE);
    printf("**      **\n");
    setTextColor(COLOR_YELLOW);
    printf(" **    ** \n");
    setTextColor(COLOR_GREEN);
    printf("  ******  \n");
    setTextColor(COLOR_RED);
    printf("      **  \n");
}

int main() {
    printGood();
    printf("\n");
    printQian();
    printf("\n");
    printCheng();
    // 恢复默认颜色
    printf("\033[0m");
    return 0;
}
