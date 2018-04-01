#include <QtGui/QPushButton>
#include <QtGui/QHBoxLayout>
#include "CcDockFrame.h"
#include "CcPushButton.h"

CcDockFrame::CcDockFrame(QWidget * parent/* = 0*/, Qt::WindowFlags f/* = 0*/)
	: QFrame(parent, f)
{

	initUI();
}

CcDockFrame::~CcDockFrame()
{

}

void CcDockFrame::initUI()
{
	//this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setFixedHeight(80);

	QList<CcPushButton*> buttons;
	CcPushButton* button1 = this->addButton(tr("open"), tr(":/CcMainWin/open.png"), tr("openButton"));
	connect(button1, SIGNAL(clicked()), this, SLOT(sendOpenSignal()));
	buttons.append(button1);
	CcPushButton* button2 = this->addButton(tr("front"), tr(":/CcMainWin/back.png"), tr("frontButton"));
	connect(button2, SIGNAL(clicked()), this, SLOT(sendFrontSignal()));
	buttons.append(button2);
	CcPushButton* button3 = this->addButton(tr("next"), tr(":/CcMainWin/next.png"), tr("nextButton"));
	connect(button3, SIGNAL(clicked()), this, SLOT(sendNextSignal()));
	buttons.append(button3);
	CcPushButton* button4 = this->addButton(tr("exit"), tr(":/CcMainWin/exit.png"), tr("exitButton"));
	connect(button4, SIGNAL(clicked()), this, SLOT(sendExitSignal()));
	buttons.append(button4);

	QHBoxLayout* hlayout = new QHBoxLayout(this);
	hlayout->setMargin(0);
	hlayout->addSpacing(20);
	for (int i = 0; i < buttons.size(); i++)
	{
		hlayout->addWidget(buttons[i]);
		hlayout->addSpacing(20);
	}

	this->setFixedWidth(80 * buttons.size());
}

void CcDockFrame::intitData()
{

}


CcPushButton* CcDockFrame::addButton(const QString& title,const QString& iconpath, const QString& objectname)
{
	CcPushButton* button = new CcPushButton(title, this);
	button->setObjectName(objectname);
	button->setBackgroundPic(iconpath);
	return button;

}

