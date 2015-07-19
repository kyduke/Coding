// http://www.codewars.com/kata/5202ef17a402dd033c000009

function titleCase(title, minorWords) {
    var titleArray, minorArray, i;
    
    titleArray = title.toLowerCase().split(' ');
    minorArray = (minorWords) ? minorWords.toLowerCase().split(' ') : [];
    
    for (i in titleArray) {
        if (i != 0 && minorArray.indexOf(titleArray[i]) >= 0) continue;
        if (titleArray[i].length == 0) continue;
        titleArray[i] = titleArray[i][0].toUpperCase() + titleArray[i].substring(1);
    }
    
    return titleArray.join(' ');
}
