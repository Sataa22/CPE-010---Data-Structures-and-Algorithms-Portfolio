// Activity 12 - ILO A: Minimum Steps to one (Memoization / Top-Down)
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> memo;

int getMinSteps(int n){
    if ( n == 1 ) return 0; // base case
    if( memo[n] != -1 ) return memo[n]; // we have solved it already :)
    int r = 1 + getMinSteps( n - 1 ); // '-1' step . 'r' will contain the optimal answer finally
    if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2 ) ) ; // '/2' step
    if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3 ) ) ; // '/3' step
    memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
    return r;
}

int main(){
    int test[] = {1, 4, 7, 10, 15, 100};

    for(int n: test){
        memo.assign(n + 1, -1);
        std::cout << "n = " << n << " -> Minimum Steps = " << getMinSteps(n) << std::endl;
    }

    return 0;
}