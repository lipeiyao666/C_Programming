#include <stdio.h>
#include <string.h>

// 函数用于打印单个字符对应的星号图案
void printCharPattern(char ch) {
    switch (ch) {
    case 'A':
        printf(" *****\n*     *\n*     *\n******\n*     *\n*     *\n*     *\n");
        break;
    case 'B':
        printf("******\n*     *\n*     *\n******\n*     *\n*     *\n******\n");
        break;
    case 'C':
        printf(" *****\n*     *\n*       \n*       \n*       \n*     *\n *****\n");
        break;
    case 'D':
        printf("******\n*     *\n*     *\n*     *\n*     *\n*     *\n******\n");
        break;
    case 'E':
        printf("******\n*     *\n******\n*     *\n******\n*     *\n******\n");
        break;
    case 'F':
        printf("******\n*     *\n******\n*     *\n*     *\n*     *\n*     *\n");
        break;
    case 'G':
        printf(" *****\n*     *\n*       \n*  ****\n*    * \n*     *\n *****\n");
        break;
    case 'H':
        printf("*     *\n*     *\n*     *\n******\n*     *\n*     *\n*     *\n");
        break;
    case 'I':
        printf("******\n  *  \n  *  \n  *  \n  *  \n  *  \n******\n");
        break;
    case 'J':
        printf("******\n    * \n    * \n*    *\n*    *\n *****\n*       \n");
        break;
    case 'K':
        printf("*     *\n*    * \n*  *  \n******\n*  *  \n*    * \n*     *\n");
        break;
    case 'L':
        printf("*     *\n*     *\n*     *\n*     *\n*     *\n*     *\n******\n");
        break;case 'L':
        printf("*     *\n*     *\n*     *\n*     *\n*     *\n*     *\n******\n");
        break;
    case 'M':
        printf("*     *\n**   **\n* * * *\n*  *  *\n*     *\n*     *\n*     *\n");
        break;
    case 'N':
        printf("*     *\n**    *\n* *   *\n*  *  *\n*   * *\n*    **\n*     *\n");
        break;
    case 'O':
        printf(" *****\n*     *\n*     *\n*     *\n*     *\n*     *\n *****\n");
        break;
    case 'P':
        printf("******\n*     *\n******\n*     *\n*     *\n*     *\n*     *\n");
        break;
    case 'Q':
        printf(" *****\n*     *\n*     *\n*     *\n*  *  *\n*    * \n *****\n");
        break;
    case 'R':
        printf("******\n*     *\n******\n*  *  *\n*     *\n*    * \n*     *\n");
        break;
    case 'S':
        printf(" *****\n*     *\n******\n *****\n*     *\n*     *\n *****\n");
        break;
    case 'T':
        printf("******\n  *  \n  *  \n  *  \n  *  \n  *  \n  *  \n");
        break;
    case 'U':
        printf("*     *\n*     *\n*     *\n*     *\n*     *\n*     *\n *****\n");
        break;
    case 'V':
        printf("*     *\n*     *\n*     *\n*     *\n*     *\n  *  \n  *  \n");
        break;
    case 'W':
        printf("*     *\n*     *\n* * * *\n**   **\n*     *\n*     *\n*     *\n");
        break; case 'W':
        printf("*     *\n*     *\n* * * *\n**   **\n*     *\n*     *\n*     *\n");
        break;
    case 'X':
        printf("*     *\n*  *  \n  *  \n  *  \n  *  \n*  *  \n*     *\n");
        break;
    case 'Y':
        printf("*     *\n*     *\n  *  \n  *  \n  *  \n*     *\n*     *\n");
        break;
    case 'Z':
        printf("******\n*       \n*       \n*       \n*       \n*       \n******\n");
        break;
    default:
        printf("不支持的字符\n");
        break;
    }
}

// 函数用于将输入字符串转换为星号图案并输出
void stringToPattern(const char *input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        printCharPattern(input[i]);
        if (i < len - 1) {
            printf("\n");
        }
    }
}

    int main() {
    char input[6];
    printf("请输入字符串（不超过5个字符）：");
    scanf("%s", input);

    stringToPattern(input);
    return 0;
    }
                              
