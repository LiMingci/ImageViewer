#pragma once

#include <QtGui/QPushButton>

class CcPushButton : public QPushButton
{
	Q_OBJECT
public:
	CcPushButton( const QString & text, QWidget * parent = 0 );

	~CcPushButton();

	void setBackgroundPic(const QString& picpath);
private:
};