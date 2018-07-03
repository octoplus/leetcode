import math

def smallestGoodBase(n):
    n=int(n)
    m=int(math.log(n,2))
    while m>=1:
        k=int(n**(m**-1))
        if (k**(m+1)-1)//(k-1) == n:
            return str(k)
        m-=1
    return str(n-1)

if __name__ == "__main__":
    print smallestGoodBase("13")