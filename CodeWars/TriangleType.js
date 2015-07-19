// http://www.codewars.com/kata/53907ac3cd51b69f790006c5/train/javascript

/* Should return ᐃ type:
  0 : if ᐃ cannot be made with given sides
  1 : acute ᐃ
  2 : right ᐃ
  3 : obtuse ᐃ
*/
function triangleType(a, b, c){
  var d, dd2, aabbcc, aabb;
  var max = function(x, y) {
    return (x >= y) ? x : y;
  };
  
  d = max(max(a, b), c);
  
  if ((a + b + c - d - d) <= 0) return 0;
  
  dd2 = d * d * 2;
  aabbcc = a * a + b * b + c * c;
  aabb = dd2 - aabbcc;
  
  return (aabb == 0) ? 2 : Math.abs(aabb) / aabb + 2;
}

/*
Test.assertEquals(triangleType(7,3,2), 0); // Not triangle
Test.assertEquals(triangleType(2,4,6), 0); // Not triangle
Test.assertEquals(triangleType(8,5,7), 1); // Acute
Test.assertEquals(triangleType(3,4,5), 2); // Right
Test.assertEquals(triangleType(7,12,8), 3); // Obtuse
*/
