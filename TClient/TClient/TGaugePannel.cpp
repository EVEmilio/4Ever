#include "StdAfx.h"
#include "TClientGame.h"
#include "Resource.h"
#include "TTournamentMode.h"

#ifdef NEW_IF
static DWORD vGaugeFrameID[TGAUGE_FRAME_COUNT][3] = {
	{ ID_FRAME_MY_GAUGE_NEW, ID_CTRLINST_POS_MYGAUGE, TRUE},			// TGAUGE_FRAME_PLAYER
	{ ID_FRAME_RECALL_GAUGE_NEW, ID_CTRLINST_POS_RECALLGAUGE, TRUE},	// TGAUGE_FRAME_SUMMON
	{ ID_FRAME_TARGET_GAUGE_NEW, ID_CTRLINST_POS_TARGET, TRUE},	// TGAUGE_FRAME_TARGET
	{ ID_FRAME_PARTY_GAUGE_NEW, ID_CTRLINST_POS_PARTYGAUGE, TRUE}	// TGAUGE_FRAME_PARTY,
};
#else
static DWORD vGaugeFrameID[TGAUGE_FRAME_COUNT][3] = {
	{ ID_FRAME_MY_GAUGE, ID_CTRLINST_POS_ME, TRUE},			// TGAUGE_FRAME_PLAYER
	{ ID_FRAME_RECALL_GAUGE, ID_CTRLINST_POS_RECALL, TRUE},	// TGAUGE_FRAME_SUMMON
	{ ID_FRAME_TARGET_GAUGE, ID_CTRLINST_POS_TARGET, TRUE},	// TGAUGE_FRAME_TARGET
	{ ID_FRAME_PARTY_GAUGE, ID_CTRLINST_POS_PARTY, TRUE},	// TGAUGE_FRAME_PARTY,
	{ ID_FRAME_NOTIFY, ID_CTRLINST_POS_NOTIFY, TRUE}};		// TGAUGE_FRAME_NOTIFY
#endif



CTGaugePannel::CTGaugePannel( TComponent *pParent, LP_FRAMEDESC pDesc, TCMLParser *pParser, CTClientGame *pMainGame, CTClientChar *pHost)
:CTClientUIBase( pParent, pDesc)
{
	DWORD dwRecallpushID[] = {
		ID_CTRLINST_RECALL_SKILL_PUSH_1,
		ID_CTRLINST_RECALL_SKILL_PUSH_2,
		ID_CTRLINST_RECALL_SKILL_PUSH_3,
		ID_CTRLINST_RECALL_SKILL_PUSH_4};

	DWORD dwRecallSkillID[] = {
		ID_CTRLINST_RECALL_SKILL_1,
		ID_CTRLINST_RECALL_SKILL_2,
		ID_CTRLINST_RECALL_SKILL_3,
		ID_CTRLINST_RECALL_SKILL_4};

	DWORD dwRecallgaugeID[] = {
		ID_CTRLINST_RECALL_SKILL_GAUGE_1,
		ID_CTRLINST_RECALL_SKILL_GAUGE_2,
		ID_CTRLINST_RECALL_SKILL_GAUGE_3,
		ID_CTRLINST_RECALL_SKILL_GAUGE_4};

	DWORD dwRecallskillSMID[] = {
		ID_CTRLINST_RECALL_SKILL_SEL_1,
		ID_CTRLINST_RECALL_SKILL_SEL_2,
		ID_CTRLINST_RECALL_SKILL_SEL_3,
		ID_CTRLINST_RECALL_SKILL_SEL_4};

#ifdef NEW_IF
		DWORD dwRecallAIpushID[] = {
		ID_CTRLINST_AI_STATUS_PUSH, 
		ID_CTRLINST_AI_MODE_PUSH
	};

	DWORD dwRecallAI[] = {
		ID_CTRLINST_AI_STATUS,
		ID_CTRLINST_AI_MODE
	};
#else
	DWORD dwRecallAIpushID[] = {
		ID_CTRLINST_MANUAL_AI_PUSH, 
		ID_CTRLINST_ACTIVE_AI_PUSH,
		ID_CTRLINST_PASSIVE_AI_PUSH,
		ID_CTRLINST_BACK_AI_PUSH,
		ID_CTRLINST_STAY_AI_PUSH};

	DWORD dwRecallAISMID[] = {
		ID_CTRLINST_MANUAL_AI_SEL,
		ID_CTRLINST_ACTIVE_AI_SEL,
		ID_CTRLINST_PASSIVE_AI_SEL,
		ID_CTRLINST_BACK_AI_SEL,
		ID_CTRLINST_STAY_AI_SEL};

	DWORD dwRecallAI[] = {
		ID_CTRLINST_MANUAL_AI,
		ID_CTRLINST_ACTIVE_AI,
		ID_CTRLINST_PASSIVE_AI,
		ID_CTRLINST_BACK_AI,
		ID_CTRLINST_STAY_AI};
#endif

#ifdef NEW_IF
	DWORD vMaintainID[TPANNEL_COUNT][3] = {
		{ ID_FRAME_MAINTAIN2R, ID_FRAME_MY_GAUGE_NEW, ID_CTRLINST_TXT_HP},			//TPANNEL_PLAYER
		{ ID_FRAME_MAINTAIN2R, ID_FRAME_RECALL_GAUGE_NEW, ID_CTRLINST_MAINTAIN},	//TPANNEL_SUMMON
		{ ID_FRAME_MAINTAIN2R, ID_FRAME_TARGET_GAUGE_NEW, ID_CTRLINST_MAINTAIN},//TPANNEL_TARGET
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE_NEW, ID_CTRLINST_MAINTAIN1_NEW},	//TPANNEL_PARTY1
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE_NEW, ID_CTRLINST_MAINTAIN2_NEW},	//TPANNEL_PARTY2
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE_NEW, ID_CTRLINST_MAINTAIN3_NEW},	//TPANNEL_PARTY3
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE_NEW, ID_CTRLINST_MAINTAIN4_NEW},	//TPANNEL_PARTY4
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE_NEW, ID_CTRLINST_MAINTAIN5_NEW},	//TPANNEL_PARTY5
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE_NEW, ID_CTRLINST_MAINTAIN6_NEW}};	//TPANNEL_PARTY6
#else
	DWORD vMaintainID[TPANNEL_COUNT][3] = {
		{ ID_FRAME_MAINTAIN2R, ID_FRAME_MY_GAUGE, ID_CTRLINST_MAINTAIN},		//TPANNEL_PLAYER
		{ ID_FRAME_MAINTAIN2R, ID_FRAME_RECALL_GAUGE, ID_CTRLINST_MAINTAIN},	//TPANNEL_SUMMON
		{ ID_FRAME_MAINTAIN2R, ID_FRAME_TARGET_GAUGE, ID_CTRLINST_MAINTAIN},	//TPANNEL_TARGET
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE, ID_CTRLINST_MAINTAIN1},	//TPANNEL_PARTY1
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE, ID_CTRLINST_MAINTAIN2},	//TPANNEL_PARTY2
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE, ID_CTRLINST_MAINTAIN3},	//TPANNEL_PARTY3
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE, ID_CTRLINST_MAINTAIN4},	//TPANNEL_PARTY4
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE, ID_CTRLINST_MAINTAIN5},	//TPANNEL_PARTY5
		{ ID_FRAME_MAINTAIN1R, ID_FRAME_PARTY_GAUGE, ID_CTRLINST_MAINTAIN6}};	//TPANNEL_PARTY6
#endif
	
	m_bHotkeyBase = TRUE;
	m_pMainRecall = NULL;
	m_pHost = pHost;

	m_bUseBasis = FALSE;
	CPoint point;

	for( BYTE i=0; i<TGAUGE_FRAME_COUNT; i++)
	{
		LP_FRAMEDESC pGAUGE = pParser->FindFrameTemplate(vGaugeFrameID[i][0]);
		TComponent *pTPOS = FindKid(vGaugeFrameID[i][1]);
		CTClientUIBase *pTFRAME = NULL;

#ifdef NEW_IF
		pTFRAME = new CTDynamicHelpDlg( this, pGAUGE);
#else
		switch(i)
		{
		case TGAUGE_FRAME_NOTIFY	: pTFRAME = new CTDynamicHelpDlg( this, pGAUGE); break;
		default						: pTFRAME = new CTClientUIBase( this, pGAUGE); break;
		}
#endif

		pTPOS->GetComponentPos(&point);
		RemoveKid(pTPOS);
		delete pTPOS;
		AddKid(pTFRAME);

		if(vGaugeFrameID[i][2])
		{
			pTFRAME->m_bCanDrag = TRUE;
			pTFRAME->m_rcDrag.SetRect(
				0, 0,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenX,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenY);
		}

		pTFRAME->MoveComponent(point);
	}


	static DWORD vSceleton[] = {
#ifdef NEW_IF
	ID_CTRLINST_MAIN_SLOT_1,
	ID_CTRLINST_MAIN_SLOT_2,
	ID_CTRLINST_MINIMAP,
	ID_CTRLINST_POS_ME,
	ID_CTRLINST_POS_RECALL, 
	ID_CTRLINST_POS_PARTY,
	ID_CTRLINST_POS_NOTIFY,
	ID_CTRLINST_PET_SLOT,
#else
	ID_CTRLINST_MAIN_SLOT_1_NEW,
	ID_CTRLINST_MAIN_SLOT_2_NEW,
	ID_CTRLINST_POS_CHANGE,
	ID_CTRLINST_POS_DURATION,
	ID_CTRLINST_POS_MINIMAP,
	ID_CTRLINST_POS_CSTXT,
	ID_CTRLINST_CASHSHOP,
	ID_CTRLINST_POS_MYGAUGE,
	ID_CTRLINST_POS_RECALLGAUGE,
	ID_CTRLINST_POS_PARTYGAUGE,
#endif
	ID_CTRLINST_POS_TOOLBOX,
	ID_CTRLINST_POS_IDK1,
	ID_CTRLINST_POS_IDK2
};

#ifdef NEW_IF
	int nDelComp = 11;
#else
	int nDelComp = 13;
#endif

	for( BYTE i=0; i<nDelComp;i++)
	{
		TComponent *pTPOS = FindKid(vSceleton[i]);
		RemoveKid(pTPOS);
		delete pTPOS;
	}

#ifdef NEW_IF
	for( int i=0; i<TPANNEL_COUNT; i++)
	{
		TComponent *pTFRAME = FindKid(vMaintainID[i][1]);

		CTMaintainPannel *pTPANNEL = new CTMaintainPannel( pTFRAME, pParser->FindFrameTemplate(vMaintainID[i][0]));

		if(i == 0)
		{
			TComponent *pTPOS = pTFRAME->FindKid(vMaintainID[i][2]);
			pTPOS->GetComponentPos(&point);

			pTPANNEL->m_id = GetUniqueID();
			pTFRAME->AddKid(pTPANNEL);

			point.x += 110;

			pTPANNEL->MoveComponent(point);
			pTPANNEL->ShowComponent(TRUE);
			pTPANNEL->EnableFloat(FALSE);
		}
		else
		{
			TComponent *pTPOS = pTFRAME->FindKid(vMaintainID[i][2]);
			pTPOS->GetComponentPos(&point);
			pTFRAME->RemoveKid(pTPOS);

			pTPANNEL->m_id = vMaintainID[i][2];
			pTFRAME->AddKid(pTPANNEL);

			pTPANNEL->MoveComponent(point);
			pTPANNEL->ShowComponent(TRUE);
			pTPANNEL->EnableFloat(FALSE);
		}

		m_vTMAINTAIN[i] = pTPANNEL;
	}
#else
	for( int i=0; i<TPANNEL_COUNT; i++)
	{
		TComponent *pTFRAME = FindKid(vMaintainID[i][1]);

		CTMaintainPannel *pTPANNEL = new CTMaintainPannel( pTFRAME, pParser->FindFrameTemplate(vMaintainID[i][0]));

		TComponent *pTPOS = pTFRAME->FindKid(vMaintainID[i][2]);
		pTPOS->GetComponentPos(&point);
		pTFRAME->RemoveKid(pTPOS);

		pTPANNEL->m_id = vMaintainID[i][2];
		pTFRAME->AddKid(pTPANNEL);

		pTPANNEL->MoveComponent(point);
		pTPANNEL->ShowComponent(TRUE);
		pTPANNEL->EnableFloat(FALSE);

		m_vTMAINTAIN[i] = pTPANNEL;
	}
#endif

#ifdef NEW_IF
#else
	{
		TComponent *pTFRAME = FindKid(ID_FRAME_PARTY_GAUGE);
		TComponent *pTPOS = pTFRAME->FindKid(ID_CTRLINST_MAINTAIN7);
		pTFRAME->RemoveKid(pTPOS);
		delete pTPOS;
	}
