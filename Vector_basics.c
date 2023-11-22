#include <stdio.h>
#include <stdlib.h>

void fail()
{
    printf("Вы все сломали. В следующий раз вводите корректные значения.");
    exit(1);
}

void print(int length, int* array)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }
}

int main(int argc, char* argv[])
{
    system("chcp 1251");
    printf("Выполнено Левицким Павлом, группа 423-2\nВариант 11.\nВ одномерном массиве, состоящем из n целых элементов, вычислить:\nА) количество пар x[i] и x[i + 1], таких, что x[i] < x[i + 1];\nБ) произведение элементов массива, расположенных после последнего нулевого элемента;\nВ) удалить из массива все элементы, значения которых равны a, значение a вводить с клавиатуры,\nдополнительный массив не использовать.\n\n");
    int length, flag;

    printf("Введите количество элементов массива:\t");
    flag = scanf_s("%d", &length);
    if (length < 1 || flag != 1)
        fail();

    int* array = (int*)malloc(length * sizeof(array[0]));
    printf("Введите зачения индексов массива:\n");
    for (int i = 0; i < length; i++)
    {
        flag = scanf_s("%d", &array[i]);
        if (flag != 1)
            fail();
    }

    printf("Исходный массив:\n");
    print(length, array);

    //first
    int pairs = 0;
    for (int i = 0; i < length - 1; i++)
        if (array[i] < array[i + 1])
            pairs++;
    printf("\nКоличество пар элементов, удовлетворяющих условию x[i]<x[i+1]:\t%d\n", pairs);

    //second
    int mult = 1;
    int targetIndex = -1;
    int tempIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if (array[i] > 0) tempIndex++;
        if (array[i] == 0) targetIndex = i;
    }
    if (targetIndex == -1)
        printf("Отсутствуют нулевые элементы в массиве.\n");
    else if (targetIndex == length - 1)
        printf("После последнего нулевого элемента нет элементов.\n");
    else
    {
        for (int i = targetIndex + 1; i < length; i++)
            mult *= array[i];
        printf("Произведение элементов массива, расположенных после последнего нулевого элемента:\t%d\n", mult);
    }

    //third
    int a;
    printf("\nВведите значение к удалению:\t");
    flag = scanf_s("%d", &a);
    if (flag != 1)
        fail();

    int isDetected = 0;
    for (int i = 0; i < length; i++) {              //выполнять до конца длины
        if (array[i] == a) {                        //если элемент равен цели
            for (int j = i; j < length; j++) {      //делать с начала индекса цели
                array[j] = array[j + 1];            //замена цели на элемент по следующему индексу
            }
            i--;                                    //повторная проверка сдвинутого элемента
            length--;                               //снижение размера
            isDetected = 1;                         //цель найдена?
        }
    }
    if (isDetected == 0)
        printf_s("\nУказанное значение не найдено...\n");
    printf("\nОбновленный массив:\n");
    print(length, array);

    free(array);
    return 0;
}
