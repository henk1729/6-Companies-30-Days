class Solution {
public:
    int evalRPN(vector<string>& tokens){
        stack<int> stack;
        for(auto i:tokens){
            if(i!="+" && i!="-" && i!="*" && i!="/"){
                int num=0;
                for(int j=0; j<i.length(); j++){
                    if(i[i.length()-1-j]!='-') num+=(int)pow(10, j)*(i[i.length()-1-j]-'0');
                    else num*=(-1);
                }
                stack.push(num);
            }
            else{
                int ult=stack.top();
                stack.pop();
                int penUlt=stack.top();
                stack.pop();
                switch(i[0]){
                    case '+':
                        stack.push(penUlt+ult);
                        break;
                    case '-':
                        stack.push(penUlt-ult);
                        break;
                    case '*':
                        stack.push(penUlt*ult);
                        break;
                    case '/':
                        stack.push(penUlt/ult);
                        break;
                }
            }
        }
        return stack.top();
    }
};
