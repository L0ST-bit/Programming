#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      User
#
# Created:     30.10.2020
# Copyright:   (c) User 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    pass

if __name__ == '__main__':
    main()
def bmi(a: float, b: float) -> float:
    return a / (b * b / 10000)
def p(bmi: float) -> float:
    if bmi < 18.5:
        print('Underweight')
    elif (18.5 <= bmi and bmi < 25):
        print('Normal')
    elif (25 <= bmi and bmi < 30):
        print('Overweight')
    else:
        print("Obesity")
print("Введите вес рост")
a, b = map(float,input().split())
p(bmi(a, b))