#endif

	m_pQList = (TList*) FindKid(ID_CTRLINST_QLIST);
	m_pQList->m_bNoHIT = TRUE;
	m_pQList->ShowComponent(TRUE);

	m_pQList->SetColumnAlign( 0, ALIGN_RIGHT);
	m_pQList->SetColumnAlign( 1, ALIGN_CENTER);
	m_pQList->SetColumnAlign( 2, ALIGN_RIGHT);
	m_pQList->ApplyUserColor(TRUE);
	m_pQList->RemoveAll();
	m_bSND = FALSE;

	{
		m_pLUCKY = FindKid(ID_CTRLINST_LUCKY);
		if( m_pLUCKY )
			m_pLUCKY->m_bNoHIT = TRUE;

		m_pLUCKY2 = FindKid( ID_CTRLINST_LUCKY2 );
		if ( m_pLUCKY2 )
			m_pLUCKY2->m_bNoHIT = TRUE;

		m_pLUCKY3 = FindKid( ID_CTRLINST_LUCKY3);
		m_pLUCKY4 = FindKid( ID_CTRLINST_LUCKY4);

		if( m_pLUCKY3 )
			m_pLUCKY3->m_bNoHIT = TRUE;

		if( m_pLUCKY4 )
			m_pLUCKY4->m_bNoHIT = TRUE;

		m_pLUCKY5 = FindKid( ID_CTRLINST_LUCKY5 );
		m_pLUCKY6 = FindKid( ID_CTRLINST_LUCKY6 );

		if( m_pLUCKY5 )
			m_pLUCKY5->m_bNoHIT = TRUE;

		if( m_pLUCKY6 )
			m_pLUCKY6->m_bNoHIT = TRUE;

		m_pLuckyNumber = FindKid(ID_CTRLINST_POS_LUCKY);
		m_pLuckyNumberFrame = FindKid(ID_CTRLINST_POS_LUCKY_FRAME);
#ifdef NEW_IF
		m_pCashShop = FindKid(ID_CTRLINST_CASHSHOP);
		m_pCashShopTxt = FindKid(ID_CTRLINST_POS_CSTXT);
#endif
	}

	{

#ifdef NEW_IF
			CPoint point;
			TComponent *pPOS = NULL;
			pPOS = FindKid(ID_CTRLINST_POS_MINIMAP);
			pPOS->GetComponentPos(&point);
			RemoveKid(pPOS);
			delete pPOS;

		{
			CTMinimapDlg *pMinimapDlg = new CTMinimapDlg( this, pParser->FindFrameTemplate(ID_FRAME_MINIMAP_NEW));
			AddKid(pMinimapDlg);
			pMinimapDlg->MoveComponent(point);
			pMinimapDlg->ShowComponent(TRUE);
			pMainGame->m_pTMinimap = pMinimapDlg;
		}

		{
			m_pRaid = new CTClientUIBase(this ,pParser->FindFrameTemplate(ID_FRAME_NEWRAID));
			AddKid(m_pRaid);
			m_pRaid->ShowComponent(FALSE);
			m_pRaid->m_rcDrag.SetRect(
				0, 0,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenX,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenY);
			
			CTRSCSDlg *pTRSCSDlg = new CTRSCSDlg( this, pParser->FindFrameTemplate(ID_FRAME_RSCS_NEW), m_pRaid);
			m_pTRSCS = pTRSCSDlg;
			pMainGame->m_pTRSCS = m_pTRSCS;
			AddKid(pTRSCSDlg);
			pTRSCSDlg->MoveComponent(point);
			pTRSCSDlg->EnableFloat(FALSE);
			pTRSCSDlg->ShowComponent(FALSE);

		}
#else
			CPoint point;
			TComponent *pPOS = NULL;
			pPOS = FindKid(ID_CTRLINST_MINIMAP);
			pPOS->GetComponentPos(&point);
			RemoveKid(pPOS);
			delete pPOS;

		{
			CTMinimapDlg *pMinimapDlg = new CTMinimapDlg( this, pParser->FindFrameTemplate(ID_FRAME_MINIMAP));
			AddKid(pMinimapDlg);
			pMinimapDlg->MoveComponent(point);
			pMinimapDlg->ShowComponent(TRUE);
			pMainGame->m_pTMinimap = pMinimapDlg;
		}

		{
			CTRSCSDlg *pTRSCSDlg = new CTRSCSDlg( this, pParser->FindFrameTemplate(ID_FRAME_RSCS));
			m_pTRSCS = pTRSCSDlg;
			pMainGame->m_pTRSCS = m_pTRSCS;
			AddKid(pTRSCSDlg);
			pTRSCSDlg->MoveComponent(point);
			pTRSCSDlg->ShowComponent(FALSE);
			pTRSCSDlg->EnableFloat(FALSE);
		}
#endif

		{
			m_pTournamentInfo = new CTTournamentMode(
				this,
				pParser->FindFrameTemplate(ID_FRAME_TOURNAMENT_MODE),
				CTTournamentMode::TM_BATTLE );

			AddKid(m_pTournamentInfo);
			m_pTournamentInfo->MoveComponent(point);
			m_pTournamentInfo->ShowComponent(FALSE);
			m_pTournamentInfo->EnableFloat(FALSE);
		}
	}
	{
		m_pClock = new CTClientUIBase( this, pParser->FindFrameTemplate(ID_FRAME_CLOCK));		
		AddKid(m_pClock);
		m_pClockCmpnt = m_pClock->FindKid(ID_CTRLINST_CLOCK);
	}

	{
		m_pNewAV = new CTClientUIBase( this, pParser->FindFrameTemplate(ID_FRAME_NEWAV));		
		AddKid(m_pNewAV);
		m_pHonour = m_pNewAV->FindKid(ID_CTRLINST_HONOUR_NEW);
		m_pAchievement = m_pNewAV->FindKid(ID_CTRLINST_ACHIEVEMENT_NEW);
	}

#ifdef NEW_IF
	{
		m_pNewRegion = new CTClientUIBase( this, pParser->FindFrameTemplate(ID_FRAME_REGION_NEW));		
		AddKid(m_pNewRegion);
		m_pChannelNew = m_pNewRegion->FindKid(ID_CTRLINST_CHANNEL_NEW);
		m_pRegionNew = m_pNewRegion->FindKid(ID_CTRLINST_REGION_NEW);
		m_pRegionNew->SetTextAlign(ALIGN_CENTER);
		CD3DFont *pRegionFont = m_pRegionNew->Get3DFont();
		pRegionFont->m_dwColor = m_pHonour->Get3DFont()->m_dwColor;
	}

	{
		CRect rt;
		m_pNotify = new CTDynamicHelpDlg( this, pParser->FindFrameTemplate(ID_FRAME_NOTIFY_NEW));
		AddKid(m_pNotify);

		m_pNotify->GetComponentRect(&rt);
		rt.right = CTachyonRes::m_pDEVICE->m_option.m_dwScreenX;
		m_pNotify->SetComponentRect(rt);

		m_pNotifyComp[0] = m_pNotify->FindKid(ID_CTRLINST_NOTIFY_COMP);

		CRect rc;
		m_pNotifyComp[0]->GetComponentRect(&rc);

		int nCurWidth = rc.Width();

		for( INT i = 1; i < HELP_COUNT_1920; ++i )
		{
			m_pNotifyComp[i] = new TComponent(m_pNotify, m_pNotifyComp[0]->m_pDESC);
			m_pNotifyComp[i]->m_id = m_pNotify->GetUniqueID();

			m_pNotify->AddKid( m_pNotifyComp[i] );

			CPoint point;
			m_pNotifyComp[i]->GetComponentPos(&point);

			point.x = nCurWidth;
			nCurWidth += rc.Width();

			m_pNotifyComp[i]->MoveComponent(point);
		}

		m_pNotify->ShowComponent(FALSE);
	}

	{
		m_pPopupMenu = new CTPopupNewMenuDlg( this, pParser->FindFrameTemplate(ID_FRAME_TOPMENU));
		AddKid(m_pPopupMenu);
		m_pPopupMenu->ShowComponent(FALSE);
	}

	{
		m_pChangePartyLottery = new CTClientUIBase( this, pParser->FindFrameTemplate(ID_FRAME_PARTYLOT_NEW));
		AddKid(m_pChangePartyLottery);
		m_pPartyLot = m_pChangePartyLottery->FindKid(ID_CTRLINST_PARTYLOT_NEW);
	}
#endif

#ifdef NEW_IF
	{
		m_pTRECALLFRM = new CTClientUIBase( this, pParser->FindFrameTemplate(ID_FRAME_RECALL_COMMAND_NEW));
		AddKid(m_pTRECALLFRM);

		m_pTRECALLFRM->m_bCanDrag = TRUE;
		m_pTRECALLFRM->m_rcDrag.SetRect(
			0, 0,
			CTachyonRes::m_pDEVICE->m_option.m_dwScreenX,
			CTachyonRes::m_pDEVICE->m_option.m_dwScreenY);

		for( INT i=0; i<TMONSKILL_COUNT; i++)
		{
			m_pTRECALLSKILLDOWN[i] = (TImageList *) m_pTRECALLFRM->FindKid(dwRecallpushID[i]);
			m_pTRECALLSKILL[i] = (TImageList *) m_pTRECALLFRM->FindKid(dwRecallSkillID[i]);

			m_pTRECALLSKILLGAUGE[i] = (TGauge *) m_pTRECALLFRM->FindKid(dwRecallgaugeID[i]);
			m_pTRECALLSKILLGAUGE[i]->SetStyle(m_pTRECALLSKILLGAUGE[i]->GetStyle()|TGS_GROW_UP);
			m_pTRECALLSKILLSM[i] = m_pTRECALLFRM->FindKid(dwRecallskillSMID[i]);
		}

		for( INT i=0; i<TRECALLAIACT_COUNT; i++)
		{
			m_pTRECALLAIDOWN_NEW[i] = (TImageList *) m_pTRECALLFRM->FindKid(dwRecallAIpushID[i]);
			m_pTRECALLAI_NEW[i] = (TImageList *) m_pTRECALLFRM->FindKid(dwRecallAI[i]);
		}
	}
#else
	{
		TComponent *pPOS = NULL;
		CPoint point;

		pPOS = FindKid(ID_CTRLINST_PET_SLOT);
		pPOS->GetComponentPos(&point);
		RemoveKid(pPOS);
		delete pPOS;

		m_pTRECALLFRM = new CTClientUIBase( this, pParser->FindFrameTemplate(ID_FRAME_RECALL_COMMAND));
		m_pTRECALLFRM->m_id = ID_CTRLINST_PET_SLOT;
		AddKid(m_pTRECALLFRM);
		m_pTRECALLFRM->MoveComponent(point);

		for( INT i=0; i<TMONSKILL_COUNT; i++)
		{
			m_pTRECALLSKILLDOWN[i] = (TImageList *) m_pTRECALLFRM->FindKid(dwRecallpushID[i]);
			m_pTRECALLSKILL[i] = (TImageList *) m_pTRECALLFRM->FindKid(dwRecallSkillID[i]);

			m_pTRECALLSKILLGAUGE[i] = (TGauge *) m_pTRECALLFRM->FindKid(dwRecallgaugeID[i]);
			m_pTRECALLSKILLGAUGE[i]->SetStyle(m_pTRECALLSKILLGAUGE[i]->GetStyle()|TGS_GROW_UP);
			m_pTRECALLSKILLSM[i] = m_pTRECALLFRM->FindKid(dwRecallskillSMID[i]);
		}

		for( INT i=0; i<TRECALLAI_COUNT; i++)
		{
			m_pTRECALLAIDOWN[i] = (TImageList *) m_pTRECALLFRM->FindKid(dwRecallAIpushID[i]);
			m_pTRECALLAISM[i] = m_pTRECALLFRM->FindKid(dwRecallAISMID[i]);
			m_pTRECALLAI[i] = m_pTRECALLFRM->FindKid(dwRecallAI[i]);
		}
	}
#endif

		//start skills
#ifdef NEW_IF
	{
		DWORD dwIconSM1[][2] = {
			{ ID_CTRLINST_ICON_SEL_7, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_8, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_9, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_10, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_11, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_12, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_7, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_8, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_9, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_10, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_11, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_12, THOTKEYBASE_SUB1 }
		};

		DWORD dwIconSM2[][2] = {
			{ ID_CTRLINST_ICON_SEL_1, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_2, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_3, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_4, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_5, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_6, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_SEL_1, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_2, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_3, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_4, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_5, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_SEL_6, THOTKEYBASE_SUB1 }
		};

		DWORD dwIconGauge1[][2] = {
			{ ID_CTRLINST_ICON_GAUGE_7, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_8, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_9, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_10, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_11, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_12, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_7, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_8, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_9, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_10, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_11, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_12, THOTKEYBASE_SUB1 }
		};

		DWORD dwIconGauge2[][2] = {
			{ ID_CTRLINST_ICON_GAUGE_1, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_2, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_3, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_4, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_5, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_6, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_GAUGE_1, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_2, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_3, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_4, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_5, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_GAUGE_6, THOTKEYBASE_SUB1 }
		};


		DWORD dwHotpushID1[][2] = {
			{ ID_CTRLINST_ICON_PUSH_7, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_8, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_9, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_10, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_11, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_12, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_7, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_8, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_9, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_10, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_11, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_12, THOTKEYBASE_SUB1 }
		};

		DWORD dwHotpushID2[][2] = {
			{ ID_CTRLINST_ICON_PUSH_1, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_2, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_3, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_4, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_5, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_6, THOTKEYBASE_DEF },
			{ ID_CTRLINST_ICON_PUSH_1, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_2, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_3, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_4, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_5, THOTKEYBASE_SUB1 },
			{ ID_CTRLINST_ICON_PUSH_6, THOTKEYBASE_SUB1 }
		};


		DWORD dwHotkeyID1[MAX_HOTKEY_POS][3] = {
			{ ID_CTRLINST_SKILL_7, ID_CTRLINST_ITEM_7, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_8, ID_CTRLINST_ITEM_8, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_9, ID_CTRLINST_ITEM_9, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_10, ID_CTRLINST_ITEM_10, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_11, ID_CTRLINST_ITEM_11, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_12, ID_CTRLINST_ITEM_12, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_7, ID_CTRLINST_ITEM_7, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_8, ID_CTRLINST_ITEM_8, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_9, ID_CTRLINST_ITEM_9, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_10, ID_CTRLINST_ITEM_10, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_11, ID_CTRLINST_ITEM_11, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_12, ID_CTRLINST_ITEM_12, THOTKEYBASE_SUB1}
		};

		DWORD dwHotkeyID2[MAX_HOTKEY_POS][3] = {
			{ ID_CTRLINST_SKILL_1, ID_CTRLINST_ITEM_1, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_2, ID_CTRLINST_ITEM_2, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_3, ID_CTRLINST_ITEM_3, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_4, ID_CTRLINST_ITEM_4, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_5, ID_CTRLINST_ITEM_5, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_6, ID_CTRLINST_ITEM_6, THOTKEYBASE_DEF},
			{ ID_CTRLINST_SKILL_1, ID_CTRLINST_ITEM_1, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_2, ID_CTRLINST_ITEM_2, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_3, ID_CTRLINST_ITEM_3, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_4, ID_CTRLINST_ITEM_4, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_5, ID_CTRLINST_ITEM_5, THOTKEYBASE_SUB1},
			{ ID_CTRLINST_SKILL_6, ID_CTRLINST_ITEM_6, THOTKEYBASE_SUB1}
		};

		DWORD dwHotkeyBaseID[THOTKEYCTRL_COUNT] = {
			ID_CTRLINST_MAIN_SLOT,//1124
			ID_CTRLINST_SCROLL_UP,//1125
			ID_CTRLINST_SCROLL_DOWN,//1125
			ID_CTRLINST_SLOT_NUM//1125
		};

		DWORD dwHotkeyPosID[THOTKEYBASE_COUNT] = {
			ID_CTRLINST_MAIN_SLOT_1_NEW, //THOTKEYBASE_DEF
			ID_CTRLINST_MAIN_SLOT_2_NEW}; //THOTKEYBASE_SUB1

		{
			LP_FRAMEDESC pDESC = pParser->FindFrameTemplate(ID_FRAME_MY_SKILLCHGER_NEW);

			TComponent *pPOS = NULL;
			CPoint point;
			pPOS = FindKid(ID_CTRLINST_POS_CHANGE);
			pPOS->GetComponentPos(&point);
			point.y -= 25;
			RemoveKid(pPOS);
			delete pPOS;

			m_pChange = new CTClientUIBase( this, pDESC);
			m_pChange->m_id = ID_CTRLINST_POS_CHANGE;
			AddKid(m_pChange);
			m_pChange->MoveComponent(point);
		}

		for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
		{
			LP_FRAMEDESC pDESC = pParser->FindFrameTemplate(ID_FRAME_MY_SKILLBAR_NEW);

			TComponent *pPOS = NULL;
			CPoint point;
			pPOS = FindKid(dwHotkeyPosID[i]);
			pPOS->GetComponentPos(&point);
			point.y -= 25;
			RemoveKid(pPOS);
			delete pPOS;

			m_pTHOTKEYFRM[i] = new CTClientUIBase( this, pDESC);
			m_pTHOTKEYFRM[i]->m_id = dwHotkeyPosID[i];
			AddKid(m_pTHOTKEYFRM[i]);
			m_pTHOTKEYFRM[i]->MoveComponent(point);

			for( BYTE j=0; j<1; j++)
				m_pTHOTKEYCTRL[i][j] = m_pTHOTKEYFRM[i]->FindKid(dwHotkeyBaseID[j]);
			for( int j=1; j<THOTKEYCTRL_COUNT; j++)
				m_pTHOTKEYCTRL[i][j] = m_pChange->FindKid(dwHotkeyBaseID[j]);
		}

		for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
		{
			for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
			{
				for( BYTE k=0; k<2; k++)
				{
					if(i == THOTKEYBASE_DEF)
						m_pTHOTKEY[i][j][k] = (TImageList *) m_pTHOTKEYFRM[dwHotkeyID1[j][2]]->FindKid(dwHotkeyID1[j][k]);
					else if(i == THOTKEYBASE_SUB1)
						m_pTHOTKEY[i][j][k] = (TImageList *) m_pTHOTKEYFRM[dwHotkeyID2[j][2]]->FindKid(dwHotkeyID2[j][k]);
				}

				if(i == THOTKEYBASE_DEF)
				{
					m_pTHOTKEYDOWN[i][j] = (TImageList *) m_pTHOTKEYFRM[dwHotpushID1[j][1]]->FindKid(dwHotpushID1[j][0]);
					m_pTHOTKEYGAUGE[i][j] = (TGauge *) m_pTHOTKEYFRM[dwIconGauge1[j][1]]->FindKid(dwIconGauge1[j][0]);
					m_pTHOTKEYSM[i][j] = m_pTHOTKEYFRM[dwIconSM1[j][1]]->FindKid(dwIconSM1[j][0]);
				}
				else if(i == THOTKEYBASE_SUB1)
				{
					m_pTHOTKEYDOWN[i][j] = (TImageList *) m_pTHOTKEYFRM[dwHotpushID1[j][1]]->FindKid(dwHotpushID2[j][0]);
					m_pTHOTKEYGAUGE[i][j] = (TGauge *) m_pTHOTKEYFRM[dwIconGauge2[j][1]]->FindKid(dwIconGauge2[j][0]);
					m_pTHOTKEYSM[i][j] = m_pTHOTKEYFRM[dwIconSM2[j][1]]->FindKid(dwIconSM2[j][0]);
				}

				m_pTHOTKEYDOWN[i][j]->SetCurImage(0);
				m_pTHOTKEYDOWN[i][j]->m_bVCenter = FALSE;

				m_pTHOTKEYGAUGE[i][j]->SetStyle(m_pTHOTKEYGAUGE[i][j]->GetStyle()|TGS_GROW_UP);
			}
		}
	}
