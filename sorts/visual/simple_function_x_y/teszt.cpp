#include <QtGui/QApplication>
#include "simple_function_x_y_mw.h"

int main(int argc, char *argv[])
{
    std::vector<double> *x = new std::vector<double>;
    std::vector<double> *y = new std::vector<double>;

    for (int i=0; i<1000; ++i)
    {
        x->push_back(i);
        y->push_back(i/2);
    }

    QApplication a(argc, argv);
    MainWindow w(x, y);
    w.show();
    
    return a.exec();
}
