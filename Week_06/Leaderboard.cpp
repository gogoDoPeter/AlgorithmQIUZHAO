#include <iostream>
#include <iterator>
#include <set>

using namespace std;

class Leaderboard
{
public:
    Leaderboard()
    {
    }

    void addScore(int playerId, int score)
    {
        auto &num = record[playerId];
        if (num == 0)
        {
            rank.emplace(score);
        }
        else
        {
            rank.erase(rank.find(num));
            rank.emplace(score + num);
        }
        num += score;
    }

    int top(int K)
    {
        int result = 0;
        auto iter = --rank.end();
        while(K--){
            result += *iter--;
        }
        return result;
    }

    void reset(int playerId)
    {
        auto& num = record[playerId];
        rank.erase(rank.find(num));
        num = 0;
    }

private:
    multiset<int> rank;
    array<int, 10001> record{};
};

int main()
{

    return 0;
}