#else
	{
		DWORD dwHotpushID[] = {
			ID_CTRLINST_ICON_PUSH_1,
			ID_CTRLINST_ICON_PUSH_2,
			ID_CTRLINST_ICON_PUSH_3,
			ID_CTRLINST_ICON_PUSH_4,
			ID_CTRLINST_ICON_PUSH_5,
			ID_CTRLINST_ICON_PUSH_6,
			ID_CTRLINST_ICON_PUSH_7,
			ID_CTRLINST_ICON_PUSH_8,
			ID_CTRLINST_ICON_PUSH_9,
			ID_CTRLINST_ICON_PUSH_10,
			ID_CTRLINST_ICON_PUSH_11,
			ID_CTRLINST_ICON_PUSH_12};

		DWORD dwHotkeyID[MAX_HOTKEY_POS][2] = {
			{ ID_CTRLINST_SKILL_1, ID_CTRLINST_ITEM_1},
			{ ID_CTRLINST_SKILL_2, ID_CTRLINST_ITEM_2},
			{ ID_CTRLINST_SKILL_3, ID_CTRLINST_ITEM_3},
			{ ID_CTRLINST_SKILL_4, ID_CTRLINST_ITEM_4},
			{ ID_CTRLINST_SKILL_5, ID_CTRLINST_ITEM_5},
			{ ID_CTRLINST_SKILL_6, ID_CTRLINST_ITEM_6},
			{ ID_CTRLINST_SKILL_7, ID_CTRLINST_ITEM_7},
			{ ID_CTRLINST_SKILL_8, ID_CTRLINST_ITEM_8},
			{ ID_CTRLINST_SKILL_9, ID_CTRLINST_ITEM_9},
			{ ID_CTRLINST_SKILL_10, ID_CTRLINST_ITEM_10},
			{ ID_CTRLINST_SKILL_11, ID_CTRLINST_ITEM_11},
			{ ID_CTRLINST_SKILL_12, ID_CTRLINST_ITEM_12}};

		DWORD dwHotkeyBaseID[THOTKEYCTRL_COUNT] = {
			ID_CTRLINST_MAIN_SLOT,
			ID_CTRLINST_SCROLL_UP,
			ID_CTRLINST_SCROLL_DOWN,
			ID_CTRLINST_SLOT_NUM};

		DWORD dwHotkeyPosID[THOTKEYBASE_COUNT] = {
			ID_CTRLINST_MAIN_SLOT_1,
			ID_CTRLINST_MAIN_SLOT_2};

		for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
		{
			LP_FRAMEDESC pDESC = pParser->FindFrameTemplate(ID_FRAME_SHORTCUT);

			TComponent *pPOS = NULL;
			CPoint point;
			pPOS = FindKid(dwHotkeyPosID[i]);
			pPOS->GetComponentPos(&point);
			RemoveKid(pPOS);
			delete pPOS;

			m_pTHOTKEYFRM[i] = new CTClientUIBase( this, pDESC);
			m_pTHOTKEYFRM[i]->m_id = dwHotkeyPosID[i];
			AddKid(m_pTHOTKEYFRM[i]);
			m_pTHOTKEYFRM[i]->MoveComponent(point);

			m_pTHOTKEY[i][0][0] = (TImageList *) m_pTHOTKEYFRM[i]->FindKid(ID_CTRLINST_SKILL);
			m_pTHOTKEY[i][0][1] = (TImageList *) m_pTHOTKEYFRM[i]->FindKid(ID_CTRLINST_ITEM);
			m_pTHOTKEYDOWN[i][0] = (TImageList *) m_pTHOTKEYFRM[i]->FindKid(dwHotpushID[0]);

			for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
			{
				for( BYTE k=0; k<2; k++)
					m_pTHOTKEY[i][j][k] = (TImageList *) m_pTHOTKEYFRM[i]->FindKid(dwHotkeyID[j][k]);

				m_pTHOTKEYDOWN[i][j] = (TImageList *) m_pTHOTKEYFRM[i]->FindKid(dwHotpushID[j]);
				m_pTHOTKEYDOWN[i][j]->SetCurImage(0);
				m_pTHOTKEYDOWN[i][j]->m_bVCenter = FALSE;

				CD3DFont *pTFONT = m_pTHOTKEYDOWN[i][j]->Get3DFont();
				pTFONT->m_dwLineColor = TTEXTSHADOW_COLOR;
				pTFONT->m_dwColor = TNAMETEXT_COLOR;
				pTFONT->m_bOutLine = FALSE;
				pTFONT->m_bShadow = TRUE;

				m_pTHOTKEYGAUGE[i][j] = (TGauge *) m_pTHOTKEYFRM[i]->FindKid(CTClientGame::m_vTICONGAUGE[j]);
				m_pTHOTKEYGAUGE[i][j]->SetStyle(m_pTHOTKEYGAUGE[i][j]->GetStyle()|TGS_GROW_UP);
				m_pTHOTKEYSM[i][j] = m_pTHOTKEYFRM[i]->FindKid(CTClientGame::m_vTICONSM[j]);
			}

			for( BYTE j=0; j<THOTKEYCTRL_COUNT; j++)
				m_pTHOTKEYCTRL[i][j] = m_pTHOTKEYFRM[i]->FindKid(dwHotkeyBaseID[j]);
		}
	}
#endif
	//endskills

	m_pCAUTION15 = NULL;
#ifdef ADD_CAUTION15
	m_pCAUTION15 = FindKid(ID_CTRLINST_CAUTION_15);
#endif

	if(m_pCAUTION15)
	{
		m_bAddedCaution15 = TRUE;

		if( !CTClientGame::m_vTOPTION.m_bShowCaution15 )
			DettachCaution15();
	}
	else
		m_bAddedCaution15 = FALSE;

	m_dwCaution15State = 0;
	m_dwCaution15Tick = 0;

	m_pSiegeAlarm = FindKid(ID_CTRLINST_SIEGE_ALARM);
	if(m_pSiegeAlarm)
		DettachSiegeAlarm();
	else
		m_bAddedSiegeAlarm = FALSE;

	m_pExitTutorial = (TButton*) FindKid( ID_CTRLINST_EXIT_TUTORIAL );
	if( m_pExitTutorial )
		DettachExitTutorial();
	else
		m_bAddedExitTutorial = FALSE;

	m_bNotifySiegeAlarm = FALSE;
	m_dwNotifySiegeAlarmTick = 0;

	m_bShowPath = FALSE;
	m_bAutoPath = FALSE;
	m_dwCurQuestID = 0;

	m_pTASSISTANT[0] = NULL;
	m_pTASSISTANT[1] = NULL;
	m_pTASSISTANT[2] = NULL;

#ifdef NEW_IF
	{
		LP_FRAMEDESC pDESC = pParser->FindFrameTemplate(ID_FRAME_DURATION_NEW);

		TComponent *pPOS = NULL;
		CPoint point;
		pPOS = FindKid(ID_CTRLINST_POS_DURATION);
		pPOS->GetComponentPos(&point);
		RemoveKid(pPOS);
		delete pPOS;

		m_pDuration = new CTDurationFrame( this, pDESC);
		m_pDuration->m_id = ID_CTRLINST_POS_DURATION;
		AddKid(m_pDuration);
		m_pDuration->MoveComponent(point);
		m_pDuration->ShowComponent(TRUE);
		m_pDuration->EnableFloat(FALSE);
	}
	
	m_bCanClickReset = TRUE;
#endif
}

CTGaugePannel::~CTGaugePannel()
{
}

ITDetailInfoPtr CTGaugePannel::GetTInfoKey( const CPoint& point )
{
	for( BYTE i=0; i<TPANNEL_COUNT; ++i)
		if( m_vTMAINTAIN[i]->HitTest(point) )
			return m_vTMAINTAIN[i]->GetTInfoKey(point);

	ITDetailInfoPtr pInfo;

	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
	{
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
		{
			pInfo = GetTInfoKey_Hotkey( point, i, j);

			if(pInfo)
				return pInfo;
		}
	}

	if(m_pMainRecall)
	{
#ifdef NEW_IF
		for( int i=0; i<TRECALLAIACT_COUNT; i++)
		{
			pInfo = GetTInfoKey_RecallAi( point, i);

			if(pInfo)
				return pInfo;
		}
#else
		for( int i=0; i<TRECALLAI_COUNT; i++)
		{
			pInfo = GetTInfoKey_RecallAi( point, i);

			if(pInfo)
				return pInfo;
		}
#endif

		for( int i=0; i<TMONSKILL_COUNT; i++)
		{
			pInfo = GetTInfoKey_RecallSkill( point, i);

			if(pInfo)
				return pInfo;
		}
	}

	if( m_pSiegeAlarm &&
		m_bAddedSiegeAlarm &&
		m_pSiegeAlarm->HitTest(point) )
	{
		CTClientGame* pGame = CTClientGame::GetInstance();

		CRect rt;
		m_pSiegeAlarm->GetComponentRect(&rt);
		m_pSiegeAlarm->ComponentToScreen(&rt);

		pInfo = CTDetailInfoManager::NewDefTooltipInst(
			CTChart::LoadString(TSTR_SIEGE_ALARM_TITLE),
			CTChart::LoadString(TSTR_SIEGE_ALARM_MSG),
			rt);

		if( pInfo )
			pInfo->SetDir(FALSE, TRUE, TRUE);

		return pInfo;
	}
	
	if( m_pExitTutorial &&
		m_bAddedExitTutorial &&
		m_pExitTutorial->HitTest(point) )
	{
		CTClientGame* pGame = CTClientGame::GetInstance();

		CRect rt;
		m_pSiegeAlarm->GetComponentRect(&rt);
		m_pSiegeAlarm->ComponentToScreen(&rt);

		CString strFMT;
		switch(pGame->GetMainChar()->m_bContryID)
		{
		case TCONTRY_D:
			strFMT = CTChart::LoadString( TSTR_TUTORIAL_SKIP_MSG_D );
			break;
		case TCONTRY_C:
			strFMT = CTChart::LoadString( TSTR_TUTORIAL_SKIP_MSG_C );
			break;
		case TCONTRY_B:
		case TCONTRY_PEACE:
			strFMT = CTChart::LoadString( TSTR_TUTORIAL_SKIP_MSG_B );
			break;
		}

		pInfo = CTDetailInfoManager::NewDefTooltipInst(
			CTChart::LoadString(TSTR_TUTORIAL_SKIP_TITLE),
			strFMT,
			rt);

		if( pInfo )
			pInfo->SetDir(FALSE, TRUE, TRUE);

		return pInfo;
	}
#ifdef ADD_SKYGARDEN
	for( int i=0 ; i < 3 ; ++i )
	{
		TComponent* pComp = m_pTASSISTANT[ i ];

		if( pComp->HitTest(point) &&
			i < CTClientGame::GetInstance()->m_vTASSISTANT.size() )
		{
			LPTASSISTANT pTASSISTANT = CTClientGame::GetInstance()->m_vTASSISTANT[ i ];
			if( pTASSISTANT )
			{
				CRect rc;
				pComp->GetComponentRect(&rc);
				pComp->ComponentToScreen(&rc);

				pInfo = CTDetailInfoManager::NewPlayerInst(
					pTASSISTANT->m_strName,
					pTASSISTANT->m_bLevel,
					pTASSISTANT->m_bRace,
					pTASSISTANT->m_bSex,
					pTASSISTANT->m_bFace,
					pTASSISTANT->m_bHair,
					pTASSISTANT->m_dwCharID == pTASSISTANT->m_dwCommanderID,
					pTASSISTANT->m_bClass,
					rc);
			}
			return pInfo;		
		}
	}
#endif

	if(m_pLuckyNumber && m_pLuckyNumber->HitTest(point) || m_pLuckyNumberFrame && m_pLuckyNumberFrame->HitTest(point))
	{
		CTClientGame* pGame = CTClientGame::GetInstance();

		CRect rt;
		m_pLuckyNumberFrame->GetComponentRect(&rt);
		m_pLuckyNumberFrame->ComponentToScreen(&rt);

		pInfo = CTDetailInfoManager::NewNorInst(
			CTChart::Format( TSTR_FMT_LUCKNUMBER, pGame->GetLucky()), 
			0, 0, 
			rt);

		pInfo->SetDir(FALSE, FALSE, FALSE);

		return pInfo;
	}

	return pInfo;
}

