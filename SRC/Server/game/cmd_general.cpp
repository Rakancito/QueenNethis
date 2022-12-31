//Search

#include "../../common/VnumHelper.h"

//Add after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif

//Search

	if (ch->GetWarMap() && !ch->IsObserverMode())
	{
		[...]
	}


//Add after

#ifdef ENABLE_QUEEN_NETHIS
	if (ch->IsSnakeMap())
	{
		switch (subcmd)
		{
			case SCMD_RESTART_TOWN:
				sys_log(0, "do_restart: restart town");
				PIXEL_POSITION pos;

				ch->RestartAtSamePos();

				ch->PointChange(POINT_HP, ch->GetMaxHP() - ch->GetHP());
				ch->PointChange(POINT_SP, ch->GetMaxSP() - ch->GetSP());
				ch->ReviveInvisible(3);
				break;

			case SCMD_RESTART_HERE:
				sys_log(0, "do_restart: restart here");
				ch->RestartAtSamePos();
				ch->PointChange(POINT_HP, ch->GetMaxHP() - ch->GetHP());
				ch->PointChange(POINT_SP, ch->GetMaxSP() - ch->GetSP());
				ch->ReviveInvisible(3);
				break;
		}

		return;
	}

#endif

//Search

ACMD(do_ungroup)
{
	[...]
	if (ch->GetDungeon())
	{
		[...]
	}

//Add after

#ifdef ENABLE_QUEEN_NETHIS
	if (SnakeLair::CSnk::instance().IsSnakeMap(ch->GetMapIndex()))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("<파티> 던전 안에서는 파티에서 나갈 수 없습니다."));
		return;
	}
#endif