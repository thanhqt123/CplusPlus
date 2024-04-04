#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void tangDan(string a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                string tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
        }
    }
}

int main() {
    string s;
    getline(std::cin, s);
    stringstream ss (s);
    int maxWords =10000;
    string words[maxWords];
    int wordCount=0;
    string word;
    while(ss>>word){
        words[wordCount]=word;
        wordCount++;
    }
    tangDan(words,wordCount);
    for(int i=0;i<wordCount;i++){
        cout<<words[i]<<" ";
    }
    cout<<"\n";
    for(int i=wordCount-1;i>=0;i--){
        cout<<words[i]<<" ";
    }
}