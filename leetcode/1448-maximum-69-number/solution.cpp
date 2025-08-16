class Solution {
public:
    int maximum69Number (int num) {
        string str_num = to_string(num);
        string answer = "";
        bool is_first = true;
        for(int i=0;i<size(str_num);i++)
        {
            if(str_num[i]=='6' && is_first)
            {
                answer += '9';
                is_first = false;
                continue;
            }

            answer += str_num[i];
        }

        return stoi(answer);
    }
};
