#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setnum(int,int,int);
    ~MainWindow();
private slots:
    void hide_them();
    void play_or_pause();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
