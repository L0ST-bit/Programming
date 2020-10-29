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
a, c, b =  input().split()
a = float(a)
b = float(b)
print(ord(c))
c = int(ord(c))
print(c)
if(c == 42):
    print(a * b);
if(c == 47 and b != 0):
    print(a / b);
if(c == 43):
    print(a + b);
if(c == 45):
    print(a - b);
else:
    print("Ошибка: деление на ноль")


