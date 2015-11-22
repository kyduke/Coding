var canArriveTarget = function(arr, visit, count, num, target) {
	var i;
	
	if (count == arr.length) {
		if (num == target) return true;
		return false;
	}
	
	for (i = 0; i < arr.length; i++) {
		if (visit[i] == 1) continue;
		visit[i] = 1;
		if (canArriveTarget(arr, visit, count + 1, num + arr[i], target) == true) return true;
		if (canArriveTarget(arr, visit, count + 1, num - arr[i], target) == true) return true;
		if (count != 0) {
			if (canArriveTarget(arr, visit, count + 1, num * arr[i], target) == true) return true;
		}
		visit[i] = 0;
	}
	
	return false;
}

var solve = function(str, target) {
	var arr, visit;
	
	arr = str.split(' ').map(function(item) {
	    return parseInt(item, 10);
	});
	if (arr.length == 0) return false;
	
	visit = arr.map(function(item) {
		return 0;
	});
	
	return canArriveTarget(arr, visit, 0, 0, target);
}
