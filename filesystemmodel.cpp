// filesystemmodel.cpp
#include "filesystemmodel.h"
#include <QStandardPaths>


FileSystemModel::FileSystemModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void FileSystemModel::setRootPath(const QString &path)
{
    beginResetModel();
    m_dir.setPath(path.isEmpty() ? QStandardPaths::writableLocation(QStandardPaths::HomeLocation) : path);
    updateData();
    endResetModel();
}

int FileSystemModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_fileInfoList.count();
}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_fileInfoList.size())
        return QVariant();

    const QFileInfo &fileInfo = m_fileInfoList.at(index.row());

    switch (role) {
    case NameRole:
        return fileInfo.fileName();
    case TypeRole:
        return fileInfo.isDir() ? "Directory" : "File";
    default:
        return QVariant();
    }
}

QString FileSystemModel::getName(int index) const
{
    if (index < 0 || index >= m_fileInfoList.size())
        return QString();

    return m_fileInfoList.at(index).fileName();
}

QString FileSystemModel::getType(int index) const
{
    if (index < 0 || index >= m_fileInfoList.size())
        return QString();

    return m_fileInfoList.at(index).isDir() ? "Directory" : "File";
}


void FileSystemModel::updateData()
{
    m_fileInfoList = m_dir.entryInfoList();
}
