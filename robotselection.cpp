#include "robotselection.h"
#include "ui_robotselection.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QList>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>

#ifdef _WIN32
    #include <Windows.h>
#endif

#include <stdlib.h>

QString fName;
QString command = "atr2.exe";
QString cmditems;

RobotSelection::RobotSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RobotSelection)
{
    ui->setupUi(this);
    QPixmap bg("background.png");
    QPalette p;
    p.setBrush(QPalette::Background, bg);
    this->setPalette(p);
}

RobotSelection::~RobotSelection()
{
    delete ui;
}

void RobotSelection::on_pushButton_clicked()
{
    fName = QFileDialog::getOpenFileName(this, "Select your Fighter", "");
    ui->listWidget->addItem(fName);
}

void RobotSelection::on_pushButton_2_clicked()
{
    qDeleteAll(ui->listWidget->selectedItems());
}

void RobotSelection::on_pushButton_3_clicked()
{
#ifdef _WIN32
    TCHAR   buffer[MAX_PATH];
    wchar_t file[11];
    char    path[MAX_PATH];
    LPCWSTR pointer;

    mbstowcs(file, "./atr2.exe", strlen("./atr2.exe")+1);

    pointer = file;

    GetFullPathName(pointer, MAX_PATH, buffer, NULL);

    wcstombs(path, buffer, MAX_PATH);

    command = path;

#else
    command = realpath("./atr2.exe", NULL);
#endif



    for(int i = 0; i < ui->listWidget->count(); i++){
        cmditems += ui->listWidget->item(i)->text() + " ";
    }
    command = command + " " + cmditems;
    cmditems = "";

    /*QStringList arguments;
    arguments << command;
    QProcess exec;
    exec.start("cmd.exe", arguments);
    exec.waitForFinished();
    */
    std::string temp = command.toStdString();

    QString qstr = QString::fromStdString(temp);
    //QMessageBox::about(this, "DEBUG", qstr);
    system((command.toStdString()).c_str());




   ui->listWidget->clear();
    command = " ";

}
