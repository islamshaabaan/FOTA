#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QProcess>
#include <QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_Connect_Button_clicked()
{
    QString SSID = ui->SSID_lineEdit->text();
    QString Pass = ui->Password_lineEdit->text();
    QFile File("WifiInformation.txt");
    // QIODevice::Append if you need the old information stored.
    // QIODevice::Truncate if you need clearing the file each time write.
    if(File.open(QIODevice::Truncate | QIODevice::ReadWrite))
    {
        QTextStream stream(&File);
        stream << SSID << "\n";
        stream << Pass << "\n";

    }
     QProcess::startDetached("/bin/bash", {"/home/islam_pi/GUI/FOTA_ver1/connect.sh"});
    // if (WifiConnected())
    if(((SSID == "shock 1") && (Pass == "k01149149126")) || ((SSID == "Bassam") && (Pass == "ITI123@iti"))){
        QMessageBox::information(this,"Connect","Connected Successfully!");
        this->hide();
        fota *fotaPage = new fota();
        fotaPage->show();

    }
    else{
        QMessageBox::warning(this,"Connect","Invalid SSID or Password!");
        ui->SSID_lineEdit->setText("");
         ui->Password_lineEdit->setText("");
    }

}

void MainWindow::on_Close_Button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Cancel","Are you sure to close App?",QMessageBox :: Yes | QMessageBox :: No);
    if(reply == QMessageBox :: Yes){
        QApplication::quit();
    }
}
