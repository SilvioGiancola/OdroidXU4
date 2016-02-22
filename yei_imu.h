#ifndef YEI_IMU_H
#define YEI_IMU_H
/******************/
/*** ADAFRUIT DRIVERS ***/
/******************/

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>
#include <iomanip>
#include <QTime>

#define SUCCESS 0
#define ERROR 1
#define ERR_DATABITS 2
#define ERR_PARITY 3
#define ERR_STOPBITS 4
#define ERR_FLOWCONTROL 5
#define ERR_OPEN 6
#define ERR_PLUG 7
#define ERR_MESSAGE 8
#define ERR_BAUDRATE 9



#define REG_PAGE_ID         0x07
#define REG_START_RAW_DATA  0x08
#define REG_START_ACC_DATA  0x08
#define REG_START_MAG_DATA  0x0E
#define REG_START_GYR_DATA  0x14
#define REG_START_EUL_DATA  0x1A
#define REG_START_QUA_DATA  0x20
#define REG_START_LIA_DATA  0x28
#define REG_START_GRV_DATA  0x2E
#define REG_START_TMP_DATA  0x34
#define REG_OPR_MODE        0x3D
#define REG_PWR_MODE        0x3E
#define REG_SYS_TRIGGER     0x3F


#include <QWidget>
#include <QDebug>
#include <eigen3/Eigen/Geometry>


class YEI_IMU : public QWidget
{
    Q_OBJECT
public:

    // Constructor
    explicit YEI_IMU(QWidget *parent = 0) : QWidget(parent)
    {

    }


    // Open/Close the Serial connection
    int open()
    {
        QList < QSerialPortInfo > ava = QSerialPortInfo::availablePorts();
        foreach (const QSerialPortInfo &info, ava )
        {
            if(info.vendorIdentifier() == 0x2476)
                if(info.productIdentifier() == 0x1010)
                    serial.setPortName(info.portName());

        }

        if (serial.portName().isEmpty())
            return ERR_PLUG;

        if (!serial.open(QIODevice::ReadWrite))
            return ERR_OPEN;

        if (!serial.setBaudRate(QSerialPort::Baud115200))
            return ERR_BAUDRATE;

        if (!serial.setDataBits(QSerialPort::Data8))
            return ERR_DATABITS;

        if (!serial.setParity(QSerialPort::NoParity))
            return ERR_PARITY;

        if (!serial.setStopBits(QSerialPort::OneStop))
            return ERR_STOPBITS;

        if (!serial.setFlowControl(QSerialPort::NoFlowControl))
            return ERR_FLOWCONTROL;

        //  serial.setReadBufferSize((qint64)1);

        //returnPose();

        return SUCCESS;
    }

    void close()
    {
        serial.close();
    }

    bool isOpen()
    {
        return serial.isOpen();
    }


