#include <QtGui/QApplication>
#include "dynamic_graph_mw.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow();
    QVector<double> *x = new QVector<double>;
    QVector<double> *y = new QVector<double>;

    for (int i=0; i<100; ++i)
    {
        x->push_back(i);
        y->push_back(i);
    }
    w->setGraph(x,y);

    w->delay(5);

    x->clear();
    y->clear();

    for (int i=0; i<100; ++i)
    {
        x->push_back(i);
        y->push_back(i/2);
    }
    w->setGraph(x,y);


    return a.exec();
}
