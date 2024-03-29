﻿#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "sbcanvas.h"
#include "sbcreaterecteventholder.h"
#include "sbcreatelineeventholder.h"
#include "sbfileiomanager.h"

#include <QFileDialog>
#include <QMessageBox>


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
    SBCreateLineEventHolder *eventHolder = new SBCreateLineEventHolder(m_pSBCanvas);
    m_pSBCanvas->setEventHolder(eventHolder);
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
    if (m_pSBCanvas == nullptr)
    {
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                 QDir::currentPath(),
                                 tr("Svgs (*.svg)"));
    if (!fileName.isEmpty())
    {
        QString saveInfo = SBFileIOManager::getInstance().saveFile(fileName, m_pSBCanvas->doc());
        if (saveInfo.isEmpty())
        {
            QMessageBox::information(this,tr("save File"),tr("Save successful"));
        }
        else
        {
            QMessageBox::warning(this,tr("save File"),tr("Save failed.\r\n%1").arg(saveInfo));
        }
    }
}

void MainWindow::on_actionOpen_triggered(bool)
{

}
