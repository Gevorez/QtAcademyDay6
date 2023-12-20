#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H

#include <QAbstractListModel>
#include <QDir>

class FileSystemModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        TypeRole
    };

    explicit FileSystemModel(QObject *parent = nullptr);

    void setRootPath(const QString &path = QString());

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    QString getName(int index) const;
    QString getType(int index) const;

private:
    QDir m_dir;
    QList<QFileInfo> m_fileInfoList;

    void updateData();
};

#endif
