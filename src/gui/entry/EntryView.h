/*
 *  Copyright (C) 2010 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_ENTRYVIEW_H
#define KEEPASSX_ENTRYVIEW_H

#include <QtGui/QTreeView>

class Entry;
class EntryModel;
class Group;
class QSortFilterProxyModel;

class EntryView : public QTreeView
{
    Q_OBJECT

public:
    explicit EntryView(QWidget* parent = 0);
    void setModel(QAbstractItemModel* model);
    Entry* currentEntry();
    bool isSingleEntrySelected();
    void setCurrentEntry(Entry* entry);
    Entry* entryFromIndex(const QModelIndex& index);
    void search(const QList<Entry*>& entries);
    bool inSearch();

public Q_SLOTS:
    void setGroup(Group* group);

Q_SIGNALS:
    void entryActivated(Entry* entry);
    void entrySelectionChanged();

private Q_SLOTS:
    void emitEntryActivated(const QModelIndex& index);
    void switchToSearch();
    void switchToView();

private:
    EntryModel* const m_model;
    QSortFilterProxyModel* const m_sortModel;
    bool m_inSearch;
};

#endif // KEEPASSX_ENTRYVIEW_H