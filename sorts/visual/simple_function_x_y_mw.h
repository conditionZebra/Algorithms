#ifndef SIMPLEFUNC_X_Y_MAINWINDOW_H
#define SIMPLEFUNC_X_Y_MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(std::vector<double> *x, std::vector<double> *yi, int rangeX = 1000, int rangeY = 1000);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    void drawTheGraph(QCustomPlot *customPlot, const std::vector<double> *x, const std::vector<double> *y, int rangeX, int rangeY);
};

#endif // SIMPLEFUNC_X_Y_MAINWINDOW_H
