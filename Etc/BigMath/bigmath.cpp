#include <iostream>
#include <vector>

using namespace std;

// bic number mathmatics for vector<char>
class BigMath
{
public:
	void print(vector<char>&);
	void normalize(vector<char>&);
	int compare(vector<char>&, vector<char>&);
	vector<char> abs(vector<char>&);
	vector<char> minus(vector<char>&);
	vector<char> add(vector<char>&, vector<char>&);
	vector<char> subtract(vector<char>&, vector<char>&);
	vector<char> multiply(vector<char>&, vector<char>&);
	vector<char> divide(vector<char>&, vector<char>&);
	vector<char> modulus(vector<char>&, vector<char>&);
};

void BigMath::print(vector<char>& num)
{
	for (vector<char>::iterator it = num.begin(); it != num.end(); it++) cout << (int)*it;
	cout << "\n";
}

void BigMath::normalize(vector<char>& num)
{
	vector<char>:: iterator it;
	vector<char>::reverse_iterator rit;
	char n, c;
	int sign = 1;

	if (num[0] < 0)
	{
		sign = -1;
		num[0] = -num[0];
	}

	n = 0;
	for (rit = num.rbegin(); rit != num.rend(); rit++)
	{
		*rit += n;
		n = *rit / 10;
		*rit %= 10;
		if (*rit < 0 && n) *rit = -*rit;
	}

	while (n)
	{
		c = n % 10;
		n /= 10;
		if (c < 0 && n) c = -c;
		num.insert(num.begin(), c);
	}

	it = num.begin();
	while (it != num.end())
	{
		if (*it == 0) it = num.erase(it);
		else break;
	}

	if (num.size() == 0) num.push_back(0);

	if (sign < 0) num[0] = -num[0];
}

int BigMath::compare(vector<char>& a, vector<char>& b)
{
	vector<char>::iterator ita, itb;
	int sign = 1;

	if (a[0] < 0 && b[0] >= 0) return -1;
	if (a[0] >= 0 && b[0] < 0) return 1;
	if (a[0] == 0 && b[0] == 0) return 0;
	if (a[0] < 0 && b[0] < 0) sign = -1;

	if (a.size() > b.size()) return sign;
	if (a.size() < b.size()) return -sign;

	ita = a.begin();
	itb = b.begin();
	while (ita != a.end())
	{
		if (*ita > *itb) return sign;
		if (*ita < *itb) return -sign;
		ita++;
		itb++;
	}

	return 0;
}

vector<char> BigMath::abs(vector<char>& num)
{
	vector<char> r = num;
	if (r[0] < 0) r[0] = -r[0];
	return r;
}

vector<char> BigMath::minus(vector<char>& num)
{
	vector<char> r = num;
	r[0] = -r[0];
	return r;
}

vector<char> BigMath::add(vector<char>& a, vector<char>& b)
{
	vector<char>::reverse_iterator ra, rb;
	vector<char> r;
	char n;
	int sign = 1;

	if (a[0] < 0 && b[0] > 0) return subtract(b, minus(a));
	if (a[0] > 0 && b[0] < 0) return subtract(a, minus(b));
	if (a[0] < 0)
	{
		sign = -1;
		a[0] = -a[0];
	}
	if (b[0] < 0)
	{
		sign = -1;
		b[0] = -b[0];
	}

	n = 0;
	ra = a.rbegin();
	rb = b.rbegin();
	while (ra != a.rend() || rb != b.rend())
	{
		if (ra != a.rend())
		{
			n += *ra;
			ra++;
		}
		if (rb != b.rend())
		{
			n += *rb;
			rb++;
		}
		r.insert(r.begin(), n % 10);
		n /= 10;
	}

	while (n)
	{
		r.insert(r.begin(), n % 10);
		n /= 10;
	}

	if (sign < 0)
	{
		a[0] = -a[0];
		b[0] = -b[0];
		r[0] = -r[0];
	}

	return r;
}

vector<char> BigMath::subtract(vector<char>& a, vector<char>& b)
{
	vector<char>::reverse_iterator ra, rb, rae, rbe;
	vector<char> r;
	char n, c;
	int sign, signA;

	if (a[0] > 0 && b[0] < 0) return add(a, minus(b));
	if (a[0] < 0 && b[0] > 0) return add(minus(a), b);

	signA = 1;
	if (a[0] < 0)
	{
		signA = -1;
		a[0] = -a[0];
		b[0] = -b[0];
	}

	if (compare(a, b) >= 0)
	{
		ra = a.rbegin();
		rb = b.rbegin();

		rae = a.rend();
		rbe = b.rend();

		sign = 1;
	}
	else
	{
		ra = b.rbegin();
		rb = a.rbegin();

		rae = b.rend();
		rbe = a.rend();

		sign = -1;
	}

	n = 0;
	while (ra != rae || rb != rbe)
	{
		if (ra != rae)
		{
			n += *ra;
			ra++;
		}
		if (rb != rbe)
		{
			n -= *rb;
			rb++;
		}
		c = n % 10;
		n /= 10;
		if (c < 0)
		{
			n += -1;
			c = 10 + c;
		}
		r.insert(r.begin(), c);
	}

	while (n)
	{
		c = n % 10;
		n /= 10;
		if (c < 0 && n) c = -c;
		r.insert(r.begin(), c);
	}

	if (signA < 0)
	{
		a[0] = -a[0];
		b[0] = -b[0];
	}

	normalize(r);

	if (sign * signA < 0) r[0] = -r[0];

	return r;
}

