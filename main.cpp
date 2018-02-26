#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

/*Filters out spaces, question marks, and commas*/
string remove_spaces(string s){
s.erase(remove(s.begin(), s.end(), '?'), s.end());
s.erase(remove(s.begin(), s.end(), ','), s.end());
return s;
};

int main()
{
    SetConsoleTitle("Parse Bins - An ICQA Tool by Garrett Chesnut");
    string s, tmp;
    vector<string> v;
    cout<<"Please enter bins. To retrieve the bins, type the word 'print' and press enter. To clear the list of bins, type 'clear' and press enter.\n\nYou can exit the program at any time by typing 'exit' and pressing enter."<<endl;
        while (cin >> s)
            if(s == "exit"){
                return 0;
            }
            else if(s == "print"){
                    cout<<"\n"<<endl;
                for(vector<string>::iterator it = v.begin();it != v.end(); it++){
                        cout<<*it<<endl;
            }
            v.clear();
            }
            else if(s == "clear"){
                v.clear();
                cout<<"\nBins cleared!"<<endl;
            }
            else{
                s = remove_spaces(s);

                if (s.length() <= 12){
                istringstream ssbin(s);
                while (ssbin >> tmp)
                    v.push_back(tmp);
                }
                else{
                    int i;
                    for(i = 0; i < s.length();i += 12){
                        string s1;
                        s1 = s.substr(i, 12);
                        istringstream ssbin(s1);
                        while (ssbin >> tmp)
                        v.push_back(tmp);
                    }
                }
            }
    }
