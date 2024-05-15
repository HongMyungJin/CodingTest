#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int PizzaPiece = 6;
    while(PizzaPiece % n != 0)
        PizzaPiece += 6;
    return PizzaPiece / 6;
}