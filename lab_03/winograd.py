import random as r
import os

def main():
    m = genRandMatrix(4, 5)
    n = genRandMatrix(5, 4)
    
    c = winograd(m, n)

    os.system("clear")
    printMatrix(m)
    printMatrix(n)
    printMatrix(c)
    
    return 1


def winograd(m, n):
    rows = []
    
    a = len(m)
    b = len(m[0])

    c = len(n[0])
    
    d = b // 2
    rows = [0 for i in range(a)]
    for i in range(a):
        rows[i] += m[i][0] * m[i][1]
        for j in range(1, d):
            rows[i] += m[i][2*j] * m[i][2*j+1]

    columns = [0 for i in range(c)]
    for i in range(c):
        columns[i] += n[0][i]*n[1][i]
        for j in range(1, d):
            columns[i] += n[2*j][i] * n[2*j+1][i]

    r = [[0 for i in range(c)] for j in range(a)]
    for i in range(a):
        for j in range(c):
            r[i][j] = - rows[i] - columns[j]
            for k in range(d):
                r[i][j] += (m[i][2*k] + n[2*k+1][j]) * (m[i][2*k+1] + n[2*k][j])

    if b%2:
        for i in range(a):
            for j in range(c):
                r[i][j] += m[i][b-1] * n[b-1][j]

    return r


def genRandMatrix(a, b):
    return [[r.randint(0, 20) for i in range(b)] for i in range(a)]


def printMatrix(a):
    if not a:
        return
    print("\n")
    for i in range(len(a)):
        for j in range(len(a[0])):
            print(" ", a[i][j], end="")
        print("\n")


if __name__ == "__main__":
    main()
