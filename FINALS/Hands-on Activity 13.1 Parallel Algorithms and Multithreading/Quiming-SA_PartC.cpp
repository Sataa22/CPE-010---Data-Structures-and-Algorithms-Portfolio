// Supplementary Activity Part C (Bottom-Up DP)
#include <iostream>
#include <thread>
#include <vector>

// Bottom-Up DP
int getMinSteps(int n){
    int dp[n + 1], i;
    dp[1] = 0;  // trivial case
    for(i = 2; i <= n; i++){
        dp[i] = 1 + dp[i - 1];
        if(i % 2 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        if(i % 3 == 0) dp[i] = std::min(dp[i], 1 + dp[i / 3]);
    }
    return dp[n];
}

// Saves the answer in its own variable (just like the add function in Part B)
void run(int n, int &result){
     result = getMinSteps(n);
}

int main(){
    int r1 = 0, r2 = 0, r3 = 0;

    std::thread t1(run, 10, std::ref(r1));
    std::thread t2(run, 100, std::ref(r2));
    std::thread t3(run, 1000, std::ref(r3));

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Min steps for n = 10: " << r1 << std::endl;
    std::cout << "Min steps for n = 100: " << r2 << std::endl;
    std::cout << "Min steps for n = 1000: " << r3 << std::endl;

    return 0;
}