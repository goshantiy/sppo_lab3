#include "bytype.h"
#include <data.h>
QList<Data> byType::calculate(QString &path)
{
double dirSize=directorySize(QDir(path));
//std::cout<<int(dirSize)<<" Bytes"<<std::endl;
auto filesInfo=getFilesInfo(path);
auto percentage=getTypePercentage(filesInfo,dirSize);
QList<Data> data;
auto typeSize = getTypeSize(filesInfo);
for (const auto& key : percentage.keys())
            data.push_back(Data(key, typeSize.value(key), percentage.value(key)));
return data;

}
QMap<QString,double> byType::getTypeSize(QMap<QString,double> list)
{
QMap<QString,double> typeSize;

for(auto ix=list.begin();ix!=list.end();ix++)
{
    double size=0;
    size=ix.value();
    auto type=QFileInfo(ix.key()).suffix();
    if(type.isEmpty())
        type="unknown";
    typeSize.insert(type,typeSize[type]+size);
}
return typeSize;

}
QMap<QString,double> byType::getTypePercentage(QMap<QString,double> list,double dirSize)
{
QMap<QString,double> typesPercentage;

for(auto ix=list.begin();ix!=list.end();ix++)
{
    double percentage=0;
    if(dirSize>0)
    percentage=double(ix.value()*100)/dirSize;
    else percentage=0;
    auto type=QFileInfo(ix.key()).suffix();
    if(type.isEmpty())
        type="unknown";
    typesPercentage.insert(type,typesPercentage[type]+percentage);
}
return typesPercentage;

}
void byType::setMap(const QMap<QString, double>& first, QMap<QString, double>& second)
{
    for(auto ix = first.begin();ix!=first.end();++ix)
        second.insert(ix.key(),ix.value());
}
QMap<QString,double> byType::getFilesInfo(const QString& path)
{
    QMap <QString,double> filesList;
    if(QFileInfo(path).isDir())//если папка
    {
   for(const auto &ix: QDir(path).entryInfoList(QDir::Files|QDir::Dirs|QDir::Drives|QDir::NoDotAndDotDot))
   {//проходимся по папке записываем размеры
       const auto somePath=ix.absoluteFilePath();//записываем путь в переменную
       if(ix.isDir())//если файл является директорией
       {
            this->setMap(this->getFilesInfo(ix.absoluteFilePath()),filesList);
          }
       else
       filesList.insert(somePath,filesSize(somePath));//вставляем в список путь и размер файла

   }
    }
    else//если просто файл, записываем его размер
        filesList.insert(path,QFileInfo(path).size());
   return filesList;
}
double byType::filesSize(const QString& path)
{
    if(QFileInfo(path).isFile())
    {
     double size=0;//переменная хранящая размер
        size+=QFileInfo(path).size();
    return size;
    }
    return 0;
}
double byType::directorySize(QDir dir)//размер директории
{
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot|QDir::Files|QDir::Drives|QDir::Dirs);
    int size=0;
    for(auto &ix: list)//идём по списку файлов
    {
        if(ix.isDir())//если директория, рекурсивно заходим
            size+=directorySize(ix.absoluteFilePath());
        else
            size+=ix.size();//если не директория, прибавляем размер файла
    }
    return size;

}
void byType::printPercentage(const QMap<QString, double>& filesList)
    {
        QTextStream cout(stdout);
        double check=0;
        cout.setRealNumberPrecision(2);//кол-во чисел после запятой
        for (auto it = filesList.begin(); it != filesList.end(); ++it)
        {

            check +=double(it.value());
            if(it.value()>0.01)
            {
                cout << it.key() << " " << it.value() << "%" << Qt::endl ;
                }
            else if(it.value()==0)
                {
                    cout <<it.key()<< " 0" << "%" << Qt::endl ;
                           }
            else
            cout << it.key() << " " << "< 0.01" << "%" << Qt::endl ;
        }
        cout.setRealNumberPrecision(4);
        if(check==0)
            cout<<"empty"<<Qt::endl;
         cout<<"check: "<<check<<"%"<<Qt::endl;

    }
