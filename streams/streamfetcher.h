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

#ifndef STREAMFETCHER_H
#define STREAMFETCHER_H

#include <QObject>
#include <QList>
#include <QByteArray>
#include <QStringList>

class NetworkJob;

class StreamFetcher : public QObject
{
    Q_OBJECT

public:
    static void enableDebug();

    StreamFetcher(QObject *p);
    virtual ~StreamFetcher();

    void get(const QStringList &items, int insertRow, int action, quint8 priority);

private:
    void doNext();

public Q_SLOTS:
    void cancel();

Q_SIGNALS:
    void result(const QStringList &items, int insertRow, int action, quint8 priority);
    void status(const QString &msg);

private Q_SLOTS:
    void dataReady();
    void jobFinished();

private:
    void jobFinished(NetworkJob *reply);
    void cancelJob();

private:
    NetworkJob *job;
    QString current;
    QString currentName;
    QStringList todo;
    QStringList done;
    int row;
    int playQueueAction;
    quint8 prio;
    int redirects;
    QByteArray data;
};

#endif
