//Search

#include "desc_client.h"
#include "dungeon.h"
#include "unique_item.h"

//Add after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif

//Search in

void CParty::Destroy()
{

			}
			else
			{
				rMember.pCharacter->SetLastAttacked(dwTime);
				rMember.pCharacter->StartDestroyWhenIdleEvent();
			}

//Add before

#ifdef ENABLE_QUEEN_NETHIS
				if (SnakeLair::CSnk::instance().IsSnakeMap(rMember.pCharacter->GetMapIndex()))
				{
					SnakeLair::CSnk::instance().LeaveParty(rMember.pCharacter->GetMapIndex());
					SnakeLair::CSnk::instance().Leave(rMember.pCharacter);
				}
#endif