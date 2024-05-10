#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int general = hp / 5;
    int soldier = (hp - general * 5) / 3;
    int worker = (hp - general * 5 - soldier * 3);
    return general + soldier + worker;
}