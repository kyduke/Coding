#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
    long x;
    long y;
};

struct particle
{
    long x;
    long y;
    int d;
    int i;
    struct particle* up;
    struct particle* down;
    struct particle* left;
    struct particle* right;
    struct particle* prev;
    struct particle* next;
};

struct particle particles[5000] = {0, };
int bottomRight = 0;
float incX[5] = {0, 0, 0, 0.5, -0.5};
float incY[5] = {0, -0.5, 0.5, 0, 0};
int fac[5][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 1, 0, 3, -1, 0, 4},
    {0, -1, 1, 1, 0, 3, -1, 0, 4},
    {-1, 0, 4, 0, 1, 2, 0, -1, 1},
    {1, 0, 3, 0, 1, 2, 0, -1, 1}
};

bool cmd(const point& p1, const point& p2)
{
    if (p1.x != p2.x)
    {
        return p1.x > p2.x;
    }
    return p1.y < p2.y;
}

void insert(struct particle* p)
{
    struct particle* node = &particles[bottomRight];
    
    if (node->y > p->y)
    {
        bottomRight = p->i;
        node->down = p;
        p->up = node;
        return;
    }
    
    while (node)
    {
        if (node->y == p->y)
        {
            if (node->x == p->x)
            {
                if (node->next == NULL && node->i != p->i)
                {
                    node->next = p;
                    p->prev = node;
                    return;
                }
                node = node->next;
            }
            else if (node->x > p->x)
            {
                if (node->left == NULL)
                {
                    node->left = p;
                    p->right = node;
                    return;
                }
                node = node->left;
            }
            else
            {
                if (node->right != NULL)
                {
                    node->right->left = p;
                    p->right = node->right;
                }
                node->right = p;
                p->left = node;
                p->up = node->up;
                if (p->up)
                {
                    p->up->down = p;
                }
                p->down = node->down;
                if (p->down)
                {
                    p->down->up = p;
                }
                node->up = NULL;
                node->down = NULL;
                if (bottomRight == node->i)
                {
                    bottomRight = p->i;
                }
                return;
            }
        }
        else
        {
            if (node->up == NULL)
            {
                node->up = p;
                p->down = node;
                return;
            }
            if (node->up->y > p->y)
            {
                node->up->down = p;
                p->up = node->up;
                node->up = p;
                p->down = node;
                return;
            }
            node = node->up;
        }
    }
}

void removeLeft(struct particle* p)
{
    struct particle* up = p->up;
    struct particle* down = p->down;
    struct particle* right = p->right;
    
    if (bottomRight == p->i)
    {
        if (up == NULL)
        {
            bottomRight = 0;
        }
        else
        {
            bottomRight = up->i;
        }
    }
    
    if (up != NULL)
    {
        up->down = down;
    }
    
    if (down != NULL)
    {
        down->up = up;
    }
    
    if (right != NULL)
    {
        right->left = NULL;
    }
}

void getKthParticleXY(unsigned int k, long* x, long* y)
{
    vector<point> p;
    int rightCount;
    long px, py;
    
    struct particle* node = &particles[bottomRight];
    struct particle* right = NULL;
    
    while (node)
    {
        rightCount = 0;
        right = node;
        while (node)
        {
            if (node->d == 4)
            {
                rightCount++;
            }
            node = node->left;
        }
        node = right;
        while (rightCount--)
        {
            p.push_back(point());
            p.back().x = node->x;
            p.back().y = node->y;
            node = node->left;
        }
        node = right->up;
    }
    if (p.size() < k)
    {
        *x = 0;
        *y = 0;
        return;
    }
    sort(p.begin(), p.end(), cmd);
    
    node = &particles[bottomRight];
    px = p[k - 1].x;
    py = p[k - 1].y;
    while (node)
    {
        if (node->y == py)
        {
            break;
        }
        node = node->up;
    }
    
    rightCount = 0;
    right = node;
    while (node)
    {
        if (node->x == px)
        {
            break;
        }
        rightCount++;
        node = node->left;
    }
    
    node = right;
    while (node)
    {
        if (node->d == 4)
        {
            if (rightCount == 0)
            {
                *x = node->x;
                *y = node->y;
                break;
            }
            rightCount--;
        }
        node = node->left;
    }
}

