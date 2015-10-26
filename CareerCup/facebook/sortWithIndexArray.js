function sort(A, B) {
	var temp, from, to, idx;
	
	if (!(A instanceof Array) || !(B instanceof Array)) return;
	if (A.length != B.length) return;
	
	for (from = 0; from < A.length; from++) {
		to = B[from];
		if (from == to) continue;
		temp = A[from];
		A[from] = A[to];
		A[to] = temp;
		idx = B.indexOf(from);
		if (idx > from) {
			B[idx] = to;
		}
	}
}

A = ['C', 'D', 'E', 'F', 'G'];
B = [3, 0, 4, 1, 2];

sort(A, B);
