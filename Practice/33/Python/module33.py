import builtins

def create(size, first = 0, step = 0) -> list:
    arr = []
    arr.append(first)
    for i in range(1, size):
        arr.append(arr[i-1] + step)

    return arr


def sort(arr) -> list:
    for i in range(1, len(arr)):
        temp = arr[i]
        j = i-1
        while j >=0 and temp < arr[j]:
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = temp

    return arr

def print(arr):
    builtins.print("[", arr[0], sep="", end="")
    for i in range(1, len(arr)):
        builtins.print(", ", arr[i], sep="", end="")
    builtins.print("]\n")
    return arr


size, first, step = map(int,input().split(' '))
arr = create(size, first, step)
sort(arr)
print(arr)

