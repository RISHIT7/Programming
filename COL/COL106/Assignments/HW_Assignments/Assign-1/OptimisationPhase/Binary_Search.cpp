#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> avail_set(int set_num, vector<pair<int, vector<int>>> set_db)
{
    int mid, start, end;
    start = 0;
    end = set_db.size();
    mid = (start+end)/2;
    while (set_db[mid].first != set_num)
    {
        if (set_db[mid].first > set_num)
        {
            
        }
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    vector<pair<int, vector<int>>> vs = {{0, {1, 2, 3}},
                                          {1, {1, 2, 3}},
                                          {2, {1, 2, 3}},
                                          {3, {1, 2, 3}},
                                          {4, {1, 2, 3}},
                                          {5, {1, 2, 3}},
                                          {6, {1, 2, 3}},
                                          {7, {1, 2, 3}},
                                          {8, {1, 2, 3}},
                                          {9, {1, 2, 3}},
                                          {10, {1, 2, 3}}};
    
    res = avail_set(5, vs);
    return 0;
}