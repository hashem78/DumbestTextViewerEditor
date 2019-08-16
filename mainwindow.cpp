#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QShortcut>
#include <QTextDocumentWriter>
#include <QTextDocumentFragment>
using std::string;
using std::ifstream;
using std::ofstream;
QString file_path_from_dialog;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QShortcut *shortcut_open = new QShortcut(QKeySequence("Ctrl+O"), this);
    QShortcut *shortcut_save = new QShortcut(QKeySequence("Ctrl+S"), this);

    connect(shortcut_open,SIGNAL(activated()),ui->actionOpen,SLOT(trigger()));
    connect(shortcut_save,SIGNAL(activated()),ui->actionSave,SLOT(trigger()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    file_path_from_dialog = QFileDialog::getOpenFileName(this,"Open file","C:/","Txt files (*.txt)");
    ifstream file(file_path_from_dialog.toStdString());
    if(!file.is_open())
        return;
    string temp;
    string final = "" ;
    while(getline(file,temp))
      //  ui->text_view->insertPlainText(QString::fromStdString(temp) + "\n");
            final+=temp;
    QString xx = QString::fromStdString(final);
    ui->text_view->setHtml(xx);

    file.close();

}

void MainWindow::on_text_view_textChanged()
{
    QTextCursor cursor = ui->text_view->textCursor();
    qDebug() << "line: " << cursor.blockNumber() << "pos: " << cursor.columnNumber();
}

void MainWindow::on_actionSave_triggered()
{
   // QTextDocumentWriter write(file_path_from_dialog);
    //write.write(ui->text_view->document());
    QString text_to_htm = ui->text_view->toHtml();
    ofstream file(file_path_from_dialog.toStdString());
    file << text_to_htm.toStdString();
    file.close();
}

void MainWindow::on_actionAlign_Center_triggered()
{
   ui->text_view->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_actionAlign_Left_triggered()
{
    ui->text_view->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_actionAlign_Right_triggered()
{
    ui->text_view->setAlignment(Qt::AlignLeft);
}
