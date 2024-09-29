//About Dialog CPP File

#include "aboutdialog.h"
#include "img/about.xpm"

#include <qlabel.h>
#include <qtextedit.h>

AboutDialog::AboutDialog( QWidget * parent, const char * name, WFlags f)
		  : QDialog( parent, name, TRUE, f )
{
	int windowXPos = 390;
	int windowYPos = 300;
	int windowWidth = 389;
	int windowHeight = 270;
	int pixmapHeight = 81;

	setMinimumSize( windowWidth, windowHeight );
	setMaximumSize( windowWidth, windowHeight );
	setGeometry( windowXPos, windowYPos, windowWidth, windowHeight );
	setCaption( "About" );
	
	QLabel * pixmapLabel = new QLabel( this );
	pixmapLabel->resize( windowWidth, pixmapHeight );
	pixmapLabel->setPixmap( QPixmap( (const char **)(about_xpm) ) );

	QTextEdit * aboutTextView = new QTextEdit( this );	
	aboutTextView->setReadOnly( TRUE );
	aboutTextView->setGeometry( 0, pixmapHeight, windowWidth, windowHeight - pixmapHeight );
	aboutTextView->setFont( QFont( "Arial", 9, QFont::Normal ) );
	aboutTextView->setText( tr(  "<table border=\"0\">"
								 "<tr><th><u><b>Development:</b></u></th></tr>"
								 "<tr><td>ASM</td><td>MafiaLib technology and file documentations</td></tr>"
								 "<tr><td>Scream</td><td>Graphical user interface</td></tr>"
								 "<tr><td>asdfadf</td><td>File documentations</td></tr>"
								 "<tr><td>LGs0pHT</td><td>Development leading</td></tr>"
								 "</table>"
								 "<br>"
								 "<table border=\"0\">"
								 "<tr><th><u><b>Translations:</b></u></th></tr>"
								 "<tr><td>TreuZ</td><td>French</td></tr>"
								 "<tr><td>excamo</td><td>Czech</td></tr>"
								 "<tr><td>LGs0pHT</td><td>German</td></tr>"
								 "</table>"
								 "<br>"
								 "<table border=\"0\">"
								 "<tr><th><u><b>Beta testing:</b></u></th></tr>"
								 "<tr><td>TreuZ</td></tr>"
								 "<tr><td>DonUittone</td></tr>"
								 "<tr><td>don|corleone</td></tr>"
								 "<tr><td>Jeep314</td></tr>"
								 "<tr><td>SecurityManKillJoy</td></tr>"
								 "</table>"
								 "<br>"
								 "<table border=\"0\">"
								 "<tr><th><u><b>Special thanks to:</b></u></th></tr>"
								 "<tr><td>smoothcode from <a href=\"http://www.puredesigns.de\">www.puredesigns.de</a> for the nice "
								 "DC||ED and MMC logo</tr></td>"
								 "<tr><td><a href=\"http://www.mafia-thegame.de\">www.Mafia-TheGame.de</a></td></tr>"
								 "<tr><td><a href=\"http://www.planet-multiplayer.de\">www.Planet-Multiplayer.de</a></td></tr>"
								 "</table>"
								 "<br>"
								 "© 2004 MMC" ) );
}
