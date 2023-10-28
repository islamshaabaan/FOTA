#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QTextStream>

#include "fota.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Connect_Button_clicked();

    void on_Close_Button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
