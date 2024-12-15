include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 窗口宽度和高度
#define WIDTH 800
#define HEIGHT 600

// 代码雨的字符数量
#define CHAR_COUNT 150

// 结构体定义，用于表示每个字符的属性
typedef struct {
    int x;
    int y;
    int speed;
    char ch;
    int visible;
} CharInfo;

// 绘制单个字符（绿色）
void drawChar(HDC hdc, int x, int y, char ch) {
    SetTextColor(hdc, RGB(0, 255, 0));
    SetBkMode(hdc, TRANSPARENT);
    TextOutA(hdc, x, y, &ch, 1);
}

// 更新并绘制代码雨
void updateAndDrawCodeRain(HDC hdc, CharInfo *chars) {
    for (int i = 0; i < CHAR_COUNT; i++) {
        if (chars[i].visible) {
            drawChar(hdc, chars[i].x, chars[i].y, chars[i].ch);
            chars[i].y += chars[i].speed;
            if (chars[i].y > HEIGHT) {
                chars[i].y = 0;
                chars[i].x = rand() % WIDTH;
            }
        } else {
            if (rand() % 100 < 5) {  // 一定概率让字符重新出现
                chars[i].visible = 1;
                chars[i].x = rand() % WIDTH; } else {
            if (rand() % 100 < 5) {  // 一定概率让字符重新出现
                chars[i].visible = 1;
                chars[i].x = rand() % WIDTH;
                chars[i].y = 0;
                chars[i].speed = rand() % 3 + 1;
                chars[i].ch = (rand() % 94) + 33;  // 生成可打印字符
            }
        }
    }
}

// 窗口过程函数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int main() {
    srand((unsigned int)time(NULL));if (!hwnd) {
        MessageBox(NULL, TEXT("创建窗口失败"), szAppName, MB_OK | MB_ICONERROR);
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    CharInfo chars[CHAR_COUNT];
    for (int i = 0; i < CHAR_COUNT; i++) {
        chars[i].visible = 0;
    }

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        HDC hdc = GetDC(hwnd);
        updateAndDrawCodeRain(hdc, chars);
        ReleaseDC(hwnd, hdc);
        Sleep(30);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
                                                              
    static TCHAR szAppName[] = TEXT("CodeRain");
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsWnds = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = GetModuleHandle(NULL);
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockBrush(BLACK_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass)) {
        MessageBox(NULL, TEXT("注册窗口类失败"), szAppName, MB_OK | MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName, TEXT("代码雨"), WS_OVERLAPPEDWINDOW,
                         CW_USEDEFAULT, CW_USEDEFAULT, WIDTH, HEIGHT,
                         NULL, NULL, GetModuleHandle(NULL), NULL);
