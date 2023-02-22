bool is_prime(long long int n)
{
	if(n == 2 || n == 3) return true;
	if(n % 6 != 1 && n % 6 != 5) return false;
	long long int tmp = sqrt(n);
	for(int i = 5; i <= tmp; i += 6)
		if(n % i == 0 || n % (i+2) == 0) return false;
	return true;
}

