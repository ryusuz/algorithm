//week11-25 직사각형 별찍기
#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    //cout << a + b << endl;
    
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}