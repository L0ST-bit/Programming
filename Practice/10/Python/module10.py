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
print("Введите 5 целых чисел")
s, l1, r1, l2, r2, x = int(input())
if((r1 + r2) < s or (l1 + l2) > s):
    print("-1")
elif(l1 + r2 == s):
    print(l1, r2)
elif(l1 + r2 < s):
    x = s - (l1 + r2) + l1
    print(x, r2)
elif(l1 + r2 > s):
    x = s - (l1 + r2) + r2
    print(l1, x)
else:
    print(-1)