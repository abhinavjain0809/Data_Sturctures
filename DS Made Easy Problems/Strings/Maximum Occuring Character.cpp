#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAX_CHARS 256
using namespace std;

int *getCountArray(char *s){
    int *count = new int[MAX_CHARS];
    memset(count,0,MAX_CHARS*sizeof(char));
    for(int i=0;s[i];i++){
        count[s[i]]++;
    }
    return count;
}

char maxOccurence(int *count,char *s){
    int max=INT_MIN,pos;
    for(int i=0;i<MAX_CHARS;i++){
        if(max<count[i]){
            pos = i;
            max = count[i];
        }
    }
    return pos;
}

int main(){
    char s[1000];
    //~ int k=0;
    cout<<"Input String: ";
    scanf("%[^\n]",s);
    int *count = getCountArray(s);
    cout<<"Maximum Occuring Character: "<<maxOccurence(count,s);
    return 0;
}
