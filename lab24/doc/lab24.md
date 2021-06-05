# Лабораторна робота №24. Потоки.

## 1. Вимоги

### 1.1 Розробник

-   Журавльов Ярослав Юрійович;
    
-   студент групи КІТ-120а;
    
-   29-тра-2020
    

### 1.2 Загальне завдання
-   **Поширити**, попередню роботу таким чином:
    -   використання функцій  `printf/scanf`  замінити на  `cin/cout`;
    -   усі конкатенації строк замінити на використання  `stringstream`;
    -   замінити метод вводу інформації про об'єкт на метод, що приймає рядок з інформацією про об'єкт, обробляє його та створює об'єкт на базі цієї інформації;
    -   поширити клас-список, шляхом реалізації методів роботи з файлами.

### 1.3 Індивідуальне завдання

Виконати завдання згідно варіанту.

## 2. Опис програми

### 2.1 Функціональне призначення
Загальне завдання виконується за допомогою розроблених методів..

### 2.2 Опис логічної структури програми

Загальне завдання виконується за допомогою розроблених методів. Методи: `FromString` пертворює строку у агенство;`toString()` перетворює об'єкт в строку; `ReadFromFile` зчитує масив елементів з файлу; `WriteToFile` записує масив елементів у файл .

##### _Метод перетворення строки в об'єкт_` `FromString

*Agency FromString*

_Призначення:_ перетворює строку в об'єкт агенства.

_Схема алгоритму функції_ подана на рис. 1.

_Опис роботи_: за допомогою розбору строки на ключ-значення створюється агенство.

_Повертає функція:_ агенство.

![]()  
  
Рисунок 1 — Схема алгоритму функції *FromString*
##### Метод `ReadFromFile`
*void ReadFromFile*

_Призначення:_ зчитує елементи з файлу.

##### Метод `WriteToFile`
*void WriteToFile*

_Призначення:_ записує список елементів у файл.

##### _**Основна функція**_

int main

_Призначення:_ головна функція

_Опис роботи: функція створює список агенств, додає до нього агенства та викликає розроблені функції.
_Повертає функція_ код повернення програми (0).

#### Структура проекту

```
└── lab24
 ├── Doxyfile
 ├── Makefile
 ├── doc
 │   ├── lab24.md
 │   └── lab24.pdf
 └── src
 	 └── agencies_list.cpp
  	 └── agencies_list.h
  	 └── agency.cpp
  	 └── agency.h
 	 └── main.cpp
 └── test
	 └── test.cpp
```

### 2.3 Важливі фрагменти програми
#### Використання stringstream для конкатенації строк
```c
std::stringstream agency_ss;  
agency_ss << "Agency{\n" << "-Name:" << name << "," << std::endl <<  
  "-Weekends:" << (is_weekends ? "Yes" : "No") << "," << std::endl <<  
  "-Director:{" << std::endl << "--Name:" << director.name << "," << std::endl <<  
  "--Surname:" << director.surname << "," << std::endl <<  
  "--Email:" << director.email << std::endl << "-}" << std::endl <<  
  "-Years on market:" << years_on_market << "," << std::endl <<  
  "-City:" << CityToString() << std::endl << "}" << std::endl;
```
#### Метод FromString
```c
Agency Agency::FromString(std::string agency_string) { // TODO: test this  
  char desired_symbol = '-';  
 auto pos_for_replace = (int32_t) agency_string.find(desired_symbol);  
  
 while (pos_for_replace != -1) {  
        agency_string.replace((unsigned long) pos_for_replace, 1, 0, desired_symbol);  
  pos_for_replace = (int32_t) agency_string.find(desired_symbol);  
 if (pos_for_replace == -1 && desired_symbol != '\n') {  
            desired_symbol = '\n';  
  pos_for_replace = (int32_t) agency_string.find(desired_symbol);  
  }  
    }  
  
    Agency result_agency;  
  std::string read_data;  
  size_t key_index = 0;  
  size_t next_delimiter_index = 0;  
  
  std::string keys[] = {  
            "Name",  
  "Weekends",  
  "Name",  
  "Surname",  
  "Email",  
  "Years on market",  
  "City"  
  };  
  size_t keys_length = 7;  
  
 for (size_t i = 0; i < keys_length; i++) {  
        key_index = agency_string.find(keys[i], key_index);  
  next_delimiter_index = std::min(agency_string.find(',', key_index),  
  agency_string.find('}', key_index)); // TODO: can return -1?  
  size_t first_value_index = key_index + keys[i].length() + 1;  
  read_data = agency_string.substr(first_value_index, next_delimiter_index - first_value_index);  
  Agency::ValueToAgencyByIndex(result_agency, (int)i, read_data);  
  }  
  
    return result_agency;  
}
```
### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність дій запуску програми.

Крок 1 (див. рис. 2). Результат роботи методу перетворення об'єкта в строку.

![]() 

Рисунок 2 — результат роботи метода toString.

Крок 2 (див. рис. 3). Результат роботи методу перетворення строки в об'єкт.

![]() 
Рисунок 3 — результат роботи метода FromString.

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи із потоками.
