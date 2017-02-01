#include "dynamic_graph_mw.h"
#include "ui_window.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QTime>

// ToDo: remove unnecessary sht
// ToDo: rename misleading sht

MainWindow::MainWindow() :
    QMainWindow(/*parent*/),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(400, 250, 542, 390);
    ui->customPlot->plotLayout()->clear(); // clear default axis rect so we can start from scratch
    subRectLeft = new QCPAxisRect(ui->customPlot, false); // false means to not setup default axes
    ui->customPlot->plotLayout()->addElement(0, 0, subRectLeft);
    subRectLeft->addAxes(QCPAxis::atBottom | QCPAxis::atLeft);
    subRectLeft->axis(QCPAxis::atBottom)->grid()->setVisible(true);
    graph = ui->customPlot->addGraph(subRectLeft->axis(QCPAxis::atBottom), subRectLeft->axis(QCPAxis::atLeft));
    graph->setLineStyle(QCPGraph::lsImpulse);
    graph->setPen(QPen(QColor("#FFA100"), 1.5));
    firstDraw = true;
    show();
}

void MainWindow::setGraph(const QVector<double> *x, const QVector<double> *y)
{
    graph->setData(*x, *y);
    if(firstDraw)
    {
        graph->rescaleAxes();
        firstDraw = false;
    }
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ToDo: put it into a helper class, needed other places for sure.

void MainWindow::delay(int delay)

{
    QTime dieTime= QTime::currentTime().addSecs(delay);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::closeEvent (QCloseEvent* /*unused*/)
{
    exit(0);
    return;
}

