//Search

#include "item_manager.h"

//Add after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif


//Search

			// leader can remove any member
			if (p->pid == ch->GetPlayerID() || pParty->GetMemberCount() == 2)
			{
				// party disband
				CPartyManager::instance().DeleteParty(pParty);
			}

//Add before

#ifdef ENABLE_QUEEN_NETHIS
			if (SnakeLair::CSnk::instance().IsSnakeMap(ch->GetMapIndex()))
			{
				ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<��Ƽ> ������������ ��Ƽ���� �߹��� �� �����ϴ�."));
				return;
			}
#endif

//Search

			if (ch->GetDungeon())
			{
				ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<��Ƽ> ������������ ��Ƽ���� �߹��� �� �����ϴ�."));
			}
			else
			{

//Add after


#ifdef ENABLE_QUEEN_NETHIS
				if (SnakeLair::CSnk::instance().IsSnakeMap(ch->GetMapIndex()))
				{
					ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<��Ƽ> ������������ ��Ƽ���� �߹��� �� �����ϴ�."));
					return;
				}
#endif