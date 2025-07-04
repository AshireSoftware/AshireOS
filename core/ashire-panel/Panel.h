#ifndef PANEL_H
#define PANEL_H

#include <QtWidgets/QWidget>
#include <QWindow>
#include <QObject>
#include <QVariantList>

class Panel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList windows READ windows NOTIFY windowsChanged)
public:
    explicit Panel(QObject *parent = nullptr);
    QVariantList windows() const;
    Q_INVOKABLE void refreshWindows();
    Q_INVOKABLE QString getFocusedWindow();
    Q_INVOKABLE void minimizeWindow(const QString &winId);
    Q_INVOKABLE void focusWindow(const QString &winId);
    Q_INVOKABLE QString getPrevFocusedId() const;
    Q_INVOKABLE void setPrevFocusedId(const QString &id);

public slots:
    void openStartMenu();
    bool isProgramRunning(const std::string &programName);
signals:
    void windowsChanged();

private:
    QVariantList m_windows;
    QString m_prevFocusedId;
};

#endif // PANEL_H
