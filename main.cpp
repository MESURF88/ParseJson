#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include<QHash>
#include<QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString loc = "C:\\Users\\hillk\\Documents\\FieldVis\\tmp.json";
    QFile file;
          file.setFileName(loc);
          file.open(QIODevice::ReadOnly | QIODevice::Text);
          QString val = file.readAll();
          QJsonDocument jsonResponse = QJsonDocument::fromJson(val.toUtf8());
          QJsonObject root_obj = jsonResponse.object();
          qDebug() << root_obj.keys();

          QHash<QString, QHash<QString, QVariant>> tmpH;
          for (auto i: root_obj.keys())
          {
              tmpH.insert(i, root_obj[i].toObject().toVariantHash());
          }
          //QVariantMap json_map = jsonResponse[].toVariantMap();
          qDebug() << tmpH["CenterDrill"]["Speed"].toBool();

    return a.exec();
}
