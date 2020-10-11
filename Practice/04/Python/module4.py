#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      User
#
# Created:     22.09.2020
# Copyright:   (c) User 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()
a = int (input())
b = int (input())
a, b = b, a
print ("Без дополнительных переменных: ", a, b )
z = int (input())
x = int (input())
c = z
z = x
x = c
print ("С дополнительной переменной: ", z, x)