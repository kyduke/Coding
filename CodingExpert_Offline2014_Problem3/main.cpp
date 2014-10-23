#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 20001;

int buffer[SIZE] = {0, };
int countPerRootN[SIZE >> 1] = {0, };
char visit[SIZE] = {0, };
int N = 0;
int rootN = 0;

void swapBuffer(int a, int b)
{
    int temp;
    a--;
    b--;
    while (a < b)
    {
        temp = buffer[a];
        buffer[a] = buffer[b];
        buffer[b] = temp;
        a++;
        b--;
    }
}

void process()
{
    int i, j, car;
    unsigned long count, result;
    
    result = 0;
    for (i = 0; i < N; i++)
    {
        car = buffer[i] - 1;
        if (car / rootN == 0)
        {
            count = 0;
        }
        else
        {
            count = countPerRootN[car / rootN - 1];
        }
        for (j = car / rootN * rootN; j < car; j++)
        {
            count += visit[j];
        }
        visit[car] = 1;
        for (j = car / rootN; j <= rootN; j++)
        {
            countPerRootN[j]++;
        }
        if (count > i)
        {
            count = i;
        }
        count = (count + 1) * (car + 1);
        result = (result + count) % 10007;
    }
    
    cout << result << "\n";
}

int main(int argc, char* argv[])
{
    int T, C, i, a, b;
    
    cin >> T;
    while (T--)
    {
        cin >> C;
        N = C;
        rootN = sqrt((double)N);
        i = 0;
        while (C--)
        {
            cin >> buffer[i++];
        }
        process();
        cin >> C;
        while (C--)
        {
            cin >> a >> b;
            memset(visit, 0, N);
            memset(countPerRootN, 0, (rootN + 1) * sizeof(int));
            swapBuffer(a, b);
            process();
        }
    }
    
    return 0;
}

/*
1
5
3 1 2 5 4
2
2 4
2 4
=====
44
32
44
*/

