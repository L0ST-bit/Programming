#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      User
#
# Created:     29.10.2020
# Copyright:   (c) User 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()
print("Введите число а затем степень")
a = float(input())
b = int(input())
c = a
if(b>0):
    i = 1
    while i < b:
        i = i + 1
        a = a * c
    print(a)
if (b == 0):
    a = 1
    print(a)
if (b<0):
    i = -1
    while i > b:
        i = i - 1
        a = a * c
    print(1/a)


