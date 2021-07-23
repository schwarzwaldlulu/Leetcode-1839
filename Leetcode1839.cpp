class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int l = 0;
        int n = word.length();
        
        queue<int> intervalStarts;
        set<int> nums;
        vector<int> vec( n );
        
        int v;
        for ( int i = 0; i < n; ++i )
        {
            v = charToInt( word[i] );
            if ( v == 1 )
                intervalStarts.push( i );
            vec[i] = v;
        }

        
        int start = -1;
        int end;
        while ( !intervalStarts.empty() )
        {
            start = intervalStarts.front();
            end = start;
            while ( end < vec.size()-1 && vec[ end + 1 ] >= vec[ end ] )
            {
                nums.insert( vec[end] );
                end++;
            }
            nums.insert( vec[end] );
            
            
            if ( vec[end] == 5 && nums.find(2) != nums.end() && nums.find(3) != nums.end() && nums.find(4) != nums.end() )
            {
                l = max( l, end-start+1 );
            }

            while( !intervalStarts.empty() && intervalStarts.front() <= end )
                    intervalStarts.pop();

            nums.clear();

        }
        return l;
    }
    
    int charToInt( char c )
    {
        switch( c )
        {
                case 'a':
                   return 1;
                   break;
                case 'e':
                   return 2;
                   break;
                case 'i':
                   return 3;
                   break;
                case 'o':
                   return 4;
                   break;
                case 'u':
                   return 5;
                   break;
            default:
                return -1;
        }
    }

};
