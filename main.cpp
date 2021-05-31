#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QFileInfoList>
#include <iostream>
#include <QMap>
#include <byfile.h>
#include <bytype.h>
void FilesInfo(QDir dir)
{
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks|QDir::Dirs|QDir::NoDotAndDotDot);//устанавливаем фильтр выводимых файлов
    dir.setSorting(QDir::Size | QDir::Reversed); //устанавливаем сортировку "от меньшего к большему"
    QFileInfoList list = dir.entryInfoList();
    std::cout << " Bytes Filename" << std::endl; //выводим заголовок
    //в цикле выводим сведения о файлах
    for (int i = 0; i < list.size(); ++i)
    {
    QFileInfo fileInfo = list.at(i);
    std::cout << qPrintable(QString("%1 %2").arg(fileInfo.size(),10).arg(fileInfo.fileName())); //выводим в формате "размер имя"
    std::cout << std::endl; //переводим строку
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString path ="C:/Users/PC/Documents/testLab3";
    std::cout<<std::endl<<"Percent by file:"<<std::endl;
    byFile test;
    test.explorer(path);
    std::cout<<std::endl<<"Percent by type:"<<std::endl;
    byType test2;
    test2.explorer(path);
    FilesInfo(QDir(path));
    //MainWindow w;
    //w.show();
    return 0;
    //return a.exec();
}
