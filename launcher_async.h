#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <iostream>

#include "talk/base/nethelpers.h"


#include <qwidget.h>
#include <qpushbutton.h>
class AsyncButton :public QWidget, public sigslot::has_slots<>
{
	Q_OBJECT
public:
	AsyncButton();
	~AsyncButton();

private:
	QPushButton *_button;
	talk_base::AsyncResolver *_resolver;
	void OnResolveResult(talk_base::SignalThread * t);
public slots:
	void DoConnect();


};

#endif
