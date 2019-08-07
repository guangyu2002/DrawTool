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

private slots:
    void on_actionLine_triggered(bool checked);

    void on_actionRect_triggered(bool checked);

    void on_actionSave_As_triggered(bool checked);

    void on_actionSave_triggered(bool checked);

    void on_actionOpen_triggered(bool checked);

private:
    Ui::MainWindow *ui;
    SBCanvas *m_pSBCanvas;
};

#endif // MAINWINDOW_H
