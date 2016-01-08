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

#ifndef CDALBUM_H
#define CDALBUM_H

#include <QString>
#include <QList>
#include "mpd-interface/song.h"

struct CdAlbum {
    CdAlbum() : isDefault(false), year(0), disc(0)  { }
    bool isNull() const { return 0==year && 0==disc && tracks.isEmpty() && name.isEmpty() && artist.isEmpty() && composer.isEmpty() && genre.isEmpty(); }
    bool isDefault;
    QString name;
    QString artist;
    QString composer;
    QString genre;
    int year;
    int disc;
    QList<Song> tracks;
};

#endif
