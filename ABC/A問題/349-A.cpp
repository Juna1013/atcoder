#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int sum = 0;
    for (int i = 1; i <= N - 1; ++i) {
        int Ai;
        std::cin >> Ai;
        sum += Ai;
    }

    int X = -sum;
    std::cout << X << std::endl;

    return 0;
}
