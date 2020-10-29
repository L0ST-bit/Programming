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
a = int(input())
if(a == 2 or a == 5 or a == 7 or a == 3):
    print(a , "Простое")
elif(a%2 == 0 or a%5 == 0 or a%3 == 0 or a%7 == 0):
    print(a, "Составное")
else:
    print(a , "Простое")