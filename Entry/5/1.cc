#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct BigInteger{
    static const int BASE=100000000;
    static const int WIDTH=8;
    vector<int> v;
    
    BigInteger operator = (const string& s){
        int x;
        int start;
        int end;
        int i;
        int blocks;

        blocks=(s.length()-1)/WIDTH+1;

        for(i=0;i<blocks;i++){
            end=s.length()-i*WIDTH;
            start=max(0,end-WIDTH);
            sscanf(s.substr(start, end-start).c_str(),"%d",&x);
            //printf("start %d, end %d, end-start %d, x %d\n", start, end, end - start, x);
            v.push_back(x);
        }
        
        return *this;
    }
    
    BigInteger operator + (const BigInteger &b){
        BigInteger c;
        int i,g;
        int x;
        for(i=0,g=0;;i++){
            if(g==0&&i>=v.size()&&i>=b.v.size()){//无进位，两个BigInteger实例均已遍历完成 
                break;
            }
            x=g;
            if(i<v.size())
                x+=v[i];
            if(i<b.v.size())
                x+=b.v[i];
            c.v.push_back(x%BASE);
            g=x/BASE;
        }
        return c;
    }

    void biprint()
    {
        for (int i=0; i<v.size(); ++i)
        {
            cout << v[i] << endl;
        }
    }

};

istream& operator >> (istream &in, BigInteger &b){
    string x;
    in>>x;
    b=x;
    return in;
}

ostream& operator << (ostream &out,const BigInteger &b){
    int i;
    char buf[20];
    out<<b.v.back();//最高位不足8位的预防处理 
    for(i=b.v.size()-2;i>=0;i--){
        sprintf(buf,"%08d",b.v[i]);//不足8位补0 
        cout<<buf;
    }
    return out;
} 

int main(){
    BigInteger a;
    BigInteger b;
    cin >> a;
    //cin >> b;
    //a.biprint();
    cout << a << endl;

    //cout << a+b << endl;
    return 0;
}

