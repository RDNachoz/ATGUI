#include "robotselection.h"
#include "ui_robotselection.h"
#include <QFileDialog>
#include <QList>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>

QString fName;
QString command = "atr2.exe";
QString cmditems;

RobotSelection::RobotSelection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RobotSelection)
{
    ui->setupUi(this);
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
    for(int i = 0; i < ui->listWidget->count(); i++){
        cmditems += ui->listWidget->item(i)->text() + " ";
    }
    command = command + " " + cmditems;
    QMessageBox::about(this, "DEBUG", command);
    QProcess exec;
    QStringList args;
    args << command;
    exec.start("cmd.exe", args);
    exec.waitForFinished();
    qDebug() << exec.readAllStandardOutput();
}
