// https://algospot.com/judge/problem/read/URI

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	char str[82];
	char result[82];
	int n, i, j;
	char c;

	cin >> n;
	while (n--) {
		cin >> str;
		i = 0;
		j = 0;
		c = str[i];
		while (c != 0) {
			if (c == '%') {
				if (str[i + 1] == '2') {
					switch (str[i + 2]) {
						case '0':
							result[j] = ' ';
							i += 2;
							break;
						case '1':
							result[j] = '!';
							i += 2;
							break;
						case '4':
							result[j] = '$';
							i += 2;
							break;
						case '5':
							result[j] = '%';
							i += 2;
							break;
						case '8':
							result[j] = '(';
							i += 2;
							break;
						case '9':
							result[j] = ')';
							i += 2;
							break;
						case 'a':
							result[j] = '*';
							i += 2;
							break;
						default:
							result[j] = c; 
					}
				} else {
					result[j] = c; 
				}
			} else {
				result[j] = c; 
			}
			i++;
			j++;
			c = str[i];
		}
		result[j] = c;
		cout << result << "\n";
	}

	return 0;
}

/*
2
Happy%20Joy%20Joy%21
http://algospot.com/%2a
=====
Happy Joy Joy!
http://algospot.com/*
*/
