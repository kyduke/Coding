function ipToInt32(ip){
  var arr, result, i;
  var D2H = function(n) {
    var str = '0' + Number(n).toString(16);
    return str.substring(str.length - 2);
  };
  
  arr = ip.split('.');
  result = '0x';
  for (i in arr) {
    result += D2H(arr[i]);
  }
  
  return parseInt(result, 16);
}
