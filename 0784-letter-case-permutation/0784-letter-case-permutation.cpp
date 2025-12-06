// class Solution {
// public:
//     void solve(string ip, string op, vector<string> &res)
//     {
//         if(ip.length() == 0){
//             res.push_back(op);
//             return;
//         }
//         if(isalnum(ip[0]))
//         {
//             string op1 = op;
//             string op2 = op;

//             op1.push_back(tolower(ip[0]));
//             op2.push_back(toupper(ip[0]));
//             //ip.erase(ip.begin()+0);
//             string str = ip.substr(1);
//             solve(str,op1,res);
//             solve(str,op2,res);
//             return;
//         }
//         else{
//             string op1 = op;
//             op1.push_back(ip[0]);
//             //ip.erase(ip.begin()+0);
//              string str = ip.substr(1);
//             solve(str,op1,res);
//             return;
//         }
//     }
//     vector<string> letterCasePermutation(string s) {
//         string ip = s;
//         string op = "";
//         vector<string> res;
//         solve(ip,op,res);
//         return res;
//     }
// };


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