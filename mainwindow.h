#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <utility>
#include <list>

extern std::list <std::string> contents;
extern size_t number_of_lines;
extern QString file_path_from_dialog;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_text_view_textChanged();

    void on_actionSave_triggered();

    void on_actionAlign_Center_triggered();

    void on_actionAlign_Left_triggered();

    void on_actionAlign_Right_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
