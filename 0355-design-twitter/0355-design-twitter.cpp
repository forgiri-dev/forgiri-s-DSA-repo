#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Custom struct to help us merge the sorted tweet lists
struct TweetPointer {
    int time;
    int tweetId;
    int userId;
    int index; // The index of this tweet in the user's tweet list

    // Max Heap comparator: We want the LARGEST time (newest tweet) at the top
    bool operator<(const TweetPointer& other) const {
        return time < other.time;
    }
};

class Twitter {
private:
    int globalTime; // Our global clock
    
    // Maps userId -> set of userIds they follow
    unordered_map<int, unordered_set<int>> follows; 
    
    // Maps userId -> list of their tweets {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets; 

public:
    Twitter() {
        globalTime = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // Append the tweet to the user's list with the current timestamp
        tweets[userId].push_back({globalTime, tweetId});
        globalTime++; // Tick the clock forward
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<TweetPointer> maxHeap;
        
        // 1. Gather all users whose tweets we care about (the user + their followees)
        vector<int> usersWeCareAbout = {userId};
        if (follows.count(userId)) {
            for (int followeeId : follows[userId]) {
                usersWeCareAbout.push_back(followeeId);
            }
        }
        
        // 2. Initialize the Max Heap with the MOST RECENT tweet from each user
        for (int uId : usersWeCareAbout) {
            if (tweets.count(uId) && !tweets[uId].empty()) {
                int lastIndex = tweets[uId].size() - 1;
                maxHeap.push({
                    tweets[uId][lastIndex].first,  // time
                    tweets[uId][lastIndex].second, // tweetId
                    uId,                           // userId
                    lastIndex                      // index
                });
            }
        }
        
        // 3. Pop the newest tweet, and push the next newest tweet from that same user
        while (!maxHeap.empty() && feed.size() < 10) {
            TweetPointer current = maxHeap.top();
            maxHeap.pop();
            
            feed.push_back(current.tweetId); // Add to our news feed
            
            // If this user has older tweets, push the next one into the heap
            if (current.index > 0) {
                int nextIndex = current.index - 1;
                maxHeap.push({
                    tweets[current.userId][nextIndex].first, 
                    tweets[current.userId][nextIndex].second, 
                    current.userId, 
                    nextIndex
                });
            }
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        // Don't let a user follow themselves in the set (handled separately in getNewsFeed)
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId)) {
            follows[followerId].erase(followeeId);
        }
    }
};