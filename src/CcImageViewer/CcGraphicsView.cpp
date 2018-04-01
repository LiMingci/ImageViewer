#include "CcImageViewer/CcGraphicsView.h"
//#include <QDebug>


CcGraphicsView::CcGraphicsView(void)
{
	this->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
	this->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
	this->setCursor(Qt::OpenHandCursor);
	//this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

	//this->setBackgroundRole(QPalette::Dark);
	this->setStyleSheet("background-color:black;");
	m_isLeftButtonPress = false;

}


CcGraphicsView::~CcGraphicsView(void)
{
}

void CcGraphicsView::wheelEvent(QWheelEvent *event)
{
	qreal scaleFactor = pow((double)2, -event->delta() / 200.0);
	qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();

	if (factor < 0.01 || factor > 100) 
		return;

	scale(scaleFactor, scaleFactor);
	emit test();
}


void CcGraphicsView::mousePressEvent(QMouseEvent *event)
{
	//int hx = event->x();
	//int vy = event->y();
	if(event->button() == Qt::LeftButton)
	{
		m_isLeftButtonPress = true;
		this->setCursor(Qt::ClosedHandCursor);
	}

	mPos = mapToScene(event->pos());
	//qDebug() << "mPos = " << mPos;
	return QGraphicsView::mousePressEvent(event);

}

void CcGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
	if (!m_isLeftButtonPress) return;

	QPointF movepoint = mapToScene(event->pos());
	QPointF offset = movepoint - mPos;
	QPoint viewCenter(viewport()->width()/2,viewport()->height()/2);
	QPointF sceneCenter = mapToScene(viewCenter);
	QPointF target = sceneCenter - offset;
	centerOn(target);
	this->update();
	return QGraphicsView::mouseMoveEvent(event);

}


void CcGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
	this->setCursor(Qt::OpenHandCursor);
	m_isLeftButtonPress = false;

	this->update();
	return QGraphicsView::mouseReleaseEvent(event);
}

