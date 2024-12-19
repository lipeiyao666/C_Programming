#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

// 去除字符串首尾空格
void trimString(char *str) {
    int len = strlen(str);
    int i = 0, j = len - 1;

    while (isspace(str[i])) {
        i++;
    }
    while (isspace(str[j])) {
        j--;
    }

    if (j < i) {
        str[0] = '\0';
        return;
    }

    int k = 0;
    for (; i <= j; i++) {
        str[k++] = str[i];
    }
    str[k] = '\0';
}

// 比较两个字符串（不区分大小写）
int compareStringsIgnoreCase(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (tolower(*s1)!= tolower(*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2; // 存储所有单词及出现次数信息的结构体
    typedef struct {
        char *word;
        int totalCount;
        int *lineCounts;
    } WordInfo;

    // 动态分配存储单词信息的数组
    WordInfo *wordsInfo = (WordInfo *)malloc(lineCount * sizeof(WordInfo));
    if (wordsInfo == NULL) {
        perror("内存分配失败");
        return 1;
    }

    int wordInfoCount = 0;

    // 处理每一行输入
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
-- 插入 --                                                // 存储所有单词及出现次数信息的结构体
    typedef struct {
        char *word;
        int totalCount;
        int *lineCounts;
    } WordInfo;

    // 动态分配存储单词信息的数组
    WordInfo *wordsInfo = (WordInfo *)malloc(lineCount * sizeof(WordInfo));
    if (wordsInfo == NULL) {
        perror("内存分配失败");
        return 1;
    }

    int wordInfoCount = 0;

    // 处理每一行输入
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
                if (wordsInfo[wordInfoCount].lineCounts == NULL) { // 存储所有单词及出现次数信息的结构体
    typedef struct {
        char *word;
        int totalCount;
        int *lineCounts;
    } WordInfo;

    // 动态分配存储单词信息的数组
    WordInfo *wordsInfo = (WordInfo *)malloc(lineCount * sizeof(WordInfo));
    if (wordsInfo == NULL) {
        perror("内存分配失败");
        return 1;
    }

    int wordInfoCount = 0;

    // 处理每一行输入
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
-- 插入 --                                               if (!found) {
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

-- 插入 --                                                                                                                                                     160,1        底端
-- 插入 --                                               
