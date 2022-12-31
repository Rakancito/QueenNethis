//Search

#include "check_server.h"

//Add after

#ifdef ENABLE_QUEEN_NETHIS
#include "SnakeLair.h"
#endif

//Search

	quest::CQuestManager quest_manager;

//Add before

#ifdef ENABLE_QUEEN_NETHIS
	SnakeLair::CSnk SnakeLair_manager;
#endif

//Search

		if(bXTrapEnabled)
		{
			if (!XTManager.LoadXTrapModule())
			{
				CleanUpForEarlyExit();
				return 0;
			}
#if defined (__FreeBSD__) && defined(__FILEMONITOR__)
			//PFN_FileChangeListener pNotifyFunc = boost::bind( &CXTrapManager::NotifyMapFileChanged, CXTrapManager::instance(), _1 );
			PFN_FileChangeListener pNotifyFunc = &(CXTrapManager::NotifyMapFileChanged);

			const std::string strMap1Name = "map1.CS3";
			const std::string strMap2Name = "map2.CS3";

			FileMonitorFreeBSD::Instance().AddWatch( strMap1Name, pNotifyFunc );
			FileMonitorFreeBSD::Instance().AddWatch( strMap2Name, pNotifyFunc );
#endif
		}

//Add after

#ifdef ENABLE_QUEEN_NETHIS
		SnakeLair_manager.Initialize();
#endif

//Search if you have

	if (!g_bAuthServer)
	{
		if (isHackShieldEnable)
		{
			sys_log(0, "<shutdown> Releasing HackShield manager...");
			HSManager.Release();
		}

//Add after

#ifdef ENABLE_QUEEN_NETHIS
		sys_log(0, "<shutdown> Destroying SnakeLair_manager.");
		SnakeLair_manager.Destroy();
#endif
