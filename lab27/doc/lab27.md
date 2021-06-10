# Лабораторна робота №27. Поліморфізм.

## 1. Вимоги

### 1.1 Розробник

-   Журавльов Ярослав Юрійович;
    
-   студент групи КІТ-120а;
    
-   29-тра-2020
    

### 1.2 Загальне завдання

-   **Поширити**, попередню роботу таким чином:
    1.  **Зробити**  базовий клас абстрактним, додати абстрактні методи;
        
    2.  **Розроблені**  класи-списки поєднуються до одного класу списку таким чином, щоб він міг працювати як з базовим класом, так і з класами-спадкоємцями;
        
    3.  **Обов'язково**  використовувати ключові слова  `override`  або  `final`

### 1.3 Індивідуальне завдання

Виконати завдання згідно варіанту.

## 2. Опис програми

### 2.1 Функціональне призначення
Загальне завдання виконується за допомогою віртуального класу та його спадкоємців.

### 2.2 Опис логічної структури програми
##### _Перевантажений метод  getAgencyFromConsole для LegalAgency_

*void LegalAgency::getAgencyFromConsole*

_Призначення:_ вирористовується для розширення віртуального метода для зчитування юридичного агенства.

_Схема алгоритму функції_ подана на рис. 1.

_Опис роботи_: викликає метод getAgencyFromConsol із Agency і запитує поля яких не вистачає.

_Повертає функція:_.

![](https://github.com/yzet/Programming/blob/main/lab27/doc/assets/lab27.png)  
  
Рисунок 1 — Схема алгоритму *LegalAgency::getAgencyFromConsole*

#### Структура проекту

```
└── lab27
 ├── Doxyfile
 ├── Makefile
 ├── doc
 │   ├── lab27.md
 │   └── lab27.pdf
 └── src
  	 └── agency.cpp
  	 └── agency.h
  	 └── agency_creator.cpp
  	 └── agency_creator.h
  	 └── legal_agency.cpp
  	 └── legal_agency.h
  	 └── main.cpp
  	 └── marriage_agency.cpp
  	 └── marriage_agency.h
  	 └── virtual_agencies_list.cpp
  	 └── virtual_agencies_list.h
 └── test
	 └── test.cpp
```

### 2.3 Важливі фрагменти програми
#### Перевантаження методу LegalAgency::getAgencyFromConsol
```c
Agency::getAgencyFromConsole(input, agency);  
 int service;  
 int numberOfCasesWonValue;  
  
  std::cout << "-Service:";  
  input >> service;  
//    std::cout << "," << std::endl;  
  
  std::cout << "-Number of cases won:";  
  input >> numberOfCasesWonValue;  
  std::cout << "}" << std::endl;  
  
  ((LegalAgency *)(&agency))->SetLegalAgencyService((LegalAgencyService)service);  
  ((LegalAgency *)(&agency))->SetNumberOfCasesWon(numberOfCasesWonValue); 
  
    agencies_list.StringOfAgenciesToList(file_data);  
  
 return input;  
}
```
### 3. Варіанти використання

Для демонстрації результатів використовується Clion. Нижче наводиться послідовність дій запуску програми.

Крок 1 (див. рис. 2). Результат вводу шлюбного агенства. 

![](https://github.com/yzet/Programming/blob/main/lab27/doc/assets/cin_marriage.jpg) 

Рисунок 2 — результат вводу MarriageAgency.

## Висновки

При виконанні даної лабораторної роботи було набуто практичного досвіду роботи із поліморфізмом.
