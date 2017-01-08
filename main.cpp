#include "mainwindow.h"
#include "startform.h"
#include "notice.h"
#include <QApplication>
#include <QtWidgets>
#include <QVector>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString PathToFolder = "";
    QString PathToXLS = "";
    QStringList MaskNotice;
    QString FileIniPath = qApp->applicationDirPath() + "/notice.ini";
    QFile FileIni(FileIniPath);
    //Читаем файл с настройками приложения
    if(FileIni.exists()){
        if(FileIni.open(QIODevice::ReadOnly)){
            while(!FileIni.atEnd()){
                QString str = FileIni.readLine();
                str = str.trimmed();
                QStringList params = str.split(":::", QString::SkipEmptyParts);
                if(params[0] == "PathToFolder"){
                    PathToFolder = params[1];
                } else if(params[0] == "PathToXLS"){
                    PathToXLS = params[1];
                }else if(params[0] == "PrefixNotice"){
                    MaskNotice = params[1].split(":", QString::SkipEmptyParts);
                    for(int i = 0; i < MaskNotice.size(); i++){
                        MaskNotice[i] += "*";
                    }
                }
            }
            FileIni.close();
        }
    } else {
        qDebug() << "File not exist";
        return 0;
        //<------------------------В будущем предусмотреть вызов настройщика!!!!
    }
    //читаем названия папок в папке с проектами
    QDir dir(PathToFolder);
    QStringList ListProjects = dir.entryList(MaskNotice ,QDir::Dirs);
    //Создаём список объектов и сами объекты
    QVector<Notice*> notices; //Этот вектор хранит указатели на все экземпляры объекта Notice
    for(int i = 0; i < ListProjects.size(); i++){
        Notice* notice = new Notice(ListProjects[i]);
        notices.push_back(notice);
    }
//    for(int i = 0; i < notices.size(); i++){
//        qDebug() << notices[i]->GetName();
//    }
    //Загружаем данные из файла базы данных внедрения
    QFile FileCSV(PathToXLS);
    if(FileCSV.exists()){
        if(FileCSV.open(QIODevice::ReadWrite)){
            QString str = FileCSV.readLine();
            while(!FileCSV.atEnd()){
                str = FileCSV.readLine();
                QStringList nt = str.split("|");
                qDebug() << nt;
            }
        }
    } else {
        qDebug() << "File not exist";
        return 0;
        //<------------------------В будущем предусмотреть вызов настройщика!!!!
    }
    //MainWindow mw;
    //StartForm s;
    //mw.show();
    return 0;
    return a.exec();
}
