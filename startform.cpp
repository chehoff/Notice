#include "startform.h"
#include "ui_startform.h"
#include <QFileDialog>

StartForm::StartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartForm)
{
    PathToFolder = "";
    PathToXLS = "";
    ui->setupUi(this);
//    connect();
}

StartForm::~StartForm()
{
    delete ui;
}

void StartForm::on_pushButton_2_clicked()
{
    PathToFolder = QFileDialog::getExistingDirectory(0,QObject::tr("Укажите путь к папке с проектами"),QDir::homePath());
    if(!PathToFolder.isEmpty()){
        ui->PathToFolderLine->setText(PathToFolder);
    }
}

void StartForm::on_pushButton_3_clicked()
{
    PathToXLS = QFileDialog::getOpenFileName(0,QObject::tr("Укажите файл базы данных"),QDir::homePath(), QObject::tr("Файл xls (*.xls);;Все файлы (*.*)"));
    if(!PathToXLS.isEmpty()){
        ui->PathToXLSLine->setText(PathToXLS);
    }
}

void StartForm::on_pushButton_clicked()
{
    emit DirPath(ui->PathToFolderLine->text());
    emit FilePath(ui->PathToXLSLine->text());
    close();
}
