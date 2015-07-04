// http://www.careercup.com/question?id=5696520106016768

var orderByInput = [];
var orderByValue = [];

var findMaxInWindow = function (windowSize, value) {
  var maxInWindow = orderByValue[0] || value;
  
  orderByInput.push(value);
  if (maxInWindow > value) {
    orderByValue.push(value);
  } else {
    orderByValue.splice(0, 0, value);
    maxInWindow = value;
  }

  if (orderByInput.length > windowSize) {
    var removeIndex = orderByValue.indexOf( orderByInput.shift() );
    orderByValue.splice(removeIndex, 1);
    if (removeIndex == 0) {
        orderByValue.sort(function(a, b){return b - a});
        maxInWindow = orderByValue[0];
    }
  }
  
  return maxInWindow;
}


var main = function ( ){
  var windowSize = 3;
  var stream = [1, 4, 2, 7, 9, 15, 11, 26, 96, 56, 3, 15, 25];

  for (var i = 0 ; i < stream.length; i++) {
    console.log (i + " ) " + stream[i] +" -  MAX : " + findMaxInWindow(windowSize, stream[i]));
  }
}

main();
