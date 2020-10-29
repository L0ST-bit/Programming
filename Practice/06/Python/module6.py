#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      User
#
# Created:     28.09.2020
# Copyright:   (c) User 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()
a = float (input())
b = float (input())
c = float (input())
D = float
print ("Введите a, b, c:" )
if (a==0 and b!=0 and c!=0):
    print("x =" and -1*(c)/b);
elif (b == 0 and (-(c) / a) > 0):
    print("x1 = ", -sqrt(-(c) / a), "\nx2 = ",  sqrt(-(c) / a) );
elif(b == 0 and a!=0 and c!=0 and (-(c) / a) < 0):
    print("Нет корней\n");
elif(c == 0 , a!=0 , b!=0):
    print("x1 = 0" , "x2 = " , ((-b) / a));
    D = b * b - 4 * a * c;
elif(D == 0 and a != 0 and b != 0 and c != 0):
    print("x = " , (-(b)-sqrt(D)) / (2 * a));
elif(D > 0 and a != 0 and b != 0 and c != 0):
    print("x1 = ", (-1*(b)-sqrt(D)) / (2 * a) , "\nx2 = " , (-1*(b)+sqrt(D)));
elif(D < 0 and a != 0 and b != 0 and c != 0):
    print("Нет корней");
if(a == 0 and b == 0 and c == 0):
    print("x любое число");
elif(a == 0 and b == 0 and c != 0):
    print("Нет корней");
elif((a == 0 and b != 0 and c == 0) or (a != 0 and b == 0 and c == 0)):
    print("/nx =  0");