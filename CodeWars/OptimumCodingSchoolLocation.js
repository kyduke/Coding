// http://www.codewars.com/kata/55738b0cffd95756c3000056

var optimumLocation = function(students, locations) {
    var distance, minDistance, minIndex;
    var cityBlockDistance = function(p, q) {
        return Math.abs(p[0] - q[0]) + Math.abs(p[1] - q[1]);
    };

    for (var i in locations) {
        distance = 0;
        for (var j in students) {
            distance += cityBlockDistance([locations[i].x, locations[i].y], students[j]);
        }
        if (minDistance == null || minDistance > distance) {
            minDistance = distance;
            minIndex = i;
        }
    }

    return 'The best location is number ' + locations[minIndex].id + ' with the coordinates x = ' + locations[minIndex].x + ' and y = ' + locations[minIndex].y;
}
