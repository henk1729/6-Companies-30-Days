class Solution {
public:
    static bool sortBySec(const pair<int, int>&a, const pair<int, int>&b){
        return a.second<b.second;
    }

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int xmin=rectangles[0][0],
            ymin=rectangles[0][1],
            xmax=rectangles[0][2],
            ymax=rectangles[0][3];
        long int totArea, sumArea=0;

        for(int i=0; i<rectangles.size(); i++){
            sumArea+=(long)(rectangles[i][2]-rectangles[i][0])*(rectangles[i][3]-rectangles[i][1]);
            xmin=min(xmin, rectangles[i][0]);
            ymin=min(ymin, rectangles[i][1]);
            xmax=max(xmax, rectangles[i][2]);
            ymax=max(ymax, rectangles[i][3]);
        }
        totArea=(long)(xmax-xmin)*(ymax-ymin);

        if(totArea!=sumArea) return false;

        vector<pair<int, int>> coords;
        for(int i=0; i<rectangles.size(); i++){
            coords.push_back({rectangles[i][0], rectangles[i][1]});
            coords.push_back({rectangles[i][2], rectangles[i][1]});
            coords.push_back({rectangles[i][2], rectangles[i][3]});
            coords.push_back({rectangles[i][0], rectangles[i][3]});
        }
        sort(coords.begin(), coords.end());
        vector<pair<int, int>>::iterator itLeft, itRight=coords.begin();
        for(; itRight<coords.end(); ){
            itLeft=itRight;
            while(itRight<coords.end() && (itRight->first)==(itLeft->first)) itRight++;
            sort(itLeft, itRight, sortBySec);
            itRight++;
        }

        int corners=4, cnt=1;
        for(int i=1; i<coords.size(); i++){
            if(coords[i]==coords[i-1]) cnt++;
            else{
                if(coords[i-1].first==xmin && coords[i-1].second==ymin){
                    if(cnt==1) corners--;
                    else return false;
                }
                else if(coords[i-1].first==xmax && coords[i-1].second==ymin){
                    if(cnt==1) corners--;
                    else return false;
                }
                else if(coords[i-1].first==xmax && coords[i-1].second==ymax){
                    if(cnt==1) corners--;
                    else return false;
                }
                else if(coords[i-1].first==xmin && coords[i-1].second==ymax){
                    if(cnt==1) corners--;
                    else return false;
                }
                else if(cnt!=2 && cnt!=4) return false;
                cnt=1;
            }
        }
        if(coords[coords.size()-1].first==xmin && coords[coords.size()-1].second==ymin){
            if(cnt==1) corners--;
            else return false;
        }
        else if(coords[coords.size()-1].first==xmax && coords[coords.size()-1].second==ymin){
            if(cnt==1) corners--;
            else return false;
        }
        else if(coords[coords.size()-1].first==xmax && coords[coords.size()-1].second==ymax){
            if(cnt==1) corners--;
            else return false;
        }
        else if(coords[coords.size()-1].first==xmin && coords[coords.size()-1].second==ymax){
            if(cnt==1) corners--;
            else return false;
        }
        else if(cnt!=2 && cnt!=4) return false;
        cnt=1;

        if(corners==0) return true;
        return false;
    }
};
