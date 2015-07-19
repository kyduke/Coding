// http://www.codewars.com/kata/54db3f2903e88ad6c30002ff/train/javascript

var abc = function() {
    var zero, two, one;
    var ten, hundred;
    var result;
    
    zero = arguments.length;
    one = zero;
    one++;
    two = one + one;
    ten = two * two * two + two;
    hundred = ten * ten;
    
    result = String.fromCharCode(hundred - ten - ten - ten + two);
    result += String.fromCharCode(hundred + one);
    result += String.fromCharCode(hundred + ten - two);
    result += String.fromCharCode(hundred + ten - two);
    result += String.fromCharCode(hundred + ten + one);
    result += String.fromCharCode(ten + ten + ten + two);
    result += String.fromCharCode(hundred - ten - two - one);
    result += String.fromCharCode(hundred + ten + one);
    result += String.fromCharCode(hundred + ten + two + two);
    result += String.fromCharCode(hundred + ten - two);
    result += String.fromCharCode(hundred);
    result += String.fromCharCode(ten + ten + ten + two + one);
    
    return result;
};
var helloWorld = abc;
