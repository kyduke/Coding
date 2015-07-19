// http://www.codewars.com/kata/541c8630095125aba6000c00

var digital_root = function(n) {
    var str, i;
    str = '' + n;
    while (str.length > 1) {
        n = 0;
        for (i in str) {
            n += parseInt(str[i]);
        }
        str = '' + n;
    }
    return n;
}
