
#include "CcPushButton.h"

CcPushButton::CcPushButton(const QString & text, QWidget * parent /*= 0*/)
	: QPushButton(text, parent)
{
	this->setFlat(true);
	this->setFixedSize(64, 80);
	//this->setIconSize(QSize(64, 64));
}

CcPushButton::~CcPushButton()
{

}

void CcPushButton::setBackgroundPic(const QString& picpath)
{
	QString begin_str("background-image: url(");
	QString end_str(");");
	QString style_str = begin_str + picpath + end_str;
	
	QString ccc("background-repeat:no-repeat;\
				background-position: center top;\
	            text-align: center bottom;\
				color: white;\
				background-color: transparent;\
	            padding-bottom: 2px;");
	
	this->setStyleSheet(style_str + ccc);




}