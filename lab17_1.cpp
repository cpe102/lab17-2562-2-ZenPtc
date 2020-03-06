//Write your code here
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

string tolower_for_str(string a){
    string y=a;
    for(int i=0;i<a.size();i++){
        y[i] = tolower(a[i]);
    }
    return y;
}

int main(){
    vector<string> name;
    vector<double> total;
    vector<string> grade;
    ifstream source("C:/Users/wisaTong/Desktop/ComPro/Lab/lab17-2562-2-ZenPtc/name_score.txt");
    string textline,fuser;
    char namae[100];
    int s1,s2,s3,sum,count=0;

    while(getline(source,textline)){
        sscanf(textline.c_str(),"%[^:]: %d %d %d",namae,&s1,&s2,&s3);
        sum = s1+s2+s3;
        name.push_back(namae);
        total.push_back(sum);
        if(sum>=80){
            grade.push_back("A");
        }else if(sum>=70){
            grade.push_back("B");
        }else if(sum>=60){
            grade.push_back("C");
        }else if(sum>=50){
            grade.push_back("D");
        }else grade.push_back("F");
        count++;
    }
    while(true){
    cout << "Please input your command : ";
    getline(cin,fuser);
    bool check = 0 ;

    fuser = tolower_for_str(fuser);
    if(fuser.substr(0,5)=="name "){
        fuser.erase(0,5);
        for(int i=0;i<count;i++){
            if(tolower_for_str(name[i])==fuser){
                cout << name[i] << "'s grade = " << grade[i];
                check = 1;
            }
        }
        if (check == 0) {
            cout << "Cannot found" << endl ;
        }
    }else if(fuser.substr(0,6)=="grade "){
        fuser.erase(0,6);
        for(int i=0;i<count;i++){
            if(tolower_for_str(grade[i])==fuser){
                cout << name[i] << endl;
                check = 1;
            }
        }
        if (check == 0) {
            cout << "Cannot found" << endl ;
        }
    }else if(fuser.substr(0,4)=="exit"){
        return 0 ;
    }else cout << "Invalid command" << endl;

    }
    source.close();

    return 0;
}