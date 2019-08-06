#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SBCanvas;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SBCanvas *m_pSBCanvas;
};

#endif // MAINWINDOW_H
