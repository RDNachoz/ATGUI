#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "robotselection.h"
#include "roboteditor.h"
#include "QPixmap"
#include "QPalette"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    mm(new Ui::MainMenu)
{
    mm->setupUi(this);
    QPixmap bg("background.png");
    QPalette p;
    p.setBrush(QPalette::Background, bg);
    this->setPalette(p);

    mm->label->setStyleSheet("color: white;");
    mm->label_2->setStyleSheet("color: white;");
}

MainMenu::~MainMenu()
{
    delete mm;
}

void MainMenu::on_pushButton_clicked()
{
    //RobotSelection rs;
    //rs.setModal(true);
    //rs.exec();
    hide();
    rs = new RobotSelection(this);
    rs->show();
}

void MainMenu::on_pushButton_2_clicked()
{
    hide();
    re = new RobotEditor(this);
    re->show();
}
