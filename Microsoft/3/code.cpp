class Solution {
public:
    string getHint(string secret, string guess) {
        string hint1="", hint2="";
        int bulls=0, cows=0;

        int digitS[10]={0}, digitG[10]={0};
        for(int i=0; i<secret.length(); i++){
            if(secret[i]==guess[i]) bulls++;
            else{
                digitS[secret[i]-'0']++;
                digitG[guess[i]-'0']++;
            }
        }
        for(int i=0; i<10; i++) cows+=min(digitS[i], digitG[i]);

        if(bulls==0) hint1="0";
        if(cows==0) hint2="0";
        while(bulls){
            hint1=char(bulls%10+'0')+hint1;
            bulls/=10;
        }
        while(cows){
            hint2=char(cows%10+'0')+hint2;
            cows/=10;
        }
        string hint=hint1+'A'+hint2+'B';
        return hint;
    }
};
