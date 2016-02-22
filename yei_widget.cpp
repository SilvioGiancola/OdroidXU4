#include "yei_widget.h"
#include "ui_yei_widget.h"


YEIWidget::YEIWidget(QWidget * parent) : QWidget(parent), ui(new Ui::YEIWidget)
{
    ui->setupUi(this);
    myIMU = new YEI_IMU();
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

YEIWidget::~YEIWidget()
{
    if (myIMU->isOpen())
        myIMU->close();
    delete ui;
}


void YEIWidget::openConnection()
{
    if(myIMU->open() == SUCCESS)
        ui->groupBox->setEnabled(true);
    return;
}

void YEIWidget::closeConnection()
{
    myIMU->close();
    ui->groupBox->setEnabled(false);
    return;
}









Eigen::Quaternionf YEIWidget::getQuaternion()
{
    Eigen::Quaternionf quat = myIMU->getTaredQuaternions();
    QString label = QString("%1 / %2 / %3 / %4").arg(quat.w()).arg(quat.x()).arg(quat.y()).arg(quat.z());
    ui->label_Quaternion->setText(label);
    return quat;
}


