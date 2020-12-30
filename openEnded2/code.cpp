#include<bits/stdc++.h>
using namespace std;

bool checkUnique(vector<int> digits){
    sort(digits.begin(), digits.end());

    for(int i=0;i<digits.size()-1;i++){
        if(digits[i]==digits[i+1])
            return false;
    }

    return true;
}

int main() {
    int l,r;

    cin>>l>>r;

    for(int i=l;i<=r;i++){
        vector<int> digits;

        int n=i,rem;

        while(n>0){
            rem = n % 10;
            n /= 10;
            digits.push_back(rem);
        }

        if(checkUnique(digits)) {
            cout<<i<<" ";
        }

    }
}