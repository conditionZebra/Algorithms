#include "simple_function_x_y_mw.h"
#include "ui_window.h"
#include <vector>
#include <iostream>

MainWindow::MainWindow(std::vector<double> *x, std::vector<double> *y, int rangeX, int rangeY) :
    QMainWindow(/*parent*/),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(400, 250, 452, 390);
    drawTheGraph(ui->customPlot, x, y, rangeX, rangeY);
}

void MainWindow::drawTheGraph(QCustomPlot *customPlot, const std::vector<double> *xi, const std::vector<double> *yi, int rangeX, int rangeY)
{
    QVector<double> x, y; // initialize with entries 0..100

    x = QVector<double>::fromStdVector( (*xi));
    y = QVector<double>::fromStdVector( (*yi));

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(0, rangeX);
    customPlot->yAxis->setRange(0, rangeY);
}


MainWindow::~MainWindow()
{
    delete ui;
}
