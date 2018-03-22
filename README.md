# AbstractSeries

DESCRIPTION: Want to create abstract code to sum across various functions of 
various special numbers like primes, perfect numbers, fibonacci numbers 


BUGS/LIMITATIONS: User must enter the starting number as a correct special number.  For example, if user enters 2 for first twin prime, the sum will be incorrect but it will be correct for primes.  The usershould enter 3 for first twin prime or can start at any valid
twin prime.  For twin prime oairslike 3 and 5, we considered only 3 (the first in the pair) to be a twin prime.
         
 TEST CASES: Linear sum of first 3 primes= 2 +3 + 5= 10 
              Sum of first 3 primes squares= 4 +9 +35= 38
              Sum of reciprocals of first 3 primes= 1/2 + 1/3 + 1/5= 1.033
              Sum of first three perfect numbers = 6 + 28 + 496= 530 
              Sum of first three twin primes= 3 + 5+ 11= 19
              Sum of first four Fibonacci numbers= 1 + 2 + 3 + 5= 11
              
 ADDING FUNCTIONALITY: There are comments in the code to indicate where to add new special numbers and where to add new 
   Transformations which should make this code easy to extend.          

HISTORY OF COMMITS:

v1: Started by writing concrete code to detect primes and to loop over
    all integers up to some Max adding in all the primes

v2: Added similar code for perfect numbers

v2: Abstracted using an iterator.  Too worried about the use of a standard
    iterator interface so defined a SpecialIntIterator with a next
    member function to move to the next special number.  Used function
    pointers to pass in tests for primes and perfect

v3: Added in support for twin primes and cousin primes.  Very little
    code

v4: Abstracted to allow for squares and cubes by transformations of
    special numbers

v5:  Added user input to choose special number (e.g., prime, perfect etc)
     and transform (linear, square, etc)
     
 v6: Added sums of reciprocals of primes, perfects, etc and abstracted by using templates to abstract across 
     functions that return doubles like reciprocals and functions like square that return ints.
 
 v7:  Added basic code for Fibonacci Numbers using routine isFibonacci
 
 v8: Found a bug for large numbers when doing Fibonacci sums beyond 40 and updated all ints to unsigned long long.
     Corrected many type mismatches in functions to make this change work
    
  v9: Added time measurement to check using the function clock() and time.h following some code in Stack Overflow
      Found the following numbers for Fibonacci sums of the first N fibonacci.  N = 10 was 3.12, N = 40 was 60 seconds
      but N = 48 took over 10 minutes. The running time is growing too fast because every call to isFibonacci starts 
      computing Fibonacci Numbers starting from 1
  
  v10:  Tried to keep state within the Fibonacci function to remember the last Fibonacci number using Functors and Lamdas
         Did not figure out how to pass a function pointer to a functor.  Finally, settled for using static variables to 
         keep track of the last two Fibonacci numbers within isFibonacci.  Now, the running time for the sum of the first 
         48 Fibonacci numbers goes down to 99 seconds
         
   FUTURE WORK: The code is still too slow for both Fibonacci and for primes. For Fibonacci, a future version would jump 
   directly to the next Fibonacci number without incrementing the integers one at a time. This would require redefining 
   the increment operator. The prime code is also too slow and needs to be rewritten using the sieve of Eratosthenes.
   Should be easy to add alternating sums to the main loop by keeping a sign variable that stays one for positive sums
   
   . 
  
         
         

