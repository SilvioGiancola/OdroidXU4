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
    if (myIMU->isOpen())
            myIMU->close();
    delete ui;
}




void AdafruitWidget::on_pushButton_Open_clicked()
{
    if(myIMU->open() == SUCCESS)
        ui->groupBox->setEnabled(true);

}

void AdafruitWidget::on_pushButton_Close_clicked()
{
    myIMU->close();
    ui->groupBox->setEnabled(false);
}









void AdafruitWidget::on_pushButton_Quaternion_clicked()
{
    Eigen::Quaternionf quat = myIMU->returnPose();
    QString label = QString("%1 / %2 / %3 / %4").arg(quat.w()).arg(quat.x()).arg(quat.y()).arg(quat.z());
    ui->label_Quaternion->setText(label);

//    if (viewer->contains("markers"))
//        viewer->removeCoordinateSystem("markers");
//    viewer->addCoordinateSystem(0.5,Eigen::Affine3f(quat.matrix()),"markers");
//    ui->qvtkwidget->update ();
}

void AdafruitWidget::on_pushButton_Init_clicked()
{
    myIMU->init();
}

void AdafruitWidget::on_pushButton_Calib_clicked()
{

}
