#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "robotselection.h"
#include "roboteditor.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainMenu *mm;
    RobotSelection *rs;
    RobotEditor *re;
};

#endif // MAINMENU_H
