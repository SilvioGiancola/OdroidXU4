#include "adafruit_widget.h"
#include "ui_adafruit_widget.h"


AdafruitWidget::AdafruitWidget(QWidget * parent) : QWidget(parent), ui(new Ui::AdafruitWidget)
{
    ui->setupUi(this);
    myIMU = new Adafruit_UART();
    /*
    viewer.reset(new pcl::visualization::PCLVisualizer("Viewer",false));
    ui->qvtkwidget->SetRenderWindow(viewer->getRenderWindow());
    viewer->setCameraPosition(-5,1,1, // mi posiziono dietro ad un Kinect
                              0.5,0.5,0.5, // guardo un punto centrale
                              0,0,1);   // orientato con la y verso l'alto
    viewer->setCameraClipDistances(-10,10);
    viewer->setBackgroundColor (0.5, 0.5, 0.5);
    viewer->addCoordinateSystem(1.0, "Main Reference System");
    ui->qvtkwidget->update ();




    // point selected (shift + left click) info
    viewer->setupInteractor(ui->qvtkwidget->GetInteractor(),ui->qvtkwidget->GetRenderWindow());
    viewer->getInteractorStyle()->setKeyboardModifier(pcl::visualization::INTERACTOR_KB_MOD_SHIFT);
*/
}

AdafruitWidget::~AdafruitWidget()
{
    if (myIMU->isopen())
        myIMU->close();
    delete ui;
}


void AdafruitWidget::openConnection()
{
    if(myIMU->open() == SUCCESS)
        ui->groupBox->setEnabled(true);
    return;
}

void AdafruitWidget::closeConnection()
{
    myIMU->close();
    ui->groupBox->setEnabled(false);
    return;
}









Eigen::Quaternionf AdafruitWidget::getQuaternion()
{
    Eigen::Quaternionf quat = myIMU->returnPose();
    QString label = QString("%1 / %2 / %3 / %4").arg(quat.w()).arg(quat.x()).arg(quat.y()).arg(quat.z());
    ui->label_Quaternion->setText(label);
    return myIMU->returnPose();
}

void AdafruitWidget::initializeSensor()
{
    myIMU->init();
    return;
}

