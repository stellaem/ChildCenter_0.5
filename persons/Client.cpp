#include "Client.h"

#include <QSqlQuery>
/**************************************************************************************************/
Client::Client(int id, QObject *parent) : QObject(parent), id(id)
{
    QSqlQuery q = QSqlQuery();
    q.prepare("select * from client where id = :id");
    q.bindValue(":id", id);
    q.exec();
    q.next();

    numCard = q.value("num_card").toInt();
    name = q.value("name").toString();
    patronymic = q.value("patronymic").toString();
    surname = q.value("surname").toString();
    birthday = q.value("birthday").toDate();
    firstConsult =  q.value("first_consult").toDate();
}
/*------------------------------------------------------------------------------------------------*/
int Client::getId() const
{
    return id;
}
/*------------------------------------------------------------------------------------------------*/
int Client::getNumCard() const
{
    return numCard;
}
/*------------------------------------------------------------------------------------------------*/
const QString &Client::getName() const
{
    return name;
}
/*------------------------------------------------------------------------------------------------*/
void Client::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}
/*------------------------------------------------------------------------------------------------*/
const QString &Client::getPatronymic() const
{
    return patronymic;
}
/*------------------------------------------------------------------------------------------------*/
void Client::setPatronymic(const QString &newPatronymic)
{
    if (patronymic == newPatronymic)
        return;
    patronymic = newPatronymic;
    emit patronymicChanged();
}
/*------------------------------------------------------------------------------------------------*/
const QString &Client::getSurname() const
{
    return surname;
}
/*------------------------------------------------------------------------------------------------*/
void Client::setSurname(const QString &newSurname)
{
    if (surname == newSurname)
        return;
    surname = newSurname;
    emit surnameChanged();
}
/*------------------------------------------------------------------------------------------------*/
const QDate &Client::getBirthday() const
{
    return birthday;
}
/*------------------------------------------------------------------------------------------------*/
void Client::setBirthday(const QDate &newBirthday)
{
    if (birthday == newBirthday)
        return;
    birthday = newBirthday;
    emit birthdayChanged();
}
/**************************************************************************************************/