BOOL CTGaugePannel::CanWithItemUI()
{
	return TRUE;
}

BYTE CTGaugePannel::OnBeginDrag( LPTDRAG pDRAG, CPoint point)
{
	if( m_pTRSCS->IsVisible() && m_pTRSCS->OnBeginDrag(pDRAG, point) )
		return TRUE;

	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
	{
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
		{
			if( !m_pTHOTKEY[i][j][0]->HitTest(point) )
				continue;
			TImageList *pTIMG = NULL;

			switch(m_vTHOTKEY[m_bHotkeyID[i]][j].m_bType)
			{
			case HOTKEY_SKILL	: pTIMG = m_pTHOTKEY[i][j][0]; break;
			case HOTKEY_ITEM	: pTIMG = m_pTHOTKEY[i][j][1]; break;
			case HOTKEY_PET : pTIMG = m_pTHOTKEY[i][j][1]; break;
			}

			if(!pTIMG)
				continue;

			if(pDRAG)
			{
				CPoint pt = point;
				CSize size;

				pDRAG->m_pIMAGE = new TImageList(
					NULL,
					pTIMG->m_pDESC);

				pDRAG->m_pIMAGE->SetCurImage(pTIMG->GetCurImage());
				pDRAG->m_pIMAGE->m_strText = pTIMG->m_strText;

				switch(i)
				{
				case THOTKEYBASE_DEF	: pDRAG->m_bSlotID = CTMainUI::MakeSlotID(TMAINSLOTID_HOTKEY_DEF, j); break;
				case THOTKEYBASE_SUB1	: pDRAG->m_bSlotID = CTMainUI::MakeSlotID(TMAINSLOTID_HOTKEY_SUB1, j); break;
				}

				pDRAG->m_pIMAGE->GetComponentSize(&size);
				pt.x -= size.cx / 2;
				pt.y -= size.cy / 2;

				pDRAG->m_pIMAGE->ShowComponent(FALSE);
				pDRAG->m_pIMAGE->MoveComponent(pt);
			}

			return TRUE;
		}
	}

	return FALSE;
}

TDROPINFO CTGaugePannel::OnDrop( CPoint point)
{
	TDROPINFO vResult;

	if( m_pTRSCS->IsVisible() )
	{
		vResult = m_pTRSCS->OnDrop(point);
		if(vResult.m_bDrop)
			return vResult;
	}

	if(m_bDropTarget)
	{
		for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
			for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
			{
				if(!m_pTHOTKEY[i][j][0]->HitTest(point))
					continue;

				switch(i)
				{
				case THOTKEYBASE_DEF	: vResult.m_bSlotID = CTMainUI::MakeSlotID(TMAINSLOTID_HOTKEY_DEF, j); break;
				case THOTKEYBASE_SUB1	: vResult.m_bSlotID = CTMainUI::MakeSlotID(TMAINSLOTID_HOTKEY_SUB1, j); break;
				}
				vResult.m_bDrop = TRUE;

				return vResult;
			}
	}

	return vResult;
}

void CTGaugePannel::DefaultPosition( CPoint* vBASIS, BOOL bRestore )
{
#ifdef NEW_IF
	static const INT TGAUGEPANNEL_COMP_COUNT = 5;

	static DWORD vCOMP[TGAUGEPANNEL_COMP_COUNT][2] =
	{
		{ ID_FRAME_MY_GAUGE_NEW, TBASISPOINT_LEFT_TOP },
		{ ID_FRAME_RECALL_GAUGE_NEW, TBASISPOINT_LEFT_TOP },
		{ ID_FRAME_TARGET_GAUGE_NEW, TBASISPOINT_CENTER_TOP },
		{ ID_FRAME_PARTY_GAUGE_NEW, TBASISPOINT_LEFT_TOP },
		{ ID_FRAME_CHATNEW, TBASISPOINT_LEFT_MIDDLE }
	};
#else
	static const INT TGAUGEPANNEL_COMP_COUNT = 6;

	static DWORD vCOMP[TGAUGEPANNEL_COMP_COUNT][2] =
	{
		{ ID_FRAME_MY_GAUGE, TBASISPOINT_LEFT_TOP },
		{ ID_FRAME_RECALL_GAUGE, TBASISPOINT_LEFT_TOP },
		{ ID_FRAME_TARGET_GAUGE, TBASISPOINT_CENTER_TOP },
		{ ID_FRAME_PARTY_GAUGE, TBASISPOINT_LEFT_MIDDLE },
		{ ID_FRAME_CHAT, TBASISPOINT_LEFT_BOTTOM },
		{ ID_FRAME_NOTIFY, TBASISPOINT_RIGHT_BOTTOM },
	};
#endif
	static CPoint vCOMP_OFFSET[TGAUGEPANNEL_COMP_COUNT];
	static BYTE vCOMP_BASIS[TGAUGEPANNEL_COMP_COUNT];
    
	if( bRestore )
	{
		for( INT i=0 ; i < TGAUGEPANNEL_COMP_COUNT ; ++i )
		{
			CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP[ i ][0] );
			if( pCOMP )
			{
				pCOMP->m_vCompOffset = vCOMP_OFFSET[i];
				pCOMP->m_bBasisPoint = vCOMP_BASIS[i];

				pCOMP->DefaultPosition( vBASIS, bRestore);
			}
		}
	}
	else
	{
		for( INT i=0 ; i < TGAUGEPANNEL_COMP_COUNT ; ++i )
		{
			CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP[ i ][0] );
			if( pCOMP )
			{
				CPoint pt;
				pCOMP->GetComponentPos(&pt);
				pt -= vBASIS[ vCOMP[i][1] ];

				pCOMP->m_vCompOffset = pt;
				pCOMP->m_bBasisPoint = (BYTE) vCOMP[i][1];

				vCOMP_OFFSET[i] = pCOMP->m_vCompOffset;
				vCOMP_BASIS[i] = pCOMP->m_bBasisPoint;

				pCOMP->DefaultPosition( vBASIS, bRestore);
			}
		}
	}

	{
#ifdef NEW_IF
		static const INT TMAINUI_COMP_COUNT = 7;
		static DWORD vCOMP[TMAINUI_COMP_COUNT][2] =
		{
			{ ID_CTRLINST_MAIN_SLOT_1_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_CTRLINST_MAIN_SLOT_2_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_FRAME_MINIMAP_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_FRAME_RSCS_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_FRAME_TOURNAMENT_MODE, TBASISPOINT_RIGHT_TOP },
			{ ID_CTRLINST_POS_CHANGE, TBASISPOINT_CENTER_BOTTOM },
			{ ID_CTRLINST_POS_DURATION, TBASISPOINT_RIGHT_TOP },
		};
#else
		static const INT TMAINUI_COMP_COUNT = 6;
		static DWORD vCOMP[TMAINUI_COMP_COUNT][2] =
		{
			{ ID_CTRLINST_MAIN_SLOT_1, TBASISPOINT_RIGHT_BOTTOM },
			{ ID_CTRLINST_MAIN_SLOT_2, TBASISPOINT_RIGHT_BOTTOM },
			{ ID_CTRLINST_PET_SLOT, TBASISPOINT_RIGHT_BOTTOM },
			{ ID_FRAME_MINIMAP, TBASISPOINT_RIGHT_TOP },
			{ ID_FRAME_RSCS, TBASISPOINT_RIGHT_TOP },
			{ ID_FRAME_TOURNAMENT_MODE, TBASISPOINT_RIGHT_TOP },
		};
#endif
		static CPoint vCOMP_OFFSET[TMAINUI_COMP_COUNT];
		static BYTE vCOMP_BASIS[TMAINUI_COMP_COUNT];

		if( bRestore)
		{
			for( INT i=0 ; i < TMAINUI_COMP_COUNT ; ++i )
			{
				CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP[ i ][0] );
				if( pCOMP )
				{
					pCOMP->m_vCompOffset = vCOMP_OFFSET[i];
					pCOMP->m_bBasisPoint = vCOMP_BASIS[i];
				}
			}
		}
		else
		{
			for( INT i=0 ; i < TMAINUI_COMP_COUNT ; ++i )
			{
				CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP[ i ][0] );
				if( pCOMP )
				{
					CPoint pt;
					pCOMP->GetComponentPos(&pt);
					pt -= vBASIS[ vCOMP[i][1] ];

					pCOMP->m_vCompOffset = pt;
					pCOMP->m_bBasisPoint = (BYTE) vCOMP[i][1];

					vCOMP_OFFSET[i] = pCOMP->m_vCompOffset;
					vCOMP_BASIS[i] = pCOMP->m_bBasisPoint;
				}
			}
		}
	}

	{
		if(m_pClock)
		{
			CPoint cp = vBASIS[TBASISPOINT_CENTER_TOP];
			cp.x -=187;
			cp.y +=0;
			m_pClock->MoveComponent(cp);
		}
	}

#ifdef NEW_IF
	{
		if(m_pRaid)
		{
			CPoint cp = vBASIS[TBASISPOINT_RIGHT_MIDDLE];
			cp.x -= 370;
			cp.y -= 125;
			m_pRaid->MoveComponent(cp);

			m_pRaid->m_rcDrag.SetRect(
				0, 0,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenX,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenY);
		}

	}

	{
		if(m_pTRECALLFRM)
		{
			CPoint cp = vBASIS[TBASISPOINT_CENTER_BOTTOM];
			cp.x -= 356;
			cp.y -= 183;
			m_pTRECALLFRM->MoveComponent(cp);
		}
	}
#endif

	{
		if(m_pNewAV)
		{
			CPoint cp = vBASIS[TBASISPOINT_CENTER_TOP];
			cp.x -=68;
			cp.y +=7; 
			m_pNewAV->MoveComponent(cp);
		}
	}

	{
		if(m_pLuckyNumber)
		{
			CPoint cp = vBASIS[TBASISPOINT_CENTER_TOP];
			cp.x +=220;
			cp.y +=8;
			m_pLuckyNumber->MoveComponent(cp);
		}
	}

	{
		if(m_pLuckyNumberFrame)
		{
			CPoint cp = vBASIS[TBASISPOINT_CENTER_TOP];
			cp.x +=183;
			cp.y +=0;
			m_pLuckyNumberFrame->MoveComponent(cp);
		}
	}

#ifdef NEW_IF
	{
		if(m_pCashShop)
		{
			CPoint cp = vBASIS[TBASISPOINT_CENTER_BOTTOM];
			cp.x +=366;
			cp.y -=109;
			m_pCashShop->MoveComponent(cp);
		}
	}

	{
		if(m_pCashShopTxt)
		{
			CPoint cp = vBASIS[TBASISPOINT_CENTER_BOTTOM];
			cp.x +=402;
			cp.y -=94;
			m_pCashShopTxt->MoveComponent(cp);
		}
	}

	{
		if(m_pNewRegion)
		{
			CPoint cp = vBASIS[TBASISPOINT_LEFT_TOP];
			cp.x +=10;
			cp.y +=5;
			m_pNewRegion->MoveComponent(cp);
		}
	}

	{
		if(m_pNotify)
		{
			CTClientGame* pGame = CTClientGame::GetInstance();
			CRect rt;

			m_pNotify->GetComponentRect(&rt);
			rt.right = CTachyonRes::m_pDEVICE->m_option.m_dwScreenX;
			m_pNotify->SetComponentRect(rt);

			m_pNotify->Release();
			m_pNotify->InitTEXT(pGame->GetHelpMsg());
			m_pNotify->ShowComponent(FALSE);

		}
	}

	{
		if(m_pPopupMenu)
		{
			CPoint cp = vBASIS[TBASISPOINT_RIGHT_TOP];
			cp.x -=265;
			cp.y +=52;
			m_pPopupMenu->MoveComponent(cp);
		}
	}

	{
		if(m_pChangePartyLottery)
		{
			CPoint cp = vBASIS[TBASISPOINT_LEFT_TOP];
			cp.x +=100;
			cp.y +=35;
			m_pChangePartyLottery->MoveComponent(cp);
		}
	}
#endif
	{
		if( m_pCAUTION15 )
		{
			CPoint pt = vBASIS[TBASISPOINT_RIGHT_TOP];
			pt.x -= 428;
			pt.y += 4;
			m_pCAUTION15->MoveComponent(pt);
		}
	}
#ifdef NEW_IF
	{
		if( m_pSiegeAlarm )
		{
			CPoint pt = vBASIS[TBASISPOINT_CENTER_BOTTOM];
			pt.y -= 250;
			pt.x -= 20;
			m_pSiegeAlarm->MoveComponent(pt);
		}
	}

	{
		if( m_pExitTutorial )
		{
			CPoint pt = vBASIS[TBASISPOINT_CENTER_BOTTOM];
			pt.y -= 250;
			pt.x -= 20;
			m_pExitTutorial->MoveComponent(pt);
		}
	}
#else
	{
		if( m_pSiegeAlarm )
		{
			CPoint pt = vBASIS[TBASISPOINT_RIGHT_TOP];
			pt.x -= 235;
			pt.y += 180;
			m_pSiegeAlarm->MoveComponent(pt);
		}
	}

	{
		if( m_pExitTutorial )
		{
			CPoint pt = vBASIS[TBASISPOINT_RIGHT_TOP];
			pt.x -= 235;
			pt.y += 180;
			m_pExitTutorial->MoveComponent(pt);
		}
	}
#endif
#ifdef NEW_IF
	m_bCanClickReset = TRUE;
#endif
}

