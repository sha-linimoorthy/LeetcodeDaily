/*Brute --> check if its pair is the next element if not iterate the array 
find its pair put there, increment swap counter
*/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int swaps =0;
        int n= size(row);
        for(int i=0;i<n;i+=2)
        {
            int partner = (row[i]%2==0)? row[i] + 1 : row[i] - 1;

            if(row[i+1]!=partner)
            {
                for(int j=i+2;j<n;j++)
                {
                    if(row[j]==partner)
                    {
                        swap(row[i+1],row[j]);
                        swaps++;
                        break;
                    }
                }
            }
        }

        return swaps;
        
    }
};
