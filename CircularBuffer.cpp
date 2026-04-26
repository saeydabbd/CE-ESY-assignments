#include <stdio.h>
#include <string.h>
#include <stdbool.h> //مكتبة من اجل النتائج المنطقية
#define SIZE 12
typedef struct
{
    char buffer[SIZE];
    int head;                 // مؤشر الرأس
    int tail;                 // مؤشر الذيل
    int count;                // عداد
} CircularBuffer;             // تعريف المخزن الدائري
void init(CircularBuffer *cb) // تابع التهيئة
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}
bool isFull(CircularBuffer *cb) // تابع الامتلاء
{
    return cb->count == SIZE;
}
bool isEmpty(CircularBuffer *cb) // تابع الفراغ
{
    return cb->count == 0;
}
void write_cb(CircularBuffer *cb, char data)
{
    if (isFull(cb))
    {
        printf("the buffer is full %c\n", data);
        return;
    }
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE; // هنا يصبح المخزن دائري
    cb->count++;
}
char read_cb(CircularBuffer *cb)
{
    if (isEmpty(cb))
    {
        printf("the buffer is empty\n");
        return '\0';
    }
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}
int main()
{
    CircularBuffer cb;
    init(&cb);
    char name[50];
    char suffix[] = " CE-ESY";
    char fullname[100];
    printf("enter your name: ");
    scanf("%s", name);
    strcpy(fullname, name);
    strcat(fullname, suffix);
    printf("the full name want to store it:%zu : number  %s\n", strlen(fullname), fullname);
    printf("the size of the buffer is: %d\n", SIZE);
    for (int i = 0; i < strlen(fullname); i++)
    {
        write_cb(&cb, fullname[i]);
    }
    printf("the content of the buffer is: ");
    while (!isEmpty(&cb))
    {
        printf("%c", read_cb(&cb));
    }
    if (isEmpty(&cb))
    {
        printf("\nthe buffer is empty\n");
    }
    return 0;
}