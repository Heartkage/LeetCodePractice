n = 10
m = 5
# arr = [[i for i in range(m)]] * n
arr = [0] * n
print(arr)

def print2DArr():
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            print(arr[i][j], end=" ")
        print("")
def printArr():
    for i in range(len(arr)):
        print(arr[i], end=" ")
    print("")

printArr()
arr[0] = 5
print("")
printArr()