#include <iostream>
using namespace std;

int digsum(int num ){
    int ans = 0 , rem ;

    while(num > 0){
        rem = num % 10;
        ans += rem;
        num = num / 10;
    }
    return ans;

}
int main() 
{
    cout<<digsum(12345)<<endl;
    return 0;

}