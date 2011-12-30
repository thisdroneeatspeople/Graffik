#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QDialog>

#include "MoCoBus/omnetwork.h"
#include "Slim/slimcommandparser.h"

#include "core/NetworkModel/networkmodel.h"
#include "core/AddNetDialog/addnetdialog.h"
#include "core/AddDeviceDialog/adddevicedialog.h"

namespace Ui {
class networkManager;
}

class networkManager : public QDialog
{
    Q_OBJECT
    
public:
    explicit networkManager(networkModel* c_net, SlimCommandParser* c_parse, QWidget *parent = 0);
    ~networkManager();
    
private:
    Ui::networkManager *ui;
    networkModel* _netMod;
    SlimCommandParser* _parser;

private slots:
    void on_addBusButton_clicked();
    void on_addDevButton_clicked();

};

#endif // NETWORKMANAGER_H
