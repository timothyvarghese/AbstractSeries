# AbstractSeries
Want to create abstract code to sum across various functions of 
various special numbers like primes, perfect numbers, fibonacci numbers 
etc

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

Warning: User must enter start as a correct special number.  For 
         example, if user enters 2 for first twin prime, the sum
         will be incorrect but it will be correct for primes.  User
         should enter 3 for first twin prime or can start at any valid
         twin prime

