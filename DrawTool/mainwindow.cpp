#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sbcanvas.h"
#include "sbcreaterecteventholder.h"

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

void MainWindow::on_actionLine_triggered(bool)
{

}

void MainWindow::on_actionRect_triggered(bool)
{
    SBCreateRectEventHolder *eventHolder = new SBCreateRectEventHolder(m_pSBCanvas);
    m_pSBCanvas->setEventHolder(eventHolder);
}

void MainWindow::on_actionSave_As_triggered(bool)
{

}

void MainWindow::on_actionSave_triggered(bool)
{

}

void MainWindow::on_actionOpen_triggered(bool)
{

}
