//Search

#include "../../common/VnumHelper.h"
#include "DragonSoul.h"

//Add after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif

//Search

		case DEVILTOWER_BLACKSMITH_WEAPON_MOB:
		case DEVILTOWER_BLACKSMITH_ARMOR_MOB:

//Add before

#ifdef ENABLE_QUEEN_NETHIS
		case SnakeLair::PILAR_STEP_4:
			{
				if(from->IsPC())
				{
					if (SnakeLair::CSnk::instance().IsSnakeMap(from->GetMapIndex()))
						SnakeLair::CSnk::instance().OnKillPilar(item, from, this);
				}
			}
			break;
		case SnakeLair::BLACKSMITH_5:
			{
				if(from->IsPC())
				{
					if (SnakeLair::CSnk::instance().IsSnakeMap(from->GetMapIndex()))
						SnakeLair::CSnk::instance().OnKillBlackSmith(item, from, this);
				}
			}
			break;

		case SnakeLair::SNAKE_STATUE1:
		case SnakeLair::SNAKE_STATUE2:
		case SnakeLair::SNAKE_STATUE3:
		case SnakeLair::SNAKE_STATUE4:
			{
				if(from->IsPC())
				{
					if (SnakeLair::CSnk::instance().IsSnakeMap(from->GetMapIndex()))
						SnakeLair::CSnk::instance().OnStatueSetRotation(item, from, this);
				}
			}
			break;
#endif