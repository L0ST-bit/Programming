#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      User
#
# Created:     28.10.2020
# Copyright:   (c) User 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()
    import math
print("Чтобы считать через стороны треугольника введите: 1\nЧтобы считать через координпты вершин введите: 2\n");
k = int (input())
if (k == 1):
    print("Введите стороны треугольника:")
    a, b, c = map(float, input().split())
    p = float;
    p = (a+b+c)/2
    if (a < 0 or b < 0 or c < 0):
        print("Длинна не может быть отрицательной")
    elif ((a + b) < c or (a + c) < b or (c + b) < a):
        print("Такого треугольника не существует")
    else:
        print("S = " , math.sqrt(p * (p - a) * (p - b) * (p - c)));
if(k==2):
    print("Введите координаты:\n")
    x1, y1 = map(float, input().split())
    x2, y2 = map(float, input().split())
    x3, y3 = map(float, input().split())
    if(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) == 0):
        print("Треугольник вырожденный")
    print("S = " , (math.fabs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))/2));
