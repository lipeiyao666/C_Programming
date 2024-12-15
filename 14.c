#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct list_item {
    int data;
    struct list_item *next;
} list_item;

// 释放链表空间的函数
void erase_list(list_item *head) {
    list_item *current = head;
    list_item *next;

    while (current!= NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
int main() {
    // 创建一个简单的链表进行测试
    list_item *head = (list_item *)malloc(sizeof(list_item));
    list_item *node2 = (list_item *)malloc(sizeof(list_item));
    list_item *node3 = (list_item *)malloc(sizeof(list_item));

    head->data = 1;
    head->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 3;
    node3->next = NULL;

    // 调用函数释放链表空间
    erase_list(head);

    return 0;
}
