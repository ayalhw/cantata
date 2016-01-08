/*
 * Cantata
 *
 * Copyright (c) 2011-2016 Craig Drummond <craig.p.drummond@gmail.com>
 *
 * ----
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef LIBRARYPAGE_H
#define LIBRARYPAGE_H

#include "widgets/singlepagewidget.h"

class Action;
//class ComboBox;

class LibraryPage : public SinglePageWidget
{
    Q_OBJECT

public:
    LibraryPage(QWidget *p);
    virtual ~LibraryPage();

    void clear();
    QStringList selectedFiles(bool allowPlaylists=false) const;
    QList<Song> selectedSongs(bool allowPlaylists=false) const;
    Song coverRequest() const;
    #ifdef ENABLE_DEVICES_SUPPORT
    void addSelectionToDevice(const QString &udi);
    void deleteSongs();
    #endif
    void showSongs(const QList<Song> &songs);
    void showArtist(const QString &artist);
    void showAlbum(const QString &artist, const QString &album);

private:
    void setItemSize(int v);

Q_SIGNALS:
    void addToDevice(const QString &from, const QString &to, const QList<Song> &songs);
    void deleteSongs(const QString &from, const QList<Song> &songs);

public Q_SLOTS:
    void itemDoubleClicked(const QModelIndex &);

private Q_SLOTS:
    void groupByChanged();
    void libraryAlbumSortChanged();
    void albumAlbumSortChanged();
    void showArtistImagesChanged(bool u);
    void updateToPlayQueue(const QModelIndex &idx, bool replace);
    void addRandomAlbum();

private:
    void setView(int v);
    void doSearch();
    void controlActions();

private:
//    ComboBox *groupCombo;
    QAction *viewAction;
    QAction *showArtistImagesAction;
    QAction *libraryAlbumSortAction;
    QAction *albumAlbumSortAction;
};

#endif
