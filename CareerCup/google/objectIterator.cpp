// http://careercup.com/question?id=5726732524978176

#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Iterator {
	T obj;
	int cnt;
	Iterator(T e, int n) : obj(e), cnt(n) {}
	bool operator() (T& ret) {
		if (cnt > 0) {
			cnt--;
			ret = obj;
			return true;
		}
		return false;
	}
};

template <typename T>
Iterator<T> repeat(T e, int n) {
	Iterator<T> iterator(e, n);
	return iterator;
}

struct Object {
	int value;
	string name;
};

int main(int argc, char* argv[]) {
	int n = 3;
	Iterator<int> integerIterator = repeat(n, 5);

	n = -1;
	while (integerIterator(n)) {
		cout << n << " ";
	}
	cout << "\n";

	Object obj;
	obj.value = 7;
	obj.name = "ABC";
	Iterator<Object> objectIterator = repeat(obj, 3);
	
	obj.value = -1;
	obj.name = "";
	while (objectIterator(obj)) {
		cout << "(" << obj.value << ", " << obj.name << ") ";
	}
	cout << "\n";

    return 0;
}
