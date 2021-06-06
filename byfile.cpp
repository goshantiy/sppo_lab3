#include "byfile.h"
void byFile::calculate(QString &path)
{
int dirSize=directorySize(QDir(path));
std::cout<<dirSize<<" Bytes"<<std::endl;
auto filesInfo=getFilesInfo(path);
auto percentage=getPercentage(filesInfo,dirSize);
printPercentage(percentage);
}
QMap<QString,double> byFile::getFilesInfo(QString& path)
{
    QMap <QString,double> filesList;
    if(QFileInfo(path).isDir())//если папка
    {
   for(const auto &ix: QDir(path).entryInfoList(QDir::Files|QDir::Dirs|QDir::Drives|QDir::NoDotAndDotDot))
   {//проходимся по папке записываем размеры
       const auto somePath=ix.absoluteFilePath();//записываем путь в переменную
       if(ix.isDir())//если файл является директорией
           filesList.insert(somePath,directorySize(ix.absoluteFilePath()));//вставляем в список путь и размер директории
       else
       filesList.insert(somePath,filesSize(somePath));//вставляем в список путь и размер файла

   }
    }
    else//если просто файл, записываем его размер
        filesList.insert(path,QFileInfo(path).size());
   return filesList;
}
QMap<QString,double> byFile::getPercentage(const QMap<QString,double> list,double dirSize)
{
    QMap <QString,double> filesPercentage;//словарь хранящий название файла и занимаемый размер в процентах
    for(auto ix=list.begin();ix!=list.end();ix++)//идём по списку файлов
    {
        if(dirSize>0)
        {
       const auto percentage= double(ix.value()*100) / dirSize;//считаем процент
       filesPercentage.insert(ix.key(),percentage);
       }//записываем
        else filesPercentage.insert(ix.key(),0);
    }
    return filesPercentage;
}
double byFile::filesSize(const QString& path)
{
    if(QFileInfo(path).isFile())
    {
     double size=0;//переменная хранящая размер
        size+=QFileInfo(path).size();
    return size;
    }
    return 0;
}
double byFile::directorySize(QDir dir)//размер директории
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
void byFile::printPercentage(const QMap<QString, double>& filesList)
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
            cout << it.key() << " " << "< 0.01" << "%" << Qt::endl;

        }
        cout.setRealNumberPrecision(4);
         cout<<"check: "<<check<<"%"<<Qt::endl;
    }
