# include <iostream>

bool isPrime(int n) // This is a function that checks if n is a prime.
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true; 
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
	

	return 0; 
}