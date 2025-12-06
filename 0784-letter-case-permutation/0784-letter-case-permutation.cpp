

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
      vector<string> v;
      string output ="";
      string input = s;
      solve (input,output,v);
      return v; 
    }
    void solve(string input, string output, vector<string>&v){
        if(input.size()==0){
            v.push_back(output);
            return;
        }
        if(isalpha(input[0])){
            char low = tolower(input[0]);
            char up = toupper(input[0]);
            string op1=output+low;
             string op2=output+up;            
           input.erase(input.begin());
            solve(input,op1,v);
            solve(input,op2,v);
        }
        else{
             string option;

            option = output + input[0];
            input.erase(input.begin());
            solve(input,option,v);
        }
    }
};