#include "fota.h"
#include "ui_fota.h"
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QFileDialog>
#include <string>
fota::fota(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fota)
{
    ui->setupUi(this);

    QFile File("WifiInformation.txt");
    if(File.open(QIODevice::ReadOnly)){

        QTextStream stream(&File);
        /*QString FileData;
         while(stream.atEnd() == false){
             FileData += stream.readLine() + "\n";
         }
         ui->ShowSSID_textEdit->setText(FileData);*/
        ui->ShowSSID_textEdit->setText(stream.readLine());
    }
    ui->LED_Button->setEnabled(false);
    ui->FingerPrint_Button->setEnabled(false);


}

fota::~fota()
{
    delete ui;
}

void fota::on_Server_pushButton_clicked()
{
    QString link="https://ide-38fcee10a9aa4a99958ad33bccd7abde-8080.cs50.ws/login";
    //QUrl url("http://www.google.com");
    //QString link="https://ide-38fcee10a9aa4a99958ad33bccd7abde-8080.cs50.ws/login";
    QDesktopServices::openUrl(QUrl(link));
}

void fota::on_pushButton_2_clicked()
{

    QString filename= QFileDialog::getExistingDirectory(this,"Choose Folder");

    if (filename.isEmpty())
        return;
    ui->Path_lineEdit->setText(filename);
    /*
    if(QDir("/home/islam_pi/Downloads").entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count() == 0)
    {

        QMessageBox::information(this,"Directory is empty","Empty!!!");
        ui->LED_Button->setVisible(false);
    }
    else{

        QMessageBox::information(this,"Directory is empty","Not Empty!!!");
        ui->LED_Button->setVisible(true);

    }*/


    /*QFileInfo check_file("/home/islam_pi/Downloads/DAC.hex");
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile()) {
        QMessageBox::information(this,"File","Exist Successfully!");
    } else {
        QMessageBox::warning(this,"File","Invalid File!");
    }*/

}

void fota::on_LED_Button_clicked()
{
    QFile f("/home/islam_pi/Downloads");
    QFileInfo fileInfo(f.fileName());
    QString filename(fileInfo.fileName());
    QMessageBox::warning(this,"File",fileInfo.fileName());

    //QString str = f.fileName();
}

void fota::on_ShowFolderContent_clicked()
{
    ui->listWidget->clear();

    QString dirPath= ui->Path_lineEdit->text();

    if (dirPath.isEmpty())
        return;

    QDir dir(dirPath);

    //Get the list of files and directories in the folder

    QList <QFileInfo> fileList= dir.entryInfoList();

    for (int i=2; i< fileList.size(); i++){

        QString prefix;
        if (fileList.at(i).isFile()){
            prefix= "File: ";
        }
        if (fileList.at(i).isDir()){
            prefix="Directory: ";
        }
        QString str = fileList.at(i).absoluteFilePath();
        str= str.split('/').last();
        QString filename = str.split('.').first();

        ui->listWidget->addItem(prefix + str   );

        if (  filename == ui->LED_Button->text() ){
            ui->LED_Button->setEnabled(true);
            QMessageBox::warning(this,"File","Led Enabled" );

        }
        if(filename== ui->FingerPrint_Button->text()){
            ui->FingerPrint_Button->setEnabled(true);
            QMessageBox::warning(this,"File","FP Enabled" );

        }
        //ui->listWidget->addItem(fileList.at(i).absoluteFilePath());
    }
}
