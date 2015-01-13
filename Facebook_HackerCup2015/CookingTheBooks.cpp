//https://www.facebook.com/hackercup/problems.php?pid=582062045257424&round=742632349177460

#include <iostream>
#include <cstring>

using namespace std;

void printMin(char* num)
{
    int i, j, l;
    char c;
    char buf[10];

    strcpy(buf, num);

    l = strlen(buf);

    i = 0;
    while (i < l)
    {
        c = '0';
        if (i == 0) c = '1';
        while (c <= '9')
        {
            j = l - 1;
            while (j > i)
            {
                if (buf[j] == c && buf[i] > c)
                {
                    buf[j] = buf[i];
                    buf[i] = c;
                    cout << buf << "\n";
                    return;
                }
                j--;
            }
            c++;
        }
        i++;
    }

    cout << buf << "\n";
}

void printMax(char* num)
{
    int i, j, l;
    char c, e;
    char buf[10];

    strcpy(buf, num);

    l = strlen(buf);

    i = 0;
    while (i < l)
    {
        c = '9';
        e = '0';
        if (i == 0) e = '1';
        while (c >= e)
        {
            j = l - 1;
            while (j > i)
            {
                if (buf[j] == c && buf[i] < c)
                {
                    buf[j] = buf[i];
                    buf[i] = c;
                    cout << buf << "\n";
                    return;
                }
                j--;
            }
            c--;
        }
        i++;
    }

    cout << buf << "\n";
}

int main(int argc, char* argv[])
{
    char num[10] = "31524";

    printMin(num);
    printMax(num);

    return 0;
}
