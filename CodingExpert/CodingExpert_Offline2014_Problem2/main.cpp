#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int T, R;
    int min, max, newMin, newMax, command, previous, current;
    
    cin >> T;
    while (T--)
    {
        min = 1;
        newMin = newMax = 0;
        cin >> max >> R;
        cin >> previous >> command;
        R--;
        while (R--)
        {
            cin >> current >> command;
            if (command == 0)
            {
                if (previous > current)
                {
                    newMin = min;
                    newMax = (previous + current - 1) * 0.5;
                }
                else if (previous < current)
                {
                    newMin = ((previous + current) * 0.5) + 1;
                    newMax = max;
                }
            }
            else if (command == 1)
            {
                if (previous < current)
                {
                    newMin = min;
                    newMax = (previous + current - 1) * 0.5;
                }
                else if (previous > current)
                {
                    newMin = ((previous + current) * 0.5) + 1;
                    newMax = max;
                }
            }
            else if (previous != current)
            {
                newMin = newMax = (previous + current) * 0.5;
            }
            
            if (newMin > min)
            {
                min = newMin;
            }
            if (newMax < max)
            {
                max = newMax;
            }
            previous = current;
            
            cout << max - min + 1 << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
2 
10 4
1 0
10 0
4 2
7 0
10 5
1 0
10 1
5 0
1 0
2 0
=====
5 1 1
5 5 2 1
*/

