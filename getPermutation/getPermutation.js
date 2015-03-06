getPermutation = function(i) {
    var arr = [1, 2, 3, 4, 5];
    var l, f;
    var result = [];
    
    l = arr.length;
    
    f = 1;
    while(--l) f *= l;
    
    l = arr.length - 1;
    while (l) {
        result.push(arr.splice(parseInt(i / f), 1)[0]);
        i = i % f;
        f /= l;
        l--;
    }
    result.push(arr.splice(0, 1)[0]);
    
    return result;
}
//nPn에서 해당 순서의 i번쨰 순열을 찾는 함수
