#ifndef USERDATA_H
#define USERDATA_H

#include <QSettings>
#include <QString>
#include <QHash>
#include <QVariant>


#include "MoCoBus/omnetwork.h"

class UserData : public QObject
{
    Q_OBJECT
public:
    explicit UserData(QWidget* parent = 0);
    ~UserData();

    void recoverBuses(OMNetwork* p_net);

public slots:
    void busAdded(OMbusInfo* p_bus);
    void deviceAdded(OMbusInfo* p_bus, OMdeviceInfo* p_dev);

private:
    QSettings* m_qset;
    QHash<QString, QVariant>* m_buses;
    QHash<QString, QVariant>* m_devices;
    QWidget* m_parent;

    void _recoverDevices(OMNetwork* p_net, QString p_bus, QString p_busPort);

};

#endif // USERDATA_H