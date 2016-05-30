//
//  main.cpp
//  CodersHigh_2016B_Starman
//
//  Created by ydkoh on 5/30/16.
//  Copyright (c) 2016 ydkoh. All rights reserved.
//
// https://www.acmicpc.net/problem/12791

#include <iostream>
#include <string>

using namespace std;

void solve(int s, int e) {
    int years[25] = {1967, 1969, 1970, 1971, 1972, 1973, 1973, 1974, 1975, 1976, 1977, 1977, 1979, 1980, 1983, 1984, 1987, 1993, 1995, 1997, 1999, 2002, 2003, 2013, 2016};
    string albums[25] = {"DavidBowie", "SpaceOddity", "TheManWhoSoldTheWorld", "HunkyDory", "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars", "AladdinSane", "PinUps", "DiamondDogs", "YoungAmericans", "StationToStation", "Low", "Heroes", "Lodger", "ScaryMonstersAndSuperCreeps", "LetsDance", "Tonight", "NeverLetMeDown", "BlackTieWhiteNoise", "1.Outside", "Earthling", "Hours", "Heathen", "Reality", "TheNextDay", "BlackStar"};
    int i, cnt;
    
    cnt = 0;
    for (i = 0; i < 25; i++) {
        if (s <= years[i] && years[i] <= e) cnt++;
    }
    
    cout << cnt << "\n";
    
    if (cnt == 0) return;
    
    for (i = 0; i < 25; i++) {
        if (s <= years[i] && years[i] <= e) {
            cout << years[i] << " " << albums[i] << "\n";
        }
    }
}

int main(int argc, const char * argv[]) {
    int T, s, e;
    
    cin >> T;
    while (T--) {
        cin >> s >> e;
        solve(s, e);
    }
    
    return 0;
}

/*
3
1973 1973
1977 1979
2014 2015
=====
2
1973 AladdinSane
1973 PinUps
3
1977 Low
1977 Heroes
1979 Lodger
0

1
1 2016
=====
25
1967 DavidBowie
1969 SpaceOddity
1970 TheManWhoSoldTheWorld
1971 HunkyDory
1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars
1973 AladdinSane
1973 PinUps
1974 DiamondDogs
1975 YoungAmericans
1976 StationToStation
1977 Low
1977 Heroes
1979 Lodger
1980 ScaryMonstersAndSuperCreeps
1983 LetsDance
1984 Tonight
1987 NeverLetMeDown
1993 BlackTieWhiteNoise
1995 1.Outside
1997 Earthling
1999 Hours
2002 Heathen
2003 Reality
2013 TheNextDay
2016 BlackStar
*/
