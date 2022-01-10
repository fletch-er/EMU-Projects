def isHeavy(n):
    sum = 0
    factors = []
    for i in range(2, n-1):
        if (n % i == 0):
            factors.append(i)
    for num in factors:
        sum += num

    if (sum > n):
        return True
    if (sum < n):
        return False

print(isHeavy(14))