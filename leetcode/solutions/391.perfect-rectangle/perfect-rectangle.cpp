struct pairhash {//double hash function for pair key
public:
    // template <typename T, typename U>
    // size_t operator()(const pair<T, U> &rhs) const {
    //     size_t l = hash<T>()(rhs.first);
    //     size_t r = hash<U>()(rhs.second);
    //     return l + 0x9e3779b9 + (r << 6) + (r >> 2);
    // }
    size_t operator()(const pair<int,int> &obj) const {
        size_t l = hash<int>()(obj.first);
        size_t r = hash<int>()(obj.second);
        return l + 0x231aef9 + (r<<6) + (r>>2);
    }
};
class Solution {
#define MP(a,b) make_pair((a),(b))
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<pair<int,int>, int, pairhash> cnt;
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        for (auto rect:rectangles) {
            minx = min(minx, rect[0]);
            miny = min(miny, rect[1]);
            maxx = max(maxx, rect[2]);
            maxy = max(maxy, rect[3]);
            
            int &m1 = cnt[MP(rect[0],rect[1])];
            if (m1&1) return false; else m1|=1;
            int &m2 = cnt[MP(rect[2],rect[1])];
            if (m2&2) return false; else m2|=2;
            int &m4 = cnt[MP(rect[0],rect[3])];
            if (m4&4) return false; else m4|=4;
            int &m8 = cnt[MP(rect[2],rect[3])];
            if (m8&8) return false; else m8|=8;
        }
        
        for (auto c:cnt){
            pair<int,int> point = c.first;
            int mask = c.second;
            if ((point.first == maxx || point.first == minx) && (point.second == maxy || point.second == miny)) {
                if (mask&(mask-1)) return false;
                // if (mask != 1 && mask != 2 && mask != 4 && mask != 8) return false;
            } else {
                if (mask != 3 && mask != 5 && mask != 10 && mask != 12 && mask != 15) return false;
            }
        }
        return true;
    }
};