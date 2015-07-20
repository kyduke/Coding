// http://www.codewars.com/kata/559f860f8c0d6c7784000119/train/javascript

function anyArrows(arrows){
  return arrows.some(function (e) {
    if (e.damaged && e.damaged == true) return false;
    return true;
  });
}

/*
Test.assertEquals(anyArrows([]), false, "Should handle empty quiver");
Test.assertEquals(anyArrows([{range: 5}, {range: 10, damaged: true}, {damaged: true}]), true, "Should handle quiver with undamaged arrows");
Test.assertEquals(anyArrows([{range: 10, damaged: true}, {damaged: true}]), false, "Should handle quiver with damaged arrows");
*/