void CTGaugePannel::ResetPosition()
{
	CTClientUIBase::ResetPosition();

	DWORD vCOMP[][2] =
	{
		{ ID_CTRLINST_HB_MY_HP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HB_OP_HP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HB_MY_MP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HB_OP_MP, TBASISPOINT_CENTER_MIDDLE },

		{ ID_CTRLINST_HG_MY_HP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HG_OP_HP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HG_MY_MP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HG_OP_MP, TBASISPOINT_CENTER_MIDDLE },

		{ ID_CTRLINST_HT_MY_HP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HT_OP_HP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HT_MY_MP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_HT_OP_MP, TBASISPOINT_CENTER_MIDDLE },
		{ ID_CTRLINST_QLIST, TBASISPOINT_RIGHT_MIDDLE }
	};

	INT nOffset[][2] = 
	{
		{ -150, -96 },
		{ -116, -60 },
		{ 101, -97 },
		{ 86, -60 },

		{ -150, -96 },
		{ -116, -60 },
		{ 101, -97 },
		{ 86, -60 },

		{ -197, 64 },
		{ -97, 64 },
		{ 139, 64 },
		{ 37, 64 },
		{ -325, -161 }
	};

	for( INT i=0 ; i < 13 ; ++i )
	{
		TComponent* pCOMP = FindKid( vCOMP[ i ][0] );
		if( pCOMP )
		{
			CPoint vOffset = CTClientUIBase::m_vBasis[ vCOMP[ i ][1] ];
			vOffset.x += nOffset[i][0];
			vOffset.y += nOffset[i][1];

			pCOMP->MoveComponent( vOffset );
		}
	}

#ifdef NEW_IF
	DWORD vCOMP2[4][2] =
	{
		{ ID_FRAME_MY_GAUGE_NEW, TBASISPOINT_LEFT_TOP },
		{ ID_FRAME_RECALL_GAUGE_NEW, TBASISPOINT_LEFT_TOP },
		{ ID_FRAME_TARGET_GAUGE_NEW, TBASISPOINT_CENTER_TOP },
		{ ID_FRAME_PARTY_GAUGE_NEW, TBASISPOINT_LEFT_TOP }
	};

	for( INT i=0 ; i < 4 ; ++i )
	{
		CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP2[ i ][0] );
		pCOMP->ResetPosition();
	}
#else
	DWORD vCOMP2[5] =
	{
		ID_FRAME_MY_GAUGE,
		ID_FRAME_RECALL_GAUGE,
		ID_FRAME_TARGET_GAUGE,
		ID_FRAME_PARTY_GAUGE,
		ID_FRAME_NOTIFY
	};

	for( INT i=0 ; i < 5 ; ++i )
	{
		CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP2[ i ] );
		pCOMP->ResetPosition();
	}

#endif

	for( BYTE i=0; i<TGAUGE_FRAME_COUNT; i++)
	{
		CTClientUIBase *pTFRAME = (CTClientUIBase*) FindKid( vGaugeFrameID[i][0] );

		if( !pTFRAME )
			continue;

		if(vGaugeFrameID[i][2])
		{
			pTFRAME->m_bCanDrag = TRUE;
			pTFRAME->m_rcDrag.SetRect(
				CPoint(0,0),
				CTClientUIBase::m_vBasis[TBASISPOINT_RIGHT_BOTTOM] );
		}
	}

	{
		DWORD vCOMP[4][2] =
		{
			{ ID_CTRLINST_LUCKY, TBASISPOINT_RIGHT_TOP },
			{ ID_CTRLINST_LUCKY2, TBASISPOINT_RIGHT_TOP },
			{ ID_CTRLINST_LUCKY3, TBASISPOINT_RIGHT_TOP },
			{ ID_CTRLINST_LUCKY4, TBASISPOINT_RIGHT_TOP },
		};

		INT nOffset[4][2] =
		{
			{ -393, 0 },
			{ -393, 17 }, // LUCKY2
			{ -393, 34 }, // LUCKY3
			{ -393, 51 }, // LUCKY4
		};

		for( INT i=0 ; i < 4 ; ++i )
		{
			TComponent* pCOMP = FindKid( vCOMP[ i ][0] );
			if( pCOMP )
			{
				CPoint vOffset = CTClientUIBase::m_vBasis[ vCOMP[ i ][1] ];
				vOffset.x += nOffset[i][0];
				vOffset.y += nOffset[i][1];
				pCOMP->MoveComponent( vOffset );
			}
		}
#ifdef NEW_IF
		DWORD vCOMP2[7][2] =
		{
			{ ID_CTRLINST_MAIN_SLOT_1_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_CTRLINST_MAIN_SLOT_2_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_FRAME_MINIMAP_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_FRAME_RSCS_NEW, TBASISPOINT_CENTER_BOTTOM },
			{ ID_FRAME_TOURNAMENT_MODE, TBASISPOINT_RIGHT_TOP },
			{ ID_CTRLINST_POS_CHANGE, TBASISPOINT_CENTER_BOTTOM },
			{ ID_CTRLINST_POS_DURATION, TBASISPOINT_RIGHT_TOP },
		};

		for( INT i=0 ; i < 7 ; ++i )
		{
			CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP2[ i ][0] );
			pCOMP->ResetPosition();
			pCOMP->m_bCanDrag = TRUE;
			pCOMP->m_rcDrag = CRect( CPoint(0,0), CTClientUIBase::m_vBasis[TBASISPOINT_RIGHT_BOTTOM] );
		}
#else
		DWORD vCOMP2[6][2] =
		{
			{ ID_CTRLINST_MAIN_SLOT_1, TBASISPOINT_RIGHT_BOTTOM },
			{ ID_CTRLINST_MAIN_SLOT_2, TBASISPOINT_RIGHT_BOTTOM },
			{ ID_CTRLINST_PET_SLOT, TBASISPOINT_RIGHT_BOTTOM },
			{ ID_FRAME_MINIMAP, TBASISPOINT_RIGHT_TOP },
			{ ID_FRAME_RSCS, TBASISPOINT_RIGHT_TOP },
			{ ID_FRAME_TOURNAMENT_MODE, TBASISPOINT_RIGHT_TOP },
		};

		for( INT i=0 ; i < 6 ; ++i )
		{
			CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP2[ i ][0] );
			pCOMP->ResetPosition();
			pCOMP->m_bCanDrag = TRUE;
			pCOMP->m_rcDrag = CRect( CPoint(0,0), CTClientUIBase::m_vBasis[TBASISPOINT_RIGHT_BOTTOM] );
		}
#endif

	}

	{
		if( m_pCAUTION15 )
		{
			CPoint pt = CTClientUIBase::m_vBasis[ TBASISPOINT_RIGHT_TOP ];
			pt.x -= 428;
			pt.y += 4;
			m_pCAUTION15->MoveComponent(pt);
		}
	}

	{
		if(m_pClock)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_TOP];
			cp.x -=187;
			cp.y +=0;
			m_pClock->MoveComponent(cp);
		}
	}

#ifdef NEW_IF
	{
		if(m_pRaid)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_RIGHT_MIDDLE];
			cp.x -= 370;
			cp.y -= 125;
			m_pRaid->MoveComponent(cp);

			m_pRaid->m_rcDrag.SetRect(
				0, 0,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenX,
				CTachyonRes::m_pDEVICE->m_option.m_dwScreenY);
		}
	}

	{
		if(m_pTRECALLFRM)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_BOTTOM];
			cp.x -= 356;
			cp.y -= 183;
			m_pTRECALLFRM->MoveComponent(cp);
		}
	}
#endif

	{
		if(m_pNewAV)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_TOP];
			cp.x -=68;
			cp.y +=7; 
			m_pNewAV->MoveComponent(cp);
		}
	}

	{
		if(m_pLuckyNumber)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_TOP];
			cp.x +=220;
			cp.y +=8;
			m_pLuckyNumber->MoveComponent(cp);
		}
	}

	{
		if(m_pLuckyNumberFrame)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_TOP];
			cp.x +=183;
			cp.y +=0;
			m_pLuckyNumberFrame->MoveComponent(cp);
		}
	}
#ifdef NEW_IF
	{
		if(m_pCashShop)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_BOTTOM];
			cp.x +=366;
			cp.y -=109;
			m_pCashShop->MoveComponent(cp);
		}
	}

	{
		if(m_pCashShopTxt)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_BOTTOM];
			cp.x +=402;
			cp.y -=94;
			m_pCashShopTxt->MoveComponent(cp);
		}
	}

	{
		if(m_pNewRegion)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_LEFT_TOP];
			cp.x +=10;
			cp.y +=5;
			m_pNewRegion->MoveComponent(cp);
		}
	}
	{
		if(m_pNotify)
		{
			CTClientGame* pGame = CTClientGame::GetInstance();

			CRect rt;
			m_pNotify->GetComponentRect(&rt);
			rt.right = CTachyonRes::m_pDEVICE->m_option.m_dwScreenX;
			m_pNotify->SetComponentRect(rt);

			m_pNotify->Release();
			m_pNotify->InitTEXT(pGame->GetHelpMsg());
			m_pNotify->ShowComponent(FALSE);
		}
	}

	{
		if(m_pPopupMenu)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_RIGHT_TOP];
			cp.x -=265;
			cp.y +=52;
			m_pPopupMenu->MoveComponent(cp);
		}
	}

	{
		if(m_pChangePartyLottery)
		{
			CPoint cp = CTClientUIBase::m_vBasis[TBASISPOINT_LEFT_TOP];
			cp.x +=100;
			cp.y +=35;
			m_pChangePartyLottery->MoveComponent(cp);
		}
	}

	{
		if( m_pSiegeAlarm )
		{
			CPoint pt = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_BOTTOM];
			pt.y -= 250;
			pt.x -= 20;
			m_pSiegeAlarm->MoveComponent(pt);
		}
	}

	{
		if( m_pExitTutorial )
		{
			CPoint pt = CTClientUIBase::m_vBasis[TBASISPOINT_CENTER_BOTTOM];
			pt.y -= 250;
			pt.x -= 20;
			m_pExitTutorial->MoveComponent(pt);
		}
	}
#else
	{
		if( m_pSiegeAlarm )
		{
			CPoint pt = CTClientUIBase::m_vBasis[TBASISPOINT_RIGHT_TOP];
			pt.x -= 235;
			pt.y += 180;
			m_pSiegeAlarm->MoveComponent(pt);
		}
	}

	{
		if( m_pExitTutorial )
		{
			CPoint pt = CTClientUIBase::m_vBasis[TBASISPOINT_RIGHT_TOP];
			pt.x -= 235;
			pt.y += 180;
			m_pExitTutorial->MoveComponent(pt);
		}
	}
#endif
}

void CTGaugePannel::UpdateQuestINFO( CTClientQuest *pTQUEST)
{
	if( !pTQUEST || !pTQUEST->m_pTQUEST )
		return;

	if(pTQUEST->m_bCheckShowRight)
	{
		int nCount = m_pQList->GetItemCount();

		int i;
		for( i=0; i<nCount; i++)
		{
			DWORD dwQuestID = m_pQList->GetItemData( i, TQLIST_COL_OBJ_STATUS);

			if( dwQuestID == pTQUEST->m_pTQUEST->m_dwID )
				break;
		}
		int nIndex = i < m_pQList->GetItemCount() ? i : m_pQList->AddString("");

		m_pQList->SetImageIndex( nIndex, TQLIST_COL_SHOW_PATH, TRUE, pTQUEST->m_pTQUEST->m_dwID == m_dwCurQuestID && m_bShowPath ? TQLIST_BTN_STATUS_DOWN : TQLIST_BTN_STATUS_UP);
		m_pQList->SetImageIndex( nIndex, TQLIST_COL_GOTO_PATH, TRUE, pTQUEST->m_pTQUEST->m_dwID == m_dwCurQuestID && m_bAutoPath ? TQLIST_BTN_STATUS_DOWN : TQLIST_BTN_STATUS_UP);

		m_pQList->SetItemString( nIndex, TQLIST_COL_QNAME, pTQUEST->m_pTQUEST->m_strTITLE);
		m_pQList->SetItemString( nIndex, TQLIST_COL_OBJ_STATUS, "");
		m_pQList->SetUserColor( nIndex, TQLIST_COL_QNAME, 0xFFFED000);

		m_pQList->SetItemData( nIndex, TQLIST_COL_OBJ_STATUS, pTQUEST->m_pTQUEST->m_dwID);
		m_pQList->SetItemData( nIndex, TQLIST_COL_SHOW_PATH, pTQUEST->m_pTQUEST->m_dwID);
		m_pQList->SetItemData( nIndex, TQLIST_COL_GOTO_PATH, pTQUEST->m_pTQUEST->m_dwID);

		nCount = INT(pTQUEST->m_pTQUEST->m_vTTERM.size());
		nIndex++;

		for( int i=0; i<nCount; i++)
		{
			CTClientTerm *pTERM = pTQUEST->FindTTerm(pTQUEST->m_pTQUEST->m_vTTERM[i]);
			CString strRESULT;
			strRESULT.Empty();

			if(pTERM)
			{
				BYTE bResult;
				bResult = pTQUEST->GetResult();

				if( pTERM->m_pTTERM->m_bType == QTT_TIMER &&
					bResult != TTERMRESULT_FAILED &&
					bResult != TTERMRESULT_TIMEOUT &&
					pTQUEST->m_bTimmer )
				{
					strRESULT = CTChart::Format( TSTR_FMT_TIMMER, (pTQUEST->m_dwTick % 3600000) / 60000, (pTQUEST->m_dwTick % 60000) / 1000);
				}
				else
				{
					if( pTERM->m_pTTERM->m_bType != QTT_TIMER )
						bResult = pTERM->GetResult();

					switch( bResult )
					{
					case TTERMRESULT_INCOMPLETE	: strRESULT = CTChart::Format( TSTR_QUEST_STATUS, pTERM->m_bCount, pTQUEST->m_pTQUEST->m_vTTERM[i]->m_bCount); break;
					case TTERMRESULT_TIMEOUT	: strRESULT = CTChart::LoadString( TSTR_QRESULT_TIMEOUT); break;
					case TTERMRESULT_FAILED		: strRESULT = CTChart::LoadString( TSTR_QRESULT_FAILED); break;
					case TTERMRESULT_COMPLETE	: strRESULT = CTChart::LoadString( TSTR_QRESULT_COMPLETE); break;
					}
				}
			}
			else
			{
				strRESULT = CTChart::Format( TSTR_QUEST_STATUS, 0, pTQUEST->m_pTQUEST->m_vTTERM[i]->m_bCount);
			}

			if( nIndex < m_pQList->GetItemCount() )
				m_pQList->SetItemString( nIndex, TQLIST_COL_OBJ_NAME, pTQUEST->m_pTQUEST->m_vTTERM[i]->m_strTermMSG);
			else
				nIndex = m_pQList->AddString(pTQUEST->m_pTQUEST->m_vTTERM[i]->m_strTermMSG);

			m_pQList->SetImageIndex( nIndex, TQLIST_COL_SHOW_PATH, TRUE, TQLIST_BTN_STATUS_HIDE);
			m_pQList->SetImageIndex( nIndex, TQLIST_COL_GOTO_PATH, TRUE, TQLIST_BTN_STATUS_HIDE);

			m_pQList->SetItemString( nIndex, TQLIST_COL_OBJ_STATUS, strRESULT);
			m_pQList->SetUserColor( nIndex, TQLIST_COL_OBJ_NAME, 0xFFD9C298);
			m_pQList->SetUserColor( nIndex, TQLIST_COL_OBJ_STATUS, 0xFFD9C298);

			m_pQList->SetItemData( nIndex, TQLIST_COL_OBJ_STATUS, pTQUEST->m_pTQUEST->m_dwID);
			m_pQList->SetItemData( nIndex, TQLIST_COL_SHOW_PATH, pTQUEST->m_pTQUEST->m_dwID);
			m_pQList->SetItemData( nIndex, TQLIST_COL_GOTO_PATH, pTQUEST->m_pTQUEST->m_dwID);
			nIndex++;
		}
	}
	else
	{
		int nCount = m_pQList->GetItemCount();

		for( int i=nCount - 1; i>=0; i--)
		{
			DWORD dwQuestID = m_pQList->GetItemData( i, 1);

			if( dwQuestID == pTQUEST->m_pTQUEST->m_dwID )
				m_pQList->DelItem(i);
		}

		if( m_dwCurQuestID == pTQUEST->m_pTQUEST->m_dwID )
		{
			m_bShowPath = FALSE;
			m_bAutoPath = FALSE;
			m_dwCurQuestID = 0;
		}
	}
}

