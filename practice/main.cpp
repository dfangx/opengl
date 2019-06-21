#include <iostream>

#include "app.h"

using namespace std;

int main(){
    cout << "MAIN: starting app... " << endl;
    App app(800, 600, 0, 1, 1);
    app.run();

    return(0);
}

