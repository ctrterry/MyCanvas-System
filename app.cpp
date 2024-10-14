#include <iostream>
#include "myCanvas.h"
using namespace std;
int main() {

   MyCanvas myCanvas;
    printMyCanvas();

    if (myCanvas.doLogin()) {
        myCanvas.doCourseMenu();
        myCanvas.doMainMenu();
    }
    else{
        cout << "Unsuccessfully Login . . . " << endl;
    }
    return 0;
}
