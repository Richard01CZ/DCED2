#include "mafiasyntax.h"
#include "globaldefs.h"

#include <qmessagebox.h>
#include <qtextedit.h>

MafiaSyntax::MafiaSyntax( QTextEdit * textEdit, Mode m ) 
	: QSyntaxHighlighter( textEdit ), mode( m )
{
	if( m == Edit )	path = "edit";
	else path = "preview";

	//-----------------------------------------------------------------------------//
	//------------------------------ Adding Keywords ------------------------------//
	//-----------------------------------------------------------------------------//
	
	commandKeywords << "autosavegame" << "autosavegamefull" << "get_pm_crashtime"
	<< "get_pm_firetime" << "get_pm_humanstate" << "get_pm_state" << "get_remote_actor" << "get_remote_float"
	<< "getactivecamera" << "getactiveplayer" << "getactorframe" << "getactorsdist" << "getangleactortoactor"
	<< "getcardamage" << "getcarlinenumfromtable" << "getenemyaistate" << "getfilmmusic" << "getframefromactor"
	<< "getgametime" << "getlastsavenum" << "getmissionnumber" << "getsoundtime" << "getticktime";
	
	
	statementKeywords << "goto" << "let" << "wait" << "if" << "end" << "call" << "gosub" << "return" << "rnd";
	
	commandKeywords << "act_setstate" << "actor_adddorici" << "actor_delete"	<< "actor_duplicate" << "actor_setdir"
	<< "actor_setplacement" << "actor_setpos" << "actorlightnesson"	<< "actorupdateplacement" << "airplane_isdestroyed" << "airplane_start" << "airplane_start2"
	<< "airplaneshowdamage" << "brigde_shutdown" << "callsubroutine" << "camera_getfov" << "camera_lock"
	<< "camera_setfov" << "camera_setrange" << "camera_setswing" << "camera_unlock" << "car_breakmotor"
	<< "car_calm" << "car_disable_uo" << "car_enableus" << "car_explosion" << "car_forcestop"
	<< "car_getactlevel" << "car_getmaxlevels" << "car_getseatcount" << "car_getspeccoll" << "car_getspeed"
	<< "car_invisible" << "car_inwater" << "car_lock" << "car_lock_all" << "car_muststeal" << "car_remove_driver"
	<< "car_repair" << "car_setactlevel" << "car_setaxis" << "car_setdestroymotor" << "car_setdooropen"
	<< "car_setprojector" << "car_setspeccoll" << "car_setspeed" << "car_switchshowenergy" << "car_unbreakable"
	<< "cardamagevisible" << "carlight_indic_l" << "carlight_indic_off" << "carlight_indic_r" << "carlight_light"
	<< "carlight_main" << "cartridge_invalidate" << "change_mission" << "character_pop" << "character_push"
	<< "citycaching_tick" << "citymusic_off" << "citymusic_on" << "cleardifferences" << "coll_testline"
	<< "commandblock" << "compareactors" << "compareframes" << "compareownerwith" << "compareownerwithex"
	<< "create_physicalobject" << "createweaponfromframe" << "ctrl_read" << "destroy_physicalobject"
	<< "detector_createdyncoll" << "detector_erasedyncoll" << "detector_erasedyncoll" << "detector_inrange"
	<< "detector_issignal" << "detector_setsignal" << "detector_waitforhit" << "detector_waitforuse"
	<< "dialog_begin" << "dialog_camswitch" << "dialog_end" << "disablecolls" << "door_enableus"
	<< "door_getstate" << "door_lock" << "door_open" << "door_setopenpose" << "emitparticle"
	<< "enablemap" << "endofmission" << "event_use_cb" << "explosion" << "findactor" << "findframe"
	<< "findnearactor" << "floatreg_pop" << "floatreg_push" << "frameistelephone" << "freeride_enablecar"
	<< "freeride_scoreadd" << "freeride_scoreget" << "freeride_scoreon" << "freeride_scoreset"
	<< "freeride_traffsetup" << "frm_getchild" << "frm_getdir" << "frm_getlocalmatrix" << "frm_getnumchildren"
	<< "frm_getparent" << "frm_getpos" << "frm_getrot" << "frm_getscale" << "frm_getworlddir"
	<< "frm_getworldmatrix" << "frm_getworldpos" << "frm_getworldrot" << "frm_getworldscale" << "frm_ison"
	<< "frm_linkto" << "frm_setalpha" << "frm_setdir" << "frm_seton" << "frm_setpos" << "frm_setrot"
	<< "frm_setscale" << "fuckingbox_add" << "fuckingbox_add_dest" << "fuckingbox_getnumbox"
	<< "fuckingbox_getnumdest" << "fuckingbox_move" << "fuckingbox_recompile" << "game_nightmission"
	<< "garage_addcar" << "garage_addcaridx" << "garage_addlaststolen" << "garage_cansteal"
	<< "garage_carmanager" << "garage_delcar" << "garage_enablesteal" << "garage_generatecars" << "garage_nezahazuj"
	<< "garage_releasecars" << "garage_show" << "group_disband" << "gunshop_menu";
	
	commandKeywords << "beep" << "console_addtext" << "debug_getframeinfo" << "debug_text";
	
	commandKeywords << "enemy_action_backlook" << "enemy_action_fire" << "enemy_action_follow" << "enemy_action_jump"
	<< "enemy_action_phonecall" << "enemy_action_runaway" << "enemy_action_runcloserto"
	<< "enemy_action_sidelook" << "enemy_action_stepaway" << "enemy_action_strafe" << "enemy_actionsclear"
	<< "enemy_arrest_player" << "enemy_az_po_panice_hovno" << "enemy_blastfire" << "enemy_block"
	<< "enemy_block_checkpoint" << "enemy_box_goto" << "enemy_box_put" << "enemy_box_take" << "enemy_brainwash"
	<< "enemy_car_escape" << "enemy_car_hunt" << "enemy_changeanim" << "enemy_enter_door" << "enemy_exit_railway"
	<< "enemy_followplayer" << "enemy_forcescript" << "enemy_gethostilestate" << "enemy_getstate"
	<< "enemy_group_add" << "enemy_group_addcar" << "enemy_group_chcipni_hajzel" << "enemy_group_del"
	<< "enemy_group_new" << "enemy_ignore_corpse" << "enemy_kickdriver" << "enemy_lockstate" << "enemy_look"
	<< "enemy_lookto" << "enemy_move" << "enemy_move_to_car" << "enemy_move_to_frame" << "enemy_naprdelivaute"
	<< "enemy_narohysevyser" << "enemy_naserse" << "enemy_nevyhazuj" << "enemy_playanim" << "enemy_podvadim_jak"
	<< "enemy_setstate" << "enemy_shutup" << "enemy_stop" << "enemy_stopanim" << "enemy_talk" << "enemy_turnback"
	<< "enemy_unblock" << "enemy_use_detector" << "enemy_use_railway" << "enemy_usecar" << "enemy_vidim"
	<< "enemy_wait" << "enemy_watch";
	
	commandKeywords << "human_activateweapon" << "human_addweapon" << "human_anyweaponinhand" << "human_anyweaponininventory"
	<< "human_canaddweapon" << "human_candie" << "human_changeanim" << "human_changemodel" << "human_createab"
	<< "human_death" << "human_delweapon" << "human_entertotruck" << "human_eraseab" << "human_force_settocar"
	<< "human_forcefall" << "human_fromcar" << "human_getactanimid" << "human_getiteminrhand" << "human_getowner"
	<< "human_getproperty" << "human_getseatidx" << "human_havebody" << "human_havebox" << "human_holster"
	<< "human_isweapon" << "human_linktohand" << "human_looktoactor" << "human_looktoframe" << "human_reset"
	<< "human_returnfrompanic" << "human_returntotraff" << "human_set8slot" << "human_setfiretarget"
	<< "human_setproperty" << "human_shutup" << "human_stoptalk" << "human_talk" << "human_throwgrenade"
	<< "human_throwitem" << "human_unlinkfromhand" << "human_waittoready" << "iffltinrange" << "ifplayerstealcar"
	<< "intro_subtitle_add" << "inventory_clear" << "inventory_pop" << "inventory_push" << "iscarusable"
	<< "ispointinarea" << "ispointinsector" << "isvalidtaxipassenger" << "loadcolltree" << "loaddifferences"
	<< "m7_zastavzkurvenepolise" << "math_abs" << "math_cos" << "math_sin" << "enemy_car_moveto" << "entity_debug_graphs"
	<< "get_pm_numpredators" << "frm_getlocalmatrix" << "mission_objectives" << "mission_objectivesclear"
	<< "mission_objectivesremove" << "model_create" << "model_destroy" << "model_playanim" << "model_stopanim"
	<< "noanimpreload" << "npc_shutup" << "person_playanim" << "person_stopanim" << "phobj_impuls" << "play_avi_intro"
	<< "player_lockcontrols" << "playsound" << "playsoundex" << "playsoundstop" << "pm_setprogress" << "pm_showprogress"
	<< "pm_showsymbol" << "pockurvenychbedencar" << "police_speed_factor" << "police_support" << "policeitchforplayer"
	<< "policemanager_add" << "policemanager_del" << "policemanager_forcearrest" << "policemanager_on"
	<< "policemanager_setspeed" << "preloadmodel" << "program_storage" << "pumper_canwork" << "racing_autoinvisible"
	<< "racing_change_model" << "racing_mission6_init" << "racing_mission6_start" << "recaddactor" << "recclear"
	<< "recload" << "recloadfull" << "recunload" << "recwaitforend" << "set_remote_actor" << "set_remote_float"
	<< "set_remote_frame" << "setaipriority" << "setcitytrafficvisible" << "setcompass" << "setevent"
	<< "setfilmmusic" << "setfreeride" << "setlmlevel" << "setmissionnameid" << "setmissionnumber"
	<< "setmodeltocar" << "setnoanimhit" << "setnpckillevent" << "setnullactor" << "setnullframe" << "setplayerfireevent"
	<< "setplayerhornevent" << "setplayerfallevent" << "settankhitcount" << "settimeoutevent" << "settraffsectorsnd"
	<< "showcardammage" << "sound_getvolume" << "sound_setvolume" << "soundfade" << "stopparticle" << "stopsound"
	<< "stream_connect" << "stream_create" << "stream_destroy" << "stream_fadevol" << "stream_getpos"
	<< "stream_pause" << "stream_play" << "stream_setloop" << "stream_setpos" << "stream_stop" << "subtitle"
	<< "taxidriver_enable" << "timer_getinterval" << "timer_setinterval" << "timeroff" << "timeron" << "use_lightcache"
	<< "version_is_editor" << "version_is_germany" << "vlvp" << "wagon_getlastnode" << "wagon_setevent"
	<< "weather_preparebuffer" << "weather_reset" << "weather_setparam" << "wingman_delindicator" << "wingman_setindicator"
	<< "zatmyse";
	
	commandKeywords << "matrix_copy" << "matrix_identity" << "matrix_inverse" << "matrix_mul" << "matrix_zero"
	<< "quat_add" << "quat_copy" << "quat_dot" << "quat_extract" << "quat_getrotmatrix" << "quat_inverse"
	<< "quat_make" << "quat_mul_quat" << "quat_mul_scl" << "quat_normalize" << "quat_rotbymatrix" << "quat_setdir"
	<< "quat_slerp" << "vect_add_vect" << "vect_angleto" << "vect_copy" << "vect_inverse" << "vect_magnitude"
	<< "vect_mul_matrix" << "vect_mul_quat" << "vect_mul_scl" << "vect_mul_vect" << "vect_normalize"
	<< "vect_set" << "vect_sub_vect";

	//-----------------------------------------------------------------//
	//-----------------------------Lines-------------------------------//
	//-----------------------------------------------------------------//
	
	labelKeywords << "label" << "event";
	dimKeywords << "dim_flt" << "dim_act" << "dim_frm";

	//-----------------------------ELSE-----------------------------//

	reloadSettings();
	reinitialise();
}


