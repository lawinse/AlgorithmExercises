class Solution {
    unordered_map<string, multiset<string>> ticket;
    vector<string> route;
    void visit(string depart){
        while (ticket[depart].size()){
            string next = *ticket[depart].begin();
            ticket[depart].erase(ticket[depart].begin());
            visit(next);
        }
        route.push_back(depart);
    }
    
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for (auto ti:tickets){
            ticket[ti.first].insert(ti.second);
        }
        visit("JFK");
        reverse(route.begin(),route.end());
        return route;
    }
};