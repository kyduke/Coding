#include <iostream>

using namespace std;

const int SIZE = 16;

char remains[SIZE] = "123456789ABCDEF";
char results[SIZE] = {0, };
char signs[SIZE] = {0, };
int idx = 0;

void process()
{
    int i, h, n;
    
    i = 0;
    h = 0;
    n = 0;
    while (signs[i])
    {
        if (signs[i] == '<')
        {
            if (n > 0)
            {
                n++;
                while(n--)
                {
                    results[h + n] = remains[idx++];
                }
                n = 0;
                h = i + 1;
            }
            else
            {
                results[h] = remains[idx++];
                h++;
            }
        }
        else
        {
            n++;
        }
        
        i++;
    }
    
    if (n > 0)
    {
        n++;
        while(n--)
        {
            results[h + n] = remains[idx++];
        }
    }
    else
    {
        results[h] = remains[idx++];
    }
}

int main(int argc, char* argv[])
{
    int T;
    
    cin >> T;
    while (T--)
    {
        memset(results, 0, SIZE);
        idx = 0;
        cin >> signs;
        process();
        cout << results << "\n";
    }
    
    return 0;
}

/*
3
>>
<>>>
<<<<<<<<<<<<<<
=====
321
15432
123456789ABCDEF
*/

