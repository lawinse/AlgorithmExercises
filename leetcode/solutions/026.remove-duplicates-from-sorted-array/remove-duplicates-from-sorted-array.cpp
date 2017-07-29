class Solution {
public:
    int removeDuplicates( vector< int > & nums ) {

    if( !nums.size() ) return 0;
    int cnt = 1;
    int tmp = nums[0];
    for ( int i = 1; i < nums.size(); ++i ) {
        if ( tmp != nums[i] ) {
            tmp = nums[cnt] = nums[i];
            ++cnt;
        }
    }
    return cnt;
}
};