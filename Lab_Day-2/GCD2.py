# 3. GCD using iteration

from timeit import default_timer

def GCD(a, b):
    while b != 0:
        a, b = b, a % b
    return a

n1=int(input("Enter firt number:"))
n2=int(input("Enter second number:"))

start=default_timer()
result=GCD(n1,n2)
end=default_timer()
print(f"The GCD of {n1} and {n2} is {result}")
print(f"The time taken is {start-end} seconds")