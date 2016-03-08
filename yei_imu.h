#ifndef YEI_IMU_H
#define YEI_IMU_H
/******************/
/*** ADAFRUIT DRIVERS ***/
/******************/

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>
#include <fstream>

#define SUCCESS 0
#define ERROR 1


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
        {
            qWarning() << " Error in finding ports";
            return ERROR;
        }
        if (!serial.open(QIODevice::ReadWrite))
        {
            qWarning() << " Error in openning device";
            return ERROR;
        }
        if (!serial.setBaudRate(QSerialPort::Baud115200))
        {
            qWarning() << " Error in setting baudrate";
            return ERROR;
        }
        if (!serial.setDataBits(QSerialPort::Data8))
        {
            qWarning() << " Error in setting 8 bits";
            return ERROR;
        }
        if (!serial.setParity(QSerialPort::NoParity))
        {
            qWarning() << " Error in setting not parity";
            return ERROR;
        }
        if (!serial.setStopBits(QSerialPort::OneStop))
        {
            qWarning() << " Error in setting onestop";
            return ERROR;
        }
        if (!serial.setFlowControl(QSerialPort::NoFlowControl))
        {
            qWarning() << " Error in setting no flow control";
            return ERROR;
        }

        std::string filename = "../SfMCalib.txt";
        Eigen::Matrix4f m;
        std::ifstream input(filename.c_str());
        if (input.fail())
        {
            std::cerr << "ERROR. Cannot find file '" << filename << "'." << std::endl;
            m = Eigen::Matrix4f(0,0);
            return false;
        }
        std::string line;
        float d;

        std::vector<float> v;
        int n_rows = 0;
        while (getline(input, line))
        {
            ++n_rows;
            std::stringstream input_line(line);
            while (!input_line.eof())
            {
                input_line >> d;
                v.push_back(d);
            }
        }
        input.close();

        int n_cols = v.size()/n_rows;
        m = Eigen::Matrix4f(n_rows,n_cols);

        for (int i=0; i<n_rows; i++)
            for (int j=0; j<n_cols; j++)
                m(i,j) = v[i*n_cols + j];


        std::cout << "calib is " << std::endl;
        std::cout << m << std::endl;

        setTareOrientationQuaternion(Eigen::Quaternionf(m.block<3,3>(0,0)));

        qDebug () << " YEI IMU successfully opened";

        return SUCCESS;
    }

    void close()
    {
        qDebug () << " YEI IMU closed";
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
