# Лабораторна робота №18. Динамічні масиви.

## 1. Вимоги

### 1.1 Розробник

-   Журавльов Ярослав Юрійович;
    
-   студент групи КІТ-120а;
    
-   29-тра-2020
    

### 1.2 Загальне завдання


-   1.  **Розробити**  функцію, яка реалізує вставку в рядок "s" другий рядок "s2" в "і" - у позицію рядка "s";
-   2.  **Розробити**  функцію, видалення з рядка "" усіх символів з індексами в заданому діапазоні;
-   3.  **Розробити**  функцію додавання та видалення елементів з динамічного масиву вашої прикладної області

### 1.3 Індивідуальне завдання

Виконати завдання згідно варіанту.

## 2. Опис програми

### 2.1 Функціональне призначення
За допомогою розроблених функцій можна вставити підрядок в рядок, видалити підрядок з рядка, вставити та видалити структуру з масиву структур.

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою функцій *insert* та *reduce*.

##### Функція вставки

*void insert*

_Призначення:_ втавляє елементи у динамічний масив.

_Схема алгоритму функції_ подана на рис. 1.

_Опис роботи_: використовуючи початковий індекс створює новий масив на основі попереднього, додаючи нові елементи.

_Повертає функція:_ .

![](https://github.com/yzet/Programming/blob/main/lab18/doc/assets/lab18.png)  
  
Рисунок 1 — Схема алгоритму функції *insert*
##### Функція видалення елементів із масиву
*size_t reduce*

_Призначення:_ видаляє елементи із динамічного масиву.

_Схема алгоритму функції_ подана на рис. 2.

_Опис роботи_: використовуючи індекси початку і кінця копіює потрібні елементи у потрібний масив.

_Повертає функція_.

![](https://github.com/yzet/Programming/blob/main/lab18/doc/assets/lab18_reduce.png) 

Рисунок 2 — Схема алгоритму функції *reduce*

##### _**Основна функція**_

int main

_Призначення:_ головна функція

_Схема алгоритму функції_ подана на рис. 3.

_Опис роботи: функція почергово викликає функції для демонстрації роботи.
_Повертає функція_ код повернення програми (0).

![]()  

Рисунок 3 — Схема алгоритму функції main

#### Структура проекту

```
└── lab18
 ├── Doxyfile
 ├── Makefile
 ├── doc
 │   ├── lab18.md
 │   └── lab18.pdf
 └── src
 	 └── lib.c
	 └── lib.h
	 └── main.c
 └── test
	 └── test.c
```

### 2.3 Важливі фрагменти програми
#### Копіювання елементів
```c
for (; last_free_index_in_new_array < from_index; last_free_index_in_new_array++)  
{  
    // memcpy((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + last_free_index_in_new_array), dynamic_array->size_of_elements);  
  memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + last_free_index_in_new_array * dynamic_array->size_of_elements), dynamic_array->size_of_elements);  
}  
for (size_t i = 0; i < count_of_elements; i++)  
{  
    // memcpy((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (inserted_data + i), dynamic_array->size_of_elements);  
  memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (inserted_data + i * dynamic_array->size_of_elements), dynamic_array->size_of_elements);  
  last_free_index_in_new_array++;  
}  
for (size_t i = from_index; i < dynamic_array->length; i++)  
{  
    // memcpy((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + i), dynamic_array->size_of_elements);  
  memmove((new_array + last_free_index_in_new_array * dynamic_array->size_of_elements), (dynamic_array->array + i * dynamic_array->size_of_elements), dynamic_array->size_of_elements);  
  last_free_index_in_new_array++;  
}
```
#### Встановлення значення змінних DynamicArray
```c
free(dynamic_array->array);  
dynamic_array->array = new_array;  
dynamic_array->length = new_length;
```
### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність дій запуску програми.

Крок 1 (див. рис. 4). Виводиться динамічний масив сформованний за рахунок вставлення і видалення елементів.

![](https://github.com/yzet/Programming/blob/main/lab18/doc/assets/program_print.jpg) 

Рисунок 4 — результат роботи функцій втавлення та видалення.

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи із динамічними масивами.
