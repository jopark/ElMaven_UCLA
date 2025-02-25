#ifndef ISOTOPEPLOT_H
#define ISOTOPEPLOT_H

#include "stable.h"

class MainWindow;
class PeakGroup;
class mzSample;
class QGraphicsItem;
class QGraphicsScene;
class QCPItemText;
class QCPBars;
class QCPTextElement;
class QCPAxisRect;

class IsotopePlot : public QObject, public QGraphicsItem
{
    Q_OBJECT

#if QT_VERSION >= 0x040600
    Q_INTERFACES( QGraphicsItem )
#endif

public:
    IsotopePlot(MainWindow *mw);
    ~IsotopePlot();

    void setPeakGroup(PeakGroup* group);
    void setMainWindow(MainWindow* mw);
    QRectF boundingRect() const;
    void clear();
    void showBars();
    void setPoolThreshold(double poolThreshold) { _poolThreshold = poolThreshold;}

public Q_SLOTS:
    void replot();

private Q_SLOTS:
    void showPointToolTip(QMouseEvent *event);
	
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void contextMenuEvent(QContextMenuEvent * event);


private:
    float _width;
    float _height;
    float _barwidth;
    vector<mzSample*> _samples;
    MainWindow* _mw;
    QVector<QString> labels;
    QCPItemText * mpMouseText;
    QVector<QCPBars *> isotopesType;
    QCPTextElement * title;
    QCPAxisRect * bottomAxisRect;

    PeakGroup* _group;
    vector<PeakGroup> _isotopes;
    double _poolThreshold = 1.0;
    MatrixXf MMDuplicate;
};

#endif
