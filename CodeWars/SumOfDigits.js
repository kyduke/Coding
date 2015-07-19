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
