#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class GUIMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GUIMainWindow(QWidget *parent = 0);
    ~GUIMainWindow();

private slots:
    void on_action_triggered();

    void on_action_2_triggered();


    void on_action_3_triggered();

private:
    int add_row(const QStringList& cols);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
