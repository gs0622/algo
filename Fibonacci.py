def fib(n):
    """ f(n) = f(n-1) + f(n-2), seed: f(0)=0, f(1)=1 """
    """ Print a Fibonacci series up to n """
    a,b = 0,1
    #print a
    while b<n:
        print b
        a,b = b,a+b

def fib2(n):
    fib = {}
    for k in range(1, n+1):
        if k<=2:
            fib[k] = 1
        else:
            fib[k] = fib[k-1] + fib[k-2]
    return fib[n]

def main():
    fib(100)
    print "--"
    print fib2(5)
    print fib2(10)
    print fib2(15)

if __name__ == '__main__':
    main()
    
