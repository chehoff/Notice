#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>

MainWindow::MainWindow(QVector<Notice*> &notices, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QStringList listNames;
    QStringList listproj;
    for(int i = 0; i < notices.size(); i++){
            listNames << notices[i]->GetName();
    }
    for(int i = 0; i < notices.size(); i++){
            listproj << notices[i]->GetProjectName();
    }
    QStringListModel *model = new QStringListModel;
    model->setStringList(listNames);
    ui->listView->setModel(model);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
