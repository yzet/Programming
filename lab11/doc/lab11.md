﻿# Лабораторна робота №11. Вступ до показчиків

## 1. Вимоги

### 1.1 Розробник

-   Журавльов Ярослав Юрійович;
-   студент групи КІТ-120а;
-   07-гру-2020
    

### 1.2 Загальне завдання

Розробити програми, що вирішують завдання з використанням показчиків.

### 1.3 Індивідуальне завдання

Реалізувати програму, що записує елементи головної діагоналі в одновимірний масив і упорядковує цей масив за зростанням.

## 2. Опис програми

### 2.1 Функціональне призначення

Програма записує елементи головної діагоналі двовимірного квадратного масиву *array* у масив *main_diagonal_elements*. Далі елементи масиву *main_diagonal_elements* упорядковуються за зростанням.

### 2.2 Опис логічної структури програми

Для заповнення масиву *main_diagonal_elements* викликаємо функцію *fill_array_with_main_diagonal_elements_of_square_array*, яка приймає параметрами розміри двовимірного масиву, показчик на двовимірний масив, показчик на масив з елементами головної діагоналі. Сортуємо масив за допомогою функції *buble_sort*, яка приймає параметрами розмір масиву та показчик на масив.

##### Функція заповнення масиву елементами головної діагоналі двовимірного масиву

*int fill_array_with_main_diagonal_elements_of_square_array*

_Призначення:_ заповнює масив елементами головної діагоналі двовимірного масиву

_Схема алгоритму функції_ подана на рис. 1.

_Опис роботи_: функція записує у i елемент масиву з елементами головної діагоналі, елементи двовимірного масиву з рівними індексами.

_Повертає функція_ змінений масив.

![](https://github.com/yzet/Programming/blob/main/lab11/doc/assets/img1_main_diag_func.png?raw=true)  
  
Рисунок 1 — Схема алгоритму функції *fill_two_dimensional_array_with_random_number*
##### Функція сортування
*void  buble_sort*

_Призначення:_ сортує масив за зростанням бульбашковим методом.

_Схема алгоритму функції_ подана на рис. 2.

_Опис роботи_: функція змінює місцями елементи, якщо елемент зліва більший за елемент справа.

_Повертає функція_ змінений масив.
![](https://github.com/yzet/Programming/blob/main/lab11/doc/assets/img2_buble_sort.png?raw=true) 

Рисунок 2 - схема алгоритму функції сортування
##### _**Основна функція**_

int main

_Призначення:_ головна функція

_Схема алгоритму функції_ подана на рис. 3.

_Опис роботи:_ функція заповнює двовимірний масив випадковими елементами за допомогою функції *fill_two_dimensional_array_with_random_number*, заповнює функцію з елементами головної діагоналі за допомогою функції *fill_array_with_main_diagonal_elements_of_square_array*, і сортує масив за допомогою функції *buble_sort*.
_Повертає функція_ код повернення програми (0).

![](https://github.com/yzet/Programming/blob/main/lab11/doc/assets/img3_main.png?raw=true)  

Рисунок 3 — Схема алгоритму функції main

#### Структура проекту

```
└── lab11
 ├── Doxyfile
 ├── Makefile
 ├── doc
 │   ├── lab11.md
 │   └── lab11.pdf
 └── src
	 └── main.c
```

### 2.3 Важливі фрагменти програми
#### Початкові дані. Константи
```c
#define ARRAY_SIZE 5
```
#### Запис елементів головної діагоналі
```c
for (int  i = 0; i < side_size; i++)
{
	main_diagonal_array[i] = square_array[i][i];
}
```
#### Зміна місцями елементів під час сортування
```c
array[j] += array[j + 1];
array[j + 1] = array[j] - array[j + 1];
array[j] -= array[j + 1];
```
### 3. Варіанти використання

Для демонстрації результатів використовується покрокове виконання програми та інші засоби налагодження відлагодника gdb. Нижче наводиться послідовність  дій запуску програми у режимі відлагодження.

Крок 1 (див. рис. 4). Знаходячись в основній процедурі, досліджуємо стан змінних, в тому числі констант.

![](https://github.com/yzet/Programming/blob/main/lab11/doc/assets/img4_check.png?raw=true) 

Рисунок 4 — значення змінних при запуску програми

Крок 2 (див. рис. 5). Дослідження стану змінних наприкінці виконання функції заповнення масиву з елементами діагоналі.

![](https://github.com/yzet/Programming/blob/main/lab11/doc/assets/img5_check2.png?raw=true) 

Рисунок 5 — значення змінних після запису масиву з елементами головної діагоналі

Крок 3 (див. рис. 6). Дослідження стану змінних після виконання функції сортування.

![](https://github.com/yzet/Programming/blob/main/lab11/doc/assets/img6_check3.png?raw=true) 

Рисунок 6 - значення змінних після сортування

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи із показчиками.