bool matchDirection(long x, long y, long d)
{
    struct particle* node = &particles[bottomRight];
    
    while (node)
    {
        if (node->y == y)
        {
            if (node->x == x)
            {
                if (node->d == d)
                {
                    return true;
                }
                node = node->next;
            }
            else if (node->x < x)
            {
                return false;
            }
            else
            {
                node = node->left;
            }
        }
        else if (node->y > y)
        {
            return false;
        }
        else
        {
            node = node->up;
        }
    }
    
    return false;
}

int getIndex(long x, long y, long d)
{
    struct particle* node = &particles[bottomRight];
    
    while (node)
    {
        if (node->y == y)
        {
            if (node->x == x)
            {
                if (node->d == d)
                {
                    return node->i + 1;
                }
                node = node->next;
            }
            else if (node->x < x)
            {
                return 0;
            }
            else
            {
                node = node->left;
            }
        }
        else if (node->y > y)
        {
            return 0;
        }
        else
        {
            node = node->up;
        }
    }
    
    return 0;
}

void process(long x, long y, long targetX)
{
    long cX, cY;
    int d, match, matchD;
    float tX, tY, dist;
    
    tX = targetX;
    tY = y;
    d = 4;
    
    dist = abs(targetX - x);
    
    while (dist > 0)
    {
        match = 0;
        matchD = d;
        
        if (dist != round(dist))
        {
            cX = tX + dist * fac[d][0];
            cY = tY + dist * fac[d][1];
            if (matchDirection(cX, cY, fac[d][2]) == true)
            {
                d = fac[d][2];
            }
        }
        else
        {
            cX = tX + dist * fac[d][0];
            cY = tY + dist * fac[d][1];
            if (matchDirection(cX, cY, fac[d][2]) == true)
            {
                d = fac[d][2];
            }
            else
            {
                cX = tX + dist * fac[d][3];
                cY = tY + dist * fac[d][4];
                if (matchDirection(cX, cY, fac[d][5]) == true)
                {
                    match++;
                    matchD = fac[d][5];
                }
                cX = tX + dist * fac[d][6];
                cY = tX + dist * fac[d][7];
                if (matchDirection(cX, cY, fac[d][8]) == true)
                {
                    match++;
                    matchD = fac[d][8];
                }
                
                if (match == 1)
                {
                    d = matchD;
                }
            }
        }
        tX += incX[d];
        tY += incY[d];
        
        dist -= 0.5;
    }
    
    cout << getIndex(tX, tY, d) << "\n";
}

int main(int argc, char* argv[])
{
    int T, M, N, K, i, d;
    long x, y, t;
    
    cin >> T;
    while (T--)
    {
        cin >> M >> N >> K;
        i = 0;
        cin >> x >> y >> d;
        particles[i].x = x;
        particles[i].y = y;
        particles[i].d = d;
        particles[i].i = i;
        i++;
        while (i < N)
        {
            cin >> x >> y >> d;
            particles[i].x = x;
            particles[i].y = y;
            particles[i].d = d;
            particles[i].i = i;
            insert(&particles[i]);
            i++;
        }
        getKthParticleXY(K, &x, &y);
        if (x == 0)
        {
            cout << 0 << " " << 0 << "\n";
        }
        else
        {
            t = M - x;
            cout << t << " ";
            process(x, y, M);
        }
        memset(particles, 0, sizeof(particle) * N);
        bottomRight = 0;
    }
    
    return 0;
}


/*
2
5 4 2
1 3 4
3 1 1
4 2 3
4 4 4
5 2 2
1 1 2
3 1 1
=====
4 3
0 0
*/

