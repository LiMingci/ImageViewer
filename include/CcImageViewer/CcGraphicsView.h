/*!
 * \file CcGraphicsView.h
 *
 * \author LiMingci
 * \date ÈýÔÂ 2018
 *
 * 
 */
#pragma once
#include <QtGui/QGraphicsView>
#include <QtGui/QWheelEvent>
#include <QObject>

#include "CcImageViewer/export.h"

class IMGVIEWER_API CcGraphicsView : public QGraphicsView
{
	Q_OBJECT
public:
	CcGraphicsView(void);
	~CcGraphicsView(void);
signals:
	void test();

protected:
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	QPointF mPos;

	bool    m_isLeftButtonPress;
};

