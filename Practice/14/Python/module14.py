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
n = int(input())
a = 2
i = 0
while a<=n:
    i = i + 1
    a = 2
    a = pow(a,i)
if(n==0):
    print("0")
elif(n==1):
    print("2")
elif(n==2):
    print("2")
else:
    print(i)
