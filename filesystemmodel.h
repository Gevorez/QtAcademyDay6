#ifndef FILESYSTEMMODEL_H
#define FILESYSTEMMODEL_H

#include <QAbstractListModel>
#include <QDir>

class FileSystemModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(QString currentPath READ getCurrentPath NOTIFY currentPathChanged)
    Q_PROPERTY(bool isRootDirectory READ getIsRootDirectory NOTIFY currentPathChanged)

public:
    enum FileRoles {
        FileNameRole = Qt::UserRole + 1,
        IsDirectoryRole
    };

    explicit FileSystemModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    bool getIsRootDirectory() const;

    QString getCurrentPath() const;
    Q_INVOKABLE void setPath(const QString &path);

signals:
    void currentPathChanged();

private:
    QDir currentDir;
    QStringList fileList;
    void updateFileList();
};

#endif // FILESYSTEMMODEL_H