    // Pose Calibration
    Eigen::Quaternionf getTareOrientationQuaternion()
    {
        Eigen::Quaternionf quat;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":128\n"));
            QStringList elements = answer.split(",");
            quat.x() = elements.at(0).toFloat();
            quat.y() = elements.at(1).toFloat();
            quat.z() = elements.at(2).toFloat();
            quat.w() = elements.at(3).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return quat;
    }

    void setTareOrientationQuaternion()
    {
        if ( isOpen() )
        {
            WriteReadASCII(QString(":96\n"));
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return;
    }

    void setTareOrientationQuaternion(Eigen::Quaternionf TareQuaternion)
    {
        if ( isOpen() )
        {
            QString message = QString(":97,%1,%2,%3,%4\n")
                    .arg(TareQuaternion.x())
                    .arg(TareQuaternion.y())
                    .arg(TareQuaternion.z())
                    .arg(TareQuaternion.w());
            WriteReadASCII(message);
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return;
    }


    Eigen::Quaternionf  getTaredQuaternions()
    {
        Eigen::Quaternionf quat;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":0\n"));
            QStringList elements = answer.split(",");
            quat.x() = elements.at(0).toFloat();
            quat.y() = elements.at(1).toFloat();
            quat.z() = elements.at(2).toFloat();
            quat.w() = elements.at(3).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return quat;
    }

    Eigen::Vector3f     getTaredEulerAngles()
    {
        Eigen::Vector3f euler;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":1\n"));
            QStringList elements = answer.split(",");
            euler.x() = elements.at(0).toFloat();
            euler.y() = elements.at(1).toFloat();
            euler.z() = elements.at(2).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return euler;
    }

    Eigen::Matrix3f     getTaredRotationMatrix()
    {
        Eigen::Matrix3f matrix;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":2\n"));
            QStringList elements = answer.split(",");
            matrix << elements.at(0).toFloat(),elements.at(1).toFloat(), elements.at(2).toFloat(),
                    elements.at(3).toFloat(),elements.at(4).toFloat(), elements.at(5).toFloat(),
                    elements.at(6).toFloat(),elements.at(7).toFloat(), elements.at(8).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return matrix;
    }

    Eigen::AngleAxisf   getTaredAxisAngle()
    {
        Eigen::AngleAxisf angleAxis;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":3\n"));
            QStringList elements = answer.split(",");
            angleAxis.axis() << elements.at(0).toFloat(),elements.at(1).toFloat(), elements.at(2).toFloat();
            angleAxis.angle() = elements.at(3).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return angleAxis;
    }

    Eigen::Quaternionf  getDifferenceQuaternions()
    {
        Eigen::Quaternionf quat;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":5\n"));
            QStringList elements = answer.split(",");
            quat.x() = elements.at(0).toFloat();
            quat.y() = elements.at(1).toFloat();
            quat.z() = elements.at(2).toFloat();
            quat.w() = elements.at(3).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return quat;
    }

    Eigen::Quaternionf  getUntaredQuaternions()
    {
        Eigen::Quaternionf quat;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":6\n"));
            QStringList elements = answer.split(",");
            quat.x() = elements.at(0).toFloat();
            quat.y() = elements.at(1).toFloat();
            quat.z() = elements.at(2).toFloat();
            quat.w() = elements.at(3).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return quat;
    }

    Eigen::Vector3f     getUntaredEulerAngles()
    {
        Eigen::Vector3f euler;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":7\n"));
            QStringList elements = answer.split(",");
            euler.x() = elements.at(0).toFloat();
            euler.y() = elements.at(1).toFloat();
            euler.z() = elements.at(2).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return euler;
    }

    Eigen::Matrix3f     getUntaredRotationMatrix()
    {
        Eigen::Matrix3f matrix;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":8\n"));
            QStringList elements = answer.split(",");
            matrix << elements.at(0).toFloat(),elements.at(1).toFloat(), elements.at(2).toFloat(),
                    elements.at(3).toFloat(),elements.at(4).toFloat(), elements.at(5).toFloat(),
                    elements.at(6).toFloat(),elements.at(7).toFloat(), elements.at(8).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return matrix;
    }

    Eigen::AngleAxisf   getUntaredAxisAngle()
    {
        Eigen::AngleAxisf angleAxis;
        if ( isOpen() )
        {
            QString answer = WriteReadASCII(QString(":9\n"));
            QStringList elements = answer.split(",");
            angleAxis.axis() << elements.at(0).toFloat(),elements.at(1).toFloat(), elements.at(2).toFloat();
            angleAxis.angle() = elements.at(3).toFloat();
        }
        else
        {
            qWarning() << "  -> Error Device not opened";
        }

        return angleAxis;
    }




private:
    // Basic Communication
    QString WriteReadASCII(QString message)
    {
        serial.write(message.toStdString().c_str());
        serial.waitForBytesWritten(1000);
        serial.waitForReadyRead(1000);
        QByteArray bytes = serial.readAll();
        return QString::fromLocal8Bit(bytes);
    }

    QSerialPort serial;
};

#endif // YEI_IMU_H
