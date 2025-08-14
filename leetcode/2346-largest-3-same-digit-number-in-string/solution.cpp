class Solution {
public:
    string largestGoodInteger(string num) {
        string good_int = "";
        for(int i=0;i<size(num)-2;i++)
        {
            if((num[i]==num[i+1]) && (num[i+1]==num[i+2]))
            {
                string curr_int = num.substr(i,3);
                if(good_int.empty() || good_int < curr_int)
                {
                    good_int = curr_int;
                }
            }
        }
        return good_int;
        
    }
};
