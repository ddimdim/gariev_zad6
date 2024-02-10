﻿// prakt6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <cctype>
void RemoveWords(char* str);



int main()
{
    setlocale(LC_ALL, "rus");
    std::cout << "Введите несколько слов: ";
    char str[1000];
    gets_s(str);
    RemoveWords(str);
    std::cout << "Новая строка: ";
    puts(str);
}

void RemoveWords(char* str)
{
    int n, i, k, nv;
    int j = 0;
    bool check = false;
    char vowels[] = { 'a', 'o', 'e', 'i', 'u', 'y', 'A', 'O', 'E', 'I', 'U', 'Y' };
    n = strlen(str);
    nv = sizeof(vowels)/sizeof(vowels[0]);
    for (i = 0; i < n; i++)
    {

        for (k = 0; k < nv; k++)
        {
            if (str[i] == vowels[k])
            {
                check = true;
                break;
            }
        }
        if (check || !isalpha(str[i]))
        {
            while (i < n && str[i] != ' ')
            {
                i++;
            }
            check = false;
        }
        else
        {
            while (i < n && str[i] != ' ')
            {
                str[j++] = str[i++];
            }
            str[j++] = ' ';
        }
    }
    str[j] = '\0';
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
