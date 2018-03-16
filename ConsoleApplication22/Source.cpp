# include <iostream>

// Now we abstract the code using an iterator and function pointers to abstract across
// isPrime and isPerfect so we can add new functions in the future without cutting and pasting

class SpecialintIterator {
public:
	SpecialintIterator(int start) {position = start;}
	void next(bool(*specialintfunction) (int)) // Jumps to the next special int
		// Based on specialintfunction which takes an integer as a parameter
		// and returns true if the number is a special number
	{
		position++; // Go to the first position after the last special number
		while (specialintfunction(position) != true) // While not special
			position++; 
	}; 
	int getSpecialInt() { return position; } // Return the current special integer
	void printSpecialInt() { std::cout << "The special integer is " << position << "\n"; }
private:
	int position; // The current or last position of the last integer 
}; 


bool isPrime(int n) // This is a function that checks if n is a prime.
{
	for (int i = 2; i < n; i++) // Go through all the integers less than n
		if (n % i == 0) // if n divides evenly it is not a prime
			return false;
	return true; // if no integer divides return true
}

bool isTwinPrime(int n) // This is a function that checks if n is a twin prime.
{
	// n is a twin prime if n and n+2 are both prime
	if (isPrime(n) && isPrime(n+2)) 
			return true;
	else return false;
}
bool isCousinPrime(int n) // This is a function that checks if n is a cousin prime.
{
	// n is a cousin prime if n and n+4 are both prime
	if (isPrime(n) && isPrime(n + 4))
		return true;
	else return false; // 
}
bool isPerfect(int n) // This is a function that checks if n is a perfect.
// A number is perfect when that number is the sum of all its factors
// Hence, to check if a number is perfect, we have to find all the factors and add
// them and check if the sum is equal to the number
{
	int sum = 0; 
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			sum= sum + i ;
	if (sum == n) return true; 
	else return false;
}

int main()
{
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
	for (int i = 0; i < max; p.next(isTwinprime)) {
		sum = sum + p.getSpecialInt();
		i++;
		p.printSpecialInt();
	}
	std::cout << "The sum of the first  " << max << " special numbers is " << sum << "\n";
	return 0; 
} 