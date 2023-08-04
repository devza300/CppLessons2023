![Alt text](task.jpg?raw=true "Задание")

# Инсрукция по использованию

1. Вызов справки:

```
./Lesson11 --help

Hello! You are run the Homework Lesson11 console application!

Usage:
-h, --help                     print this help page
-d, --dialog                   setup config from dialog
-f, --file     [config_file]   load config from file
```

2. Запуск в режиме диалога (конфигурирование из консоли)

```
./Lesson11 -d
```

3. Запуск с чтением конфигурации из файла

> в каталоге с исходным кодом прграммы находятся примеры конфигурационных файлов `Bender.conf` и `R2D2.conf`

```
./Lesson11 -f R2D2.conf
```

## Пример выполнения программы:

```
./Lesson11 -f ../../../src/homeWork/Lesson11/R2D2.conf

[Emulator]: Create new robot...
[R2D2]: Hi!

[R2D2]: Start task <DropItem>
[R2D2]: Drop mechanism...
[R2D2]: Done. Mechanism <Leverage> are dropped

[R2D2]: Start task <GetSmth>
[R2D2]: Done. Smth count are <1>

[R2D2]: Start task <MoveTo>
[R2D2]: Start. I'm at destination point <-7, 3>
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: Finish. I'm at destination point <-2, 5>

[R2D2]: Start task <PutSmth>
[R2D2]: Done. Smth count are <0>

[R2D2]: Start task <MoveTo>
[R2D2]: Start. I'm at destination point <-2, 5>
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: Finish. I'm at destination point <1, -1>

[R2D2]: Start task <OilShower>
[R2D2]: Done. Oil makes me stronger

[R2D2]: Start task <MoveTo>
[R2D2]: Start. I'm at destination point <1, -1>
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: Finish. I'm at destination point <3, 5>

[R2D2]: Start task <OilShower>
[R2D2]: Done. Oil makes me stronger

[R2D2]: Start task <MoveTo>
[R2D2]: Start. I'm at destination point <3, 5>
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: makes a move...
[R2D2]: Finish. I'm at destination point <3, 1>

[R2D2]: Start task <DropItem>
[R2D2]: I can't complete the task <DropItem>
[R2D2]: I don't have the necessary mechanism!
```
