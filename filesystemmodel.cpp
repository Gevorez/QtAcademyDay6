#include "FileSystemModel.h"
#include <QFileInfo>

FileSystemModel::FileSystemModel(QObject *parent)
    : QAbstractListModel(parent) {
    setPath(QDir::homePath());
}

int FileSystemModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return fileList.count();
}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();

    const QString &fileName = fileList[index.row()];
    QFileInfo fileInfo(currentDir.absoluteFilePath(fileName));

    switch (role) {
    case FileNameRole:
        return fileInfo.fileName();
    case IsDirectoryRole:
        return fileInfo.isDir();
    default:
        return QVariant();
    }
}

bool FileSystemModel::getIsRootDirectory() const {
    return currentDir.isRoot();
}

QHash<int, QByteArray> FileSystemModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[FileNameRole] = "fileName";
    roles[IsDirectoryRole] = "isDirectory";
    return roles;
}

QString FileSystemModel::getCurrentPath() const {
    return currentDir.absolutePath();
}

void FileSystemModel::setPath(const QString &path) {
    QDir newDir(path);
    if (newDir.exists()) {
        currentDir = newDir;
        emit currentPathChanged();
        updateFileList();
    }
}

void FileSystemModel::updateFileList() {
    fileList = currentDir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries, QDir::DirsFirst | QDir::Name);
    emit dataChanged(createIndex(0, 0), createIndex(fileList.size(), 0));
}
