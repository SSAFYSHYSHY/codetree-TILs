s = int(input())

left = 1
right = s
min_num = 0

while left <= right:
    mid = (left + right) // 2

    if mid * (mid + 1) // 2 <= s:
        left = mid + 1
        min_num = max(min_num, mid)
    else:
        right = mid - 1

print(min_num)