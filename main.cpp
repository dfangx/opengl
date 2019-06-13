#include <iostream>

#include "app.h"

using namespace std;

int main(){
    cout << "MAIN: starting app... " << endl;
    App app(640, 480, 0, 1, 1);
    app.init();
    app.run();

    return(0);
}

