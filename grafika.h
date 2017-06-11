#ifndef GRAFIKA
#define GRAFIKA

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QTimer>
#include <QEventLoop>

class ElementyBoiska: public QObject,
        public QGraphicsRectItem, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    ElementyBoiska(){QTimer *timer = new QTimer(this);
                     QEventLoop *event=new QEventLoop(this);
                     connect(timer, SIGNAL(timeout()), event, SLOT(quit()));
                     timer->start(1000);
                     rysujmecz();
                     event->exec()
                     ;};
    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsView * view = new QGraphicsView(scene);

    //view->setFixedSize(400,400);
    void dodajelement();
    void dodajruchome();  
public slots:
    void rysujmecz();
};

/*QTimer *timer = new QTimer(this);
        QEventLoop *event=new QEventLoop(this);
        connect(timer, SIGNAL(timeout()), event, SLOT(quit()));
        timer->start(waitT);
        event->exec();*/

#endif // GRAFIKA

