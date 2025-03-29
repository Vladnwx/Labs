#include <graphics.h>

int main() {
    initgraph(NULL, NULL, (char*)"");  // Автоопределение режима
    circle(100, 100, 50);
    getch();
    closegraph();
    return 0;
}


//g++ test.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 -o test.exe