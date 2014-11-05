#pragma once

#include "TrackingMethod.h"
#include <NuiApi.h>
#include <NuiImageCamera.h>
#include <NuiSensor.h>

class KinectSDKTracking : public TrackingMethod
{
	Q_OBJECT
public:
	KinectSDKTracking(GLDisplay *display);
	~KinectSDKTracking();

	virtual bool init();
	virtual void draw();
	virtual void close();
	void drawDepth();

public slots:
	void startVideo();
	void startDepth();
	void stopVideo();

protected:
	void run();

private:
	static const char* methodName;

	enum TYPES_OF_STREAM {COLOR = 1, DEPTH = 2};
	TYPES_OF_STREAM streamType;

	unsigned char* data;
	unsigned int textureId;
	void* rgbStream;
	void* depthStream;
	INuiSensor* sensor;

	void createButtons();
};

