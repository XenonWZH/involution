def fac(n) :
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    return ans

n = int(input())
ans = fac(2 * n) // fac(n + 1) // fac(n)
print(str(ans))