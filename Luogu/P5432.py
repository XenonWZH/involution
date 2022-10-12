m = int(input())
n = int(input())

l = 0
r = 1
while r ** m < n:
    r *= 2

while l < r:
    mid = (l + r) // 2 + 1
    x = mid ** m
    if x <= n:
        l = mid
    else:
        r = mid - 1

print(l)