![Alt text](task.jpg?raw=true "Задание")

# Инсрукция по использованию

1. Вызов справки:

```
./Lesson6 --help

Hello! You are run the Homework Lesson6 console application!

Usage:
-h, --help                     print this help page
-m, --massive                  run with massive storage
-v, --vector                   run with vector storage
```

2. Запуск с сохранением данных в массив

```
./Lesson6 --massive

Put count of array elements: 5
Put the value of index <0>: 5
Put the value of index <1>: 2
Put the value of index <2>: 3
Put the value of index <3>: 1
Put the value of index <4>: 4

Minimal even found: 2

Minimum and maximum position summ: 3

Multiply odd positions: 2

Swapping elemnts...
Put the value of index: 2
Put the value of index: 4

Value in index <2> is: 3
Value in index <4> is: 4

Values are swapped!
Value in index <2> is: 4
Value in index <4> is: 3
```

3. Запуск с сохранением данных в вектор

```
./Lesson6 --vector

Put the value of index <0> or 'D' to done: 5
Put the value of index <1> or 'D' to done: 2
Put the value of index <2> or 'D' to done: 3
Put the value of index <3> or 'D' to done: 1
Put the value of index <4> or 'D' to done: 4
Put the value of index <5> or 'D' to done: D

Minimal even found: 2

Minimum and maximum position summ: 3

Multiply odd positions: 2

Swapping elemnts...
Put the value of index: 2
Put the value of index: 4

Value in index <2> is: 3
Value in index <4> is: 4

Values are swapped!
Value in index <2> is: 4
Value in index <4> is: 3
```
