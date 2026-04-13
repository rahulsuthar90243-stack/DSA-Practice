#include<iostream>
using namespace std;

bool isFreqSame(int freq[], int windFreq[]){
    for(int i = 0; i < 26; i++){
        if(freq[i] != windFreq[i]) {
            return false;
        }
    }
    return true;
}

int checkInclusion(string s1, string s2){
    int freq[26] = {0};
    for(int i = 0; i < s1.length(); i++){   // stare the frequence of character
        int idx = s1[i] - 'a';
        freq[idx]++;
    }
    
    int windSize = s1.length();
    for(int i = 0; i < s2.length(); i++){
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};

        while (windIdx < windSize && idx < s2.length())
        {
           windFreq[s2[idx] - 'a'];
           windIdx++, idx++;
        }

        if(isFreqSame(freq, windFreq)){
            return true;
        }
    }
    return false;
}

int main(){
    string s1  = "ab";
    string s2 = "eidbaooo";

    if(!checkInclusion(s1, s2)){
        cout<<"true";
    }else{
        cout <<"Not found false";
    }

}