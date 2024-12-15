 while (*s1 && *s2) {
        if (tolower(*s1)!= tolower(*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

int main() {
    char *inputLines[MAX_LINES];
    int lineCount = 0;

    printf("请输入英文字符串，输入END结束输入：\n");

    // 读取用户输入
    while (lineCount < MAX_LINES) {
        inputLines[lineCount] = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (inputLines[lineCount] == NULL) {
            perror("内存分配失败");
            return 1;
        }

        fgets(inputLines[lineCount], MAX_LENGTH, stdin);

        // 去除换行符
        int len = strlen(inputLines[lineCount]);
        if (inputLines[lineCount][len - 1] == '\n') {
            inputLines[lineCount][len - 1] = '\0';
        }

        if (strcmp(inputLines[lineCount], "END") == 0) {
            break;
        }

        lineCount++;
    }
                                                                             while (*s1 && *s2) {
        if (tolower(*s1)!= tolower(*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

int main() {
    char *inputLines[MAX_LINES];
    int lineCount = 0;

    printf("请输入英文字符串，输入END结束输入：\n");

    // 读取用户输入
    while (lineCount < MAX_LINES) {
        inputLines[lineCount] = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (inputLines[lineCount] == NULL) {
            perror("内存分配失败");
            return 1;
        }

        fgets(inputLines[lineCount], MAX_LENGTH, stdin);

        // 去除换行符
        int len = strlen(inputLines[lineCount]);
        if (inputLines[lineCount][len - 1] == '\n') {
            inputLines[lineCount][len - 1] = '\0';
        }

        if (strcmp(inputLines[lineCount], "END") == 0) {
            break;
        }

        lineCount++;
    }
                                                                             while (*s1 && *s2) {
        if (tolower(*s1)!= tolower(*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

int main() {
    char *inputLines[MAX_LINES];
    int lineCount = 0;

    printf("请输入英文字符串，输入END结束输入：\n"); // 处理每一行输入
    for (int i = 0; i < lineCount; i++) {
        char *words[MAX_LENGTH];
        int wordCount = 0;

        // 分割字符串为单词
        splitString(inputLines[i], words, &wordCount);

        // 处理每个单词
        for (int j = 0; j < wordCount; j++) {
            int found = 0;
            for (int k = 0; k < wordInfoCount; k++) {
                if (compareStringsIgnoreCase(words[j], wordsInfo[k].word)) {
                    wordsInfo[k].totalCount++;
                    wordsInfo[k].lineCounts[i]++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                wordsInfo[wordInfoCount].word = words[j];
                wordsInfo[wordInfoCount].totalCount = 1;
                wordsInfo[wordInfoCount].lineCounts = (int *)malloc(lineCount * sizeof(int));
                if (wordsInfo[wordInfoCount].lineCounts == NULL) {
                    perror("内存分配失败");
                    return 1;
                }
                for (int l = 0; l < lineCount; l++) {
                    wordsInfo[wordInfoCount].lineCounts[l] = 0;
                }
                wordsInfo[wordInfoCount].lineCounts[i] = 1;
                wordInfoCount++;
            }
        }
    }

    // 输出结果
    printf("\n统计结果如下：\n");
    for (int i = 0; i < wordInfoCount; i++) {
        printf("单词：%s\n", wordsInfo[i].word);
        printf("总共出现次数：%d\n", wordsInfo[i].totalCount);
                                                              printf("在每一行出现的次数：");
        for (int j = 0; j < lineCount; j++) {
            printf("%d ", wordsInfo[i].lineCounts[j]);
        }
        printf("\n\n");
    }

    // 释放内存
    for (int i = 0; i < lineCount; i++) {
        free(inputLines[i]);
    }

    for (int i = 0; i < wordInfoCount; i++) {
        free(wordsInfo[i].lineCounts);
    }

    free(wordsInfo);

    return 0;
}
                                                                                                                                                               159,1        底端

    // 读取用户输入
    while (lineCount < MAX_LINES) {
        inputLines[lineCount] = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (inputLines[lineCount] == NULL) {
            perror("内存分配失败");
            return 1;
        }

        fgets(inputLines[lineCount], MAX_LENGTH, stdin);

        // 去除换行符
        int len = strlen(inputLines[lineCount]);
        if (inputLines[lineCount][len - 1] == '\n') {
            inputLines[lineCount][len - 1] = '\0';
        }

        if (strcmp(inputLines[lineCount], "END") == 0) {
            break;
        }

        lineCount++;
    }
                                                                             while (*s1 && *s2) {
        if (tolower(*s1)!= tolower(*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

int main() {
    char *inputLines[MAX_LINES];
    int lineCount = 0;

    printf("请输入英文字符串，输入END结束输入：\n");

    // 读取用户输入
    while (lineCount < MAX_LINES) {
        inputLines[lineCount] = (char *)malloc(MAX_LENGTH * sizeof(char));
        if (inputLines[lineCount] == NULL) {
            perror("内存分配失败");
            return 1;
        }

        fgets(inputLines[lineCount], MAX_LENGTH, stdin);

        // 去除换行符
        int len = strlen(inputLines[lineCount]);
        if (inputLines[lineCount][len - 1] == '\n') {
            inputLines[lineCount][len - 1] = '\0';
        }

        if (strcmp(inputLines[lineCount], "END") == 0) {
            break;
        }

        lineCount++;
    }
                                                                            
