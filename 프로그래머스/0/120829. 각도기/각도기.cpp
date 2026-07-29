using namespace std;

int solution(int angle) {
    if (angle < 90)
        return 1;
    else if(angle > 90 && angle < 180)
        return 3;
    else if(angle == 90)
        return 2;
    else
        return 4;
}