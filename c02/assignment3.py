def factorial(n):
    if n <= 0:
        return 1
    result = n * factorial(n - 1)
    print(n, "! = ", result)
    return result


factorial(50)
