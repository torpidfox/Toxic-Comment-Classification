#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DataProviders/KaggleDataProvider.cpp"
#include "Cores/RandomCore.cpp"
#include <memory>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

GUIMainWindow::GUIMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList headers;
    headers << "Cat1" << "Cat2" << "Cat3" << "RACISM";
    ui->tableWidget->setColumnCount(headers.count());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

int GUIMainWindow::add_row(const QStringList& cols)
{
    auto c = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(c);
    for(auto i = 0; i < cols.count(); i++)
        ui->tableWidget->setItem(c, i, new QTableWidgetItem(cols.at(i)));
    return c;
}


GUIMainWindow::~GUIMainWindow()
{
    delete ui;
}

void GUIMainWindow::on_action_triggered()
{
    auto fd = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", tr("(*.txt)"));
    if (fd.isEmpty())
            return;
    QFileInfo fi(fd);
    ui->plainTextEdit->clear();
    if (fi.suffix() == ".json")
    {
        /*
        json j;
        auto tmp = fd.toStdString(); //Я говорил именннно про это. const reference
        auto test = tcc::KaggleDataProvider(tmp);
        auto data = test.get_data();
        for(json j: data)
        {
            ui->plainTextEdit->appendPlainText(j['title']);
            ui->plainTextEdit->appendPlainText(j['text']);
        }
        */
    }
    else
    {
        QFile f(fd);
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream in(&f);
        ui->plainTextEdit->document()->setPlainText(in.readAll());
        f.close();
    }
}

void GUIMainWindow::on_action_2_triggered()
{
    auto fd = QFileDialog::getSaveFileName(this, tr("Сохранить в файл"), "", tr("(*.txt)"));
    if (fd.isEmpty())
            return;
    QFile f(fd);
    f.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&f);
    out << ui->plainTextEdit->document()->toPlainText();
    f.close();
}

void GUIMainWindow::on_action_3_triggered()
{
    //json j;
    //auto core = std::make_shared<tcc::RandomCore>(100);
    //TODO

}
