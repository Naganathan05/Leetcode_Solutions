/*---------------------------------------------
Data Strrctures Used: (Set, Queue, Deque)
  Time Complexity: O(logn), O(logn), O(logn)
  Space Complexity: O(n) + O(n) + O(n)
----------------------------------------------*/

class Packet {
public:
    int source;
    int destination;
    int timestamp;

    Packet(int s, int d, int t) {
        this -> source = s;
        this -> destination = d;
        this -> timestamp = t;
    }

    vector<int> getList() {
        return {this -> source, this -> destination, this -> timestamp};
    }

    string makeKey() {
        return (to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp));
    }
};

class Router {
public:
    int memoryLimit;
    unordered_set<string> seenPackets;
    queue<Packet> routingTable;
    unordered_map<int, deque<int>> destinationPacketTimestamps;

    Router(int memoryLimit) {
        this -> memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet newPacket = Packet(source, destination, timestamp);
        if (seenPackets.find(newPacket.makeKey()) != seenPackets.end()) return false;

        if ((int)routingTable.size() == memoryLimit) vector<int> _ = forwardPacket();

        seenPackets.insert(newPacket.makeKey());
        routingTable.push(newPacket);
        destinationPacketTimestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (routingTable.empty()) return {};
        Packet nextPacket = routingTable.front();
        routingTable.pop();

        seenPackets.erase(nextPacket.makeKey());
        destinationPacketTimestamps[nextPacket.destination].pop_front();
        return nextPacket.getList();
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destinationPacketTimestamps.find(destination);
        if (it == destinationPacketTimestamps.end()) return 0;

        auto &dq = it->second;
        auto firstInd  = lower_bound(dq.begin(), dq.end(), startTime) - dq.begin();
        auto secondInd = upper_bound(dq.begin(), dq.end(), endTime)   - dq.begin();
        return secondInd - firstInd;
    }
};

/*
Question Link: https://leetcode.com/problems/implement-router/
Author: M.R.Naganathan
*/
