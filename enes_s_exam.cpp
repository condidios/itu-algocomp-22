#include <iostream>

using namespace std;
int findTheSingleDigit(int n) {
    int sum = 0;
    while(n > 0 || sum > 9) {
        if(n == 0) {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int summination(int n){
    int sum =0;
    int m;
    while(n>0)
    {
        m=n%10;
        sum=sum+m;
        n=n/10;
    }
    return sum;
}
int main() {
    long a;
    long b;
    cin >> a;
    cin >> b;
    b--;
    if(findTheSingleDigit(a)==1){
        cout<<1;
    } else if (findTheSingleDigit(a)==2){
        int mod = b%6;
        if (mod==0){
            cout<<2;
        }else if (mod==1){
            cout<<4;
        }else if (mod==2){
            cout<<8;
        }else if (mod==3){
            cout<<7;
        }else if (mod==4){
            cout<<5;
        }else if (mod==5){
            cout<<1;
        }
    }else if (findTheSingleDigit(a)==3){

        if (b==0){
            cout<<3;
        } else cout<<9;
    }else if (findTheSingleDigit(a)==4){
        int mod = b%3;
        if (mod==0){
            cout<<4;
        }else if (mod==1){
            cout<<7;
        }else if (mod==2){
            cout<<1;
        }
    } else if (findTheSingleDigit(a)==5){
        int mod = b%6;
        if (mod==0){
            cout<<5;
        }else if (mod==1){
            cout<<7;
        }else if (mod==2){
            cout<<8;
        }else if (mod==3){
            cout<<4;
        }else if (mod==4){
            cout<<2;
        }else if (mod==5){
            cout<<1;
        }
    }else if (findTheSingleDigit(a)==6){
        if (b==0){
            cout<<6;
        } else cout<<9;
    }else if (findTheSingleDigit(a)==7){
        int mod = b%3;
        if (mod==0){
            cout<<7;
        }else if (mod==1){
            cout<<4;
        }else if (mod==2){
            cout<<1;
        }
    }else if (findTheSingleDigit(a)==8){
        int mod = b%2;
        if (mod==0){
            cout<<8;
        } else cout<<1;
    }else if (findTheSingleDigit(a)==9){
        cout<<9;
    }

    return 0;
}