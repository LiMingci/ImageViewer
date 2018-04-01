#pragma once

#include <QtGui/QFrame>
#include <QtCore/QList>

class CcPushButton;

class CcDockFrame : public QFrame
{
	Q_OBJECT
public:
	CcDockFrame(QWidget * parent = 0, Qt::WindowFlags f = 0);

	~CcDockFrame();

	CcPushButton* addButton(const QString& title, const QString& iconpath, const QString& objectname);

signals:
	void sig_open();
	void sig_exit();
	void sig_next();
	void sig_front();

private slots:
	void sendOpenSignal(){emit sig_open();}
	void sendExitSignal(){emit sig_exit();}
	void sendNextSignal(){emit sig_next();}
	void sendFrontSignal(){emit sig_front();}

private:
	void initUI();
	void intitData();

private:




};