#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sbcanvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pSBCanvas = new SBCanvas(this);
    setCentralWidget(m_pSBCanvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}
