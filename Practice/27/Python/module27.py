def Out(signal: list, n: int):
    if(n > 5):
        for i1 in range(n-5, n):
            print(signal[i1], ' ', end='')
        print()
    else:
        for i2 in range(n):
            print(signal[i2], ' ', end='')
        print()



def Sort(insort: list, n: int):
    for i1 in range(n-1):
        for i2 in range(n-1-i1):
            if(insort[i2] < insort[i2+1]):
                insort[i2], insort[i2+1] = insort[i2+1], insort[i2]
    return insort;




n = int(input())
signal = list(map(int, input().split(' ')))
sorted = []
count = 0
for i in range(n):
    count += 1
    sorted.append(signal[i])
    sorted = Sort(signal, count)
    Out(sorted, count)



