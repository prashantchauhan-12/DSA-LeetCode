#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Twitter {
private:
    // Global timer to simulate tweet recency
    int timestamp;

    // userId -> list of pairs {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // userId -> set of followeeIds
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() { timestamp = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    typedef pair<int, int> p;
    vector<int> getNewsFeed(int userId) {
        // Min-heap to keep track of the 10 most recent tweets
        // Stores: pair<timestamp, tweetId>
        priority_queue<p, vector<p>, greater<p>> pq;

        // 1. Get user's own tweets
        for (auto& t : tweets[userId]) {
            pq.push(t);
            if (pq.size() > 10)
                pq.pop();
        }

        // 2. Get tweets from everyone they follow
        for (int followeeId : following[userId]) {
            for (auto& t : tweets[followeeId]) {
                pq.push(t);
                if (pq.size() > 10)
                    pq.pop();
            }
        }

        // 3. Extract from heap (results will be in increasing order of time)
        vector<int> res;
        while (!pq.empty()) {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        // A user cannot follow themselves in this context (usually)
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (following[followerId].count(followeeId)) {
            following[followerId].erase(followeeId);
        }
    }
};