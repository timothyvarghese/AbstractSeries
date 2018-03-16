# include <iostream>

bool isPrime(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;
	return true; 
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
	std::cout << "The sum of the first " << max << " primes is " << sum << "\n"; 

	/*
	sum = 0; 
	for (int i = 2; i <= max; i++) { // Goes through all integers less than max
		if (isPerfect(i) == true) { // Update if i is a perfect number
			sum = sum + i;
			std::cout << i << " is a perfect number \n";
		}
	}
	std::cout << "The sum of the first " << max << " perfect numbers is " << sum << "\n";
	*/

	return 0; 
}