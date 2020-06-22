#include "fraction.h"


	Fraction::Fraction(long long num, long long denom)
	{
		if (denom == 0)
			throw std::overflow_error("Division by 0");
		numerator = num;
		denominator = denom;
		simplify();
	}

	Fraction::Fraction(double d)
	{
		double integralPart, fractionalPart = modf(d, &integralPart);
		int base10Exponent = 0;
		while (fractionalPart != 0)
		{
			d = d * 10;
			base10Exponent++;
			fractionalPart = modf(d, &integralPart);			
		}
		numerator = integralPart;
		denominator = pow(10, base10Exponent);
		simplify();
	}

	Fraction::Fraction()
	{
		numerator = 0;
		denominator = 1;
	}	

	long long Fraction::getNumerator()
	{
		return numerator;
	}
	long long Fraction::getDenominator()
	{
		return denominator;
	}
	void Fraction::setNumerator(long long n)
	{
		numerator = n;	
		simplify();
	}
	void Fraction::setDenominator(long long n)
	{
		if (n != 0)
			denominator = n;	
		simplify();
	}

	void Fraction::simplify()
	{
		long long i_gcd =gcd(getNumerator(),getDenominator());
		numerator /= i_gcd;
		denominator /= i_gcd;
		if ((numerator < 0 && denominator < 0) || (denominator < 0 && numerator > 0))
		{
			numerator *= -1;
			denominator *= -1;
		}		
	}

	long long Fraction::gcd(long long a, long long b)
	{
		long long _a { (std::abs(a) > std::abs(b)) ? std::abs(a) : std::abs(b) };
		long long _b { (_a != std::abs(a)) ? std::abs(a) : std::abs(b) };
		while (_b != 0)
		{
			long long temp = _a % _b;
			_a = _b;
			_b = temp;
		}
		return _a;
	}	

	long long Fraction::lcm(long long a, long long b)
	{
		return a * (b / gcd(a,b));
	}

	Fraction Fraction::operator+(const Fraction &f)
	{
		long long _lcm = lcm(denominator, f.denominator);
		return Fraction (numerator * (_lcm / denominator) + f.numerator * (_lcm / f.denominator),_lcm);				
	}

	Fraction Fraction::operator+(const long long &f)
	{
		return Fraction (numerator + f * denominator, denominator);		
	}

	void Fraction::operator+=(const Fraction &f)
	{
		long long _lcm = lcm(denominator, f.denominator);
		Fraction res(numerator * (_lcm / denominator) + f.numerator * (_lcm / f.denominator), _lcm);		
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}

	void Fraction::operator+=(const long long & f)
	{
		Fraction res(numerator + f * denominator, denominator);
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}

	Fraction Fraction::operator-(const Fraction &f)
	{
		long long _lcm = lcm(denominator, f.denominator);
		return Fraction (numerator * (_lcm / denominator) - f.numerator * (_lcm / f.denominator),_lcm);				
	}

	Fraction Fraction::operator-(const long long & f)
	{
		return Fraction (numerator - f * denominator, denominator);		
	}

	Fraction Fraction::operator*(const Fraction & f)
	{
		return Fraction(numerator * f.numerator,denominator * f.denominator);
	}

	Fraction Fraction::operator*(const long long & f)
	{
		return Fraction(numerator * f, denominator);
	}

	Fraction Fraction::operator/(const Fraction & f)
	{
		return Fraction(numerator * f.denominator, denominator * f.numerator);
	}

	Fraction Fraction::operator/(const long long & f)
	{
		return Fraction(numerator, denominator * f);
	}

	void Fraction::operator-=(const Fraction &f)
	{
		long long _lcm = lcm(denominator, f.denominator);
		Fraction res(numerator * (_lcm / denominator) - f.numerator * (_lcm / f.denominator), _lcm);		
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}

	void Fraction::operator-=(const long long & f)
	{
		Fraction res(numerator - f * denominator, denominator);
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}

	void Fraction::operator*=(const Fraction & f)
	{
		Fraction res(numerator * f.numerator, denominator * f.denominator);
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}

	void Fraction::operator/=(const Fraction & f)
	{
		Fraction res(numerator * f.denominator, denominator * f.numerator);
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}

	void Fraction::operator*=(const long long & f)
	{
		Fraction res(numerator * f, denominator);
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}

	void Fraction::operator/=(const long long & f)
	{
		Fraction res(numerator, denominator * f);
		numerator = res.getNumerator();
		denominator = res.getDenominator();
	}


	bool Fraction::operator==(const Fraction &f)
	{
		return (numerator == f.numerator && denominator == f.denominator);
	}
	bool Fraction::operator!=(const Fraction & f)
	{
		return (numerator != f.numerator || denominator != f.denominator);
	}

	bool Fraction::operator<(const Fraction & f)
	{
		return (double)numerator/denominator < (double)f.numerator/f.denominator;
	}

	bool Fraction::operator<=(const Fraction & f)
	{
		return (double)numerator / denominator <= (double)f.numerator / f.denominator;
	}

	bool Fraction::operator>(const Fraction & f)
	{
		return (double)numerator / denominator > (double)f.numerator / f.denominator;
	}

	bool Fraction::operator>=(const Fraction & f)
	{
		return (double)numerator / denominator >= (double)f.numerator / f.denominator;
	}

	Fraction Fraction::abs()
	{
		Fraction f = Fraction(numerator, denominator);
		if (f.numerator < 0)
			f.numerator *= -1;
		if (f.denominator < 0)
			f.denominator *= -1;
		return f;
	}

	int Fraction::to_int()
	{
		double integralPart;
		modf((double)numerator / denominator, &integralPart);
		return (int)integralPart;
	}

	double Fraction::to_double()
	{
		return (double)numerator / denominator;		
	}

	std::string Fraction::to_string()
	{		
		return std::string() + std::to_string(numerator) + "/" + std::to_string(denominator);
	}

	