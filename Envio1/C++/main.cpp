#include <cstdlib>
#include <ctime>

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <QDateTime>
#include <QProcess>

#include "lineitem.h"
#include "pointitem.h"
#include "globals.h"
#include "myscene.h"

//#define VEL = 1.2



int main(int argc, char *argv[])
{
    srand(time(0));

    QApplication a(argc, argv);

    // Create the scene
    MyScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    QGraphicsView view(&scene);
    view.setMouseTracking(true);


    // CSV CREATION
    QString projectPath = QCoreApplication::applicationDirPath() + "/../../../";
    QString filePath = projectPath + "/log.csv";

    QFile logFile(filePath);
    if (!logFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Não foi possível abrir log.csv para escrita";
    }
    QTextStream logStream(&logFile);
    logStream << "timestamp,evento,x,y,tipo_objeto,detalhes\n";
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    // END CSV CREATION

    g_logStream = &logStream;
    g_startTime = startTime;


    //QRectF rect = scene.sceneRect();


    // POINTS
    // Generate random positions for the points
    QVector<PointItem*> points;

    int n_points = (rand() % 10) + 1;
    for (int i = 0; i < n_points; i++) {
        PointItem* p = new PointItem((rand()%500) + 1, (rand()%500) + 1, 10, 10, (rand()%3) - 1, (rand()%3) - 1);
        points.append(p);
        scene.addItem(p);
    }
    // END POINTS


    // LINES
    QVector<LineItem*> lines;

    int n_lines = (rand() % 5) + 1;
    for (int i = 0; i < n_lines; i++) {
        QPointF* p1 = new QPointF((rand()%500) + 1, (rand()%500) + 1);
        QPointF* p2 = new QPointF((rand()%500) + 1, (rand()%500) + 1);

        LineItem* l = new LineItem(QLineF(*p1, *p2), (rand()%3) - 1, (rand()%3) - 1);
        lines.append(l);
        scene.addItem(l);
    }
    // END LINES


    // TIMER
    //QRectF rect = scene.sceneRect();
    QTimer *timer = new QTimer(&view);
    QObject::connect(timer, &QTimer::timeout, [&]() {
        for (PointItem* p : points) {
            /*
            if ( p->hitBorder(p, rect) ){
                p->dx *= -1;
                p->dy *= -1;
            }

            if (p->x() <= rect.left() || p->x() + p->rect().width() >= rect.right())
                p->dx *= -1;
            if (p->y() <= rect.top() || p->y() + p->rect().height() >= rect.bottom())
                p->dy *= -1;*/
            //TODO: implement border collision

            p->moveBy(p->dx, p->dy);
        }

        for (LineItem* l : lines) {
            QLineF line = l->line();

            line.translate(l->dx, l->dy);
            l->setLine(line);

        }
    });
    timer->start(16); // ~60 FPS
    // END TIMER


    // TODO: implement python call using QSystem

    view.show();
    return a.exec();
}
