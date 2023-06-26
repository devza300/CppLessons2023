# Демонстрация наложения маски на изображение

Инструкция использования:
```
./Lesson4 -h

Hello! You are run the Homework Lesson4 console application!

Usage:
-h, --help                     print this help page
-g, --generate                 generate new image and mask files
-p, --print                    print image, mask set and out file
-i, --image    [img_file]      image file path
-m, --mask     [msk_file]      mask file path
-o, --out      [out_file]      out file path

--pro-mode                     mask file must be written in decimal mode
```

## Стандартный режим

```
./Lesson4 -i image -m mask -o out -g -p

IMAGE
9 0 7 8 7 7 2 5 
4 8 5 5 5 0 1 0 
5 8 0 5 6 4 7 2 
4 0 5 8 7 3 8 3 
4 1 4 8 6 8 9 1 
3 8 8 4 2 4 7 1 
4 2 3 5 2 3 6 7 
0 4 0 2 8 6 6 6 

MASK
0 0 1 1 0 0 0 0 
0 1 1 1 1 1 1 1 
1 0 0 0 1 0 0 1 
1 0 0 0 0 1 0 0 
0 1 0 0 1 0 1 1 
1 1 0 1 1 1 1 1 
1 1 1 0 1 1 1 1 
1 0 0 0 1 1 1 1 

OUT
0 0 7 8 0 0 0 0 
0 8 5 5 5 0 1 0 
5 0 0 0 6 0 0 2 
4 0 0 0 0 3 0 0 
0 1 0 0 6 0 9 1 
3 8 0 4 2 4 7 1 
4 2 3 0 2 3 6 7 
0 0 0 0 8 6 6 6 

```

## Режим работы с файлом маски в десятичном виде

```
./Lesson4 -i image -m mask -o out -g -p --pro-mode

IMAGE
7 7 6 5 4 0 2 8 
2 6 9 3 6 8 1 6 
1 6 6 3 6 1 9 7 
0 7 5 2 2 6 5 0 
9 2 8 7 4 6 8 1 
3 7 7 6 4 7 3 8 
4 5 6 0 4 8 9 6 
0 1 7 8 3 0 8 3 

MASK
154
137
0
107
185
79
119
9

OUT
7 0 0 5 4 0 2 0 
2 0 0 0 6 0 0 6 
0 0 0 0 0 0 0 0 
0 7 5 0 2 0 5 0 
9 0 8 7 4 0 0 1 
0 7 0 0 4 7 3 8 
0 5 6 0 0 8 9 6 
0 0 0 0 3 0 0 3

```
