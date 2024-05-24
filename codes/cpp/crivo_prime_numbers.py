# -*- coding: UTF-8 -*-
prime_numbers = []
def sieve(n):
  global prime_numbers
  prime_numbers = [True]*(n+1) # add Nth value
  prime_numbers[0] = prime_numbers[1] = False

  for i in range(2,n):
    if (prime_numbers[i+1]==False):
      continue
    for j in range(i*i, n, i):
      prime_numbers[j+1] = False

def is_prime(n):
  from math import sqrt
  if n<=100: # arbitrary value, comparing cost to run sieve, and cost to verifies it using a "linear list"
    aux = int(sqrt(n)) + 1 # (a/a)==1, a*(a/a)=a, (a/sqrt(a))*sqrt(a)==a. Added 1 to count it self
    for i in range(2,aux):
      if (n%i==0):
        return False
    return True
  else:
    sieve(n+1)
    return prime_numbers[n+1]

inp = int(input("Entre com o valor: "))
print ( is_prime(inp) )