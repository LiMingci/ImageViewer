/*!
 * \file CcImageViewer.h
 *
 * \author LiMingci
 * \date ÈýÔÂ 2018
 *
 * 
 */
#ifndef CC_IMAGE_VIEWER_H
#define CC_IMAGE_VIEWER_H

#include <QtGui/QWidget>


#include "CcImageViewer/export.h"

class QGraphicsView;
class QDragEnterEvent;
class QDropEvent;
class QPushButton;
class IMGVIEWER_API CcImageViewer : public QWidget
{
	Q_OBJECT

public:
	CcImageViewer(QWidget* parent = 0, Qt::WindowFlags f = 0 );
	~CcImageViewer();

	bool showImage(QString imagepath);

protected:
	void dragEnterEvent(QDragEnterEvent * event);

	void dropEvent(QDropEvent * event);

signals:

private slots:

private:
	void initUI();
	
	void initData();

	void initConnect();

private:
	QGraphicsView*     _graphicsView;

	//QPushButton*       _okButton;

};


#endif