MafiaSyntax::~MafiaSyntax( void ) {
	return;
}

int MafiaSyntax::highlightParagraph( const QString &text, int endStateOfLastPara )
{
	
	int start=0;
	int wholeLine = -1;
	bool commentLine = false;
	QStringList tempLines1 = QStringList::split( ',', text, true );
	QStringList tempLines2 = QStringList::split( '[', tempLines1.join( "[" ), true );
	QStringList tempLines3 = QStringList::split( ']', tempLines2.join( "]" ), true );
	QStringList tempLines4 = QStringList::split( '-', tempLines3.join( "-" ), true );
	QStringList tempLines5 = QStringList::split( '+', tempLines4.join( "+" ), true );
	QStringList tempLines6 = QStringList::split( '=', tempLines5.join( "=" ), true );
	QStringList tempLines7 = QStringList::split( '<', tempLines6.join( "<" ), true );
	QStringList tempLines8 = QStringList::split( '>', tempLines7.join( ">" ), true );
	QStringList lines = QStringList::split( ' ', tempLines8.join( " " ), true );
	
	for(unsigned int i=0; i<lines.count(); i++) {
		int commandLength = 0;

		QString line = lines[i];
		int lineLength = line.length() + 1;

		if(line.isNull() || line.isEmpty()) {
			setFormat(start, lineLength, standardFont, QColor( 0, 0, 0 ) );
			start += lineLength;
			continue;
		}

		for(int i=0; i<lineLength-1; i++) {
			QChar a = line[i];
			if(a == QChar::null) {
				break;
			} else if(a.isSpace()) {
				commandLength++;
			} else {
				break;
			}
		}
		line = line.simplifyWhiteSpace().lower();
		
		bool failed = true;
		
		//---------------------------------------------------------//
		
		if( endStateOfLastPara == 1 )
		{
			setFormat( start, lineLength, standardFont, quotationColor );
			failed = false;
			if( line.endsWith( "\"" ) == true )
				endStateOfLastPara = 0;
			else
				endStateOfLastPara = 1;
		}
		else if( line.startsWith( "\"" ) )
		{
			setFormat( start, lineLength, standardFont, quotationColor );
			failed = false;
			if( line.endsWith( "\"" ) == FALSE )
				endStateOfLastPara = 1;
		}
		else if( wholeLine > -1 )
		{
			setFormat( start, lineLength, lineFont[wholeLine], lineColor[wholeLine] );
			failed = false;
		}
		else if( line.startsWith( "//" ) || commentLine == true )
		{
			setFormat(start, lineLength, commentFont, commentColor );
			failed = false;
			commentLine = true;
		}
		else
		
		if( failed )
			for( unsigned int i = 0; i < lineKeywords.count(); i++ )
				for( unsigned int j = 0; j < lineKeywords[i].count(); j++ )
					if( line == lineKeywords[i][j] )
					{
						setFormat( start, lineLength, lineFont[i], lineColor[i] );
						failed = false;
						wholeLine = i;
						break;
					}
		
		//-----------//
		if( failed )
			for( unsigned int i = 0; i < wordKeywords.count(); i++ )
				for( unsigned int j = 0; j < wordKeywords[i].count(); j++ )
					if( line == wordKeywords[i][j] )
					{
						setFormat( start, lineLength, wordFont[i], wordColor[i] );
						failed = false;
						break;
					}
		
		//-----------//
		
		if( failed )
		{
			bool startWithInt = false;
			bool endWithInt = false;
			for( unsigned short i = 0; i < 10; i++ )
			{
				if( line.startsWith( QString::number( i ) ) == TRUE )
					startWithInt = true;
				if( line.endsWith( QString::number( i ) ) == TRUE )
					endWithInt = true;
			}
			if( startWithInt == true && endWithInt == true )
			{
				setFormat( start, line.length(), digitFont, digitColor );
				failed = false;
			}
		}
		
		if( failed ) {
			setFormat( start, lineLength, standardFont, standardColor );
		}

		start += lineLength;
	}

	return endStateOfLastPara;
}

