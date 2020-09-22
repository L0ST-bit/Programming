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
    print ("Введите x0:" )
x0 = float (input())
print ("Введите V0:")
V0 = float (input())
print ("Введите t:")
t = float (input())
a = 9.8
print ("Рассчитываю по формуле: x0 + V0*t - 1/2*a*t*t=",x0 + V0*t - a*t*t/2)