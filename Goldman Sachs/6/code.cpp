class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int minCards=cards.size()+1;
        unordered_map<int, int> cardPosition;

        for(int i=0; i<cards.size(); i++){
            if(cardPosition[cards[i]]!=0){
                minCards=min(minCards, (i+1)-cardPosition[cards[i]]+1);
            }
            cardPosition[cards[i]]=i+1;
        }

        return (minCards<=cards.size()?minCards:-1);
    }
};
