/******************************
* MessageManager.h
*
* Desc: Singleton to handle all msg traffic
*		for output.  A derived listener can subscribe
*		and do what it will with the information.
*
******************************/
#ifndef _MESSAGEMANAGER_H_
#define _MESSAGEMANAGER_H_

#include <Windows.h>
#include <forward_list>
#include <unordered_map>


enum MessageType
{
	DEFAULT_MSG =	0x1,
	INFO_MSG =		0x2,
	ERROR_MSG =		0x4,
	DEBUG_MSG =		0x8
};

class __declspec(novtable) IMessageHandler
{
public:
	virtual ~IMessageHandler() {};

	virtual bool Notify(char* msg) = 0;
};


class MessageManager
{
private:
	MessageManager();
	MessageManager(const MessageManager&);
	MessageManager& operator=(MessageManager const&);
	~MessageManager();

public:
	static MessageManager * Instance();
	bool Initialize();
	void Shutdown();
	void RegisterHandler(IMessageHandler *hndlr, int msgType = DEFAULT_MSG);
	void UnRegisterHandler(IMessageHandler *hndlr, MessageType msgType);
	void NotifyHandlers(MessageType msgType, char* msg);
	
private:
	static MessageManager*				m_inst;
	std::unordered_multimap< int, IMessageHandler* >			m_handlers;
};

#endif