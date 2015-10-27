int stringToInteger(string str) {
	int sign, i, n;
	
	n = 0;
	if (str.size() == 0) return n;

	i = 0;
	sign = 1;
	if (str[i] == '-') {
		i = 1;
		sign = -1;
	}

	while (i < str.size()) {
		n = n * 10 + (str[i] - '0');
		i++;
	}

	n = n * sign;

	return n;
}
