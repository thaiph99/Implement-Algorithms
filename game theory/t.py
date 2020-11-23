def solve(a,b,c,m) : # split and solve
    result = 1
    p = 2            # primes
    while p**2 <= a :
        z = 0
        while a % p == 0 :
                     # calculate z
            a /= p
            z += 1
        if z != 0 :
            result *=  modpow(p,z,b,c,m)
            result %= m
        p += 1
    if a != 1 :      # Possible last prime
        result *= modpow(a, 1, b, c, m)
    return result % m

