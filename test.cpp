#include<bits/stdc++.h>
using namespace std;




void takeInput(int n , vector<string>&arr){
       for(int i = 0 ; i < n ; i++){
        string temp;
        cin>>temp;

        arr.push_back(temp);
    }

}


void cmpAdd(unordered_map<string,int> &mp , vector<string> &ans){
        for(auto i : mp){
        if(i.second == 1) ans.push_back(i.first);
    }
}


void insertInMap(unordered_map<string,int> &mp , vector<string> &arr){
        for(auto i : arr){
        if(mp.find(i) == mp.end()) mp[i]++;
    }
}

void solve(vector<string> &ans1 , vector<string> &ans2 , vector<string> &a1 , vector<string> &a2 ){

    unordered_map<string,int> mp1 , mp2;

    insertInMap(mp1 , a1);
    insertInMap(mp2 , a2);


    for(auto i : a2){
        if(mp1[i] == 1 ){
            mp1[i]++;
        }
    }
    for(auto i : a1){
        if(mp2[i] == 1 ){
            mp2[i]++;
        }
    }


    cmpAdd(mp1 , ans1);
    cmpAdd(mp2 , ans2);
}


void print(vector<string> &arr){
    for(auto i : arr){
        cout<<i<<", ";
    }

    cout<<endl;
}

int main(){

    vector<string> a, b;
    int n , m ;

    cout<<"Enter size of array 1\n";
    cin>>n;
    cout<<"Enter size of array 2\n";
    cin>>m;

    cout<<"Enter the string values for array 1\n";

    takeInput(n , a);

    cout<<"Enter the string values for array 2\n";

    takeInput(m , b);

    vector<string> A_B , B_A;

    solve(A_B , B_A , a , b);

cout<<"Set difference A-B is :\n";
    print(A_B);
cout<<"Set difference B-A is :\n";
    print(B_A);


 return 0;
}