vector<char> BigMath::multiply(vector<char>& a, vector<char>& b)
{
	vector<char>::reverse_iterator ra, rb;
	vector<char> r;
	char n;
	int index, length;
	int signA, signB;

	if (a[0] == 0 || b[0] == 0)
	{
		r.push_back(0);
		return r;
	}
	signA = 1;
	if (a[0] < 0)
	{
		signA = -1;
		a[0] = -a[0];
	}
	signB = 1;
	if (b[0] < 0)
	{
		signB = -1;
		b[0] = -b[0];
	}

	length = a.size() + b.size() - 1;
	n = length;
	while (n--)
	{
		r.push_back(0);
	}

	ra = a.rbegin();
	while (ra != a.rend())
	{
		rb = b.rbegin();
		while (rb != b.rend())
		{
			n = *ra * *rb;
			index = length - 1 - ((ra - a.rbegin()) + (rb - b.rbegin()));
			r[index] += n;
			rb++;
		}
		ra++;
	}

	if (signA < 0) a[0] = -a[0];
	if (signB < 0) b[0] = -b[0];
	if (signA * signB < 0) r[0] = -r[0];

	normalize(r);

	return r;
}

vector<char> BigMath::divide(vector<char>& a, vector<char>& b)
{
	vector<char> r, c, x, z;
	char n;
	int index, length;
	int signA, signB;

	length = compare(abs(a), abs(b));
	if (length < 0)
	{
		r = a;
		return r;
	}
	if (length == 0)
	{
		r.push_back(0);
		return r;
	}

	signA = 1;
	if (a[0] < 0)
	{
		signA = -1;
		a[0] = -a[0];
	}
	signB = 1;
	if (b[0] < 0)
	{
		signB = -1;
		b[0] = -b[0];
	}

	length = a.size() - b.size() + 1;
	n = length;
	while (n--)
	{
		r.push_back(0);
	}

	z.push_back(0);
	x = a;
	index = 0;
	while (index < length)
	{
		r[index] = 1;
		c = r;
		normalize(c);
		c = multiply(c, b);
		r[index] = 0;

		x = subtract(x, c);
		while (compare(x, z) >= 0)
		{
			r[index]++;
			x = subtract(x, c);
		}
		x = add(x, c);
		index++;
	}

	if (signA < 0) a[0] = -a[0];
	if (signB < 0) b[0] = -b[0];

	normalize(r);

	if (signA * signB < 0) r[0] = -r[0];

	return r;
}

vector<char> BigMath::modulus(vector<char>& a, vector<char>& b)
{
	vector<char> r, c, x;
	char n;
	int index, length;
	int signA, signB;

	length = compare(abs(a), abs(b));
	if (length < 0)
	{
		r = a;
		return r;
	}
	if (length == 0)
	{
		r.push_back(0);
		return r;
	}

	signA = 1;
	if (a[0] < 0)
	{
		signA = -1;
		a[0] = -a[0];
	}
	signB = 1;
	if (b[0] < 0)
	{
		signB = -1;
		b[0] = -b[0];
	}

	length = a.size() - b.size() + 1;
	n = length;
	while (n--)
	{
		r.push_back(0);
	}

	x = a;
	index = 0;
	while (index < length)
	{
		r[index] = 1;
		c = r;
		normalize(c);
		c = multiply(c, b);
		r[index] = 0;

		x = subtract(x, c);
		while (x[0] > 0)
		{
			r[index]++;
			x = subtract(x, c);
		}
		x = add(x, c);
		index++;
	}

	if (signA < 0) a[0] = -a[0];
	if (signB < 0) b[0] = -b[0];

	r = x;
	normalize(r);

	if (signA < 0) r[0] = -r[0];

	return r;
}

int main(int argc, char* argv[])
{
	BigMath math;
	vector<char> numA, numB, numC;

	numA.push_back(0);
	numA.push_back(0);
	numA.push_back(0);
	numA.push_back(-41);
	numA.push_back(0);

	numB.push_back(0);
	numB.push_back(0);
	numB.push_back(0);
	numB.push_back(-42);
	numB.push_back(0);

	cout << "A: ";
	math.normalize(numA);
	math.print(numA);

	cout << "B: ";
	math.normalize(numB);
	math.print(numB);

	cout << "comapare -410 > -420 = " << (-410 > -420) << "\n";
	cout << math.compare(numA, numB) << "\n";

	cout << "add -410 + -420 = " << (-410 + -420) << "\n";
	numC = math.add(numA, numB);
	math.print(numC);

	cout << "subtract 410 - 420 = " << (410 - 420) << "\n";
	numC = math.subtract(math.minus(numA), math.minus(numB));
	math.print(numC);

	cout << "multiply -410 * -420 = " << (-410 * -420) << "\n";
	numC = math.multiply(numA, numB);
	math.print(numC);

	cout << "multiply 410 * -420 = " << (410 * -420) << "\n";
	numC = math.multiply(math.minus(numA), numB);
	math.print(numC);

	numA.clear();
	numA.push_back(-2);
	numA.push_back(9);
	numA.push_back(9);

	numB.clear();
	numB.push_back(-3);
	numB.push_back(9);

	cout << "divide -299 * -39 = " << (-299 / -39) << "\n" ;
	numC = math.divide(numA, numB);
	math.print(numC);

	cout << "modulus -299 % -39 = " << (-299 % -39) << "\n" ;
	numC = math.modulus(numA, numB);
	math.print(numC);

	return 0;
}
