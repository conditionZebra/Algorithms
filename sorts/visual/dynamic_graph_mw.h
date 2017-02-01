#ifndef DYN_GRAPH_MAINWINDOW_H
#define DYN_GRAPH_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "qcustomplot.h" // the header file of QCustomPlot. Don't forget to add it to your project, if you use an IDE, so it gets compiled.

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow();
        ~MainWindow();
        
        void setGraph(const QVector<double> *x, const QVector<double> *y);
        void delay(int);

    private:
        Ui::MainWindow *ui;
        QString demoName;
        QTimer dataTimer;
        QCPItemTracer *itemDemoPhaseTracer;
        int currentDemoIndex;
        QCPAxisRect *subRectLeft;
        QCPGraph *graph;
        void closeEvent (QCloseEvent *e);
        bool firstDraw;
};

#endif // DYN_GRAPH_MAINWINDOW_H
