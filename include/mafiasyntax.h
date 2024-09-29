#ifndef MYMAFIASYNTAX_H
#define MYMAFIASYNTAX_H

#include <qsyntaxhighlighter.h>
#include <qregexp.h>
#include <qstring.h>
#include <qstringlist.h>

class MafiaSyntax : public QSyntaxHighlighter
{
public:
	enum Mode { Edit, Preview };
	
	MafiaSyntax( QTextEdit * textEdit, Mode m = Edit );
	virtual ~MafiaSyntax( void );

	int highlightParagraph( const QString &text, int endStateOfLastPara );
	void reinitialise();
	void reloadSettings();
	void changeMode( Mode mode );

	QColor standardColor;
	QColor labelColor;
	QColor statementColor;
	QColor commandColor;
	QColor dimColor;
	QColor digitColor;
	QColor quotationColor;
	QColor commentColor;

	QString fontFamily;

	QFont standardFont;
	QFont labelFont;
	QFont statementFont;
	QFont commandFont;
	QFont dimFont;
	QFont digitFont;
	QFont quotationFont;
	QFont commentFont;

protected:
	QStringList labelKeywords;
	QStringList statementKeywords;
	QStringList commandKeywords;
	QStringList dimKeywords;
	QStringList digitKeywords;
	QStringList quotationKeywords;
	QStringList commentKeywords;

	QValueList<QStringList> wordKeywords;
	QValueList<QColor> wordColor;
	QValueList<QFont> wordFont;
	QValueList<QStringList> lineKeywords;
	QValueList<QColor> lineColor;
	QValueList<QFont> lineFont;

	Mode mode;
	QString path;
};
#endif