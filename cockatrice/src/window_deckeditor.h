#ifndef WINDOW_DECKEDITOR_H
#define WINDOW_DECKEDITOR_H

#include <QMainWindow>
#include <QAbstractItemModel>
#include "decklist.h"

class CardDatabase;
class CardDatabaseModel;
class DeckListModel;
class QTreeView;
class QTableView;
class CardInfoWidget;
class QLineEdit;

class WndDeckEditor : public QMainWindow {
	Q_OBJECT
private slots:
	void updateCardInfoLeft(const QModelIndex &current, const QModelIndex &previous);
	void updateCardInfoRight(const QModelIndex &current, const QModelIndex &previous);

	void actNewDeck();
	void actLoadDeck();
	void actSaveDeck();
	void actSaveDeckAs();

	void actAddCard();
	void actRemoveCard();
	void actIncrement();
	void actDecrement();
private:
	QString lastFileName;
	DeckList::FileFormat lastFileFormat;
	CardDatabase *db;

	CardDatabaseModel *databaseModel;
	DeckListModel *deckModel;
	QTreeView *databaseView;
	QTreeView *deckView;
	CardInfoWidget *cardInfo;
	QLineEdit *nameEdit, *commentsEdit;

	QMenu *deckMenu;
	QAction *aNewDeck, *aLoadDeck, *aSaveDeck, *aSaveDeckAs;
	QAction *aAddCard, *aRemoveCard, *aIncrement, *aDecrement;
public:
	WndDeckEditor(CardDatabase *_db, QWidget *parent = 0);
	~WndDeckEditor();
};

#endif
