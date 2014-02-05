#ifndef __ADXL345_2489_h__
#define __ADXL345_2489_h__

#include "SensorBase.h"

class I2C;

/**
 * ADXL345 Accelerometer on I2C.
 * 
 * This class alows access to a Analog Devices ADXL345 3-axis accelerometer on an I2C bus.
 * This class assumes the default (not alternate) sensor address of 0x3A (8-bit address).
 */
class ADXL345_2489 : public SensorBase
{
protected:
	UINT8 kAddress;
	static const UINT8 kPowerCtlRegister = 0x2D;
	static const UINT8 kDataFormatRegister = 0x31;
	static const UINT8 kDataRegister = 0x32;
	static const double kGsPerLSB = 0.00390625;
	enum PowerCtlFields {kPowerCtl_Link=0x20, kPowerCtl_AutoSleep=0x10, kPowerCtl_Measure=0x08, kPowerCtl_Sleep=0x04};
	enum DataFormatFields {kDataFormat_SelfTest=0x80, kDataFormat_SPI=0x40, kDataFormat_IntInvert=0x20,
		kDataFormat_FullRes=0x08, kDataFormat_Justify=0x04};

public:
	enum DataFormat_Range {kRange_2G=0x00, kRange_4G=0x01, kRange_8G=0x02, kRange_16G=0x03};
	enum Axes {kAxis_X=0x00, kAxis_Y=0x02, kAxis_Z=0x04};
	struct AllAxes
	{
		double XAxis;
		double YAxis;
		double ZAxis;
	};

public:
	explicit ADXL345_2489(UINT8 moduleNumber,UINT8 address , DataFormat_Range range=kRange_2G);
	virtual ~ADXL345_2489();
	virtual double GetAcceleration(Axes axis);
	virtual AllAxes GetAccelerations();

protected:
	I2C* m_i2c;
};

#endif
