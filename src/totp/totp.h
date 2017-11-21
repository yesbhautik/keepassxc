/*
 *  Copyright (C) 2017 Weslly Honorato <﻿weslly@protonmail.com>
 *  Copyright (C) 2017 KeePassXC Team <team@keepassxc.org>
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

#ifndef QTOTP_H
#define QTOTP_H

#include <QtCore/qglobal.h>
#include <QString>
#include <QMap>

class QUrl;

class Totp
{
public:
    Totp();
    static QString parseOtpString(QString rawSecret, quint8& digits, quint8& step);
    static QString generateTotp(const QByteArray key, quint64 time, const quint8 numDigits, const quint8 step);
    static QUrl generateOtpString(const QString& secret,
                                  const QString& type,
                                  const QString& issuer,
                                  const QString& username,
                                  const QString& algorithm,
                                  quint8 digits,
                                  quint8 step);
    static const quint8 defaultStep;
    static const quint8 defaultDigits;
    struct Encoder
    {
        QString name;
        QString shortName;
        QString alphabet;
        quint8 digits;
        quint8 step;
        bool reverse;
    };
    static const Encoder defaultEncoder;
    // custom encoder values that overload the digits field
    static const quint8 ENCODER_STEAM;
    static const QMap<quint8, Encoder> encoders;
    static const QMap<QString, quint8> shortNameToEncoder;
    static const QMap<QString, quint8> nameToEncoder;
};

#endif // QTOTP_H
