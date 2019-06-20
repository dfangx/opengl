#include <iostream>

#include "app.h"

using namespace std;

int main(){
    cout << "MAIN: starting app... " << endl;
    App app(800, 600, 0, 0, 0);
    app.run();

    return(0);
}

