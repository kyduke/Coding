// http://www.codewars.com/kata/52b757663a95b11b3d00062d/train/javascript

function toWeirdCase(string){
  var arr, i;
  var makeCamelOddEven = function(str) {
    var cases, arr, i;
    if (str == '') return '';
    
    cases = [str.toUpperCase(), str.toLowerCase()];
    arr = [];
    for (i in str) {
      arr[i] = cases[i % 2][i];
    }
    
    return arr.join('');
  };
  
  arr = string.split(' ');
  for (i in arr) {
    arr[i] = makeCamelOddEven(arr[i]);
  }
  
  return arr.join(' ');
}

/*
Test.assertEquals(toWeirdCase('This'), 'ThIs');
Test.assertEquals(toWeirdCase('is'), 'Is');
Test.assertEquals(toWeirdCase('This is a test'), 'ThIs Is A TeSt');
*/
