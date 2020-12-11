import math
def ReshetoEratosfena(n:int):
    nums = []
    count = 2
    while(1):


        if(n % count == 0 and count != 1):
            n = n/count
            nums.append(count)
            count = 0

        elif(count == n):
            if(count != 1):
                nums.append(count)
            ##print(nums)
            return nums

        count +=1
    print(nums)
    return nums


def print_factorization(n:int) -> None:
    nums = []
    nums = ReshetoEratosfena(n)
    temp = 0
    if(len(nums) == 1):
        print(nums[0])
        exit(1)
    print(nums[0],end='',sep='')
    for i in range(1, len(nums)):
        if(nums[i-1] == nums[i]):
            degree = 1;
            count = i
            while(nums[count-1] == nums[count]):
                if(temp == nums[count]):
                    break
                degree+=1
                count+=1
                if(count == len(nums)):
                    break
            if(degree != 1):
                print("^",degree,end='',sep='')
            temp = nums[count-1]
            i = count-1
        else:
            print("*",nums[i],end='',sep='')


n = int(input())
print_factorization(n)

