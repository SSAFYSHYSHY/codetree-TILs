m = int(input())
a, b = tuple(map(int, input().split()))

min_num = 21e8
max_num = 0

def calc(num):
    left = 1
    right = m
    cnt = 0

    while left <= right:
        cnt += 1
        mid = (left + right) // 2

        if mid == num:
            break

        if mid > num:
            right = mid - 1
        else:
            left = mid + 1

    return cnt

for i in range(a, b + 1):
    min_num = min(min_num, calc(i))
    max_num = max(max_num, calc(i))

print(min_num, max_num)