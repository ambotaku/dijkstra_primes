def dijkstraPrimes(last):
    primes = [2]
    pool = [4]
    for test in range(3, last):
        isPrim = True
        for index in range(0, len(pool)-1 ):
            if pool[index] == test:
                pool[index] += primes[index]
                isPrim = False

        if isPrim:
            primes.append(test)
            pool.append(test *test)
            #print(test)

    return primes

repr(dijkstraPrimes(100))
