#ifndef FOTA_H
#define FOTA_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class fota;
}

class fota : public QMainWindow
{
    Q_OBJECT

public:
    explicit fota(QWidget *parent = nullptr);
    ~fota();

private slots:
    void on_Server_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LED_Button_clicked();

    void on_ShowFolderContent_clicked();

private:
    Ui::fota *ui;
};

#endif // FOTA_H
