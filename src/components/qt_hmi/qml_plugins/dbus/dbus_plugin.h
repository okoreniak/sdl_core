#ifndef DBUS_PLUGIN_H
#define DBUS_PLUGIN_H

#include <QQmlExtensionPlugin>
#include <QDBusContext>

class DbusPlugin : public QQmlExtensionPlugin, public QDBusContext
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};

#endif // DBUS_PLUGIN_H

