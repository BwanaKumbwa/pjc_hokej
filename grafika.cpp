#include<grafika.h>
#include<klasy.h>
#include <QThread>
#include <QTimer>

void ElementyBoiska::dodajelement()
{
    QGraphicsRectItem * element1 =
                new QGraphicsRectItem(-200,-150,400,300);
    obrazki.push_back(element1);
    int i = 7;
    for(i;i<11;i++){
        QGraphicsEllipseItem * slupek =
                new QGraphicsEllipseItem(wskazniki[i]->x-(wskazniki[i]->dlugosc/2),wskazniki[i]->y,wskazniki[i]->dlugosc,wskazniki[i]->szerokosc,0);
        slupek->setBrush(Qt::green);
        obrazki.push_back(slupek);
    }
}


void ElementyBoiska::dodajruchome()
{
    QGraphicsEllipseItem * krazek =
            new QGraphicsEllipseItem(wskazniki[0]->x,wskazniki[0]->y,wskazniki[0]->szerokosc,wskazniki[0]->dlugosc,0);
    krazek->setBrush(Qt::black);
    obrazki.push_back(krazek);

    int i = 0;

    for(i;i<12;i++){
        QGraphicsEllipseItem * punkt =
                new QGraphicsEllipseItem(gracze[i]->x,gracze[i]->y,gracze[i]->szerokosc,gracze[i]->dlugosc,0);
        if(i<6){punkt->setBrush(Qt::red);}
        else punkt->setBrush(Qt::blue);
        obrazki.push_back(punkt);
    };
}

void ElementyBoiska::rysujmecz()
{

    obrazki.clear();
    scene->clear();
    this->dodajelement();
    this->dodajruchome();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,view->width(),view->height());
    int i=0;
    while(i<obrazki.size()){
        scene->addItem(obrazki[i]);
        obrazki[i]->setPos(view->width()/2,view->height()/2);
        i++;
    };
    view->show();


}
