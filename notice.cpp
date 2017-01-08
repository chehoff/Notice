#include "notice.h"

int Notice::count = 0;
QStringList Notice::projects;

Notice::Notice(const QString &str, QObject *parent) : QObject(parent)//Конструктор
{
    this->name = str;
    Notice::count++;
}
Notice::~Notice(){//Деструктор
    Notice::count--;
}
int Notice::GetCount(){
    return Notice::count;
}

QString Notice::GetName(){
    return this->name;
}
void Notice::setisInFolder(bool b){
    this->isInFolder = b;
}
bool Notice::GetisInFolder(){
    return this->isInFolder;
}
void Notice::setProjectName(const QString &str){
    this->projectName = str;
    if(!Notice::projects.contains(str)){
        Notice::projects.push_back(str);
    }
}
QString Notice::GetProjectName(){
    return this->projectName;
}
void Notice::setAutor(const QString &str){
    this->author = str;
}
QString Notice::GetAuthor(){
    return this->author;
}
void Notice::setStatus(const QString &str){
    this->status = str;
}
QString Notice::GetStatus(){
    return this->status;
}
void Notice::setinwork(bool b){
    this->inwork = b;
}

bool Notice::Getinwork(){
    return this->inwork;
}
void Notice::setDateIncoming(const QString &str){
    QStringList tmp = str.split(".");
    if(tmp[2].toInt() < 100){
        this->dateIncoming = QDate::fromString(str, "dd.MM.yy");
    } else {
        this->dateIncoming = QDate::fromString(str, "dd.MM.yyyy");
    }
    if(this->dateIncoming.year()<2000){
        this->dateIncoming = this->dateIncoming.addYears(100);
    }
}
QDate Notice::GetDateIncoming(){
    return this->dateIncoming;
}
QStringList Notice::Getprojects(){
    return Notice::projects;
}
