/******************************
* MessageLogger.h
*
* Desc: Handles all msges and will
*		save them to a log file
*
******************************/

#ifndef _MESSAGELOGGER_H_
#define _MESSAGELOGGER_H_

#include "MessageManager.h"

class MessageLogger : public IMessageHandler
{
public:
	MessageLogger();
	virtual ~MessageLogger();

	void Initialize();
	void Shutdown();

	virtual bool Notify(char* msg);

private:
};

#endif