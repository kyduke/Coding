string integerToString(long long n) {
	string str;
	string table[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	int sign;
	
	if (n == 0) return "0";

	sign = 1;
	if (n < 0) {
		sign = -1;
		n = -n;
	}

	str = "";
	while (n) {
		str = table[n % 10] + str;
		n /= 10;
	}

	if (sign == -1) {
		str = "-" + str;
	}

	return str;
}
