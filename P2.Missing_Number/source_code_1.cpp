#include <iostream>
int main(){
    int64_t n;
    std::cin >> n;
    int64_t sum = n*(n+1)/2;
    for(int i = 0, tmp; i<n-1; i++) {
        std::cin >> tmp; 
        sum -= tmp;
    }
    std::cout << sum << '\n';
    return 0;
}