void CTGaugePannel::UpdateAllQuestINFO( CTClientChar *pTCHAR)
{
	if(!pTCHAR)
		return;
	int nCount = m_pQList->GetItemCount();

	for( int i=nCount - 1; i>=0; i--)
	{
		CTClientQuest *pTQUEST = pTCHAR->FindTQuest(m_pQList->GetItemData( i, TQLIST_COL_OBJ_STATUS));

		if( !pTQUEST || !pTQUEST->m_bCheckShowRight )
			m_pQList->DelItem(i);
	}

	if(m_dwCurQuestID)
	{
		CTClientQuest *pTQUEST = pTCHAR->FindTQuest(m_dwCurQuestID);

		if( !pTQUEST || !pTQUEST->m_bCheckShowRight )
		{
			m_bShowPath = FALSE;
			m_bAutoPath = FALSE;
			m_dwCurQuestID = 0;
		}
	}

	MAPTQCLASS::iterator itTCLASS;
	for( itTCLASS = pTCHAR->m_mapTQCLASS.begin(); itTCLASS != pTCHAR->m_mapTQCLASS.end(); itTCLASS++)
	{
		CTClientQClass *pTCLASS = (*itTCLASS).second;

		if(pTCLASS)
		{
			MAPTQUEST::iterator itTQUEST;

			for( itTQUEST = pTCLASS->m_mapTQUEST.begin(); itTQUEST != pTCLASS->m_mapTQUEST.end(); itTQUEST++)
				UpdateQuestINFO((*itTQUEST).second);
		}
	}
}

void CTGaugePannel::UpdateQuestBUTTON()
{
	int nCount = m_pQList->GetItemCount();

	for( int i=0; i<nCount; i++)
	{
		MAP_LISTITEM *pTLIST = m_pQList->m_items[i];

		if(pTLIST)
		{
			MAP_LISTITEM::iterator finder = pTLIST->find(TQLIST_COL_SHOW_PATH);

			if( finder != pTLIST->end() )
			{
				TListItem *pItem = (*finder).second;

				if( pItem && pItem->m_nImageIndex )
				{
					pItem->m_nImageIndex = m_bShowPath && pItem->m_param == m_dwCurQuestID ? TQLIST_BTN_STATUS_DOWN : TQLIST_BTN_STATUS_UP;
					m_pQList->m_bNeedUpdateRender = TRUE;
				}
			}

			finder = pTLIST->find(TQLIST_COL_GOTO_PATH);
			if( finder != pTLIST->end() )
			{
				TListItem *pItem = (*finder).second;

				if( pItem && pItem->m_nImageIndex )
				{
					pItem->m_nImageIndex = m_bAutoPath && pItem->m_param == m_dwCurQuestID ? TQLIST_BTN_STATUS_DOWN : TQLIST_BTN_STATUS_UP;
					m_pQList->m_bNeedUpdateRender = TRUE;
				}
			}
		}
	}
}

CString CTGaugePannel::GetResultString( CTClientTerm *pTERM)
{
	CString strRESULT;
	strRESULT.Empty();

    return strRESULT;
}

void CTGaugePannel::SetQuestState( LPTQUEST pTQUEST)
{
}

void CTGaugePannel::CalcRecallTick( CTClientRecall *pTRECALL)
{
	if( pTRECALL && pTRECALL->m_pTEMP->m_dwOBJ )
	{
		for( BYTE i=0; i<TMONSKILL_COUNT; ++i)
		{
			CTClientSkill *pTSKILL = pTRECALL->FindTSkill(pTRECALL->m_pTEMP->m_wTSKILL[i]);

			if(pTSKILL)
			{
				if(pTSKILL->m_dwTick)
				{
					m_pTRECALLSKILLGAUGE[i]->m_strText = CTClientGame::ToTimeString(pTSKILL->m_dwTick);
					m_pTRECALLSKILLGAUGE[i]->SetGauge( pTSKILL->m_dwTick, pTSKILL->m_dwReuseTick);

					m_pTRECALLSKILLGAUGE[i]->ShowComponent(TRUE);
				}
				else
					m_pTRECALLSKILLGAUGE[i]->ShowComponent(FALSE);

				m_pTRECALLSKILLSM[i]->ShowComponent(pTSKILL == pTRECALL->m_pTCURSKILL ? TRUE : FALSE);
			}
			else
			{
				m_pTRECALLSKILLGAUGE[i]->ShowComponent(FALSE);
				m_pTRECALLSKILLSM[i]->ShowComponent(FALSE);
				
				if( m_pTRECALLSKILLDOWN[i]->IsVisible() )
					m_pTRECALLSKILLDOWN[i]->ShowComponent(FALSE);
				
				if( m_pTRECALLSKILL[i]->IsVisible() )
					m_pTRECALLSKILL[i]->ShowComponent(FALSE);
			}
		}
#ifndef NEW_IF
		for( int i=0; i<TRECALLAI_COUNT; ++i)
			m_pTRECALLAISM[i]->ShowComponent(pTRECALL->m_bSubAI == i || pTRECALL->m_bAI == i ? TRUE : FALSE);
#endif
	}
	else
	{
		for( BYTE i=0; i<TMONSKILL_COUNT; ++i)
		{
			m_pTRECALLSKILLGAUGE[i]->ShowComponent(FALSE);
			m_pTRECALLSKILLSM[i]->ShowComponent(FALSE);
		}
#ifndef NEW_IF
		for( int i=0; i<TRECALLAI_COUNT; ++i)
			m_pTRECALLAISM[i]->ShowComponent(FALSE);
#endif
	}
}


void CTGaugePannel::ResetRecallUI( CTClientRecall *pTRECALL)
{
	if( pTRECALL && pTRECALL->m_pTEMP->m_dwOBJ )
	{
		for( BYTE i=0; i<TMONSKILL_COUNT; ++i)
		{
			CTClientSkill *pTSKILL = pTRECALL->FindTSkill(pTRECALL->m_pTEMP->m_wTSKILL[i]);

			if(pTSKILL)
			{
				m_pTRECALLSKILLDOWN[i]->ShowComponent(TRUE);
				m_pTRECALLSKILL[i]->ShowComponent(TRUE);

				m_pTRECALLSKILL[i]->SetCurImage(pTSKILL->m_pTSKILL->m_wIconID);
				m_pTRECALLSKILLDOWN[i]->SetCurImage(0);
			}
			else
			{
				m_pTRECALLSKILLDOWN[i]->ShowComponent(FALSE);
				m_pTRECALLSKILL[i]->ShowComponent(FALSE);
			}
		}
#ifndef NEW_IF
		for( int i=0; i<TRECALLAI_COUNT; ++i)
		{
			m_pTRECALLAIDOWN[i]->ShowComponent(TRUE);
			m_pTRECALLAI[i]->ShowComponent(TRUE);
		}
#else
		for( int i=0; i<TRECALLAIACT_COUNT; ++i)
		{
			m_pTRECALLAIDOWN_NEW[i]->ShowComponent(TRUE);
			m_pTRECALLAI_NEW[i]->ShowComponent(TRUE);
		}
#endif
		BOOL bPrevShow = m_pTRECALLFRM->IsVisible();
		m_pTRECALLFRM->ShowComponent(TRUE);

		if( FALSE == bPrevShow )
		{
			CTMainUI* pMainUI = static_cast<CTMainUI*>( CTClientGame::GetInstance()->GetFrame( TFRAME_MAIN ) );
			pMainUI->AdjustOtherCompByTREECALLSLOT( TRUE );
		}
	}
	else
	{
		for( BYTE i=0; i<TMONSKILL_COUNT; ++i)
		{
			m_pTRECALLSKILLDOWN[i]->ShowComponent(FALSE);
			m_pTRECALLSKILL[i]->ShowComponent(FALSE);
		}
#ifndef NEW_IF
		for( int i=0; i<TRECALLAI_COUNT; ++i)
		{
			m_pTRECALLAIDOWN[i]->ShowComponent(FALSE);
			m_pTRECALLAI[i]->ShowComponent(FALSE);
		}
#else
		for( int i=0; i<TRECALLAIACT_COUNT; ++i)
		{
			m_pTRECALLAIDOWN_NEW[i]->ShowComponent(FALSE);
			m_pTRECALLAI_NEW[i]->ShowComponent(FALSE);
		}
#endif
		BOOL bPrevShow = m_pTRECALLFRM->IsVisible();
		m_pTRECALLFRM->ShowComponent(FALSE);

		if( TRUE == bPrevShow )
		{
			CTMainUI* pMainUI = static_cast<CTMainUI*>( CTClientGame::GetInstance()->GetFrame( TFRAME_MAIN ) );
			pMainUI->AdjustOtherCompByTREECALLSLOT( FALSE );
		}
	}

	m_pMainRecall = pTRECALL;
}

void CTGaugePannel::ResetHotkeyStr()
{
	static const WORD wSkillKey[THOTKEYBASE_COUNT] = 
	{
		TKEY_SKILL_1,
		TKEY_SKILL2_1,
	};

	CTKeySetting* pKeySet = CTKeySetting::GetInstance();

#ifdef NEW_IF
	DWORD dwVKStr1[][2] =
	{
		{ ID_CTRLINST_VK_NEW7, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW8, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW9, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW10, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW11, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW12, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW7, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW8, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW9, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW10, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW11, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW12, THOTKEYBASE_SUB1 }
	};

	DWORD dwVKStr2[][2] =
	{
		{ ID_CTRLINST_VK_NEW1, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW2, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW3, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW4, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW5, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW6, THOTKEYBASE_DEF },
		{ ID_CTRLINST_VK_NEW1, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW2, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW3, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW4, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW5, THOTKEYBASE_SUB1 },
		{ ID_CTRLINST_VK_NEW6, THOTKEYBASE_SUB1 }
	};

#endif

	for( WORD h=0; h<THOTKEYBASE_COUNT; ++h)
	{
		for( WORD i=0; i<MAX_HOTKEY_POS; ++i)
		{
#ifdef NEW_IF
			TKEY_SET eKEY = (TKEY_SET)(wSkillKey[h]+i);

			TComponent * pVKStr;

			if(h == THOTKEYBASE_DEF)
				pVKStr = m_pTHOTKEYFRM[dwVKStr1[i][1]]->FindKid(dwVKStr1[i][0]);
			else if(h == THOTKEYBASE_SUB1)
				pVKStr = m_pTHOTKEYFRM[dwVKStr2[i][1]]->FindKid(dwVKStr2[i][0]);

			pVKStr->m_strText = pKeySet->VKeyToStr( 
				pKeySet->GetCurVKey(eKEY),
				pKeySet->GetCurModKey(eKEY));

#else
			TKEY_SET eKEY = (TKEY_SET)(wSkillKey[h]+i);

			m_pTHOTKEYDOWN[h][i]->m_strText = pKeySet->VKeyToStr( 
				pKeySet->GetCurVKey(eKEY),
				pKeySet->GetCurModKey(eKEY));
#endif
		}
	}
}

void CTGaugePannel::CalcHotkeyTick()
{
	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
	{
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
		{
			m_pTHOTKEYGAUGE[i][j]->ShowComponent(FALSE);
			m_pTHOTKEYSM[i][j]->ShowComponent(FALSE);

			switch(m_vTHOTKEY[m_bHotkeyID[i]][j].m_bType)
			{
			case HOTKEY_SKILL	:
				{
					CTClientSkill *pTSKILL = m_pHost->FindTSkill(m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID);

					if(pTSKILL)
					{
						if(pTSKILL->m_dwTick)
						{
							m_pTHOTKEYGAUGE[i][j]->m_strText = CTClientGame::ToTimeString(pTSKILL->m_dwTick);
							m_pTHOTKEYGAUGE[i][j]->SetGauge( pTSKILL->m_dwTick, pTSKILL->m_dwReuseTick);

							m_pTHOTKEYGAUGE[i][j]->ShowComponent(TRUE);
						}

						if(pTSKILL->m_bLoopON)
							m_pTHOTKEYSM[i][j]->ShowComponent(TRUE);
					}
				}

				break;

			case HOTKEY_ITEM	:
				{
					LPTITEM pTITEM = CTChart::FindTITEMTEMP(m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID);
					DWORD dwTick = pTITEM ? CTClientItem::GetTick(pTITEM->m_wDelayGroupID) : 0;

					if(dwTick)
					{
						m_pTHOTKEYGAUGE[i][j]->m_strText = CTClientGame::ToTimeString(dwTick);
						m_pTHOTKEYGAUGE[i][j]->SetGauge( dwTick, pTITEM->m_dwDelay);

						m_pTHOTKEYGAUGE[i][j]->ShowComponent(TRUE);
					}
				}

				break;
			}
		}
	}
}

void CTGaugePannel::ShowHotkeyBase( BYTE bShow)
{
	bShow = TRUE; //임시 재수정해야함

	if( m_bHotkeyBase != bShow )
	{
		for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
			for( BYTE j=0; j<THOTKEYCTRL_COUNT; j++)
				m_pTHOTKEYCTRL[i][j]->ShowComponent(bShow);

		m_bHotkeyBase = bShow;
	}
}

BYTE CTGaugePannel::CheckHotkeyBase( CPoint point, THOTKEY_BASE* outType )
{
	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
	{
		CRect rect;
		m_pTHOTKEYCTRL[i][THOTKEYCTRL_BASE]->GetComponentRect(&rect);
		m_pTHOTKEYCTRL[i][THOTKEYCTRL_BASE]->ComponentToScreen(&rect);

		if( rect.PtInRect(point) )
		{
			if( outType )
				*outType = (THOTKEY_BASE) i;

			return TRUE;
		}
	}

	return FALSE;
}


