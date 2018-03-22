# include <iostream>
# include <time.h>

// Now we abstract the code using an iterator and function pointers to abstract across
// isPrime and isPerfect so we can add new functions in the future without cutting and pasting

class SpecialintIterator {
public:
	SpecialintIterator(unsigned long long start) {position = start;}
	void next(bool(*specialintfunction) (unsigned long long)) // Jumps to the next special int
		// Based on specialintfunction which takes an integer as a parameter
		// and returns true if the number is a special number
	{
		position++; // Go to the first position after the last special number
		while (specialintfunction(position) != true) // While not special
			position++; 
	}; 
	unsigned long long getSpecialInt() { return position; } // Return the current special integer
	void printSpecialInt() { std::cout << "The special integer is " << position << "\n"; }
private:
	unsigned long long  position; // The current or last position of the last integer 

}; 

// Special Number detection functions. Add new special number functions  here 

// isPrime Not as efficient as my earlier code which used the sieve of eratosthenes
// but probably requires functors to remember all sieved integers

bool isPrime(unsigned long long n) // This is a function that checks if n is a prime.
{
	for (unsigned long long i = 2; i < n; i++) // Go through all the integers less than n
		if (n % i == 0) // if n divides evenly it is not a prime
			return false;
	return true; // if no integer divides return true
}

bool isFibonacci(unsigned long long n) // This is a function that checks if n is a Fibonacci.
{
	unsigned long long last = 1; // Create last as an int and initialize it to 1, Last Fibonacci 
	unsigned long long secondlast = 1; // This represents the second last Fibonacci number
	unsigned long long fib= 0 ; // The current Fibonacci number
	for (unsigned long long i = 1; fib < n; i++)
	{
		fib = last + secondlast; // The recurrence for Fibonacci
		secondlast = last; // Update secondlast to be the last number	
		last = fib; // Updating last to the current Fibonacci
	}
	if (n == fib)
		return true; 
	else
		return false; 
}


bool isTwinPrime(unsigned long long n) // This is a function that checks if n is a twin prime.
{
	// n is a twin prime if n and n+2 are both prime
	if (isPrime(n) && isPrime(n+2)) 
			return true;
	else return false;
}
bool isCousinPrime(unsigned long long n) // This is a function that checks if n is a cousin prime.
{
	// n is a cousin prime if n and n+4 are both prime
	if (isPrime(n) && isPrime(n + 4))
		return true;
	else return false; // 
}
bool isPerfect(unsigned long long n) // This is a function that checks if n is a perfect.
// A number is perfect when that number is the sum of all its factors
// Hence, to check if a number is perfect, we have to find all the factors and add
// them and check if the sum is equal to the number
{
	unsigned long long sum = 0; 
	for (unsigned long long i = 1; i < n; i++)
		if (n % i == 0)
			sum= sum + i ;
	if (sum == n) return true; 
	else return false;
}



// Apply is an abstract function that takes two parameters. The first is a function and 
// the second is an integer and it returns the function applied to the integer. 
// We are going to use it to square, cube numbers etc, while keeping the basic sum 
// framework as abstract or generic as possible

template<typename T>

T apply(T (*f) (unsigned long long), unsigned long long x)
{
	return f(x);
}

// add new concrete transformations here 

unsigned long long linear(unsigned long long x)
{
	return x;
}

double reciprocal(unsigned long long x)
{
	return (1.0/x);
}

unsigned long long square(unsigned long long x)
{
	return x*x;
}

unsigned long long cube(unsigned long long x)
{
	return x*x*x;
}

