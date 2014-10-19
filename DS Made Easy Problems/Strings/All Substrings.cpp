#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int count=0;
        char t[n];
        scanf("%s",t);
        char *s=t;
        while(*s){
            int x=0;
            while(s[x]){
                /*for(int y=0;y<=x;y++){
                    cout<<s[y];
                    //char *str = s;
                }
                //cout<<endl;
                cout<<endl<<s[0]<<"  "<<s[x]<<endl<<endl;*/
                if(s[0]=='1' && s[x]=='1')
                    count++;
                x++;
            }
            s++;
        }
        printf("%d\n",count);
    }
    return 0;
}