void CTGaugePannel::ResetHotkeyUI()
{
	BOOL bCanUsePet = m_pHost->CountCanNotUsePetMaintain() > 0 ? FALSE : TRUE;

	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
	{
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
			switch(m_vTHOTKEY[m_bHotkeyID[i]][j].m_bType)
			{
			case HOTKEY_NONE	:
				{
					m_pTHOTKEY[i][j][1]->m_strText.Empty();
					m_pTHOTKEY[i][j][0]->SetCurImage(0);
					m_pTHOTKEY[i][j][1]->SetCurImage(0);

					m_pTHOTKEYDOWN[i][j]->ShowComponent(FALSE);
				}

				break;
	 
			case HOTKEY_SKILL	:
				{
					CTClientSkill *pTSKILL = m_pHost->FindTSkill(m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID);

					if( !pTSKILL || !pTSKILL->m_pTSKILL )
					{
						m_vTHOTKEY[m_bHotkeyID[i]][j].m_bType = HOTKEY_NONE;
						m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID = 0;

						m_pTHOTKEYDOWN[i][j]->ShowComponent(FALSE);
						m_pTHOTKEY[i][j][0]->SetCurImage(0);
					}
					else
					{
						BOOL bENABLE = IsEnableHotkeySkill(pTSKILL);
						
						m_pTHOTKEYDOWN[i][j]->ShowComponent(TRUE);
						m_pTHOTKEYDOWN[i][j]->SetCurImage(0);

						m_pTHOTKEY[i][j][0]->SetCurImage(pTSKILL->m_pTSKILL->m_wIconID);
						m_pTHOTKEY[i][j][0]->EnableComponent(bENABLE);

						if(!bENABLE)
							pTSKILL->m_bLoopON = FALSE;
					}

					m_pTHOTKEY[i][j][1]->m_strText.Empty();
					m_pTHOTKEY[i][j][1]->SetCurImage(0);
				}

				break;

			case HOTKEY_ITEM	:
				{
					LPTITEM pTITEM = CTChart::FindTITEMTEMP(m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID);
					WORD wCount = m_pHost->GetItemCount(m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID);

					if( !wCount || !pTITEM )
					{
						// 2009.11.27 권성혁
						// 인벤토리내에서 아이템 이동시에 
						// hotkey에 등록되었던 아이템이 hotkey slot에서 사라지는 것 때문에
						// bType과 wID를 계속 가지고있음..
//						m_vTHOTKEY[m_bHotkeyID[i]][j].m_bType = HOTKEY_NONE;
//						m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID = 0;

						m_pTHOTKEYDOWN[i][j]->ShowComponent(FALSE);
						m_pTHOTKEY[i][j][1]->m_strText.Empty();
						m_pTHOTKEY[i][j][1]->SetCurImage(0);
					}
					else
					{
						if( wCount > 1 )
							m_pTHOTKEY[i][j][1]->m_strText = CTChart::Format( TSTR_FMT_NUMBER, wCount);
						else
							m_pTHOTKEY[i][j][1]->m_strText.Empty();

						m_pTHOTKEYDOWN[i][j]->ShowComponent(TRUE);
						m_pTHOTKEYDOWN[i][j]->SetCurImage(0);

						LPTITEMVISUAL pTVISUAL = CTClientItem::GetDefaultVisual(pTITEM);
						WORD wImg = pTVISUAL? pTVISUAL->m_wIcon: 0;

						m_pTHOTKEY[i][j][1]->SetCurImage(wImg);
					}

					m_pTHOTKEY[i][j][0]->SetCurImage(0);
				}

				break;

			case HOTKEY_PET	:
				{
					WORD wPetID = m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID;

					if( !wPetID )
					{
						m_vTHOTKEY[m_bHotkeyID[i]][j].m_bType = HOTKEY_NONE;
						m_vTHOTKEY[m_bHotkeyID[i]][j].m_wID = 0;

						m_pTHOTKEYDOWN[i][j]->ShowComponent(FALSE);
						m_pTHOTKEY[i][j][1]->m_strText.Empty();
						m_pTHOTKEY[i][j][1]->SetCurImage(0);
					}
					else
					{
						wPetID = MAKEWORD( m_pHost->GetRaceID(), wPetID );

						LPTPET pTPET = CTChart::FindTPETTEMP( wPetID );
						if( pTPET )
						{
							m_pTHOTKEYDOWN[i][j]->ShowComponent(TRUE);
							m_pTHOTKEYDOWN[i][j]->SetCurImage(0);

							m_pTHOTKEY[i][j][1]->SetCurImage( pTPET->m_wIcon);
							m_pTHOTKEY[i][j][1]->EnableComponent(bCanUsePet);
							m_pTHOTKEY[i][j][1]->m_strText.Empty();
							m_pTHOTKEY[i][j][0]->SetCurImage(0);
						}
					}					
				}
				break;
			}

#ifdef NEW_IF
		m_pTHOTKEYCTRL[i][THOTKEYCTRL_NUM]->m_strText = CTChart::Format( TSTR_FMT_NUMBER, (m_bHotkeyID[i] + 1) / 2);
#else
		m_pTHOTKEYCTRL[i][THOTKEYCTRL_NUM]->m_strText = CTChart::Format( TSTR_FMT_NUMBER, m_bHotkeyID[i] + 1);
#endif
	}
}

void CTGaugePannel::ReleaseHotkey()
{
	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
	{
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
			m_pTHOTKEYDOWN[i][j]->ShowComponent(FALSE);

		m_bHotkeyID[i] = i;
	}

	for( int i=0; i<MAX_HOTKEY_INVEN; i++)
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
		{
			m_vTHOTKEY[i][j].m_bType = HOTKEY_NONE;
			m_vTHOTKEY[i][j].m_wID = 0;
		}
}

ITDetailInfoPtr CTGaugePannel::GetTInfoKey_Hotkey(const CPoint& point, INT nHotkeyID, INT nSlotID)
{
	BYTE bHotkeySlot = m_bHotkeyID[nHotkeyID];
	ITDetailInfoPtr pInfo;

	switch(m_vTHOTKEY[bHotkeySlot][nSlotID].m_bType)
	{
	case HOTKEY_SKILL	:
		if(m_pTHOTKEY[nHotkeyID][nSlotID][0]->HitTest(point))
		{
			LPTSKILL pTSKILL = CTChart::FindTSKILLTEMP(m_vTHOTKEY[bHotkeySlot][nSlotID].m_wID);

			if( pTSKILL )
			{
				CRect rc;
				m_pTHOTKEY[nHotkeyID][nSlotID][0]->GetComponentRect(&rc);
				m_pTHOTKEY[nHotkeyID][nSlotID][0]->ComponentToScreen(&rc);

				CTClientSkill *pTSkill = m_pHost->FindTSkill(m_vTHOTKEY[bHotkeySlot][nSlotID].m_wID);
				pInfo = CTDetailInfoManager::NewSkillInst(
					pTSKILL, 
					pTSkill ? pTSkill->m_bLevel : 0,
					FALSE,
					rc);

				pInfo->SetDir(FALSE, TRUE, TRUE);
			}
		}
		break;

	case HOTKEY_ITEM	:
		if(m_pTHOTKEY[nHotkeyID][nSlotID][1]->HitTest(point))
		{
			LPTITEM pTITEM = CTChart::FindTITEMTEMP(m_vTHOTKEY[bHotkeySlot][nSlotID].m_wID);

			if( pTITEM )
			{
				CRect rc;
				m_pTHOTKEY[nHotkeyID][nSlotID][0]->GetComponentRect(&rc);
				m_pTHOTKEY[nHotkeyID][nSlotID][0]->ComponentToScreen(&rc);

				pInfo = CTDetailInfoManager::NewItemInst(pTITEM, rc);
				pInfo->SetDir(FALSE, TRUE, TRUE);
			}
		}
		break;

	case HOTKEY_PET:
		{
			// 구현
		}
		break;
	}

	return pInfo;
}


ITDetailInfoPtr CTGaugePannel::GetTInfoKey_RecallSkill(const CPoint& point, INT nID)
{
	ITDetailInfoPtr pInfo;
	if( m_pTRECALLSKILL[nID]->HitTest(point) )
	{
		CTClientSkill* pSkill = m_pMainRecall->FindTSkill( m_pMainRecall->m_pTEMP->m_wTSKILL[nID] );

		if( pSkill )
		{
			CRect rc;
			m_pTRECALLSKILL[nID]->GetComponentRect(&rc);
			m_pTRECALLSKILL[nID]->ComponentToScreen(&rc);

			pInfo = CTDetailInfoManager::NewSkillInst(
				pSkill->m_pTSKILL, 
				pSkill ? pSkill->m_bLevel : 0,
				FALSE,
				rc);

			pInfo->SetDir(FALSE, TRUE, TRUE);
		}
	}

	return pInfo;
}

ITDetailInfoPtr CTGaugePannel::GetTInfoKey_RecallAi(const CPoint& point, INT nID)
{
	ITDetailInfoPtr pInfo;

#ifdef NEW_IF
	if(nID == TRECALLAIACT_STATUS)
	{
		const DWORD RECALLINFOIDS[3] = {
			60005,		// TRECALLAI_MANUAL
			60003,		// TRECALLAI_ACTIVE
			60004		// TRECALLAI_PASSIVE
		};

		if(m_pTRECALLAI_NEW[nID]->HitTest(point))
		{
			CRect rc;
			m_pTRECALLAIDOWN_NEW[nID]->GetComponentRect(&rc);
			m_pTRECALLAIDOWN_NEW[nID]->ComponentToScreen(&rc);

			pInfo = CTDetailInfoManager::NewNorInst("", RECALLINFOIDS[m_pTRECALLAI_NEW[nID]->GetCurImage()], 0, &rc);
			pInfo->SetDir(FALSE, FALSE, TRUE);
		}

		return pInfo;
	}
	else if(nID == TRECALLAIACT_MODE)
	{
		const DWORD RECALLINFOIDS[2] = {
			60001,		// TRECALLAI_BACK
			60002		// TRECALLAI_STAY
		};

		if(m_pTRECALLAI_NEW[nID]->HitTest(point))
		{
			CRect rc;
			m_pTRECALLAIDOWN_NEW[nID]->GetComponentRect(&rc);
			m_pTRECALLAIDOWN_NEW[nID]->ComponentToScreen(&rc);

			pInfo = CTDetailInfoManager::NewNorInst("", RECALLINFOIDS[m_pTRECALLAI_NEW[nID]->GetCurImage()], 0, &rc);
			pInfo->SetDir(FALSE, FALSE, TRUE);
		}

		return pInfo;
	}
#else

	const DWORD RECALLINFOIDS[TRECALLAI_COUNT] = {
		60005,		// TRECALLAI_MANUAL
		60003,		// TRECALLAI_ACTIVE
		60004,		// TRECALLAI_PASSIVE
		60001,		// TRECALLAI_BACK
		60002};		// TRECALLAI_STAY

	if(m_pTRECALLAI[nID]->HitTest(point))
	{
		CRect rc;
		m_pTRECALLAIDOWN[nID]->GetComponentRect(&rc);
		m_pTRECALLAIDOWN[nID]->ComponentToScreen(&rc);

		pInfo = CTDetailInfoManager::NewNorInst("", RECALLINFOIDS[nID], 0, &rc);
		pInfo->SetDir(FALSE, FALSE, TRUE);
	}

	return pInfo;

#endif

	return pInfo;
}

BOOL CTGaugePannel::HitTest( CPoint pt)
{
	if(CTClientUIBase::HitTest(pt))
		return TRUE;

	if(m_pQList)
	{
		int nColumn = 0;
		TListItem *pItem = m_pQList->GetHitItem( pt, &nColumn);

		if( pItem && pItem->m_nImageIndex && (
			nColumn == TQLIST_COL_SHOW_PATH ||
			nColumn == TQLIST_COL_GOTO_PATH) )
			return TRUE;
	}

	return FALSE;
}

void CTGaugePannel::PushIcon( CPoint point)
{
	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
		{
			if( !m_pTHOTKEY[i][j][0]->HitTest(point) )
				continue;

			switch(m_vTHOTKEY[m_bHotkeyID[i]][j].m_bType)
			{
			case HOTKEY_SKILL	:
				m_pTHOTKEYDOWN[i][j]->SetCurImage(1);
				return;

			case HOTKEY_ITEM	:
				m_pTHOTKEYDOWN[i][j]->SetCurImage(1);
				return;

			case HOTKEY_PET:
				m_pTHOTKEYDOWN[i][j]->SetCurImage(1);
				return ;
			}
		}

	for( int i=0; i<TMONSKILL_COUNT; i++)
		if(m_pTRECALLSKILL[i]->HitTest(point))
		{
			m_pTRECALLSKILLDOWN[i]->SetCurImage(1);
			return;
		}
#ifndef NEW_IF
	for( int i=0; i<TRECALLAI_COUNT; i++)
		if(m_pTRECALLAI[i]->HitTest(point))
		{
			m_pTRECALLAIDOWN[i]->SetCurImage(1);
			return;
		}
#else
	for( int i=0; i<TRECALLAIACT_COUNT; i++)
		if(m_pTRECALLAI_NEW[i]->HitTest(point))
		{
			m_pTRECALLAIDOWN_NEW[i]->SetCurImage(1);
			return;
		}
#endif
	if( m_pQList && m_pHost && !m_pHost->IsDead() && !m_pHost->m_bGhost )
	{
		int nColumn = 0;
		TListItem *pItem = m_pQList->GetHitItem( point, &nColumn);

		if( pItem && pItem->m_nImageIndex && (
			nColumn == TQLIST_COL_SHOW_PATH ||
			nColumn == TQLIST_COL_GOTO_PATH) )
		{
			switch(pItem->m_nImageIndex)
			{
			case TQLIST_BTN_STATUS_DOWN	:
				{
					if( nColumn == TQLIST_COL_GOTO_PATH )
						m_bAutoPath = FALSE;
					else
						m_bShowPath = FALSE;

					if( !m_bShowPath && !m_bAutoPath )
						m_dwCurQuestID = 0;
				}

				break;

			case TQLIST_BTN_STATUS_UP	:
				{
					if( nColumn == TQLIST_COL_GOTO_PATH )
						m_bAutoPath = TRUE;
					else
						m_bShowPath = TRUE;

					m_dwCurQuestID = pItem->m_param;
				}

				break;
			}

			UpdateQuestBUTTON();
		}
	}
}

