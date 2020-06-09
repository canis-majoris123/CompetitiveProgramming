#include<bits/stdc++.h>
#define aakriti unsigned long long int
using namespace std;
aakriti gcd(aakriti a, aakriti b)
{

	while (b) {
		aakriti t = b;

		b = a % b;
		a = t;
	}
	return a;
}

aakriti max_unique_primes(aakriti n)
{
	aakriti count;
	aakriti prod;
	aakriti prim;

	if (n < 2)
		return 0;

	prod = 2;
	count = 1;
	for (prim = 3; prod * prim <= n; prim += 2) {
		if (gcd(prod, prim) == 1) {
			prod *= prim;
			count++;
		}
	}
	return count;
}

int main()
{
	aakriti q;

	cin >> q ;

	while (q--) {
		aakriti n;
        cin >> n ;
		printf("%u\n", max_unique_primes(n));
	}
	return 0;
}
