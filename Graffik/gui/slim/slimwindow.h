#ifndef SLIMWINDOW_H
#define SLIMWINDOW_H

#include <QWidget>
#include <QString>

#include "MoCoBus/omcommandbuffer.h"
#include "MoCoBus/omnetwork.h"
#include "Slim/commandhistorymodel.h"
#include "Slim/slimcommandparser.h"

namespace Ui {
class SlimWindow;
}

class SlimWindow : public QWidget
{
    Q_OBJECT

public:
    SlimWindow(OMNetwork* net, CommandHistoryModel* hist, SlimCommandParser* parse, QWidget *parent = 0);
    ~SlimWindow();

private slots:
    void onCmdEntry();
    void onCmdResult(slimCommand);

public slots:
        void registerNewDevice(OMbusInfo* p_bus, OMdeviceInfo* p_dev);
        void removeDevice(OMbusInfo* p_bus, unsigned short p_addr);
private:

    Ui::SlimWindow *ui;
    CommandHistoryModel* _cmdHist;
    OMNetwork* _net;
    SlimCommandParser * _parser;
};


#endif // SLIMWINDOW_H
