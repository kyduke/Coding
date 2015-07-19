// http://www.codewars.com/kata/520b9d2ad5c005041100000f/train/javascript

function pigIt(string){
  var arr, i;
  var makePig = function(str) {
    return (str == '') ? '' : str.substr(1) + str.substr(0, 1) + 'ay';
  };
  
  arr = string.split(' ');
  for (i in arr) {
    arr[i] = makePig(arr[i]);
  }
  
  return arr.join(' ');
}

/*
Test.assertEquals(pigIt('Pig latin is cool'),'igPay atinlay siay oolcay')
Test.assertEquals(pigIt('This is my string'),'hisTay siay ymay tringsay')
*/
