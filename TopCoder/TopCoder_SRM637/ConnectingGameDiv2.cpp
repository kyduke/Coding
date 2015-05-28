#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class ConnectingGameDiv2
{
private:
    static const int SIZE = 123;
    static const int MAX = 50;
    struct Blob
    {
        int cell;
        int min;
        int max;
        int cost;
        int calc;
        int neighbors[SIZE];
    };
    struct Cost
    {
        int idx;
        int cell;
        int cost;
    };
    vector<struct Cost> queue;
    struct Blob blobs[SIZE];
    int column;
    int minCell;
    int min(int a, int b)
    {
        return a > b ? b : a;
    };
    int max(int a, int b)
    {
        return a > b ? a : b;
    };
    void findPath();
public:
    int getmin(vector<string> board);
    static bool compare(struct Cost a, struct Cost b)
    {
        return (a.cost > b.cost);
    }
};
//
void ConnectingGameDiv2::findPath()
{
    int idx;
    int cell;
    int cost;
    struct Blob *b;
    while (queue.size())
    {
        idx = queue.back().idx;
        cell = queue.back().cell;
        cost = queue.back().cost;
        queue.pop_back();
        if (cell >= minCell)
        {
            continue;
        }
        b = &blobs[idx];
        if (cost > b->calc)
        {
            continue;
        }
        //오른쪽까지 연결된 것을 만나면 최소값 갱신
        if (b->max == column - 1)
        {
            minCell = min(minCell, cell);
            if (minCell == column)
            {
                return;
            }
        }
        else //오른쪽까지 연결되지 않았다면 처리해야할 대상에 추가
        {
            for (idx = 0; idx < SIZE; idx++)
            {
                //이웃 중에서 비용이 현재 계산된 최소비용 보다 싸고, 이전에 계산된 비용보다 싼 경우에만 계산 대상에 포함
                if (b->neighbors[idx] == 1 && (cell + blobs[idx].cost) < minCell && (cell + blobs[idx].cost) < blobs[idx].calc)
                {
                    queue.push_back(struct Cost());
                    queue.back().idx = idx;
                    queue.back().cell = cell + blobs[idx].cell;
                    queue.back().cost = cell + blobs[idx].cost;
                    blobs[idx].calc = cell + blobs[idx].cost;
                }
            }
            sort(queue.begin(), queue.end(), ConnectingGameDiv2::compare); //비용이 최소인 것을 먼저 계산하도록 정렬
        }
    }
}
//
int ConnectingGameDiv2::getmin(vector<string> board)
{
    int i, j, row;
    int ni, nj;
    struct Blob* b;
    //자료 초기화
    memset(blobs, 0, sizeof(struct Blob) * SIZE);
    for (i = 0; i < SIZE; i++)
    {
        blobs[i].min = MAX;
        blobs[i].calc = MAX * MAX;
    }
    //그룹 정보 추출
    row = board.size();
    column = board[0].size();
    minCell = row * column;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            b = &blobs[board[i][j]];
            b->cell++;
            b->min = min(b->min, j);
            b->max = max(b->max, j);
            b->cost = b->cell + (column - (b->max + 1));
            ni = i - 1;
            if (ni >= 0 && ni < row)
            {
                nj = j - 1;
                if (nj >= 0 && nj < column)
                {
                    b->neighbors[board[ni][nj]] = 1;
                }
                b->neighbors[board[ni][j]] = 1;
                nj = j + 1;
                if (nj >= 0 && nj < column)
                {
                    b->neighbors[board[ni][nj]] = 1;
                }
            }
            nj = j - 1;
            if (nj >= 0 && nj < column)
            {
                b->neighbors[board[i][nj]] = 1;
            }
            nj = j + 1;
            if (nj >= 0 && nj < column)
            {
                b->neighbors[board[i][nj]] = 1;
            }
            ni = i + 1;
            if (ni >= 0 && ni < row)
            {
                nj = j - 1;
                if (nj >= 0 && nj < column)
                {
                    b->neighbors[board[ni][nj]] = 1;
                }
                b->neighbors[board[ni][j]] = 1;
                nj = j + 1;
                if (nj >= 0 && nj < column)
                {
                    b->neighbors[board[ni][nj]] = 1;
                }
            }
        }
    }
    //필요없는 이웃 제거
    for (i = 0; i < SIZE; i++)
    {
        b = &blobs[i];
        b->neighbors[i] = 0;
        for (j = 0; j < SIZE; j++)
        {
            if (b->neighbors[j] == 1 && blobs[j].min == 0)
            {
                b->neighbors[j] = 0;
            }
        }
    }
    //왼쪽에서 시작하는 것만 검색 시작
    for (i = 0; i < SIZE; i++)
    {
        if (blobs[i].cell > 0 && blobs[i].min == 0 && blobs[i].cost < minCell)
        {
            queue.clear();
            queue.push_back(struct Cost());
            queue.back().idx = i;
            queue.back().cell = blobs[i].cell;
            queue.back().cost = blobs[i].cost;
             
            findPath();
            if (minCell == column)
            {
                return minCell;
            }
        }
    }
    return minCell;
}
//
int main(int argc, char* argv[])
{
    ConnectingGameDiv2 game;
    string test0[] = {"AA", "BB"};
    string test1[] = {"AAB", "ACD", "CCD"};
    string test2[] = {"iii", "iwi", "iii"};
    string test3[] = {"rng58", "Snuke", "Sothe"};
    string test4[] = {"yyAArJqjWTH5", "yyEEruYYWTHG", "hooEvutpkkb2", "OooNgFFF9sbi", "RRMNgFL99Vmm", "R76XgFF9dVVV", "SKnZUPf88Vee"};
 
    vector<string> board;
    board.clear();
    board.push_back(test0[0]);
    board.push_back(test0[1]);
    cout << game.getmin(board) << "\n";
//
    board.clear();
    board.push_back(test1[0]);
    board.push_back(test1[1]);
    board.push_back(test1[2]);
    cout << game.getmin(board) << "\n";
//
    board.clear();
    board.push_back(test2[0]);
    board.push_back(test2[1]);
    board.push_back(test2[2]);
    cout << game.getmin(board) << "\n";
//
    board.clear();
    board.push_back(test3[0]);
    board.push_back(test3[1]);
    board.push_back(test3[2]);
    cout << game.getmin(board) << "\n";
//
    board.clear();
    board.push_back(test4[0]);
    board.push_back(test4[1]);
    board.push_back(test4[2]);
    board.push_back(test4[3]);
    board.push_back(test4[4]);
    board.push_back(test4[5]);
    board.push_back(test4[6]);
    cout << game.getmin(board) << "\n";
    return 0;
}
