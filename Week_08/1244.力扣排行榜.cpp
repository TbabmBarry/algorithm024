class Leaderboard
{
    unordered_map<int, int> id2Score;
    multiset<int, greater<int>> board;

public:
    Leaderboard()
    {
    }

    void addScore(int playerId, int score)
    {
        if (id2Score.find(playerId) != id2Score.end())
        {
            if (id2Score[playerId] != 0)
                board.erase(board.find(id2Score[playerId]));
        }
        id2Score[playerId] += score;
        board.emplace(id2Score[playerId]);
    }

    int top(int K)
    {
        int sum = 0, cnt = 0;
        for (auto it = board.begin(); it != board.end() && cnt < K; it++, cnt++)
        {
            sum += *it;
        }
        return sum;
    }

    void reset(int playerId)
    {
        if (id2Score[playerId] != 0)
        {
            board.erase(board.find(id2Score[playerId]));
        }
        id2Score[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */