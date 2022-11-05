class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

        unordered_map<string, int> ListOne;
        vector<string> result;

        int min = 0, signal = 0;

        for(int i = 0; i < list1.size(); i++)
            ListOne[list1[i]] = (i+1);

        for(int i = 0; i < list2.size(); i++)
        {
            if(signal == 0 && ListOne[list2[i]] > 0)
            {
                result.push_back(list2[i]);
                min = ((ListOne[list2[i]]-1) + i);
                signal = 1;
                continue;
            }

            if(ListOne[list2[i]] > 0 && min >= ((ListOne[list2[i]]-1) + i))
            {
                if(min == ((ListOne[list2[i]]-1) + i))
                    result.push_back(list2[i]);
                else
                {
                    result.clear();
                    result.push_back(list2[i]);
                    min = ((ListOne[list2[i]]-1) + i);
                }

            }
        }

    return result;

    }
};