void CTGaugePannel::ReleaseIcon()
{
	for( BYTE i=0; i<THOTKEYBASE_COUNT; i++)
		for( BYTE j=0; j<MAX_HOTKEY_POS; j++)
			m_pTHOTKEYDOWN[i][j]->SetCurImage(0);

	for( int i=0; i<TMONSKILL_COUNT; i++)
		m_pTRECALLSKILLDOWN[i]->SetCurImage(0);
#ifndef NEW_IF
	for( int i=0; i<TRECALLAI_COUNT; i++)
		m_pTRECALLAIDOWN[i]->SetCurImage(0);
#else
	for( int i=0; i<TRECALLAIACT_COUNT; i++)
		m_pTRECALLAIDOWN_NEW[i]->SetCurImage(0);
#endif
}

void CTGaugePannel::HotkeyNext(THOTKEY_BASE eHOTKEY)
{
#ifdef NEW_IF
	if(m_bHotkeyID[THOTKEYBASE_SUB1] == (MAX_HOTKEY_INVEN-1))
	{
		m_bHotkeyID[THOTKEYBASE_SUB1] = 1;
		m_bHotkeyID[THOTKEYBASE_DEF] = 0;
	}
	else
	{
		m_bHotkeyID[THOTKEYBASE_SUB1] += 2;
		m_bHotkeyID[THOTKEYBASE_DEF] += 2;
	}
#else
	if( m_bHotkeyID[eHOTKEY] >= (MAX_HOTKEY_INVEN-1) )
		m_bHotkeyID[eHOTKEY] = 0;
	else
		++m_bHotkeyID[eHOTKEY];
#endif
	
	ResetHotkeyUI();
}

void CTGaugePannel::HotkeyPrev(THOTKEY_BASE eHOTKEY)
{
#ifdef NEW_IF
	if(m_bHotkeyID[THOTKEYBASE_SUB1] == 1)
	{
		m_bHotkeyID[THOTKEYBASE_SUB1] = (MAX_HOTKEY_INVEN-1);
		m_bHotkeyID[THOTKEYBASE_DEF] = (MAX_HOTKEY_INVEN-2);
	}
	else
	{
		m_bHotkeyID[THOTKEYBASE_SUB1] -= 2;
		m_bHotkeyID[THOTKEYBASE_DEF] -= 2;
	}
#else
	if( m_bHotkeyID[eHOTKEY] == 0 )
		m_bHotkeyID[eHOTKEY] = MAX_HOTKEY_INVEN - 1;
	else
		--m_bHotkeyID[eHOTKEY];
#endif

	ResetHotkeyUI();
}

void CTGaugePannel::OnLButtonDown( UINT nFlags, CPoint pt)
{
#ifdef NEW_IF
	if(m_pPartyLot->HitTest(pt))
		m_pCommandHandler->m_vCOMMAND.push_back(GM_CHANGE_PARTY_ITEM_TYPE);
#endif
	PushIcon(pt);
	CTClientUIBase::OnLButtonDown( nFlags, pt);
}

void CTGaugePannel::OnLButtonUp( UINT nFlags, CPoint pt)
{
	ReleaseIcon();
	CTClientUIBase::OnLButtonUp( nFlags, pt);
}

void CTGaugePannel::OnMouseMove( UINT nFlags, CPoint pt)
{
	INT nX = m_ptPrev.x > pt.x ? m_ptPrev.x-pt.x : pt.x-m_ptPrev.x;
	INT nY = m_ptPrev.y > pt.y ? m_ptPrev.y-pt.y : pt.y-m_ptPrev.y;

	if( nX >= 6 || nY >= 6 )
		ReleaseIcon();

	m_ptPrev = pt;

	CTClientUIBase::OnMouseMove( nFlags, pt);
}

BOOL CTGaugePannel::IsEnableHotkeySkill( CTClientSkill * pTSKILL )
{
	BOOL bENABLE;

	CTClientGame* pGame = CTClientGame::GetInstance();
	CTClientObjBase* pTargetObj = pGame->GetTargetObj();
	
	if( pTSKILL->m_pTSKILL->m_bRangeType == TSKILLRANGE_NONE )
	{
		CTClientObjBase* pTARGET = pGame->GetSkillTarget(
			pTargetObj,
			pTSKILL->m_pTSKILL);

		BYTE bRESULT = pGame->CanUseSkill(
			pGame->GetMainChar(),
			pTARGET, 
			NULL,
			pTSKILL->m_pTSKILL);

		bENABLE = IsEnableHotkeySkill(bRESULT);
	}
	else
		bENABLE = m_pHost->CheckSkill(pTSKILL->m_pTSKILL);

	return bENABLE;
}

BOOL CTGaugePannel::IsEnableHotkeySkill(BYTE bRESULT)
{
	switch(bRESULT)
	{
	case SKILL_NEEDMP			:
	case SKILL_NEEDHP			:
	case SKILL_UNSUITWEAPON		:
	case SKILL_NEEDPREVACT		:
	case SKILL_MATCHCLASS		:
	case SKILL_WRONGTARGET		:
	case SKILL_WRONGREGION		:
	case SKILL_TRANS			:
	case SKILL_DEAD				:
	case SKILL_SILENCE			:
	case SKILL_MODE				:
	case SKILL_PEACEZONE		:
	case SKILL_NOTARGET			:
	case SKILL_NEEDITEM			: return FALSE;
	}

	return TRUE;
}

LPTHOTKEY CTGaugePannel::GetHotKey(THOTKEY_BASE eTYPE, BYTE bHotkeyID)
{
	if( bHotkeyID < MAX_HOTKEY_POS )
		return &m_vTHOTKEY[m_bHotkeyID[eTYPE]][bHotkeyID];

	return NULL;
}

void CTGaugePannel::CalcCaution15Tick(DWORD dwTick)
{
}

void CTGaugePannel::AttachCaution15()
{
	if( !m_bAddedCaution15 && m_pCAUTION15 )
	{
		m_pCAUTION15->ShowComponent(TRUE);
		m_bAddedCaution15 = TRUE;
	}
}

void CTGaugePannel::DettachCaution15()
{
	if( m_bAddedCaution15 && m_pCAUTION15 )
	{
		m_pCAUTION15->ShowComponent(FALSE);
		m_bAddedCaution15 = FALSE;
	}
}

void CTGaugePannel::AttachSiegeAlarm()
{
	if( !m_bAddedSiegeAlarm )
	{
		m_pSiegeAlarm->ShowComponent(TRUE);
		m_bAddedSiegeAlarm = TRUE;
	}
}

void CTGaugePannel::DettachSiegeAlarm()
{
	if( m_bAddedSiegeAlarm )
	{
		m_pSiegeAlarm->ShowComponent(FALSE);
		m_bAddedSiegeAlarm = FALSE;
	}

	CTDetailInfoManager::m_dwInfoStaticTick = 0;
}

void CTGaugePannel::SetClockTime(CString strTime)
{
	m_pClockCmpnt->m_strText = strTime;
}

void CTGaugePannel::AttachExitTutorial()
{
	if( !m_bAddedExitTutorial )
	{
		m_pExitTutorial->ShowComponent(TRUE);
		m_bAddedExitTutorial = TRUE;
	}
}

void CTGaugePannel::DettachExitTutorial()
{
	if( m_bAddedExitTutorial )
	{
		m_pExitTutorial->ShowComponent(FALSE);
		m_bAddedExitTutorial = FALSE;
	}

	CTDetailInfoManager::m_dwInfoStaticTick = 0;
}

HRESULT CTGaugePannel::Render( DWORD dwTickCount )
{
	if(!IsVisible())
		return S_OK;

#ifdef NEW_IF
	m_pDuration->Update();
#endif

	return CTClientUIBase::Render(dwTickCount);
}

void CTGaugePannel::SetNotifySiegeAlarm(BOOL bNotify)
{
	CRect rt;
	m_pSiegeAlarm->GetComponentRect(&rt);
	m_pSiegeAlarm->ComponentToScreen(&rt);
	
	CTClientGame* pGame = CTClientGame::GetInstance();
	CTDetailInfoDlg* pDetInfoDlg = static_cast<CTDetailInfoDlg*>( pGame->GetFrame(TFRAME_DETAIL_INFO) );
	CTDetailInfoManager::m_dwInfoStaticTick = 6000;

	// 팝업창 빌드
	ITDetailInfoPtr info = CTDetailInfoManager::NewDefTooltipInst(
		CTChart::LoadString(TSTR_SIEGE_ALARM_TITLE),
		CTChart::LoadString(TSTR_SIEGE_ALARM_MSG),
		rt);

	info->SetDir(FALSE, TRUE, TRUE);

	CTDetailInfoManager::m_pLastInfo = info;
	pGame->DisableUI(TFRAME_DETAIL_INFO);

	pDetInfoDlg->ResetINFO(CTDetailInfoManager::m_pLastInfo);

	CRect rc;
	pDetInfoDlg->GetComponentRect(&rc);

	CPoint pt = CTDetailInfoManager::m_pLastInfo->GetUIPosition(rc, CPoint(0,0));
	pDetInfoDlg->MoveComponent(pt);

	pGame->EnableUI(TFRAME_DETAIL_INFO);
}

void CTGaugePannel::ShowComponent(BOOL bVisible)
{
	CTClientUIBase::ShowComponent(bVisible);

	if(m_pCAUTION15)
		m_pCAUTION15->ShowComponent(bVisible && m_bAddedCaution15 ? TRUE : FALSE);

	if(m_pSiegeAlarm)
		m_pSiegeAlarm->ShowComponent(bVisible && m_bAddedSiegeAlarm ? TRUE : FALSE);

	if(m_pExitTutorial)
		m_pExitTutorial->ShowComponent(bVisible && m_bAddedExitTutorial ? TRUE : FALSE);
}

#ifdef NEW_IF

void CTGaugePannel::NotifyFrameStaticMoveReset(BYTE bStatus)
{
	if(bStatus)
	{
		static const INT TGAUGE_COMP_COUNT = 9;

		CTClientUIBase *pCOMP[TGAUGE_COMP_COUNT] =
		{
			m_pClock,
			m_pNewAV,
			(CTClientUIBase*)m_pLuckyNumber,
			(CTClientUIBase*)m_pLuckyNumberFrame,
			m_pNewRegion,
			(CTClientUIBase*)m_pPopupMenu,
			m_pChangePartyLottery,
			(CTClientUIBase*)m_pCAUTION15,
			((CTMainUI*) CTClientGame::GetInstance()->m_vTFRAME[TFRAME_MAIN] )->m_pRIGHT
		};

		for( INT i=0 ; i < TGAUGE_COMP_COUNT ; ++i )
		{
			CPoint cp;
			pCOMP[i]->GetComponentPos(&cp);
			cp.y -= 24;
			pCOMP[i]->MoveComponent(cp);
		}
	}
}

void CTGaugePannel::NotifyFrameStaticMove(BYTE bStatus)
{
	if(bStatus)
	{
		static const INT TGAUGE_COMP_COUNT = 9;

		CTClientUIBase *pCOMP[TGAUGE_COMP_COUNT] =
		{
			m_pClock,
			m_pNewAV,
			(CTClientUIBase*)m_pLuckyNumber,
			(CTClientUIBase*)m_pLuckyNumberFrame,
			m_pNewRegion,
			(CTClientUIBase*)m_pPopupMenu,
			m_pChangePartyLottery,
			(CTClientUIBase*)m_pCAUTION15,
			((CTMainUI*) CTClientGame::GetInstance()->m_vTFRAME[TFRAME_MAIN] )->m_pRIGHT
		};

		for( INT i=0 ; i < TGAUGE_COMP_COUNT ; ++i )
		{
			CPoint cp;
			pCOMP[i]->GetComponentPos(&cp);
			cp.y += 24;
			pCOMP[i]->MoveComponent(cp);
		}
		
		////

		if(m_bCanClickReset)
		{
			static const INT TGAUGEPANNEL_COMP_COUNT2 = 7;

			static DWORD vCOMP[TGAUGEPANNEL_COMP_COUNT2] =
			{
				ID_FRAME_MY_GAUGE_NEW,
				ID_FRAME_RECALL_GAUGE_NEW,
				ID_FRAME_TARGET_GAUGE_NEW,
				ID_FRAME_PARTY_GAUGE_NEW,
				ID_FRAME_CHATNEW,
				ID_FRAME_TOURNAMENT_MODE,
				ID_CTRLINST_POS_DURATION
			};

			for( INT i=0 ; i < TGAUGEPANNEL_COMP_COUNT2 ; ++i )
			{
				CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP[ i ] );
				if( pCOMP )
				{
					CPoint cp;
					pCOMP->GetComponentPos(&cp);
					cp.y += 24;
					pCOMP->MoveComponent(cp);
				}
			}

			m_bCanClickReset = FALSE;
		}
	}
	else
	{
		static const INT TGAUGE_COMP_COUNT = 9;

		CTClientUIBase *pCOMP[TGAUGE_COMP_COUNT] =
		{
			m_pClock,
			m_pNewAV,
			(CTClientUIBase*)m_pLuckyNumber,
			(CTClientUIBase*)m_pLuckyNumberFrame,
			m_pNewRegion,
			(CTClientUIBase*)m_pPopupMenu,
			m_pChangePartyLottery,
			(CTClientUIBase*)m_pCAUTION15,
			((CTMainUI*) CTClientGame::GetInstance()->m_vTFRAME[TFRAME_MAIN] )->m_pRIGHT
		};

		for( INT i=0 ; i < TGAUGE_COMP_COUNT ; ++i )
		{
			CPoint cp;
			pCOMP[i]->GetComponentPos(&cp);
			cp.y -= 24;
			pCOMP[i]->MoveComponent(cp);
		}

		////

		static const INT TGAUGEPANNEL_COMP_COUNT2 = 7;

		static DWORD vCOMP[TGAUGEPANNEL_COMP_COUNT2] =
		{
			ID_FRAME_MY_GAUGE_NEW,
			ID_FRAME_RECALL_GAUGE_NEW,
			ID_FRAME_TARGET_GAUGE_NEW,
			ID_FRAME_PARTY_GAUGE_NEW,
			ID_FRAME_CHATNEW,
			ID_FRAME_TOURNAMENT_MODE,
			ID_CTRLINST_POS_DURATION
		};

		for( INT i=0 ; i < TGAUGEPANNEL_COMP_COUNT2 ; ++i )
		{
			CTClientUIBase* pCOMP = (CTClientUIBase*) FindKid( vCOMP[ i ] );
			if( pCOMP )
			{
				CPoint cp;
				pCOMP->GetComponentPos(&cp);
				cp.y -= 24;
				pCOMP->MoveComponent(cp);
			}
		}

		m_bCanClickReset = !CTClientGame::m_vTOPTION.m_bAutoHelp;
	}
}
#endif
