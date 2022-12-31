//Add before the last }

#ifdef ENABLE_QUEEN_NETHIS
	PyModule_AddIntConstant(poModule, "ENABLE_QUEEN_NETHIS", true);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_QUEEN_NETHIS", false);
#endif