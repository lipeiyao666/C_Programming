#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For usleep function

#define WIDTH 80
#define HEIGHT 24
#define RAIN_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define DELAY 50000 // usleep takes microseconds
#define RAIN_PROBABILITY 0.3 // 控制雨点的密集程度，范围0.0到1.0

// ANSI escape code to clear the screen and set the text color
#define CLEAR_SCREEN_AND_SET_COLOR "\033[H\033[J\033[32m" // Green text

void clearScreenAndSetColor() {
    printf("%s", CLEAR_SCREEN_AND_SET_COLOR);
}

void drawRain(char screen[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void updateRain(char screen[HEIGHT][WIDTH]) {
    // Move rain down and reset top row with random characters based on probability
    for (int i = HEIGHT - 1; i > 0; i--) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = screen[i - 1][j];
        }
    }
    // Randomly place characters in the top row with a certain probability
    for (int j = 0; j < WIDTH; j++) {
        if ((double)rand() / RAND_MAX < RAIN_PROBABILITY) {
            screen[0][j] = RAIN_CHARS[rand() % (sizeof(RAIN_CHARS) - 1)];
        } else {
            screen[0][j] = ' '; // No rain drop here
        }
    }       }
    }
}

int main() {
    srand(time(NULL));
    char screen[HEIGHT][WIDTH];

    // Initialize the screen with spaces
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }

    while (1) {
        updateRain(screen);
        clearScreenAndSetColor();
        drawRain(screen);
        usleep(DELAY);
    }

    return 0;
}
