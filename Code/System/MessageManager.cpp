/******************************
* MessageManager.cpp
******************************/
#include "MessageManager.h"

MessageManager* MessageManager::m_inst = NULL;

MessageManager::MessageManager()
{
}


MessageManager::MessageManager(const MessageManager& other)
{
}


MessageManager::~MessageManager()
{
	//remove all handlers in the list and destroy list and map
}

MessageManager* MessageManager::Instance()
{
	if(!m_inst) {
		m_inst = new MessageManager();
	}
	return m_inst;
}

bool MessageManager::Initialize()
{
	return true;
}

void MessageManager::Shutdown()
{
}

void MessageManager::RegisterHandler(IMessageHandler *hndlr, int msgType)
{
	for (int mt = DEFAULT_MSG; mt <= DEBUG_MSG; mt = mt << 1) {
		if ((msgType & mt) == mt) {
			std::pair<int, IMessageHandler*> newHandler (mt, hndlr);
			m_handlers.insert(newHandler);
		}
	}
}

void MessageManager::UnRegisterHandler(IMessageHandler *hndlr, MessageType msgType)
{
	//may call destructor on pointers???
	for (int mt = DEFAULT_MSG; mt <= DEBUG_MSG; mt = mt << 1) {
		if ((msgType & mt) == mt) {
			auto range = m_handlers.equal_range(MessageType(mt));
			auto iter = range.first;
			while (iter != range.second)
			{
				if (iter->second == hndlr) {
					auto temp = iter;
					iter++;
					m_handlers.erase(temp);
				} else {
					iter++;
				}
			}
		}
	}

}

void MessageManager::NotifyHandlers(MessageType msgType, char* msg)
{
	//implements enum as int
	for (int mt = DEFAULT_MSG; mt <= DEBUG_MSG; mt = mt << 1) {
		if ((msgType & mt) == mt) {
			auto range = m_handlers.equal_range(MessageType(mt));
			for (auto iter = range.first; iter != range.second; iter++) {
				iter->second->Notify(msg);
			}
		}
	}
}