int main()
{
	// Taking code to measure time from Stack Overflow (14433728)
	clock_t t = clock(); // Record current time in t 
	std::cout << "Enter the special number to be summed:\n";
	std::cout << "1. Primes \n";
	std::cout << "2. Twin Primes \n";
	std::cout << "3. Cousin Primes \n";
	std::cout << "4. Perfect Numbers \n";
	std::cout << "5. Fibonacci Numbers \n "; 
	int specialcode;
	std::cin >> specialcode;

	bool(*specialFunction)(unsigned long long); // function to tell whether an integer is special

	switch (specialcode)
	{
	case 1:  specialFunction = isPrime;
			 std::cout << "Special numbers being summed are primes \n";
			 break;
	case 2:  specialFunction = isTwinPrime;
			 std::cout << "Special numbers being summed are twin primes \n";
		     break;
	case 3: specialFunction = isCousinPrime;
			std::cout << "Special numbers being summed are cousin primes \n";
		    break;
	case 4: specialFunction = isPerfect;
			std::cout << "Special numbers being summed are perfect numbers \n";
			break; 
	case 5: specialFunction = isFibonacci; 
			std::cout << "Special numbers being summed are Fibonacci numbers \n "; 
			break; 
	// add new special function cases here
	default: std::cout << "Invalid special number code \n";
	}

	bool isFloat = false; 
	std::cout << "Enter the kind of transformation to be summed:\n";

	std::cout << "1. Linear \n";
	std::cout << "2. Squares \n";
	std::cout << "3. Cubes \n";
	std::cout << "4. Reciprocal \n";
	int functioncode;
	std::cin >> functioncode;
	
	unsigned long long (*transformFunction)(unsigned long long); //  What transformation of special number to be summed? 
	double(*transformFunctionfloat)(unsigned long long); //  What transformation of special number to be summed? 

	switch (functioncode)
	{
	case 1:  transformFunction = linear;
			 std::cout << "Transformation is identity function \n";
			 break;
	case 2:  transformFunction = square;
			 std::cout << "Transformation is squaring \n";
			 break;
	case 3: transformFunction = cube;
			std::cout << "Transformation is cubing \n";
			break;
	case 4: transformFunctionfloat = reciprocal;
			std::cout << "Transformation is taking reciprocals \n";
		    isFloat = true; 
		    break;

	// add new transformations here
	default: std::cout << "Invalid function code \n";
	}
	int start;
	std::cout << "Enter the special number to start the sequence:\n";
	std::cin >> start;

	int max ;
	std::cout << "Enter the number of special numbers to be summed:\n";
	std::cin >> max;

	SpecialintIterator s(start); // Create a special number iterator starting at 2
	unsigned long long sum = 0; // Sum is initialized to 0
	for (unsigned long long i = 0; i < max; s.next(specialFunction)) {
		// Go through all special numbers as indicated by special function
		if (isFloat == true)
			sum = sum + apply<double>(transformFunctionfloat, s.getSpecialInt());
		else
			sum = sum + apply<unsigned long long>(transformFunction, s.getSpecialInt());
		// update the sum to include the transformed special number
		i++;
		s.printSpecialInt(); // Print the special number
	}
	std::cout << "The sum of the first  " << max << " transformed special numbers is " << sum << "\n";


	/* concrete code, first attempts before abstracting, now commented out
	int max = 10;
	int sum = 0;

	for (int i = 2; i <= max; i++) { // Goes through all integers less than max
		if (isPrime(i) == true) { // Update if i is a prime 
			sum = sum + i;
			std::cout << i << " is a prime \n";
		}
	}
	std::cout << "The sum of the primes less than " << max << " is " << sum << "\n";


	sum = 0;
	for (int i = 2; i <= max; i++) { // Goes through all integers less than max
		if (isPerfect(i) == true) { // Update if i is a perfect number
			sum = sum + i;
			std::cout << i << " is a perfect number \n";
		}
	}
	std::cout << "The sum of the perfect numbers less than " << max << " is " << sum << "\n";

	// Rewrite code above with abstract iterator

	SpecialintIterator p(2); // Create a prime iterator starting at 2
	sum = 0; // Sum is initialized to 0
	for (int i = 0; i < max; p.next(isPrime)) {
		sum = sum + p.getSpecialInt();
		i++;
		p.printSpecialInt();
	}
	std::cout << "The sum of the first  " << max << " special numbers is " << sum << "\n";

	SpecialintIterator p(2); // Create a prime iterator starting at 2
	sum = 0; // Sum is initialized to 0
	for (int i = 0; i < max; p.next(isTwinPrime)) {
		sum = sum + apply(square,p.getSpecialInt());
		i++;
		p.printSpecialInt();
	}
	std::cout << "The sum of the first  " << max << " special numbers is " << sum << "\n";
	*/
	std::cout << "\n time taken in seconds: " << (float)(clock() - t) / CLOCKS_PER_SEC << "\n"; 
	return 0; 
} 