void MafiaSyntax::reinitialise()
{
	wordKeywords.clear();
	wordColor.clear();
	wordFont.clear();

	lineKeywords.clear();
	lineColor.clear();
	lineFont.clear();

	wordKeywords << statementKeywords << commandKeywords;
	wordColor << statementColor << commandColor;	
	wordFont << statementFont << commandFont;


	lineKeywords << labelKeywords << dimKeywords;
	lineColor << labelColor << dimColor;
	lineFont << labelFont << dimFont;

	this->rehighlight();
}

void MafiaSyntax::reloadSettings()
{
	standardColor = QColor( settings->readEntry( "syntax/" + path + "/colors/standard", "#000000" ) );
	labelColor = QColor( settings->readEntry( "syntax/" + path + "/colors/label", "#0000B4" ) );
	statementColor = QColor( settings->readEntry( "syntax/" + path + "/colors/statement", "#0000B4" ) );
	commandColor = QColor( settings->readEntry( "syntax/" + path + "/colors/command", "#0000B4" ) );
	dimColor = QColor( settings->readEntry( "syntax/" + path + "/colors/dim", "#FF0000" ) );
	digitColor = QColor( settings->readEntry( "syntax/" + path + "/colors/digit", "#000000" ) );
	quotationColor = QColor( settings->readEntry( "syntax/" + path + "/colors/quotation", "#E600B3" ) );
	commentColor = QColor( settings->readEntry( "syntax/" + path + "/colors/comment", "#007D00" ) );

	standardFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/standard", this->textEdit()->font().toString() ) );
	labelFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/label", this->textEdit()->font().toString() ) );
	statementFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/statement", this->textEdit()->font().toString() ) );
	commandFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/command", this->textEdit()->font().toString() ) );
	dimFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/dim", this->textEdit()->font().toString() ) );
	digitFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/digit", this->textEdit()->font().toString() ) );
	quotationFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/quotation", this->textEdit()->font().toString() ) );
	commentFont.fromString( settings->readEntry( "syntax/" + path + "/fonts/comment", this->textEdit()->font().toString() ) );
}
